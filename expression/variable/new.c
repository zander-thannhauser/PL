
#include <debug.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_variable_expression(
	struct expression** new,
	char* name)
{
	int error = 0;
	struct variable_expression* this;
	ENTER;
	
	error = new_expression(
		(struct expression**) &this,
		ek_variable,
		&variable_expression_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->name = name;
		
		*new = (struct expression*) this, this = NULL;
	}
	
	EXIT;
	return error;
}

