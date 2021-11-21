
#include <debug.h>

#include <expression/evaluate.h>

#include <value/struct.h>
#include <value/free.h>

#include "struct.h"
#include "evaluate.h"

int loopdo_statement_evaluate(
	struct statement* super,
	struct statement** next,
	struct scope* scope)
{
	int error = 0;
	struct loopdo_statement* const this = (typeof(this)) super;
	struct value* conditional = NULL;
	ENTER;
	
	if (this->reset)
	{
		error = expression_evaluate(this->conditional, scope, &conditional);
		
		mpz_set(this->loop_counter, conditional->value);
		
		this->reset = false;
	}
	
	if (!error)
	{
		if (mpz_sgn(this->loop_counter))
		{
			mpz_sub_ui(this->loop_counter, this->loop_counter, 1);
			
			*next = this->body;
		}
		else
		{
			this->reset = true;
			
			*next = this->next;
		}
	}
	
	free_value(conditional);
	
	EXIT;
	return error;
}






























