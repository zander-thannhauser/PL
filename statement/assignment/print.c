
#include <stdio.h>

#include <debug.h>

#include <expression/print.h>

#include "struct.h"
#include "print.h"

void assignment_statement_print(
	struct statement* super)
{
	struct assignment_statement* const this = (typeof(this)) super;
	ENTER;
	
	printf("%s <- ", this->name);
	
	expression_print(this->expression);
	
	printf(";");
	
	EXIT;
}

