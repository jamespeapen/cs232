/* CommandLine.cpp defines the functions for reading, parsing and storing user input on the command line
   author: Valeria Martinez (@vam6), James Eapen(jpe4)
   class: CS232, Spring 2020
   date: 03/07/2020
 */


#include "CommandLine.h"
#include <stdio.h>
#include <string.h>
#include <istream>
#include <sstream>

/* Default constructor for comma
 */
CommandLine::CommandLine() {

}

/* Explicit CommandLine constructor
 * @param: istream in - takes a istream and changes type to string and stores in a vector
 */
CommandLine::CommandLine(istream& in){
	my_argc = 0;
    	ampersand = false;
    	getline(in, myCommandLine);
    	istringstream iss  (myCommandLine);

    	string aTempString;

	while(iss >> aTempString){
	        if (strcmp(aTempString.c_str(), "&") == 0) { 
			//if commmand has an ampersand, return 
			ampersand = true;
		}
		else {
			commandLineWords.push_back(aTempString);
			my_argc++;
		}
	}

	my_argv = new char* [commandLineWords.size()];
	
	// add input tokens to arg vector
	for (int i = 0; i < commandLineWords.size(); i++) {
		my_argv[i] = new char[commandLineWords[i].size() + 1];
		strcpy(my_argv[i], commandLineWords[i].c_str());
	}
}

CommandLine::~CommandLine() {
	for (int i = 0; i < my_argc; i++) {
		delete[] my_argv[i];
	}

	delete[] my_argv;

}
