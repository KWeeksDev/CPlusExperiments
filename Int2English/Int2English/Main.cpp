// Interger to Enlish Converter
// http://www.cprogramming.com/challenges/integer-to-english.html
// Take an interger input and output the regular sentence of that value
// Example input '123' output 'one hundred twenty three'
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

string underTwenty[20] = { "", "one ", "two ", "three ", "four ", "five ", "six ", "seven ", "eight ", "nine ", "ten ", "eleven ", "twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen " };
string doubleDigits[10] = { "", "", "twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety " };
string larger[5] = { "", "thousand ", "million ", "billion ", "hundred " };
string negative = "negative ";

// Get length in digits spaces for a given number
int NumberLength(int number)
{
	int len = 0;
	int temp = (int)abs(number);

	if (temp == 0)
	{
		len++;
	}

	while (temp > 0)
	{
		len++;
		temp /= 10;
	}

	return len;
}

int main(int argc, char* argv[])
{
	cout << "Enter an interger: ";

	int test;
	cin >> test;

	string result = "";
	// If the number is negative denote it and get the absolute value for easier calculations
	if (test < 0)
	{
		result.append(negative);
		test = (int)abs(test);
	}

	int len = NumberLength(test);
	for (int i = len; i > 0; i--)
	{
		int pwr = (int)pow(10, i-1);
		int temp = test / pwr;
		int temp2 = 0;
		bool isOverTwenty = false;
		switch (i % 3)
		{
		case 0: // The value is in a hundreds place
			temp2 = 4;
			break;
		case 1: // The value is in the ones place
			temp2 = i / 3;
			break;
		case 2: // The value is in the tens place and may prompt us to skip the ones place
			if (temp == 1)
			{
				pwr = (int)pow(10, i - 2);
				temp = test / pwr;
				i--;
				temp2 = i / 3;
			}
			else
			{
				isOverTwenty = true;
			}
			break;
		}
		if (isOverTwenty == false)
		{
			result.append(underTwenty[temp]);
			result.append(larger[temp2]);
		}
		else
		{
			result.append(doubleDigits[temp]);
		}
		test %= pwr;
	}
	
	if (result == "")
	{
		result = "zero";
	}

	cout << result;
	return 0;
}