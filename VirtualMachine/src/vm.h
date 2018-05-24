#ifndef VM_H_
#define VM_H_
#include "types.h"
#include "structs.h"
#include "executable.h"
#include "function.h"

typedef struct
{
	Stack stack;
	Heap heap;
	int pc;
	Function* function;
	int function_count;
	Executable* executable;
} VirtualMachine;

int vm_execute(VirtualMachine* vm);
#endif /* VM_H_ */
