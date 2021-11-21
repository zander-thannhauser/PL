
#include <debug.h>

#include <expression/free.h>

#include <value/free.h>

#include "../free.h"

#include "struct.h"
#include "free.h"

void free_goto_statement(
	struct statement* super)
{
	struct goto_statement* const this = (typeof(this)) super;
	ENTER;
	
	HERE;
	
	EXIT;
}

