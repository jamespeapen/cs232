# Homework 3: Mystery binary file

James Eapen (jpe4),
Valeria Martinez (vam6)

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
3. `-n`: sets a port number  
4. mystery sends output to the specified port
5. `file`: Executable and Linkable Format file (ELF) 64-bit executable, LSB executable, dynamically linked, for GNU/Linux 2.6.32
6. mystery is dynamically linked which means that it needs external components to run. These were found with ldd
6. `readelf`:  
	 - Class: ELF-64
	 - version: 1
	 - Type: Executable
	 - OS: UNIX-System V
	 - entry point address: 0x400b80
	 - header size: 64bytes 
7. `ldd`: mystery depends on linux-vsdo.so.1 and libc.so.6 to run
7. mystery shows error messages if an unavailable socket is assigned to its output.
## Citations  

 - https://unix.stackexchange.com/questions/42696/mystery-of-binary-files
 - https://linux-audit.com/elf-binaries-on-linux-understanding-and-analysis/
 - elftoc from ELFkickers: https://github.com/BR903/ELFkickers
