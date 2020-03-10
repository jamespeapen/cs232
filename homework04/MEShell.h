/* MEShell.h declares a class for the MEShell environment
 */

#ifndef MESHELL_H_
#define MESHELL_H_ 
#include "Path.h"
#include "Prompt.h"
#include "CommandLine.h"
#include <string>
class MEShell {

	public:
		MEShell();
		void run();
	
	private:
		std::string line_in;
		std::istringstream iss;
		Path path = Path();
		Prompt prompt = Prompt();
		CommandLine input = CommandLine();

};

#endif /* MESHELL_H_  */
