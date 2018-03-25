// RomanToArabicCpp.cpp : Defines the entry point for the console application.
//
//#include "ConvertNumbers.h"
#include "stdafx.h"


using namespace std;



int main()
{ 
	
	string  p = "s";
	
	while (1)
	{ 
		ConvertNumbers ToArabic;
		ToArabic.EnterNumber();  //Suggestion to type any Roman number
	ToArabic.ValidationFunction(); //Validation of the entered Roman number
	if (ToArabic.getErrorPresence() != 0) // If there is an error go back to suggestion to type any valid Roman number
		continue;
	cout <<  ToArabic.fromRoman(ToArabic.getEnteredNumber())<<'\n'<<"\nPress ""q"" to quit or another key to repeat\n";
	cin >> p;

		if ( p== "q")
		{
			break; 
		}
	
	}
    return 0;
}

