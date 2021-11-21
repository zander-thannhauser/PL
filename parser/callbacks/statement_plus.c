
#include <stdio.h>

#include <debug.h>

#include <defines/argv0.h>

#include <enums/error.h>

/*#include <statement/ifelse/struct.h>*/
/*#include <statement/ifelse/new.h>*/
#include <statement/inc.h>
#include <statement/free.h>

#include <next_ll/struct.h>
#include <next_ll/free.h>

#include "statement_plus.h"

int statement_plus_callback(
	struct statement** out_start, struct next_ll** out_nexts,
	struct statement* head_start, struct next_ll* head_nexts,
	struct statement* tail_start, struct next_ll* tail_nexts)
{
	int error = 0;
	struct next_link* nlink;
	ENTER;
	
	if (!head_nexts->n)
		fprintf(stderr, "%s: unreachable statement!\n", argv0),
		error = e_bad_input_file;
	else for (nlink = head_nexts->head; nlink; nlink = nlink->next)
		*nlink->element = sinc(tail_start);
	
	if (!error)
	{
		*out_start = sinc(head_start);
		*out_nexts = tail_nexts;
	}
	else
	{
		free_next_ll(tail_nexts);
	}
	
	free_statement(head_start);
	free_statement(tail_start);
	free_next_ll(head_nexts);
	
	EXIT;
	return error;
}












