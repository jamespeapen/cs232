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
    	getline(in, myCommandLine);
    	istringstream iss  (myCommandLine);

    	string aTempString;

	//check if command has ampersand
	
	for (string s; iss >> s;) {
		commandLineWords.push_back(s);
		my_argc += 1;
	}

	while(iss >> aTempString){
	        if (strcmp(aTempString.c_str(), "&") == 0) { 
			//if commmand has an ampersand, return 
			ampersand = true;
		}
		else {
			commandLineWords.push_back(aTempString);
		}
	}

	my_argv = new char* [commandLineWords.size()];

	for (int i = 0; i < commandLineWords.size(); i++) {
		my_argv[i] = new char[commandLineWords[i].size() + 1];
		strcpy(my_argv[i], commandLineWords[i].c_str());
	}
}


