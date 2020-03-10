/* Driver for the MEShell
 * James Eapen (jpe4)
 * Valeria Martinez (vam6)
 */

#include "MEShell.h"
#include "Path.h"
#include "Prompt.h"
#include "CommandLine.h"
#include <iostream>
#include <string>
#include <istream>
#include <sstream>
using std::cout;
using std::endl;

int main() {
	cout << "MEShell" << endl;
	std::string test_input;	
	Path path = Path();
	Prompt prompt = Prompt();
	cout << prompt.get();
	std::string lineIn;
	istream iss (lineIn);
	CommandLine cmd = CommandLine(iss);
}
