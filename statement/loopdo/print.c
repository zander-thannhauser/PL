
#include <stdio.h>

#include <debug.h>

#include <expression/print.h>

#include "struct.h"
#include "print.h"

void loopdo_statement_print(
	struct statement* super)
{
/*	int error = 0;*/
	struct loopdo_statement const* this = (typeof(this)) super;
	ENTER;
	
	printf("LOOP ");
	
	expression_print(this->conditional);
	
	printf(" DO GOTO LINE %u;", this->body->line);
	
	if (this->next)
		printf(" ELSE GOTO LINE %u; END", this->next->line);
	
	EXIT;
}






















