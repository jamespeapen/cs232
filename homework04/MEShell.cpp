/* MEShell.cpp contains the methods of the MEShell environment
 * Authors: James Eapen (jpe4), Valeria Martinez (vam6)
 * Date: 2020 March 12
 */

#include "MEShell.h"
#include "sys/wait.h"
/* Constructor for MEShell
 */
MEShell::MEShell()
{
}

/* driver for running the shell
 */
void MEShell::run() {
	cout << "a" << endl;
	while (true)
	{
		prompt.get_path();
		cout << prompt.get_prompt();
		CommandLine cmd = CommandLine(cin);
		//char *command = cmd.getCommand();
		//cout << command_str;

		//if (command_str == "exit")
		if (strcmp(cmd.getCommand(), "exit") == 0) 
		{
			break;
		}

		//else if (command_str == "pwd")
		else if (strcmp(cmd.getCommand(), "pwd") == 0) 
		{
			cout << prompt.get_path() << endl;
		}

		else if (strcmp(cmd.getCommand(), "cd") == 0)
		{
			try
			{
				string dirname(cmd.getArg(1));
				if (cmd.IsPathExist(cmd.getArg(1)))
				{
					const char *cd_path;
					cd_path = cmd.getArg(1);
					chdir(cd_path);
				}
				else
				{
					throw CustomException("cd: ", dirname);
				}
			}
			catch (CustomException &e)
			{
				cout << "The directory does not exist" << endl;
			}
		}

		else
		{
			char* program = cmd.getCommand();

			if (program && !program[0]) {
				continue;
			}
			int command_found = path.find(program);
			if (command_found == -1)
			{
				cout << program << ": command not found" << endl;
			}

			else
			{
				string program_path = path.get_directory(command_found) + "/" + program;

				pid_t c_pid = fork();
				int status;

				char **args = cmd.getArgVector();
				args[cmd.getArgCount()] = NULL;
				if (c_pid == 0)
				{
					execve(program_path.c_str(), args, NULL);

					exit(0);
				}

				else if (c_pid > 0)
				{
					if (cmd.noAmpersand()) {
						c_pid = waitpid(c_pid, &status, WUNTRACED | WCONTINUED);
					}

				}
			}
		}
		cout << cmd.getCommand();
//		cmd.~CommandLine(); 
	}
}
