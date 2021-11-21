
#include <debug.h>

#include <expression/free.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_assignment_statement(
	struct assignment_statement** new,
	unsigned line,
	char* name,
	struct expression* expression)
{
	int error = 0;
	ENTER;
	
	struct assignment_statement* this;
	
	error = new_statement(
		(struct statement**) &this,
		sk_assignment,
		&assignment_statement_inheritance,
		line,
		sizeof(*this));
	
	if (!error)
	{
		this->name = name, name = NULL;
		this->expression = expression, expression = NULL;
		
		this->next = NULL;
		
		*new = this;
	}
	
	free(name);
	free_expression(expression);
	
	EXIT;
	return error;
}











