#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Function prototypes
void add(long long rs, long long rt, long long rd);
void and(long long rs, long long rt, long long rd);
void or(long long rs, long long rt, long long rd);
void andi(long long rs, long long rt, long long imm);
void ori(long long rs, long long rt, long long imm);
void addi(long long rs, long long rt, long long imm);
void sw(long long rs, long long rt, long long offset);
void lw(long long rs, long long rt, long long offset);
void slt(long long rs, long long rt, long long rd);
long long convert(int n);
long long getRegNo(char* reg);


int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Error: Invalid number of arguments\n");
        exit(1);
    }

    // Open the input file
    FILE *fp = fopen(argv[1], "r");

    // Check if the file was successfully opened
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    // Read the instructions from the file, one line at a time
    char line[64];
    while (fgets(line, sizeof(line), fp)) {
        // Tokenize the line to extract the instruction and its operands
        char *instruction = strtok(line, " ");
        long long rd, rs, rt, offset;

        if (strcmp(instruction, "sw") == 0 || strcmp(instruction, "lw") == 0) {
            rt = getRegNo(strtok(NULL, ","));
            char * temp = strtok(NULL, ",");


            if (temp[strlen(temp)-1] == '\n') {
                temp[strlen(temp)-1] = '\0';
            }

            if (strchr(temp, '(') != NULL) {
                if (temp[0] == '(') {
                    offset = 0;
                    temp = strtok(temp, "(");
                    temp[strlen(temp)-1] = '\0';
                    rs = getRegNo(temp);
                } else {
                    char *temp2 = temp;
                    offset = atoi(strtok(temp2, "("));
                    temp2 = strtok(NULL, "(");
                    rs = getRegNo(temp2);
                    offset = convert(offset);
                }
            }

        } else {
            rd = getRegNo(strtok(NULL, ","));
            rs = getRegNo(strtok(NULL, ","));
            rt = getRegNo(strtok(NULL, ","));
        }

        // Convert the instruction to binary code
        if (strcmp(instruction, "add") == 0) {
            add(rs, rt, rd);
        } else if (strcmp(instruction, "and") == 0) {
            and(rs, rt, rd);
        } else if (strcmp(instruction, "or") == 0) {
            or(rs, rt, rd);
        } else if (strcmp(instruction, "andi") == 0) {
            andi(rs, rt, rd);
        } else if (strcmp(instruction, "ori") == 0) {
            ori(rs, rt, rd);
        } else if (strcmp(instruction, "addi") == 0) {
            addi(rs, rt, rd);
        } else if (strcmp(instruction, "sw") == 0) {
            sw(rs, rt, offset);
        } else if (strcmp(instruction, "lw") == 0) {
            lw(rs, rt, offset);
        } else if (strcmp(instruction, "slt") == 0) {
            slt(rs, rt, rd);
        }
        printf("\n");
    }

    // Close the file
    fclose(fp);

    return 0;
}


long long convert(int n) {
    // Check if the number is negative
//    n = atoi(n + 1);
    if (n < 0) {
        // Convert the number to its two's complement representation
        n = ~n + 1;
    }

    long long bin = 0;
    int rem, i = 1;

    while (n!=0) {
        rem = n % 2;
        n /= 2;
        bin += rem * i;
        i *= 10;
    }

    return bin;
}

