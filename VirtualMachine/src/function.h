#ifndef FUNCTION_H_
#define FUNCTION_H_
#include "executable.h"

typedef enum
{
	NATIVE_FUNCTION, USER_DEFINED_FUNCTION
} FunctionKind;

typedef struct
{
	Executable* executable;
	int index;
} UserDefinedFunction;

typedef struct
{
	int arg_count;
} NativeFunction;

typedef struct
{
	char* name;
	FunctionKind kind;
	union
	{
		NativeFunction native_f;
		UserDefinedFunction udf;
	} u;
} Function;

typedef struct
{
	Function* caller;
	int caller_address;
	int base;
} CallInfo;

#endif /* FUNCTION_H_ */
