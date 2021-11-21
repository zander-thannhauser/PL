
#include <stdlib.h>

#include <debug.h>

#include "struct.h"
#include "free.h"

void free_value(struct value* this)
{
	ENTER;
	
	if (this)
	{
		dpv(this->refcount);
	}
	
	if (this && !--this->refcount)
	{
		mpz_clear(this->value);
		
		free(this);
	}
	
	EXIT;
}

