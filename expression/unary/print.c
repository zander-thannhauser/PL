
#include <stdio.h>

#include <debug.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

static const char* const operators[number_of_unary_operators] = {
	[uek_logical_not] = "!",
};

void unary_expression_print(
	struct expression* super)
{
	struct unary_expression* const this = (typeof(this)) super;
	ENTER;
	
	const char* operator = operators[this->kind];
	
	assert(operator);
	
	printf("%s", operator);
	
	expression_print(this->inner);
	
	EXIT;
}










