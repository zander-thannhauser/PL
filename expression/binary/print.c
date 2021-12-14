
#include <stdio.h>

#include <debug.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

static const char* const operators[number_of_binary_operators] = {
	[bek_addition] = "+",
	[bek_divide] = "/",
	[bek_equals] = "=",
	[bek_greater_than] = ">",
	[bek_greater_than_equal] = ">=",
	[bek_less_than] = "<",
	[bek_less_than_equal] = "<=",
	[bek_logical_and] = "&&",
	[bek_logical_or] = "||",
	[bek_not_equals] = "!=",
	[bek_subtract] = "-",
	[bek_times] = "*",
};

void binary_expression_print(
	struct expression* super)
{
	struct binary_expression* const this = (typeof(this)) super;
	ENTER;
	
	expression_print(this->left);
	
	dpv(this->kind);
	
	const char* operator = operators[this->kind];
	
	assert(operator);
	
	printf(" %s ", operator);
	
	expression_print(this->right);
	
	EXIT;
}










