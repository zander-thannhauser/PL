
#include <debug.h>

#include <memory/smalloc.h>

#include "struct.h"
#include "new.h"

int new_statement(
	struct statement** new,
	enum statement_kind kind,
	struct statement_inheritance* inheritance,
	unsigned line,
	size_t alloc_size)
{
	int error = 0;
	struct statement* this;
	ENTER;
	
	error = smalloc((void**) &this, alloc_size);
	
	if (!error)
	{
		this->refcount = 1;
		
		this->kind = kind;
		this->inheritance = inheritance;
		this->line = line;
		
		*new = this;
	}
	
	EXIT;
	return error;
}

