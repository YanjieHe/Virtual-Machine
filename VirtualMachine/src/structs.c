#include "structs.h"
#include "opcode.h"
#include "malloc.h"
int load_constant_pool(ConstantPool** constant_pool, byte* byte_code,
		int* start, int code_size)
{
	int count = count_constants(byte_code, *start, code_size);
	*constant_pool = malloc(count * sizeof(constant_pool));
	int i = *start;
	int index = 0;
	while (i < code_size)
	{
		switch (byte_code[i])
		{
			case CONSTANT_INT:
			{
				count++;
				int32_t value = bytes_to_int(byte_code, i + 1);
				(*constant_pool)[index].u.c_int = value;
				(*constant_pool)[index].tag = CONSTANT_POOL_INT;
				index++;
				i += 5;
				break;
			}
			case CONSTANT_DOUBLE:
			{
				count++;
				double value = bytes_to_double(byte_code, i + 1);
				(*constant_pool)[index].u.c_double = value;
				(*constant_pool)[index].tag = CONSTANT_POOL_DOUBLE;
				index++;
				i += 9;
				break;
			}
			default:
			{
				*start = i;
				return 0;
			}
		}
	}
	*start = i;
	return 0;
}

int count_constants(byte* byte_code, int start, int code_size)
{
	int count = 0;
	int i = start;
	while (i < code_size)
	{
		switch (byte_code[i])
		{
			case CONSTANT_INT:
			{
				count++;
				i += 5;
				break;
			}
			case CONSTANT_DOUBLE:
			{
				count++;
				i += 9;
				break;
			}
			default:
			{
				break;
			}
		}
	}
	return count;
}

int load_code_block(CodeBlock** code_block, byte* byte_code, int start,
		int code_size)
{

}

int calculate_code_block_stack_size(byte* byte_code, int start, int code_size)
{
}

int32_t bytes_to_int(byte* bytes, int start)
{
	return ((int32_t) bytes[start + 0]) | ((int32_t) bytes[start + 1]) << 8
			| ((int32_t) bytes[start + 2]) << 16
			| ((int32_t) bytes[start + 3]) << 24;
}
int64_t bytes_to_long(byte* bytes, int start)
{
	return ((int64_t) bytes[start + 0]) | ((int64_t) bytes[start + 1]) << 8
			| ((int64_t) bytes[start + 2]) << 16
			| ((int64_t) bytes[start + 3]) << 24
			| ((int64_t) bytes[start + 4]) << 32
			| ((int64_t) bytes[start + 5]) << 40
			| ((int64_t) bytes[start + 6]) << 48
			| ((int64_t) bytes[start + 7]) << 56;
}

double bytes_to_double(byte* bytes, int start)
{
	union
	{
		long long_value;
		double double_value;
	} u;
	u.long_value = bytes_to_long(bytes, start);
	return u.double_value;
}
