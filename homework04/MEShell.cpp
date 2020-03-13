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

	while (true) {
		prompt.get_path();
		cout << prompt.get_prompt(); 
		CommandLine cmd = CommandLine(cin); 

		if (cmd.getCommand() == "exit") {
			cout << "exiting";
			break;
		}
		else if (cmd.getCommand() == "pwd") {
			cout << "pwd: ";
		}

		else if (cmd.getCommand() == "cd") {
			const char* path;	
			path = cmd.getArg(1).c_str();
			chdir(path);
		}

		else {
			string program = cmd.getCommand();
			int command_found = path.find(program); 
			if (command_found == -1 ) {
				cout << program << ": command not found" << endl;
			}
			
			else {
				string program_path = path.get_directory(command_found) + "/" + program; 
				cout << program_path << endl;

				pid_t c_pid = fork();
				char** args = cmd.get_argv();
				if (c_pid == 0) {
					cout << "child proc" << endl;
					execve(program_path.c_str(), args, NULL);
				}

				else if (c_pid > 0) {
					cout << "child finished" << endl;
				}
			}
		}
	}
}
			
