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
	while (line_in != "exit") {
		cout << prompt.get(); 
		cin >> line_in;
		if (line_in == "pwd") {
			cout << "pwd: ";
			cout << prompt.get_path() << endl;
		}

		else {
			string entry_command_path;
			if (path.find(line_in) != -1) {
				entry_command_path = path.get_directory(path.find(line_in));
			}

			else {
				cout << path.get_directory(path.find(line_in)) << endl;
			}
		}
	}
}
			
