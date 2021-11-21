
#include <debug.h>

#include <memory/smalloc.h>

#include "struct.h"
#include "new.h"

int new_expression(
	struct expression** new,
	enum expression_kind kind,
	struct expression_inheritance* inheritance,
	size_t alloc_size)
{
	int error = 0;
	struct expression* this;
	ENTER;
	
	error = smalloc((void**) &this, alloc_size);
	
	if (!error)
	{
		this->kind = kind;
		this->inheritance = inheritance;
		
		*new = this, this = NULL;
	}
	
	EXIT;
	return error;
}

