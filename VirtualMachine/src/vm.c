#include "vm.h"
#include "opcode.h"

#define GET_2BYTE_INT(p) (((p)[0] << 8) + (p)[1])
#define SET_2BYTE_INT(p, value) \
  (((p)[0] = (value) >> 8), ((p)[1] = value & 0xff))
#define STI_WRITE(vm, sp, value) ((vm)->stack.values[(vm)->stack.pointer + (sp)].int_v = (value))
#define STI(vm, sp) ((vm)->stack.values[(vm)->stack.pointer + (sp)].int_v)
#define STD(vm, sp) ((vm)->stack.values[(vm)->stack.pointer + (sp)].double_v)

int vm_execute(VirtualMachine* vm)
{
	Executable* exe = vm->executable;
	byte* code = exe->code_block.code;
	ExecutableEntry* entry = 0;
	int pc = vm->pc;
	int code_size = exe->code_block.code_size;
	while (pc < code_size)
	{
		switch (code[pc])
		{
			case PUSH_INT:
				STI_WRITE(vm, 0,
						exe->constant_pool[GET_2BYTE_INT(&code[pc + 1])].u.c_int);
				vm->stack.pointer++;
				pc += 3;
				break;
			case ADD_INT:
				STI(vm, -2) = STI(vm, -2) + STI(vm, -1);
				vm->stack.pointer--;
				pc++;
				break;
			case SUB_INT:
				STI(vm, -2) = STI(vm, -2) - STI(vm, -1);
				vm->stack.pointer--;
				pc++;
				break;
			case MUL_INT:
				STI(vm, -2) = STI(vm, -2) * STI(vm, -1);
				vm->stack.pointer--;
				pc++;
				break;
			case DIV_INT:
				STI(vm, -2) = STI(vm, -2) / STI(vm, -1);
				vm->stack.pointer--;
				pc++;
				break;
			case MOD_INT:
				STI(vm, -2) = STI(vm, -2) % STI(vm, -1);
				vm->stack.pointer--;
				pc++;
				break;
			case EQ_INT:
				STI(vm, -2) = STI(vm, -2) == STI(vm, -1);
				vm->stack.pointer--;
				pc++;
				break;
			case NE_INT:
				STI(vm, -2) = STI(vm, -2) != STI(vm, -1);
				vm->stack.pointer--;
				pc++;
				break;
			case GT_INT:
				STI(vm, -2) = STI(vm, -2) > STI(vm, -1);
				vm->stack.pointer--;
				pc++;
				break;
			case GE_INT:
				STI(vm, -2) = STI(vm, -2) >= STI(vm, -1);
				vm->stack.pointer--;
				pc++;
				break;
			case LT_INT:
				STI(vm, -2) = STI(vm, -2) < STI(vm, -1);
				vm->stack.pointer--;
				pc++;
				break;
			case LE_INT:
				STI(vm, -2) = STI(vm, -2) <= STI(vm, -1);
				vm->stack.pointer--;
				pc++;
				break;
			case PUSH_FUNCTION:
			{
				int index_in_exe = GET_2BYTE_INT(&code[pc + 1]);
				STI_WRITE(vm, 0, entry->function_table[index_in_exe]);
				vm->stack.pointer++;
				pc += 3;
				break;
			}
		}
	}
	return 0;
}
