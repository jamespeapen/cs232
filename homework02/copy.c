/**
 * Copy program to copy the contents of one file to another
 * * USAGE: copy source_file destination_file
 * * source file must exist and destination file must not exist
 * @author: James Eapen (jpe4)
 * @data: 2020 Feb 11
 * 
 * * citations:
 *      https://codeforwin.org/2018/02/c-program-to-copy-file.html
 *      https://www.tutorialspoint.com/cprogramming/c_strings.html
 *      https://www.tutorialspoint.com/cprogramming/c_command_line_arguments.html
 */

#include <stdio.h>
// TODO: std lib

/** 
 * Copy function
 * @param param argc the number of arguments
 * @param argvp[] an array with the arguments supplied
 */
int main(int argc, char *argv[])
{
	const char *src = NULL;
	const char *dest = NULL;
	
	if (argc < 3)
	{
		printf("%d\n", argc);
		printf("%s\n", "missing parameters");
		printf("%s", "USAGE: copy source_file destination_file");
		return 0;
	}

	src = argv[1];
	dest = argv[2];
	printf("%s\n", src);
	printf("%s\n", dest);

}
