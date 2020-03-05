/* Path.cpp defines the functions for the MEShell path class to represent the directories in which it searches for executable programs
 * James Eapen (jpe4)
 * Date: 2020 March 9
 */

#include "Path.h"
#include <string>
#include <cstdlib>
#include <iostream>
#include <vector>
using std::cout;

/* Constructor
 */
Path::Path() {
	std::string path = std::getenv("PATH");
}


/* return the index of the directory containing the program
 */ 
int Path::find(const std::string& program) {
	return -1;
}

/* return the name of the directory whose index is i
 */

std::string Path::get_directory(int i) const{
	//TODO getDirectory
}
 
