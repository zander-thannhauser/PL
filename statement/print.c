
#include <debug.h>

#include "struct.h"
#include "inheritance.h"
#include "print.h"

void statement_print(
	struct statement* this)
{
/*	int error = 0;*/
	ENTER;
	
	dpv(this);
	dpv(this->kind);
	dpv(this->inheritance);
	
	assert(this->inheritance);
	assert(this->inheritance->print);
	
	(this->inheritance->print)(this);
	
	EXIT;
}

