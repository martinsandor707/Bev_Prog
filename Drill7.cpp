
/*
	calculator08buggy.cpp

	Helpful comments removed.

	We have inserted 3 bugs that the compiler will catch and 3 that it won't.
	Bugs caught by the compiler:
		1. There was no constructor declared for Token with parameters char and string, even though it was requested	//This was the only compile error detected by Visual Studio
		2. Several warnings due to certain functions not having a default return value in case of an error
		


	Errors NOT caught by the compiler:
		1. In the get function, the word "quit" was interpreted as a symbol name instead of an order to quit
		2. In the get function when examining strings, concatenation should be s+=ch, not s=ch
		3. Primary didn't have a return value when examining parentheses

*/

#include "std_lib_facilities.h"

struct Token {
	char kind;		//Determines if input is an operation, assignment or a number
	double value;	
	string name;	//stores variables
	Token(char ch) :kind(ch), value(0) { }
	Token(char ch, double val) :kind(ch), value(val) { }
	Token(char ch, string str) :kind(ch), value(0), name(str) { }
};

class Token_stream {
	bool full;
	Token buffer;
public:
	Token_stream() :full(0), buffer(0) { }

	Token get();
	void unget(Token t) { buffer=t; full=true; }	//Puts token back into token strem

	void ignore(char);
};

const char let = '#';			//Constant expressions to be used in the calculator's syntax
const char set = 'S';
const char rt = 'R';
const char power = 'P';
const char quit = 'Q';
const char print = ';';
const char number = '8';
const char name = 'a';

Token Token_stream::get()
{
	//Check the buffer first
	if (full) { full=false; return buffer; }
	//Analyze the next token otherwise
	char ch;
	cin >> ch;
	switch (ch) {	//Looks at the input character by character
	case '#':
	case '(':
	case ')':
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case ';':
	case '=':
	case ',':
		return Token(ch);	//Operation or special action
	case '.':
	case '0':
	case '1':
	case '2':
	case '3':
	case '4':
	case '5':
	case '6':
	case '7':
	case '8':
	case '9':
	{	cin.unget();
		double val;
		cin >> val;
		return Token(number,val);	//Number
	}
	default:	//Other
		if (isalpha(ch)) {
			string s;
			s += ch;
			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s+=ch;	//Undetected bug #2 was here
			cin.unget();
			//if (s == "let") return Token(let);	 
			if (s == "set") return Token(set);	// Special actions denoted by multiple characters
			if (s == "sqrt") return Token(rt);
			if (s == "pow") return Token(power);
			if (s == "exit") return Token(quit); //Undetected bug #1 was here
			return Token(name,s);
		}
		error("Bad token");	//Warning detected at this line "Control reaches end of non void function"
		
	}
	return Token('e');
}

//Ignore tokens up to and including c
void Token_stream::ignore(char c)	
{
	if (full && c==buffer.kind) {
		full = false;
		return;
	}
	full = false;

	char ch;
	while (cin>>ch)
		if (ch==c) return;
}

struct Variable {
	string name;
	double value;
	Variable(string n, double v) :name(n), value(v) { }
};

vector<Variable> names;	

//Retrieves the value of symbols in the "names" vector
double get_value(string s)	
{
	for (int i = 0; i<names.size(); ++i)				//Warning detected here "Control reaches end of non void function"
		if (names[i].name == s) return names[i].value;
	error("get: undefined name ",s);
	return 0;
}

//Sets the value assigned to a symbol in the names vector
void set_value(string s, double d)	
{
	for (int i = 0; i<=names.size(); ++i)
		if (names[i].name == s) {
			names[i].value = d;
			return;
		}
	error("set: undefined name ",s);
}

//Checks if a symbol of a given name exists
bool is_declared(string s)	
{
	for (int i = 0; i<names.size(); ++i)
		if (names[i].name == s) return true;
	return false;
}

Token_stream ts;

