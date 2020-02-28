# Homework 3: Mystery binary file

James Eapen (jpe4),
Valeria Martinez (vam6)
Date: 2020 Feb 27
## Tools:

1. move mystery out to home dir: this allowed the program to execute since we did not have the permission to execute it while it was still in its original location. 
2. `file`: a program to determine file type. It gives information about the file passed to it and showed that mystery was an ELF 64-bit executable
3. `strings`: this program showed the strings in the binary file that remained strings. The output included printing statements and memory allocation functions. 
4. `objdump`: This program displays information about object files  
5. `stat`: This showed the binary file size
6. `readelf`: This shows information about ELF files
7. `hexdump -C -n 64`: shows the hexdump of the ELF header and the machine type
8. `ldd`: prints shared object dependencies, showing what mystery depends on to run
## Info:

1. `stat`: 14008 bytes  
2. `mystery -h` displays a help message
3. `-s` outputs 100 numbers in ascending order
4. `-p`: sets a port number  
5. mystery sends output to the specified port unordered
6. mystery shows error messages if an unavailable socket is assigned to its output.
7. bug: assigning a string to the port number does not produce an error
8. `-n` sets a number of output lines
9. `-e` sets a seed and outputs numbers without sorting them 
10. `file`: Executable and Linkable Format file (ELF) 64-bit executable, LSB executable, dynamically linked, for GNU/Linux 2.6.32
11. mystery is dynamically linked which means that it needs external components to run. These were found with ldd
12. `readelf`:  
	 - Class: ELF-64
	 - version: 1
	 - Type: Executable program
	 - OS: UNIX-System V
	 - entry point address: 0x400b80 - first instructions of the program are executed here
	 - header size: 64bytes - size of metadata information
13. `ldd`: mystery depends on linux-vsdo.so.1 and libc.so.6 to run
14. mystery shows error messages if an unavailable socket is assigned to its output.
 
## Citations  

 - https://unix.stackexchange.com/questions/42696/mystery-of-binary-files
 - https://linux-audit.com/elf-binaries-on-linux-understanding-and-analysis/
 - elftoc from ELFkickers: https://github.com/BR903/ELFkickers
