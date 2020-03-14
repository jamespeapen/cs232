/* MEShell.h declares a class for the MEShell environment
 * Authors: James Eapen (jpe4), Valeria Martinez (vam6)
 * Date: 13 March 2020
 */

#ifndef MESHELL_H_
#define MESHELL_H_ 
#include "Path.h"
#include "Prompt.h"
#include "CommandLine.h"
#include <string>
#include <sstream>
#include <iostream>
#include <sys/types.h>
#include <sys/stat.h>
#include <exception>
#include "CustomException.h"
using namespace std;

class MEShell {

	public:
		MEShell();
		void run();
	
	private:
		string line_in;
		Path path = Path();
		Prompt prompt = Prompt();
		vector<string> get_args(vector<string> &vec);
		void get_args(vector<string> &vec, char* argv);
};

#endif /* MESHELL_H_  */
