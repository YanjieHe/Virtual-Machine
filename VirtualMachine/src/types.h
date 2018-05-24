#ifndef TYPES_H_
#define TYPES_H_

#include <inttypes.h>
#include <stdbool.h>
typedef struct Object_tag Object;

typedef enum
{
	STRING_TYPE
} ObjectType;

struct Object_tag
{
	ObjectType type;
	bool marked;
	struct Object_tag* prev;
	struct Object_tag* next;
};

typedef union
{
	int32_t int_v;
	double double_v;
	Object* object;
} Value;

#endif /* TYPES_H_ */
