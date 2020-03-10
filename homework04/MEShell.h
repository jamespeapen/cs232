/* MEShell.h declares a class for the MEShell environment
 */

#ifndef MESHELL_H_
#define MESHELL_H_ 
#include "Path.h"
#include "Prompt.h"
#include <string>
class MEShell {

	public:
		MEShell();
		void run();
	
	private:
		std::string prompt;
		std::string path;
};

#endif /* MESHELL_H_  */
