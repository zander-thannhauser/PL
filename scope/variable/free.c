
#include <stdlib.h>

#include <debug.h>

#include <value/free.h>

#include "struct.h"
#include "free.h"

void free_variable(struct variable* this)
{
	ENTER;
	
	if (this)
	{
		dpvs(this->name);
		free(this->name);
		
		free_value(this->value);
		
		free(this);
	}
	
	EXIT;
}

