// Lab01.cpp : Defines the entry point for the console application.
//

#include "pch.h"

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::ifstream;
using std::fstream;
using std::cout;
using std::endl;
using std::cin;
using std::cerr;

int main()
{
	//---------------------JUST SOME VARIABLES TO STORE RELEVANT INFO----------------------------------------------------------------------------------------

	string theFileName = "NotaValidFileName$$$%%%_###"; //default filename for the while-loop to have true false conditions
	ifstream theFile(theFileName);
	double a;											//for later use when we only want to read out double values from our file
	double b;
	double c;
	double firstNum;
	double firstNum2;
	double lastNum;
	double lastNum2;
	int count = -1;				//keeps a count of the amount of doubles the prgram comes across in a given file

	//----------------------BEGIN TESTING IF THE FILE IS OPENABLE---------------------------------------------------------------------------------------------
	
	do {																										//Chose a do-while loop so that we could define a reason within the loop to exit the loop instead of making another true false variable to exit the loop
		cout << "Please enter the name of your file you wish to open:\nDON'T FORGET THE .<EXTENSION>" << endl;
		cin >> theFileName;
		theFile.open(theFileName);

		if (theFileName.compare("EXIT%") == 0) {									//comparing two strings, if the user enters the EXIT% command then the .compare comes back true or 0
			cout << "USER EXIT" << endl; exit(0);								//then we exit the whole progeram as per the users request
		}

		if (theFile.is_open() == true) {											//If the file is open, or if the file exists and can be found then we do not change the filename back to its standard thus allowing our while loop to exit.
			//cout << "TEST OPEN SUCCESS" << endl;									//Noting happens in here because we can exit our while loop using this user given filename, as it exists
		}
		else {
			cout << "Could not open the file" << theFileName << "Did you for get the .<EXTENSION>" << endl;		//The file could not be found, or it does not exist given that path
			theFile.close();
			theFileName = "NotaValidFileName$$$%%%_###";														//We reset the filename to is default value so that we may stay in our while loop
			continue;
		}
	} while (theFileName.compare("NotaValidFileName$$$%%%_###") == 0);				//While loop condition only changes when a valid filename that can be opened is given

	//-----------------BEGIN READING OF FILE--------------------------------------------------------------------------------------------------------------
	int tf = 1;
	while (!(theFile.eof())) {		//Will keep running until it hits the end of the file
		if (theFile >> a) {
			if (tf % 2 == 0) {
				b = a;				//stored the double it finds when we find a double and it is one of our double we found on an odd find. i.e store the 1st 3rd 5th 7th... doubles found
				tf--;
			}
			else {
				c = a;				//stored the double it finds when we find a double and it is one of our double we found on an even find. i.e store the 2nd 4th 6th... doubles found
				tf++;
			}
			count++;
			if (count == 0) {
				firstNum = a;
			}
			if (count == 1) {
				firstNum2 = a;
			}
		}
		else{
			theFile.clear();			//Telling the program that for anything that isnot a double including spaces and tabs etc.. to ignore that and clear it from memory as if it never existed
			theFile.ignore();
		}
	}
	lastNum = a;						//The last thing stored in 'a', since everything else is ignored and cleared should be the last double it encountered.
	theFile.close();
	theFile.clear();
	count++;
	if (count % 2 == 0) {			//logic that take the even or odd double at the end of what it found and compares the count an whether or not it is even or odd. 
		lastNum2 = c;				//if the count is even we know to take our odd double becasue that was our previous double found to the end
	}
	else {
		lastNum2 = b;				//if the count is odd we know to take our even double because that was our previuos to the last double found.
	}

	//-------------------BEGIN PRINT OUT FROM THE READING----------------------------------------------------------------------------------------------------

	cout << "\n\n\tHere is what I got from that File:\n<<<---------------------------------------------------------->>>" << endl;
	cout << "The First Double I read was: " << firstNum << endl << endl;		//This is just a print out for the user of what the program found to be the count of doubles, and the first and last double in the file.
	cout << "The Second Double I read was: " << firstNum2 << endl << endl;
	cout << "The Last Double I read was: " << lastNum << endl << endl;
	cout << "The Second-To-Last Double I read was: " << lastNum2 << endl << endl;
	cout << "In All I read this many doubles: " << count << endl;
	cout << "<<<---------------------------------------------------------->>>\n\n";
	return 0;
}