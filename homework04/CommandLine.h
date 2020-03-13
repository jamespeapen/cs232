/*

   Command Line: header file for class
   that reads a command-line

   author: Valeria Martinez (@vam6)
   class: CS232, Spring 2020
   date: 03/07/2020

 */

#ifndef COMMANDLINE_H_
#define COMMANDLINE_H_

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

class CommandLine {
	public:
		CommandLine(istream& in);
    		bool noAmpersand() const { return !ampersand; }

    //CommandLine getters
 		string getCommand() const { return commandLineWords[0]; }
		int getArgCount() const { return commandLineWords.size(); }
		vector<string> getArgVector() const { return commandLineWords; }
		string getArg(int i) const { return commandLineWords[i]; }
	

	private:
		int my_argc = 0;
		char** my_argv;
		bool ampersand;
		vector<string> commandLineWords; 
		string myCommandLine;
};

#endif /* COMMANDLINE_H_ */
