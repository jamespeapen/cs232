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
#include <sstream>
#include <vector>
#include <istream>
using namespace std;

class CommandLine {
public:
	CommandLine(istream& in);
	char* getCommand() const { return argv[0]; }
	int getArgCount() const { return argc; }
	char** getArgVector() const { return argv; }
	char* getArgVector(int i) const { return argv[i]; }
	bool noAmpersand() const { return !ampersand; }

private:
	string myCommandLine;
	int argc = 0;
	char** argv;
	bool ampersand;
};

#endif /* COMMANDLINE_H_ */