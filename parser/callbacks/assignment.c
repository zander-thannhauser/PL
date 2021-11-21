
#include <stdio.h>

#include <debug.h>

#include <statement/assignment/struct.h>
#include <statement/assignment/new.h>
#include <statement/free.h>

#include <next_ll/new.h>
#include <next_ll/append.h>
#include <next_ll/free.h>

#include "assignment.h"

int assignment_callback(
	struct statement** out_start,
	struct next_ll** out_nexts,
	unsigned line,
	char* name,
	struct expression* expression)
{
	int error = 0;
	ENTER;
	
	struct assignment_statement* assignment = NULL;
	struct next_ll* nexts = NULL;
	
	error = 0
		?: new_assignment_statement(&assignment, line, name, expression)
		?: new_next_ll(&nexts)
		?: next_ll_append(nexts, &assignment->next);
	
	if (!error)
	{
		dpv(assignment->super.refcount);
		
		*out_start = (struct statement*) assignment, assignment = NULL;
		*out_nexts = nexts, nexts = NULL;
	}
	
	free_statement((struct statement*) assignment);
	free_next_ll(nexts);
	
	EXIT;
	return error;
}












