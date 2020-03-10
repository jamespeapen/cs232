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
		std::string get() const;

	private:
		std::string prompt;

};

#endif /* PROMPT_H_ */
