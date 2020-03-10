/* MEShell.cpp contains the methods of the MEShell environment
 * Authors: James Eapen (jpe4), Valeria Martinez (vam6)
 * Date: 2020 March 12
 */

#include "MEShell.h"
using std::cout;
using std::endl;

MEShell::MEShell() {
		
}

void MEShell::run() {
	while (line_in != "exit") {
		cout << prompt.get(); 
		cin >> line_in;
		if (line_in == "pwd") {
			cout << "pwd: ";
			cout << prompt.get_path() << endl;
		}
	}
}
