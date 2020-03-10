/* Driver for the MEShell
 * James Eapen (jpe4)
 * Valeria Martinez (vam6)
 */

#include "MEShell.h"
#include "Path.h"
#include "Prompt.h"
#include <iostream>
#include <string>
using std::cout;
using std::endl;

int main() {
	MEShell shell = MEShell();
	cout << "MEShell" << endl;
	std::string test_input;	
	Path path = Path();
	//cout << path.get_directory(path.find("cp"));
	Prompt prompt = Prompt();
	cout << prompt.get();
}
