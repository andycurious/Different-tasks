#include "stdafx.h"




	string fromUserInput;

	string fromRomanInput;
	int ErrorPresence = 0;
	int tempValForArab = 0;
	int resultValForArab = 0;
	int ConvertNumbers::getErrorPresence()
	{
		return ErrorPresence;
	}
ConvertNumbers::ConvertNumbers()
	{
		ErrorPresence = 0;
		tempValForArab = 0;
		resultValForArab = 0;
		setNumber("IV");
	}
ConvertNumbers::ConvertNumbers(string fromUserInput)
	{
		setNumber(fromUserInput);
	}
ConvertNumbers::~ConvertNumbers()
	{

	}

	void  ConvertNumbers::setNumber(string fromUserInput)
	{
		fromRomanInput = (string) fromUserInput;

	}

	void ConvertNumbers::EnterNumber()
	{
		cout << "\nPlease, type a valid Roman number  you want to convert into Arabic:\n";
		cin >> fromUserInput;
		setNumber(fromUserInput);
	}
string ConvertNumbers::getEnteredNumber()
{
	return fromRomanInput;
}

	int ConvertNumbers::fromRoman(string fromRomanInput) //converting entered Roman number into Arabic
	{

		map <char, int> DictionaryOfRomanNumbers;
		DictionaryOfRomanNumbers['I'] = 1;
		DictionaryOfRomanNumbers['V'] = 5;
		DictionaryOfRomanNumbers['X'] = 10;
		DictionaryOfRomanNumbers['L'] = 50;
		DictionaryOfRomanNumbers['C'] = 100;
		DictionaryOfRomanNumbers['D'] = 500;
		DictionaryOfRomanNumbers['M'] = 1000;

		for (char c : fromRomanInput)
		{
			int fromRomanInput = DictionaryOfRomanNumbers[c];
			if (fromRomanInput < tempValForArab)
			{
				resultValForArab += tempValForArab; tempValForArab = fromRomanInput;

			}
			else if (fromRomanInput > tempValForArab)
			{
				if (tempValForArab == 0)
					tempValForArab = fromRomanInput;
				else
				{
					resultValForArab += fromRomanInput - tempValForArab;
					tempValForArab = 0;
				}
			}

			else if (fromRomanInput == tempValForArab)
			{
				resultValForArab += tempValForArab + fromRomanInput;
				tempValForArab = 0;
			}
		}
		return resultValForArab + tempValForArab;
	}


	void ConvertNumbers::ValidationFunction() //Validation of an entered Roman number
	{
		char character = 'I';
		int charcountUpperCase = 0;
		//int InputStringSize = 0;
		int charMatch = 0;
		int fromUserInputSize = 0;
		string outputUnaccept = "";
		string templateNumbersLowCase = "ivxlcdm";
		string templateNumbersUpperCase = "IVXLCDM";
		int charMismatch = 0;
		
		// Validation for not allowed characters
		for (char c : fromUserInput)
		{
			//charMatch = 0;
			charMismatch = fromUserInput.size();
			fromUserInputSize= fromUserInput.size();
			for (int index = 0; index < 7; index++)
			{

				if (templateNumbersUpperCase[index] == c)

				{
					charMatch++;
					charMismatch--;
				}
			}



		
			if (charMismatch != --fromUserInputSize)

			{
				outputUnaccept += c;  // information for user about not allowed characters
			}
		
		}
		try
		{
			if (charMatch != fromUserInput.size())
			{
				throw 102;
			}
		}
		catch (int inputError)
		{
			cout << "\n Not allowed characters: " << outputUnaccept<< "Error-"<<inputError;
			ErrorPresence = 1;
		}


		// validation for presence of lower case characters

		for (int index = 0; index < 7; index++)

		{
			try
			{
				for (char c : fromUserInput)

				{
					if (templateNumbersLowCase[index] == c)
					{
						throw 101;
					}

				}
			}
			catch (int inputError)
			{
				cout << "\nLower case in Roman numbers is not allowed- Error" << inputError;
				ErrorPresence = 1;
			}
		}

		// validation for presence more then three same characters following one another

		for (char c : fromUserInput)
		{
			if (character != c)
			{
				character = c;
			}
			if (character == c)
			{
				charcountUpperCase++;
			}
			character = c;

		}
		try
		{
			if (charcountUpperCase > 3)
			{
				throw 100;
			}
		}
		catch (int inputError)
		{

			cout << fromUserInput << "is not existing Roman number-Error" << inputError << "Roman number can't content more than three same characters following one after another";
			ErrorPresence = 1;
		}

	}