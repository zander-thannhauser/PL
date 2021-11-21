
#include <stdio.h>

#include <debug.h>

#include <statement/ifelse/struct.h>
#include <statement/ifelse/new.h>
#include <statement/free.h>

#include <next_ll/concat.h>
#include <next_ll/append.h>
#include <next_ll/free.h>

#include "ifelse.h"

int ifelse_callback(
	struct statement** out_start, struct next_ll** out_nexts,
	unsigned line,
	struct expression* conditional,
	struct statement* true_start, struct next_ll* true_nexts,
	struct statement* false_start, struct next_ll* false_nexts)
{
	int error = 0;
	struct ifelse_statement* ifelse = NULL;
	struct next_ll* nexts = NULL;
	ENTER;
	
	error = new_ifelse_statement(&ifelse, line, isk_ifelse, conditional, true_start, false_start);
	
	if (!error)
	{
		if (false_nexts)
		{
			error = next_ll_concat(&nexts, true_nexts, false_nexts);
			true_nexts = false_nexts = NULL;
		}
		else
		{
			error = next_ll_append(true_nexts, &ifelse->false_case);
			
			nexts = true_nexts, true_nexts = NULL;
		}
	}
	
	if (!error)
	{
		*out_start = (struct statement*) ifelse, ifelse = NULL;
		*out_nexts = nexts, nexts = NULL;
	}
	
	free_statement((struct statement*) ifelse);
	
	free_next_ll(true_nexts), free_next_ll(false_nexts);
	free_next_ll(nexts);
	
	EXIT;
	return error;
}












