/* Driver for the MEShell
 * James Eapen (jpe4)
 * Valeria Martinez (vam6)
 * Date: 13 March 2020
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
	shell.run();
}
