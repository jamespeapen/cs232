/* Path.cpp defines the functions for the MEShell path class to represent the directories in which it searches for executable programs
 * James Eapen (jpe4)
 * Date: 2020 March 9
 */

#include "Path.h"
#include <string>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <dirent.h>
using std::cout;

/* Constructor
 * Gets the environment path and appends each path directory to a vector 
 */
Path::Path() {
	path = std::getenv("PATH");
	char* path_tokens = std::strtok(path, ":");
	while (path_tokens != NULL) {
		path_directories.push_back(path_tokens);
	}
}

/* return the index of the directory containing the program
 */ 
int Path::find(const std::string& program) {
	DIR *dir;
	struct dirent *entry;
	for (int i = 0; i < path_directories.size(); i++) {

	}
	return -1;
}

/* return the name of the directory whose index is i
 */

std::string Path::get_directory(int i) const{
	//TODO getDirectory
}
 
