
#include <debug.h>

#include <expression/evaluate.h>

#include <value/struct.h>
#include <value/free.h>

#include "struct.h"
#include "evaluate.h"

int goto_statement_evaluate(
	struct statement* super,
	struct statement** next,
	struct scope* scope)
{
	int error = 0;
	struct goto_statement* const this = (typeof(this)) super;
/*	struct value* conditional = NULL;*/
	ENTER;
	
	*next = this->gotome;
	
	EXIT;
	return error;
}






















