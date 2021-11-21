
#include <stdlib.h>

#include <debug.h>

#include <statement/free.h>

#include "struct.h"
#include "free.h"

void free_label(struct label* this)
{
	if (this)
	{
		free(this->name);
		
		free_statement(this->statement);
		
		free(this);
	}
}

