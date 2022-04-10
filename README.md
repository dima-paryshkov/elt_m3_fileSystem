### File system

In this repo i working with file input and output.

All executable file are located in bin.

#### ls-al.c

This programm output information about files in directory

Compile: 

    make ls-al
    or
    gcc ls-al.c -o bin/ls-al

Launch: 

    bin/ls-al <name of directory>

#### fs10-11.c & fs10-11Out.c

This program works with mapped memory to memory

fs10-11.c write information in binary file and fs10-11Out.c out this info.

Compile: 

    make fs10-11; make fs10-11Out
    or
    gcc fs10-11.c -o bin/fs10-11; gcc fs10-11Out.c -o bin/fs10-11Out

Launch: 

    bin/fs10-11
    and 
    bin/fs10-11Out


#### Standart in, out

Programm open binary file write string, and after that read this string with begin of file. Also we use position read(pread) and write(pwrite).
At the end of the program we cut length of file by length first const string.

Compile: 

    make standartio
    or
    gcc standartio.c -o bin/standartio

Launch: 

    bin/standartio

#### Select

Programm tracks fd standart input with select

Compile: 

    make multiplexio
    or
	gcc multiplexio.c -o bin/multiplexio

Launch: 

    bin/multiplexio

