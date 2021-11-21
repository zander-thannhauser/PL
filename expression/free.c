
#include <stdlib.h>

#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "free.h"

void free_expression(struct expression* this)
{
	ENTER;
	
	if (this)
	{
		dpv(this);
		dpv(this->kind);
		dpv(this->inheritance);
		dpv(this->inheritance->free);
		
		assert(this->inheritance->free);
		
		(this->inheritance->free)(this);
		
		free(this);
	}
	
	EXIT;
}

