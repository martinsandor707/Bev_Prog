#include "std_lib_facilities.h"
//Drill3.cpp
int main()
{
	cout <<"Enter the name of the person you want to write to:\n";
	string first_name, friend_name; 
	char friend_sex=0;
	int age=0;
	
	cin>> first_name;	//read characters into first_name
	cout <<"Enter their age:\n";
	cin >> age;
	cout <<"Enter the name of a friend:\n";
	cin>> friend_name;
	cout <<"Enter 'm' if the other friend is male, 'f' if female:\n";
	cin>> friend_sex;
	cout<<"Dear " <<first_name<<",\n";
	cout<<"How are you? I am fine. I miss you. It's been over 3 weeks that we weren't able to see each other, but that's hopefully going to change soon! Have you seen "<<friend_name<<" lately?";
	
	if (friend_sex=='m') cout<<" If you see " <<friend_name<<" please ask him to call me.";
	else cout<<" If you see " <<friend_name<<" please ask her to call me.";
	
	if (age>0 && age<110) cout << " I hear you just had a birthday and you are "<< age <<" years old.";
	else simple_error(" You're kidding!");
		
	if (age<12) cout <<" Next year you will be "<< (age+1) <<".";
	else if (age==17) cout <<" Next year you will be able to vote.";
	else if (age>70) cout <<" I hope you are enjoying retirement.";
	cout <<" I really hope that we'll be able to celebrate together next time!";
	
	cout<<"\nYours sincerely,\n\n\nMartin Sandor";
	
	return 0;
}
