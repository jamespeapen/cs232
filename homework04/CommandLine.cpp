/*

   CommandLine.cpp

   author: Valeria Martinez (@vam6)
   partner: James Eapen (@jpe4)
   class: CS232, Spring 2020
   date: 03/07/2020

 */


#include "CommandLine.h"
#include <stdio.h>
#include <string.h>
#include <istream>
#include <sstream>


CommandLine::CommandLine(istream& in){
    
    ampersand = false;
    cout << "Waiting for CLI input" << endl;
    getline(in, myCommandLine);
    cout << "Your input was" << myCommandLine << endl;
    istringstream iss  (myCommandLine);
    string aTempString;

//push istringstream converted strings from commandline into the vector
    for (string s; iss >> s; ) {
		tempArgv.push_back(s);
		my_argc += 1;
	}

//check if command has ampersand
    while(iss >> aTempString){
        tempArgv.push_back(aTempString);
        if (strcmp(aTempString.c_str(), "&") != 0) { //if commmand has an ampersand, return true
			ampersand = true;}
    }
   






}





