#include <stdio.h>
#include <stdlib.h>
#include "byte_code.h"
#include "structs.h"
void test_converter()
{
	byte bytes[] = { 135, 214, 18, 0, 0, 0, 0, 0 };
	printf("bytes to long: %d", bytes_to_long(bytes, 0));
}
int main(int argc, char** argv)
{
	byte* byte_code;
	int length;
	if (read_byte_code_file("/home/jasonhe/Documents/MyCode/Python/vm/test.txt",
			&byte_code, &length))
	{
		show_byte_code(byte_code, length);
	}
	else
	{
		printf("unable to open file.");
	}
	test_converter();
	return EXIT_SUCCESS;
}
