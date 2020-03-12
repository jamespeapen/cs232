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
		cin >> line_in;
		if (line_in == "exit") {
			break;
		}
		else if (line_in == "pwd") {
			cout << "pwd: ";
			cout << prompt.get_path() << endl;
		}
		
		else {
			istringstream iss2 (line_in);
			CommandLine cmd = CommandLine(iss2);
		}
	}
}
			
