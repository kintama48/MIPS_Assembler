# INTRODUCTION:
● This code is a program that converts MIPS assembly language instructions to
their corresponding binary code. Assembly language is a low-level
programming language that is used to write programs for computers and
other devices. It consists of a set of mnemonic codes that represent machine
instructions, as well as directives and data definitions. Assembly language is
often used to write programs for microprocessors and other devices that have
a simple instruction set, because it is easier to write and read than machine
code, which consists of binary numbers that represent the machine
instructions.

● An assembler is a program that converts assembly language code into
machine code, which can be executed by a computer or other device. An
assembler reads the assembly language code and generates the corresponding
machine code, which is usually stored in a file or written to memory. The
machine code generated by an assembler can be loaded into the memory of a
computer or device and executed by the processor.

● The MIPS (Microprocessor without Interlocked Pipeline Stages) architecture
is a Reduced Instruction Set Computing (RISC) architecture that was
developed by MIPS Technologies, Inc. in the 1980s. MIPS is a popular
choice for teaching computer architecture and programming at the
undergraduate level, as it has a simple and clean instruction set that is easy to
understand and implement. The MIPS instruction set consists of about 200
instructions, which can be grouped into several categories, such as arithmetic,
logical, load/store, branch, and other instructions.

● This program reads instructions from a file called "testFile.txt" and converts
them one by one. The input file should contain a list of MIPS assembly
language instructions, one per line. The program supports the following
instructions: add, and, or, andi, ori, addi, sw, lw, and slt. The program
converts each instruction to its corresponding machine code and stores the
result in a file or writes it to memory.

● In the following section, we will describe the logic of the program in more
detail, including the functions that are used to convert the MIPS instructions
to their binary representation.

# LOGIC:
● The program begins by calling the main function, which is the entry point of the
program. The main function first opens the input file "testFile.txt" using the fopen
function from the stdio.h library. The "r" mode specifies that the file should be
opened in read-only mode.

● Next, the main function checks if the file was successfully opened by checking if the
file pointer returned by fopen is NULL. If the file could not be opened, the program
prints an error message and returns 1 to indicate an error. Otherwise, the program
proceeds to read the instructions from the file.

● The main function reads the instructions from the file one line at a time using the
fgets function from the stdio.h library. fgets reads a line of text from the file and
stores it in the line character array. The sizeof operator is used to determine the size of
the line array, so that fgets knows how many characters to read.

● For each line read from the file, the main function tokenizes the line using the strtok
function from the string.h library. strtok splits a string into tokens based on a specified
delimiter. In this case, the delimiter is a space character, so strtok splits the line into
the instruction and its operands.

● The main function declares several variables: rd, rs, rt, and offset. These variables are
used to store the operands for the MIPS instructions. The meaning of each operand
depends on the instruction. For example, in the add instruction, rd is the destination
register, rs is the first source register, and rt is the second source register.

● After extracting the instruction and operands, the main function checks if the
instruction is one of the load/store instructions (sw or lw). These instructions have a
slightly different syntax than the other instructions, so they require special handling.
If the instruction is a load/store instruction, the main function extracts the register
operands (rt and rs) and the offset value from the line.

● The main function uses the getRegNo function to convert the register names to their
corresponding numbers. getRegNo takes a string containing the register name and
returns a long long representing the register number.

● The main function then checks the instruction and calls the appropriate function to
convert the instruction to its binary representation. The functions add, and, or, andi,
ori, addi, sw, lw, and slt are responsible for converting each of the respective
instructions to their binary representation.

● The add function takes three long long arguments: rs, rt, and rd. These arguments
represent the operands for the add instruction. The function converts these operands
to their binary representation and returns the result.

● The and, or, andi, and ori functions work in a similar way. They take two or three
long long arguments, depending on whether the instruction is a register-register or
immediate instruction. These arguments represent the operands for the instruction.
The function converts these operands to their binary representation and returns the
result.

● The addi function is similar to the add, and, or, andi, and ori functions, but it takes an
immediate value as one of its operands. An immediate value is a constant value that is
encoded in the instruction itself, rather than being stored in a register.

● The sw and lw functions are used to store and load values from memory, respectively.
These functions take three long long arguments: rs, rt, and offset. The rs and rt
arguments represent the registers containing the memory address and the data to bestored/loaded, respectively. The offset argument represents the displacement from the
base address specified by the rs register.
●
The slt function compares the values in two registers and stores the result in a third
register. It takes three long long arguments: rs, rt, and rd. The rs and rt arguments
represent the registers containing the values to be compared, and the rd argument
represents the destination register where the result will be stored.
●
The program also has a helper function called convert, which converts a decimal
number to its binary representation. The function takes an int argument n and returns
a long long representing the binary representation of n. If n is negative, the function
first converts it to its two's complement before returning the binary representation.

● Finally, the main function closes the input file using the fclose function from the
stdio.h library, and returns 0 to indicate success.
