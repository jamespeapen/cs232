/* Function definitions for the MEShell command line prompt
 *  James Eapen (jpe4)
 *  Date: 2020 March 9
 */ 

#include "Prompt.h"
using std::cout;

/*Constructor that builds a prompt as the full path to the working directory
 */
Prompt::Prompt() {
	char cwd[255];	
	getcwd(cwd, 255); 
	prompt += cwd;
}

/* an accessor that returns the current value of the prompt 
 */
std::string Prompt::get() const {
	return prompt + "$ ";
}

/* an accessor that returns the current path for pwd
 */
std::string Prompt::get_path() const {
	return prompt;
}
