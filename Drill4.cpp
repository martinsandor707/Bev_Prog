#include "std_lib_facilities.h"
//Drill4.cpp
int main()
{
	char again=' ';
	string unit = "";
	int nrOfValues=0;
	double input, value=0, min=2000000, max=-2000000, sum=0;
	vector<double> allValues;
	while (again != '|')
	{
		cout << "Enter | to exit, or anything else to continue\n";
		cin >> again;
		if (again == '|') break;
		cout << "Please enter a number and a unit (cm, m, in, ft)\n";
		cin >> input >> unit;
			if (unit == "cm")
			{
				value = input * 0.01;
				cout << input << " centimeters = " << value << " meters\n";
				sum += value;
				allValues.push_back(value);
			}

			else if (unit == "m")
			{
				value = input;
				sum += value;
				allValues.push_back(value);
			}

			else if (unit == "in")
			{
				value = input * 0.0254;
				cout << input << " inches = " << value << " meters\n";
				sum += value;
				allValues.push_back(value);
			}

			else if (unit == "ft")
			{
				value = input * 0.0254 * 12;
				cout << input << " feet = " << value << " meters\n";
				sum += value;
				allValues.push_back(value);
			}

			else
			{
				cout << "Invalid unit!\n";
				break;
			}
		
			if (value<min)
			{
				min=value;
				cout<<value<<" the smallest number so far\n";
			}
			else if (value>max) 
			{
				max=value;
				cout<<value<<" the largest number so far\n";
			}
			
			
		}
	double dummy;							//Sorting the vector in ascending order using a third variable
	for (int i = 0; i < allValues.size(); i++)
	{
		for (int k = i; k < allValues.size(); k++)
		{
			if (allValues[i] > allValues[k]) 
			{
				dummy = allValues[i];
				allValues[i] = allValues[k];
				allValues[k] = dummy;
			}
		}
	}

	cout << "The smallest number given is " << min << '\n';
	cout << "The largest number given is " << max << '\n';
	cout << "The sum of all values given is " << sum << '\n';
	cout << "The number of values given is " << allValues.size() << '\n';
	cout << "The list of values given in ascending order is: " <<'\n';
	for (int i = 0; i <allValues.size(); i++)
	{
		cout << allValues[i] << '\n';
	}
	string quit;
	cout << "\n Enter any key to exit\n";
	cin >> quit;
	return 0;
}
