
#include <stdlib.h>

#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "free.h"

void free_statement(struct statement* this)
{
	ENTER;
	
	if (this && !--this->refcount)
	{
		dpv(this->kind);
		dpv(this->inheritance->free);
		
		assert(this->inheritance->free);
		
		(this->inheritance->free)(this);
		
		free(this);
	}
	
	EXIT;
}