long long getRegNo(char* reg) {
    if (reg[0] == ' '){
        while (reg[0] == ' ') {
            reg++;
        }
    }

    if (reg[strlen(reg)-1] == '\n') {
        reg[strlen(reg)-1] = '\0';
    }

    if (reg[strlen(reg)-1] == ')') {
        reg[strlen(reg)-1] = '\0';
    }

    if (strcmp(reg, "$zero") == 0) {
        return convert(0);
    } else if (strcmp(reg, "$at") == 0) {
        return convert(1);
    } else if (strcmp(reg, "$v0") == 0) {
        return convert(2);
    } else if (strcmp(reg, "$v1") == 0) {
        return convert(3);
    } else if (strcmp(reg, "$a0") == 0) {
        return convert(4);
    } else if (strcmp(reg, "$a1") == 0) {
        return convert(5);
    } else if (strcmp(reg, "$a2") == 0) {
        return convert(6);
    } else if (strcmp(reg, "$a3") == 0) {
        return convert(7);
    } else if (strcmp(reg, "$t0") == 0) {
        return convert(8);
    } else if (strcmp(reg, "$t1") == 0) {
        return convert(9);
    } else if (strcmp(reg, "$t2") == 0) {
        return convert(10);
    } else if (strcmp(reg, "$t3") == 0) {
        return convert(11);
    } else if (strcmp(reg, "$t4") == 0) {
        return convert(12);
    } else if (strcmp(reg, "$t5") == 0) {
        return convert(13);
    } else if (strcmp(reg, "$t6") == 0) {
        return convert(14);
    } else if (strcmp(reg, "$t7") == 0) {
        return convert(15);
    } else if (strcmp(reg, "$s0") == 0) {
        return convert(16);
    } else if (strcmp(reg, "$s1") == 0) {
        return convert(17);
    } else if (strcmp(reg, "$s2") == 0) {
        return convert(18);
    } else if (strcmp(reg, "$s3") == 0) {
        return convert(19);
    } else if (strcmp(reg, "$s4") == 0) {
        return convert(20);
    } else if (strcmp(reg, "$s5") == 0) {
        return convert(21);
    } else if (strcmp(reg, "$s6") == 0) {
        return convert(22);
    } else if (strcmp(reg, "$s7") == 0) {
        return convert(23);
    } else if (strcmp(reg, "$t8") == 0) {
        return convert(24);
    } else if (strcmp(reg, "$t9") == 0) {
        return convert(25);
    } else if (strcmp(reg, "$k0") == 0) {
        return convert(26);
    } else if (strcmp(reg, "$k1") == 0) {
        return convert(27);
    } else if (strcmp(reg, "$gp") == 0) {
        return convert(28);
    } else {
        // Extract the register number from the operand string
//        long long reg_num = atoi(reg + 1);
        if (reg[0] == '$') {
            reg++;
        }

        // Convert the register number to binary
        return convert(atoi(reg));
    }
}


// add instruction: add $rd, $rs, $rt
void add(long long rs, long long rt, long long rd) {

    // Convert the instruction to binary code
    printf("000000%05lld%05lld%05lld00000100000\n", rs, rt, rd);

}

// and instruction: and $rd, $rs, $rt
void and(long long rs, long long rt, long long rd) {
    // Convert the instruction to binary code
    printf("000000%05lld%05lld%05lld00000100100\n", rs, rt, rd);
}

// or instruction: or $rd, $rs, $rt
void or(long long rs, long long rt, long long rd) {

    // Convert the instruction to binary code
    printf("000000%05lld%05lld%05lld0000100101\n", rs, rt, rd);
}

// andi instruction: andi $rt, $rs, imm
void andi(long long rs, long long rt, long long imm) {
    // Convert the instruction to binary code
    printf("001100%05lld%05lld%016lld\n", rs, imm, rt);
}

// ori instruction: ori $rt, $rs, imm
void ori(long long rs, long long rt, long long imm) {
    // Convert the instruction to binary code
    printf("001101%05lld%05lld%016lld\n", rs, imm, rt);
}
// addi instruction: addi $rt, $rs, imm
void addi(long long rs, long long rt, long long imm) {
    // Convert the instruction to binary code
    printf("001000%05lld%05lld%016lld\n", rs, imm, rt);
}

// sw instruction: sw $rt, offset($rs)
void sw(long long rs, long long rt, long long offset) {
    // Convert the instruction to binary code
    printf("101011%05lld%05lld%016lld\n", rs, rt, offset);
}

// lw instruction: lw $rt, offset($rs)
void lw(long long rs, long long rt, long long offset) {
    // Convert the instruction to binary code
    printf("100011%05lld%05lld%016lld\n", rs, rt, offset);
}

// slt instruction: slt $rd, $rs, $rt
void slt(long long rs, long long rt, long long rd) {
    // Convert the instruction to binary code
    printf("000000%05lld%05lld%05lld00000101010\n", rs, rt, rd);
}
