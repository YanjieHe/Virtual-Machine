#ifndef STRUCTS_H_
#define STRUCTS_H_
#include <inttypes.h>
#include "types.h"
typedef unsigned char byte;
typedef struct
{
	int size;
	int pointer;
	Value* values;
} Stack;

typedef struct
{
	int size;
	int threshold;
	Object* head;
} Heap;

typedef enum
{
	CONSTANT_POOL_INT, CONSTANT_POOL_DOUBLE, CONSTANT_POOL_STRING
} ConstantPoolTag;

typedef struct
{
	ConstantPoolTag tag;
	union
	{
		int32_t c_int;
		double c_double;
	} u;
} ConstantPool;

typedef struct
{
	int code_size;
	byte* code;
	int need_stack_size;
} CodeBlock;

int load_constant_pool(ConstantPool** constant_pool, byte* byte_code,
		int* start, int code_size);

int count_constants(byte* byte_code, int start, int code_size);

int load_code_block(CodeBlock** code_block, byte* byte_code, int start,
		int code_size);
int calculate_code_block_stack_size(byte* byte_code, int start, int code_size);

int32_t bytes_to_int(byte* bytes, int start);
int64_t bytes_to_long(byte* bytes, int start);
double bytes_to_double(byte* bytes, int start);
#endif /* STRUCTS_H_ */
