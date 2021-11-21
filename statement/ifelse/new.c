
#include <debug.h>

#include <expression/free.h>
#include <statement/free.h>

#include "../new.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_ifelse_statement(
	struct ifelse_statement** new,
	unsigned line,
	enum ifelse_statement_kind kind,
	struct expression* conditional,
	struct statement* true_case,
	struct statement* false_case)
{
	int error = 0;
	ENTER;
	
	struct ifelse_statement* this;
	
	error = new_statement(
		(struct statement**) &this,
		sk_ifelse,
		&ifelse_statement_inheritance,
		line,
		sizeof(*this));
	
	if (!error)
	{
		this->kind = kind;
		this->conditional = conditional, conditional = NULL;
		this->true_case = true_case, true_case = NULL;
		this->false_case = false_case, false_case = NULL;
		
		this->loop_counter = NULL;
		
		*new = this;
	}
	
	free_expression(conditional);
	free_statement(true_case);
	free_statement(false_case);
	
	EXIT;
	return error;
}


















