
#include <debug.h>

#include <expression/free.h>
#include <statement/free.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_goto_statement(
	struct goto_statement** new,
	unsigned line,
	struct statement* gotome)
{
	int error = 0;
	ENTER;
	
	struct goto_statement* this;
	
	error = new_statement(
		(struct statement**) &this,
		sk_goto,
		&goto_statement_inheritance,
		line,
		sizeof(*this));
	
	if (!error)
	{
		this->gotome = gotome;
		
		*new = this;
	}
	
	EXIT;
	return error;
}


















