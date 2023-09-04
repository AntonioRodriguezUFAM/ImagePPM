// How to convert a string to an int using the stoi() function
/*
One effective way to convert a string object into a numeral int is to use the stoi() function.

This method is commonly used for newer versions of C++, with is being introduced with C++11.

It takes as input a string value and returns as output the integer version of it.
https://www.freecodecamp.org/news/string-to-int-in-c-how-to-convert-a-string-to-an-integer-example/

*/

#include <iostream>
#include <string>
using namespace std;

int main() {
	// a string variable named str
	string str = "7";
	//print to the console
	cout << "I am a string " << str << endl;

	//convert the string str variable to have an int value
	//place the new value in a new variable that holds int values, named num
	int num = stoi(str);

	//print to the console
	cout << "I am an int " << num << endl;
}