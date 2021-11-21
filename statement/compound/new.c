
#if 0
#include <debug.h>

#include <statement_ll/free.h>

#include "../new.h"

#include "struct.h"
#include "new.h"

int new_compound_statement(
	struct statement** new,
	struct statement_ll* substatements)
{
	int error = 0;
	ENTER;
	
	TODO;
	#if 0
	struct compound_statement* this;
	
	error = new_statement(
		(struct statement**) &this,
		sk_compound,
		sizeof(*this));
	
	if (!error)
	{
		this->substatements = substatements, substatements = NULL;
		
		*new = (struct statement*) this, this = NULL;
	}
	
	free_statement_ll(substatements);
	#endif
	
	EXIT;
	return error;
}
#endif
