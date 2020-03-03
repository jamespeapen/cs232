/* Path.cpp defines the functions for the MEShell path class to represent the directories in which it searches for executable programs
 * James Eapen (jpe4)
 * Date: 2020 March 9
 */

#include "Path.h"
#include <string>
#include <cstdlib>

/* Constructor
 */
Path::Path() {

}

/* return the index of the directory containing the program
 */ 
int Path::find(const std::string& program) {
	return -1;
}

/* return the name of the directory whose index is i
 */

std::string Path::getDirectory(int i) const{
	return "string";
}
 
