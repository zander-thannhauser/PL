
#include <stdlib.h>

#include <debug.h>

#include "struct.h"
#include "free.h"

void free_variable_expression(
	struct expression* super)
{
	struct variable_expression* const this = (typeof(this)) super;
	ENTER;
	
	dpvs(this->name);
	
	free(this->name);
	
	EXIT;
}

