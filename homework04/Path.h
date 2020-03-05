/* Path.h declares a path class for MEShell to represent the directories in which it searches for executable programs
 * James Eapen (jpe4)
 * Date: 2020 March 9
 */

#ifndef PATH_H_
#define PATH_H_
#include <string>

class Path {
	public:
		Path();
		int find(const std::string& program);
		std::string get_directory(int i) const;

	private:
		std::string path;
		std::vector<char*> path_directories;
};

#endif /* PATH_H_ */
