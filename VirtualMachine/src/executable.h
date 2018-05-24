#ifndef EXECUTABLE_H_
#define EXECUTABLE_H_
#include "structs.h"
typedef struct ExecutableEntry_tag ExecutableEntry;

typedef struct
{
	int constant_pool_count;
	ConstantPool* constant_pool;
	CodeBlock code_block;
} Executable;

struct ExecutableEntry_tag
{
	Executable* executable;
	int* function_table;
	struct ExecutableEntry_tag* next;
};

int make_exe(Executable* exe, byte* byte_code, int start, int code_size);
#endif /* EXECUTABLE_H_ */
