
#include <stdio.h>
/*#include <gmp.h>*/

#include <debug.h>

#include <expression/evaluate.h>

#include <value/free.h>

#include <scope/declare.h>

#include "struct.h"
#include "evaluate.h"

int assignment_statement_evaluate(
	struct statement* super,
	struct statement** next,
	struct scope* scope)
{
	int error = 0;
	struct assignment_statement* const this = (typeof(this)) super;
	struct value* value = NULL;
	ENTER;
	
	error = 0
		?: expression_evaluate(this->expression, scope, &value)
		?: scope_declare(scope, this->name, value);
	
	if (!error)
		*next = this->next;
	
	free_value(value);
	
	EXIT;
	return error;
}

