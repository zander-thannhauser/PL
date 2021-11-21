
#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "evaluate.h"

int expression_evaluate(
	struct expression* this,
	struct scope* scope,
	struct value** out_value)
{
	int error = 0;
	ENTER;
	
	dpv(this);
	dpv(this->kind);
	dpv(this->inheritance);
	dpv(this->inheritance->evaluate);
	
	assert(this->inheritance->evaluate);
	
	error = (this->inheritance->evaluate)(this, scope, out_value);
	
	EXIT;
	return error;
}

