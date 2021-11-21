
#include <debug.h>

#include <expression/free.h>
#include <statement/free.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_loopdo_statement(
	struct loopdo_statement** new,
	unsigned line,
	struct expression* conditional,
	struct statement* body)
{
	int error = 0;
	ENTER;
	
	struct loopdo_statement* this;
	
	error = new_statement(
		(struct statement**) &this,
		sk_loopdo,
		&loopdo_statement_inheritance,
		line,
		sizeof(*this));
	
	if (!error)
	{
		this->conditional = conditional, conditional = NULL;
		this->body = body, body = NULL;
		this->next = NULL;
		
		mpz_init(this->loop_counter);
		
		this->reset = true;
		
		*new = this;
	}
	
	free_expression(conditional);
	free_statement(body);
	
	EXIT;
	return error;
}


















