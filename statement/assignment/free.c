
#include <stdlib.h>

#include <debug.h>

#include <expression/free.h>

#include "../free.h"

#include "struct.h"
#include "free.h"

void free_assignment_statement(struct statement* super)
{
	struct assignment_statement* const this = (typeof(this)) super;
	ENTER;
	
	free(this->name);
	
	free_expression(this->expression);
	
	free_statement(this->next);
	
	EXIT;
}

