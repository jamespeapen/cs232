# Homework 3: Mystery binary file

James Eapen (jpe4),
Valeria Martinez (vam6)

## Tools:

1. move mystery out to home dir: this allowed the program to execute since we did not have the permission to execute it while it was still in its original location. 
2. `file`: a program to determine file type. It gives information about the file passed to it and showed that mystery was an ELF 64-bit executable
3. `strings`: this program showed the strings in the binary file that remained strings. The output included printing statements and memory allocation functions. 
4. `objdump`: This program displays information about object files  
5. `stat`: This showed the binary file size

## Info:

1. `stat`: 14008 bytes  
2. `mystery -h` displays a help message
3. `-n`: sets a port number  
4. it sends output to the specified port
5. `file`: ELF 64-bit executable, LSB executable, dynamically linked, for GNU/Linux 2.6.32
6. `readelf`:  
	 - Class: ELF-64
	 - version: 1
	 - OS: UNIX-System V
	 - entry point address: 0x400b80
	 - header size: 64bytes 
7. mystery shows error messages if an unavailable socket is assigned to its output.
## Citations  

 - https://unix.stackexchange.com/questions/42696/mystery-of-binary-files
 - https://linux-audit.com/elf-binaries-on-linux-understanding-and-analysis/
