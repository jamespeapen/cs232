/* MEShell.h declares a class for the MEShell environment
 */

#ifndef MESHELL_H_
#define MESHELL_H_ 
#include "Path.h"
#include "Prompt.h"
#include "CommandLine.h"
#include <string>
#include <sstream>
#include <iostream>
class MEShell {

	public:
		MEShell();
		void run();
	
	private:
		std::string line_in;
		Path path = Path();
		Prompt prompt = Prompt();
};

#endif /* MESHELL_H_  */
