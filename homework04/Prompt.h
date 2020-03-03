/* Prompt.h declares a prompt class for MEShell to represent the command-line prompt
 */

#ifndef PROMPT_H_
#define PROMPT_H_
#include <string>

class Prompt {
	public:
		Prompt();
		std::string get() const;
};

#endif /* PROMPT_H_ */
