/* MEShell.cpp contains the methods of the MEShell environment
 * Authors: James Eapen (jpe4), Valeria Martinez (vam6)
 * Date: 2020 March 12
 */

#include "MEShell.h"

/* Constructor for MEShell
 */
MEShell::MEShell() {
		
}

/* driver for running the shell
 */
void MEShell::run() {

	while (true) {
		prompt.get_path();
		cout << prompt.get_prompt(); 
		CommandLine cmd = CommandLine(cin); 

		if (cmd.getCommand() == "exit") {
			cout << "exiting";
			break;
		}
		else if (cmd.getCommand() == "pwd") {
			cout << "pwd: ";
		}

		else if (cmd.getCommand() == "cd") {
			const char* path;	
			path = cmd.getArg(1).c_str();
			cout << path << endl;
			chdir(path);
		}
	}
}
			
