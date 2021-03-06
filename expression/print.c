
#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "print.h"

void expression_print(
	struct expression* this)
{
/*	int error = 0;*/
	ENTER;
	
	dpv(this);
	dpv(this->kind);
	
	assert(this->inheritance);
	assert(this->inheritance->print);
	
	(this->inheritance->print)(this);
	
	EXIT;
}

