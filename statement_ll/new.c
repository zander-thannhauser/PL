
#if 0
#include <debug.h>

#include <memory/smalloc.h>

#include "struct.h"
#include "new.h"

int new_statement_ll(
	struct statement_ll** new)
{
	int error = 0;
	struct statement_ll* this;
	ENTER;
	
	error = smalloc((void**) &this, sizeof(*this));
	
	if (!error)
	{
		this->head = NULL;
		
		*new = this;
	}
	
	EXIT;
	return error;
}
#endif
