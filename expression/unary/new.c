
#include <debug.h>

#include "../new.h"
#include "../free.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_unary_expression(
	struct expression** new,
	enum unary_expression_kind kind,
	struct expression* inner)
{
	int error = 0;
	struct unary_expression* this;
	ENTER;
	
	error = new_expression(
		(struct expression**) &this,
		ek_unary,
		&unary_expression_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->kind = kind;
		this->inner = inner, inner = NULL;
		
		*new = (struct expression*) this, this = NULL;
	}
	
	free_expression(inner);
	
	EXIT;
	return error;
}

