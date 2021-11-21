
#include <gmp.h>

#include <debug.h>

#include <value/struct.h>
#include <value/new.h>
#include <value/inc.h>
#include <value/free.h>

#include <scope/struct.h>

#include "../evaluate.h"

#include "struct.h"
#include "evaluate.h"

int unary_expression_evaluate(
	struct expression* super,
	struct scope* scope,
	struct value** out_value)
{
	int error = 0;
	struct value* inner = NULL;
	struct unary_expression* const this = (typeof(this)) super;
	ENTER;
	
	error =  expression_evaluate(this->inner, scope, &inner);
	
	if (!error)
	{
		switch (this->kind)
		{
			case uek_logical_not:
				*out_value = !mpz_sgn(inner->value)
					? vinc(scope->one)
					: vinc(scope->zero);
				break;
			
			default:
				TODO;
				break;
		}
	}
	
	free_value(inner);
	
	EXIT;
	return error;
}















