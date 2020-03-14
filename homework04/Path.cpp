/* Path.cpp defines the functions for the MEShell path class to represent the directories in which it searches for executable programs
 * James Eapen (jpe4)
 * Date: 2020 March 9
 */

#include "Path.h"
using std::cout;
using std::endl;

/* Constructor
 * Gets the environment path and appends each path directory to a vector 
 */
Path::Path() {
	path = std::getenv("PATH");
	char* path_tokens = std::strtok(path, ":");
	
	while (path_tokens != NULL) {
		path_directories.push_back(path_tokens);
		path_tokens = std::strtok(NULL, ":");
	}
	//for (unsigned i = 0; i < path_directories.size(); i++) {
	//	cout << path_directories[i] << endl;
	//}
}

/* return the index of the directory containing the program
 */ 
int Path::find(const std::string& program) {
	int index = -1;
	DIR *dirptr; 
	struct dirent *direntry;
	for (unsigned i = 0; i < path_directories.size(); i++) {
		//cout << path_directories[i] << endl;
		dirptr = opendir(path_directories[i]);
		if (dirptr != NULL) {
			while(direntry = readdir(dirptr)) {
		//		cout << direntry->d_name << endl;
				if (direntry->d_name == program) {
					index = i;
				}
			}
		}
		closedir(dirptr);
	}
	return index;
}

/* return the name of the directory whose index is i
 */

std::string Path::get_directory(int i) const{
	return path_directories[i];
}
 
