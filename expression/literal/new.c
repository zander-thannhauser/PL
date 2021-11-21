
#include <debug.h>

#include <value/inc.h>
#include <value/free.h>

#include "../new.h"

#include "inheritance.h"
#include "struct.h"
#include "new.h"

int new_literal_expression(
	struct expression** new,
	struct value* value)
{
	int error = 0;
	struct literal_expression* this;
	ENTER;
	
	error = new_expression(
		(struct expression**) &this,
		ek_literal,
		&literal_expression_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->value = vinc(value);
		
		*new = (struct expression*) this, this = NULL;
	}
	
	free_value(value);
	
	EXIT;
	return error;
}

