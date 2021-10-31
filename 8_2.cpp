#include "../std_lib_facilities.h"


void swap_v(int a, int b)
{
	int temp; 
	temp = a; 
	a = b;
	b = temp;
}

void swap_r(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

/*void swap_cr(const int& a, const int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}*/							//This function doesn't compile, because we are trying to change the value of the constant parameters




int main()		
{
	int x = 7;
	int y = 9;
	cout << "The value of x is: " << x << "\nThe value of y is: " << y;
	swap_v(x, y);
	swap_v(7, 9);
	cout << "\nSwap_v called\n";
	cout << "The value of x is: " << x << "\nThe value of y is: " << y;		//The values of x and y didn't actually change, because the parameters passed to swap_v are separate objects, and not actually x and y
	
	const int cx = 7;
	const int cy = 9;
	//swap_r(cx, cy);				//Compile error: The parameters we gave were constant, and therefore the function wasn't allowed to change their values
	//swap_r(7.7, 9.9);				//Compile error: The parameters we gave were #1: double instead of int #2: not reference variables
	
	double dx = 7.7;
	double dy = 9.9;
	//swap_cr(dx, dy);
	//swap_cr(7.7, 9.9);

	return 0;
}
