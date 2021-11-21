
#include <debug.h>

#include <value/free.h>

#include <scope/lookup.h>

#include "../evaluate.h"

#include "struct.h"
#include "evaluate.h"

int variable_expression_evaluate(
	struct expression* super,
	struct scope* scope,
	struct value** out_value)
{
	int error = 0;
	struct variable_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = scope_lookup(scope, this->name, out_value);
	
	EXIT;
	return error;
}





















