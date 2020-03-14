/* Prompt.h declares a prompt class for MEShell to represent the command-line prompt
 */

#ifndef PROMPT_H_
#define PROMPT_H_
#include <iostream>
#include <string>
#include <unistd.h>

class Prompt {
	public:
		Prompt();
		void get_current_dir();
		std::string get_prompt() const;
		std::string get_path();

	private:
		std::string prompt;
		char cwd[255];

};

#endif /* PROMPT_H_ */
