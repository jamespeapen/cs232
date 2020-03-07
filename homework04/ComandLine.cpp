/*

   CommandLine.cpp

   author: Valeria Martinez (@vam6)
   partner: James Eapen (@jpe4)
   class: CS232, Spring 2020
   date: 03/07/2020

 */


#include "CommandLine.h"

CommandLine::CommandLine(istream& in){

    ampersand = false;
    cout << "Waiting for CLI input" << endl;
    getline(in, myCommandLine);
    cout << "Your input was" << myCommandLine << endl;




}





