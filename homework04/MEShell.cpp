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

		cout << prompt.get(); 
		CommandLine cmd = CommandLine(cin); 
		cout << "entered" << endl;
		if (cmd.getCommand() == "exit") {
			cout << "exiting";
			break;
		}
		else if (cmd.getCommand() == "pwd") {
			cout << "pwd: ";
			cout << prompt.get_path() << endl;
		}
	}
}
			
