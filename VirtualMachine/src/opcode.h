#ifndef OPCODE_H
#define OPCODE_H

typedef enum
{
	PUSH_INT,
	PUSH_DOUBLE,
	PUSH_STRING,

	PUSH_STACK_INT,
	PUSH_STACK_DOUBLE,
	PUSH_STACK_STRING,

	POP_STACK_INT,
	POP_STACK_DOUBLE,
	POP_STACK_STRING,

	ADD_INT,
	SUB_INT,
	MUL_INT,
	DIV_INT,
	MOD_INT,
	EQ_INT,
	NE_INT,
	GT_INT,
	GE_INT,
	LT_INT,
	LE_INT,
	LOGICAL_AND,
	LOGICAL_OR,

	ADD_DOUBLE,
	SUB_DOUBLE,
	MUL_DOUBLE,
	DIV_DOUBLE,
	MOD_DOUBLE,
	EQ_DOUBLE,
	NE_DOUBLE,
	GT_DOUBLE,
	GE_DOUBLE,
	LT_DOUBLE,
	LE_DOUBLE,

	MINUS_INT,
	MINUS_DOUBLE,
	LOGICAL_NOT,
	CAST_INT_TO_DOUBLE,
	CAST_DOUBLE_TO_INT,

	JUMP_IF_FALSE,
	JUMP,

	PUSH_FUNCTION,
	INVOKE,

	CONSTANT_INT,
	CONSTANT_DOUBLE,
	CONSTANT_STRING
} Opcode;

typedef struct
{
	char* name;
	char* parameter;
	int stack_increment;
} OpcodeInfo;

//static OpcodeInfo opcode_info[] = { { "push_int", "cp", 2 },
//		{ "push_double", "cp", 2 }, { "push_string", "cp", 2 },
//
//		{ "push_stack_int", "s", 2 }, { "push_stack_double", "s", 2 }, {
//				"push_stack_string", "s", 2 },
//
//		{ "pop_stack_int", "s", 2 }, { "pop_stack_double", "s", 2 }, {
//				"pop_stack_string", "s", 2 },
//
//		{ "add_int", "", 0 }, { "sub_int", "", 0 }, { "mul_int", "", 0 }, {
//				"div_int", "", 0 }, { "mod_int", "", 0 }, { "eq_int", "", 0 }, {
//				"ne_int", "", 0 }, { "gt_int", "", 0 }, { "ge_int", "", 0 }, {
//				"lt_int", "", 0 }, { "le_int", "", 0 },
//
//		{ "logical_and", "", 0 }, { "logical_or", "", 0 },
//
//		{ "add_double", "", 0 }, { "sub_double", "", 0 },
//		{ "mul_double", "", 0 }, { "div_double", "", 0 },
//		{ "mod_double", "", 0 }, { "eq_double", "", 0 }, { "ne_double", "", 0 },
//		{ "gt_double", "", 0 }, { "ge_double", "", 0 }, { "lt_double", "", 0 },
//		{ "le_double", "", 0 },
//
//		{ "minus_int", "", 0 }, { "minus_double", "", 0 }, { "logical_not", "",
//				0 }, { "cast_int_to_double", "", 0 }, { "cast_double_to_int",
//				"", 0 },
//
//		{ "jump_if_false", "s", 2 }, { "jump", "s", 2 }, { "push_function", "s",
//				2 }, { "invoke", "s", 2 } };

#endif /* OPCODE_H */
