
#include <stdio.h>

#include <debug.h>

#include <value/inc.h>

#include "../evaluate.h"

#include "struct.h"
#include "evaluate.h"

int literal_expression_evaluate(
	struct expression* super,
	struct scope* scope,
	struct value** out_value)
{
	int error = 0;
/*	struct value* left = NULL;*/
/*	struct value* right = NULL;*/
	struct literal_expression* const this = (typeof(this)) super;
	ENTER;
	
	*out_value = vinc(this->value);
	
	EXIT;
	return error;
}

