#pragma once
#ifndef CONVERTNUMBERS_H
#define CONVERTNUMBERS_H
#include "stdafx.h"

using namespace std;

class ConvertNumbers
{

public:
	string fromUserInput;
private:
	string fromRomanInput;
	int ErrorPresence;
	int tmp;
	int res;
public:
	int getErrorPresence();

	ConvertNumbers();

	ConvertNumbers(string fromUserInput);

	~ConvertNumbers();

	void  setNumber(string fromUserInput);

	void EnterNumber();

	string getEnteredNumber();

	int fromRoman(string fromRomanInput);

	void ValidationFunction();
	
};
#endif
