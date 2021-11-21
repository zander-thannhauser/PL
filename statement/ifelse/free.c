
#include <debug.h>

#include <expression/free.h>

#include <value/free.h>

#include "../free.h"

#include "struct.h"
#include "free.h"

void free_ifelse_statement(
	struct statement* super)
{
	struct ifelse_statement* const this = (typeof(this)) super;
	ENTER;
	
	free_expression(this->conditional);
	
	free_statement(this->true_case);
	free_statement(this->false_case);
	
	free_value(this->loop_counter);
	
	EXIT;
}

