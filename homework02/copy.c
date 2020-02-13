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
#include <unistd.h>
#include <stdlib.h>

/** 
 * Copy function
 * @param param argc the number of arguments
 * @param argvp[] an array with the arguments supplied
 */

//check if file exists
const int fileExists(const char *filename)
{
	if (access(filename, F_OK) != -1)	
	{
		return 1;	
	}
	return 0;
}

void inputCheck(int argc, char *argv[], const char *src, const char *dest)
{

	if (argc < 2)
	{
		perror("missing parameters");
		perror("USAGE: copy source_file destination_file");
		exit(-1);
	}

	//check if destination file was input
	if (argv[2] == NULL)
	{
		perror("missing destination filename");
		exit(-1);
	}	

	src = argv[1];
	dest = argv[2];

	//check if source file exists
	if (!fileExists(src))
	{
		perror(src);
		exit(-1);  
	}

	// check if dest file already exists
	if (fileExists(dest))
	{
		fprintf(stderr, "%s", dest);
		fprintf(stderr, "%s\n", "file already exists");
		exit(-1);
	}
}

int main(int argc, char *argv[])
{
	const char *src = NULL;		//store source filename
	const char *dest = NULL;	//store destination filename
	
	//check for input and file errors
	inputCheck(argc, argv, src, dest);

	printf("copying...");

}

