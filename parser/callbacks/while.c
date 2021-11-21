
#include <stdio.h>

#include <debug.h>

#include <defines/argv0.h>

#include <enums/error.h>

#include <statement/ifelse/struct.h>
#include <statement/ifelse/new.h>
#include <statement/inc.h>
#include <statement/free.h>

#include <next_ll/struct.h>
#include <next_ll/new.h>
#include <next_ll/append.h>
#include <next_ll/free.h>

#include "while.h"

int while_callback(
	struct statement** out_start, struct next_ll** out_nexts,
	unsigned line,
	struct expression* conditional,
	struct statement* body_start, struct next_ll* body_nexts)
{
	int error = 0;
	struct next_link* nlink;
	struct next_ll* nexts = NULL;
	struct ifelse_statement* whiledo = NULL;
	ENTER;
	
	error = 0
		?: new_ifelse_statement(&whiledo, line, isk_whiledo, conditional, body_start, NULL)
		?: new_next_ll(&nexts)
		?: next_ll_append(nexts, &whiledo->false_case);
	
	if (!body_nexts->n)
		fprintf(stderr, "%s: unreachable statement!\n", argv0),
		error = e_bad_input_file;
	else for (nlink = body_nexts->head; nlink; nlink = nlink->next)
		*nlink->element = ((struct statement*) whiledo);
	
	if (!error)
	{
		*out_start = (struct statement*) whiledo, whiledo = NULL;
		*out_nexts = nexts, nexts = NULL;
	}
	
	free_statement((struct statement*) whiledo);
	free_next_ll(nexts);
	free_next_ll(body_nexts);
	
	EXIT;
	return error;
}












