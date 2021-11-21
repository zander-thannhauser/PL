
#include <stdio.h>

#include <debug.h>

#include <expression/print.h>

#include "struct.h"
#include "print.h"

void goto_statement_print(
	struct statement* super)
{
/*	int error = 0;*/
	struct goto_statement const* this = (typeof(this)) super;
	ENTER;
	
	if (this->gotome)
		printf("GOTO LINE %u;", this->gotome->line);
	else
		printf("HALT");
	
	EXIT;
}






















