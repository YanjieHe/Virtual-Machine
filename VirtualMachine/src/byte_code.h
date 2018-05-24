#ifndef BYTE_CODE_H_
#define BYTE_CODE_H_
#include <stdio.h>
typedef unsigned char byte;
int byte_code_file_length(char* file_name);
int read_byte_code_file(char* file_name, byte** bytes, int* length);
void write_byte_code_to_file(char* file_name, byte* bytes, int length);
void show_byte_code(byte* bytes, int length);
#endif /* BYTE_CODE_H_ */
