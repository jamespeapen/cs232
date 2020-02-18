/**
 * Copy program to copy the contents of one file to another
 * * USAGE: copy source_file destination_file
 * * source file must exist and destination file must not exist
 * @author: James Eapen (jpe4)
 * @data: 2020 Feb 17
 * 
 * * citations:
 *      https://www.tutorialspoint.com/cprogramming/c_strings.html
 *      https://www.tutorialspoint.com/cprogramming/c_command_line_arguments.html
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

/* 
 * * File existence checker
 * @param: *filename - pointer to the filename
 * @returns: 1 if file exists, 0 if it doesn't
 */
const int fileExists(const char *filename)
{
	if (access(filename, F_OK) != -1)	
	{
		return 1;	
	}
	return 0;
}

/*
 * * File type checker
 * @param: *filename - pointer to filename
 * @returns: 0 if file is a directory or symlink
 * @citation: https://stackoverflow.com/questions/4553012/checking-if-a-file-is-a-directory-or-just-a-file
 */
int checkFileType(const char *filename) 
{
	struct stat path_stat;
	stat(filename, &path_stat);
	if (!S_ISREG(path_stat.st_mode))
	{
		return 0;
	}

	return 1;
}

/* 
 * *Input checker - checks for input of source and destination files and checks if the files exist, 
 * @param: argc - arguments passed number to check that arguments are passed
 * @param: *argc[] - pointer to the array containing passed arguments
 * @param: *src - pointer to the 
 */
void inputCheck(int argc, char *argv[])
{
	// *check if parameters were provided
	if (argc < 2)
	{
		perror("missing parameters");
		perror("USAGE: copy source_file destination_file");
		exit(-1);
	}

	// *check if destination file was input
	if (argv[2] == NULL)
	{
		perror("missing destination filename");
		exit(-1);
	}	

	// *check if source file exists
	if (!fileExists(argv[1]))
	{
		perror(argv[1]);
		exit(-1);  
	}
	
	// *check if source file is a regular file
	else if (!checkFileType(argv[1]))
	{
		perror("source file is not a regular file");
		exit(-1);
	}

	// *check if dest file already exists
	if (fileExists(argv[2]))
	{
		fprintf(stderr, "%s", argv[2]);
		fprintf(stderr, "%s\n", ": file already exists");
		exit(-1);
	}
}

/** 
 * Copy function
 * @param param argc the number of arguments
 * @param argvp[] an array with the arguments supplied
 * @citation: https://codeforwin.org/2018/02/c-program-to-copy-file.html
 */
int main(int argc, char *argv[])
{
	// *check for input and file errors
	inputCheck(argc, argv);

	FILE *srcFilePtr;
	FILE *destFilePtr;

	srcFilePtr = fopen(argv[1], "r");
	destFilePtr = fopen(argv[2], "w");
	
	//copying
	char ch;
	ch = fgetc(srcFilePtr);

	while (ch != EOF)
	{
		fputc(ch, destFilePtr);
		ch = fgetc(srcFilePtr);
	}

	fclose(srcFilePtr);
	fclose(destFilePtr);

	return 0;
}

