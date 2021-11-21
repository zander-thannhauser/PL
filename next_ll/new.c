
#include <debug.h>

#include <memory/smalloc.h>

#include "struct.h"
#include "new.h"

int new_next_ll(
	struct next_ll** new)
{
	int error = 0;
	struct next_ll* this;
	ENTER;
	
	error = smalloc((void**) &this, sizeof(*this));
	
	if (!error)
	{
		this->n = 0;
		
		this->head = NULL;
		this->tail = NULL;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

