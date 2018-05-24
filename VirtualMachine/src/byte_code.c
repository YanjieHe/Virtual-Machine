#include "byte_code.h"
#include <malloc.h>
#include <stdio.h>
int byte_code_file_length(char* file_name)
{
	FILE* file = fopen(file_name, "rb");
	if (!file)
	{
		return -1; // unable to open file
	}
	else
	{
		int count = 0;
		while (1)
		{
			byte b;
			fread(&b, sizeof(byte), 1, file);
			if (feof(file))
			{
				break;
			}
			else
			{
				count++;
			}
		}
		fclose(file);
		return count;
	}
}

int read_byte_code_file(char* file_name, byte** bytes, int* length)
{
	int byte_code_length = byte_code_file_length(file_name);
	if (byte_code_length != -1)
	{
		FILE* file = fopen(file_name, "rb");
		if (file)
		{
			*length = byte_code_length;
			*bytes = malloc(byte_code_length * sizeof(byte));
			for (int i = 0; i < byte_code_length; i++)
			{
				byte b;
				fread(&b, sizeof(byte), 1, file);
				(*bytes)[i] = b;
			}
			fclose(file);
			return 1;
		}
		else
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}
}

void write_byte_code_to_file(char* file_name, byte* bytes, int length)
{
	FILE* file = fopen(file_name, "wb");
	if (file)
	{
		for (int i = 0; i < length; i++)
		{
			fwrite(bytes[i], sizeof(byte), 1, file);
		}
		fclose(file);
	}
}

void show_byte_code(byte* bytes, int length)
{
	printf("byte code(%d): \n", length);
	for (int i = 0; i < length; i++)
	{
		printf("%d\n", (int) bytes[i]);
	}
}
