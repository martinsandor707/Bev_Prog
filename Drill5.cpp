#include "std_lib_facilities.h"
//Drill5.cpp
int main(){

try {
	//Cout<<"Success!\n";								//1. The "c" in cout is capital instead of lowercase 
	//cout << "Success!\n;								//2. Closing apostrophes are missing
	//cout << "Success" << !\n"							//3. Exclamation mark doesn't have opening apostrophes
	//cout << success << '\n';							//4. No apostrophes for "success"
	//string res = 7; vector<int> v(10); v[5] = res;	//5. res was given an integer value (should have used apostrophes), and the integer vector v was given a string as a value
	//cout << "Success!\n";								//This line is fine
	//vector<int> v(10); v(5) = 7;						//6. When operating vectors, referencing a position in the vector should be done using square brackets [] instead of parentheses
	//if (v(5) != 7) cout << "Success!\n";				//Same here
	//if (cond) cout << "Success!\n";					//7. Condition "cond" is not defined and no such variable exists 
	//else cout << "Fail!\n";
	//bool c = false; if (c) cout << "Success!\n";		//8. No compile error this time, but the if statement will always be false
	//else cout << "Fail!\n";
	//string s = "ape"; boo c = "fool" < s;				//9. Missing l from bool. No idea what the condition is though.
	//if (c) cout << "Success!\n";
	//string s = "ape";									//10. Condition is always false
	//if (s == "fool") cout << "Success!\n";
	//string s = "ape";									//11. Missing < operand in cout
	//if (s == "fool") cout < "Success!\n";
	//string s = "ape";									//12. Operand still missing, plus the if statement's condition is not convertible to boolean
	//if (s + "fool") cout < "Success!\n";
	//vector<char> v(5);
	//for (int i = 0; 0 < v.size(); ++i);				//13. Infinite loop, condition not affected by incrementing i
	//cout << "Success!\n";
	//vector<char> v(5); 
	//for (int i = 0; i <= v.size(); ++i);				//14. No mistake here
	//cout << "Success!\n";
	//string s = "Success!\n"; 
	//for (int i = 0; i < 6; ++i) cout << s[i];			//15. No compile error, but the loop only outputs the first 6 characters instead of the entire string. Use s.size() instead.
	//if (true) then cout << "Success!\n";				//16. "then" is not a keyword in c++ by default. It also serves no purpose here.
	//else cout << "Fail!\n";
	//int x = 2000; char c = x; 
	//if (c == 2000) cout << "Success!\n";				//17. Making c equal with a number x modifies the character to the one which has an id of 2000 (in the utf-8 character table I presume). The condition will always be false, as a character cannot be equal to an integer.
	//string s = "Success!\n"; 
	//for (int i = 0; i < 10; ++i) cout << s[i];		//18. This is *technically* good, but it should throw an IndexOutOfBounds error/exception
	//vector v(5);										//19. Vector wasn't given the type of variables to store
	//for (int i = 0; i <= v.size(); ++i); 
	//cout << "Success!\n";
	//int i = 0; int j = 9; while (i < 10) ++j;			//20. Infinite loop, i isn't incremented.
	//if (j < i) cout << "Success!\n";
	//int x = 2; double d = 5 / (x–2);					//21. A long dash – is used instead of a regular dash - in "x-2", not to mention that doing this means we divide d by 0, which is a mathematical error.
	//if (d == 2 * x + 0.5) cout << "Success!\n";
	//string<char> s = "Success!\n";					//22. Strings are by definition an array of char, specifying char as an argument is therefore pointless and against syntax
	//for (int i = 0; i <= 10; ++i) cout << s[i];
	//int i = 0;										//23. Same problem as #20, plus j isn't even defined as a variable here
	//while (i < 10) ++j; if (j < i) cout << "Success!\n";
	//int x = 4; double d = 5 / (x–2);					//24. Same as #21, plus the if clause is always false
	//if (d = 2 * x + 0.5) cout << "Success!\n";
	//cin << "Success!\n";								//25. cin is used instead of cout
	keep_window_open();
	return 0;
}
catch (exception& e){
	cerr<<"error: "<< e.what()<<'\n';
	keep_window_open();
	return 1;
}
catch(...){
	cerr<<"Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}
}