double expression();

//Handles the input of parentheses, negative and positive numbers and symbols
double primary()	
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{	
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected");
		return d;	//Undetected bug #3, this case originally had no return value;
	}
	case '-':
		return - primary();
	case '+':
		return primary();
	case number:
		return t.value;
	case name:
		return get_value(t.name);
	default:
		error("primary expected");	//Warning detected here "Control reaches end of non void function"	
	}
	return 0;
}

//Handles the input for multiplication, division and modulo
double term()	
{
	double left = primary();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '*':
			left *= primary();
			break;
		case '/':
		{	
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			break;
		}

		default:
			ts.unget(t);
			return left;
		}
	}
}

//Handles the input for addition and subtraction
double expression()	
{
	double left = term();
	while(true) {
		Token t = ts.get();
		switch(t.kind) {
		case '+':
			left += term();
			break;
		case '-':
			left -= term();
			break;
		default:
			ts.unget(t);
			return left;
		}
	}
}

//Handles creating a new symbol
double declaration()	
{
	Token t = ts.get();
	if (t.kind != 'a') error ("name expected in declaration");
	string name = t.name;
	if (is_declared(name)) error(name, " declared twice");
	Token t2 = ts.get();
	if (t2.kind != '=') error("= missing in declaration of " ,name);
	double d = expression();
	names.push_back(Variable(name,d));
	return d;
}

//Takes the square root of the next expression
double fsqrt()
{
	double d = expression();
	if (d < 0) error("You can't take the square root of negative numbers in the domain of real numbers");
	else return sqrt(d);
	return 0;
}

//Raises the first argument (a double) to the power of the second argument (an integer)
double fpow()
{
	Token t = ts.get();
	if (t.kind != '(') error("' ( ' expected after pow");
	double base = expression();
	t = ts.get();
	if (t.kind != ',') error("' , ' expected");
	double tempexp = expression();
	if (tempexp < 0) error("You must give a positive integer as an exponent!");
	int exp = narrow_cast<int>(tempexp);		//casting the second parameter from double to int
	t = ts.get();
	if (t.kind != ')') error("' ) ' expected");	//error handling for syntax
	double result = 1;
	if (exp == 0) return result;
	else
	{
		for (int i = 0; i < exp; i++)
		{
			result *= base;
		}
	}

	return result;

}

//Detects keywords and initiates their function.
double statement()	
{
	Token t = ts.get();
	switch(t.kind) {
	case let:
		return declaration();
	case set:
	{
		Token t1 = ts.get();
		if (is_declared(t1.name))
		{
			Token t2 = ts.get();
			if (t2.kind != '=') error("= missing in redeclaration of ", name);
			double d = expression();
			set_value(t1.name, d);
		}
		else error("You can't redeclare a variable that doesn't exist");
	}
	case rt:
	{
		return fsqrt();
	}
	case power:
	{
		return fpow();
	}
	default:
		ts.unget(t);
		return expression();
	}
}

//Ignores everything in the token stream up until a ;
void clean_up_mess()	
{
	ts.ignore(print);
}

const string prompt = "> ";
const string result = "= ";

void calculate()
{
	while(true) try {
		cout << prompt;
		Token t = ts.get();
		while (t.kind == print) t=ts.get();
		if (t.kind == quit) return;
		ts.unget(t);
		cout << result << statement() << endl;
	}
	catch(runtime_error& e) {
		cerr << e.what() << endl;
		clean_up_mess();
	}
}

//main was missing it's curly brackets
int main()
{
	try {
		names.push_back(Variable("k", 1000)); //Predefining value of k
		calculate();
		return 0;
	}
	catch (exception& e) {
		cerr << "exception: " << e.what() << endl;
		char c;
		while (cin >> c && c != ';');
		return 1;
	}
	catch (...) {
		cerr << "exception\n";
		char c;
		while (cin >> c && c != ';');
		return 2;
	}
}
