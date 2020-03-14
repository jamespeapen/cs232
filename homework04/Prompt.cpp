/* Function definitions for the MEShell command line prompt
 * Authors: James Eapen (jpe4), Valeria Martinez (vam6)
 * Date: 2020 March 9
 */

#include "Prompt.h"
using std::cout;

/*Constructor that builds a prompt as the full path to the working directory
 */
Prompt::Prompt() {
	get_path();
}

/* an accessor that returns the current path for pwd
 */
void Prompt::get_current_dir() {
	prompt = "";
	getcwd(cwd, 255);
	prompt += cwd;
}

/* an accessor that returns the current value of the prompt 
 */
std::string Prompt::get_prompt() const {
	return prompt + "$ ";
}

/* refreshes the current path value and returns to caller
 */
std::string Prompt::get_path() {
	get_current_dir();
	return prompt;
}

