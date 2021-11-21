
#include <debug.h>

#include <expression/evaluate.h>

#include <value/struct.h>
#include <value/free.h>

#include "struct.h"
#include "evaluate.h"

int ifelse_statement_evaluate(
	struct statement* super,
	struct statement** next,
	struct scope* scope)
{
	int error = 0;
	struct ifelse_statement* const this = (typeof(this)) super;
	struct value* conditional = NULL;
	ENTER;
	
	error = expression_evaluate(this->conditional, scope, &conditional);
	
	if (!error)
		*next = mpz_sgn(conditional->value)
			? this->true_case
			: this->false_case;
	
	free_value(conditional);
	
	EXIT;
	return error;
}






















