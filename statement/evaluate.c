
#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "evaluate.h"

int statement_evaluate(
	struct statement* this,
	struct statement** next,
	struct scope* scope)
{
	int error = 0;
	ENTER;
	
	dpv(this);
	dpv(this->kind);
	dpv(this->inheritance);
	
	assert(this->inheritance->evaluate);
	
	error = (this->inheritance->evaluate)(this, next, scope);
	
	EXIT;
	return error;
}

