
#include <debug.h>

#include <expression/free.h>

#include <value/free.h>

#include "../free.h"

#include "struct.h"
#include "free.h"

void free_loopdo_statement(
	struct statement* super)
{
	struct loopdo_statement* const this = (typeof(this)) super;
	ENTER;
	
	free_expression(this->conditional);
	
	mpz_clear(this->loop_counter);
	
	free_statement(this->body);
	free_statement(this->next);
	
	EXIT;
}

