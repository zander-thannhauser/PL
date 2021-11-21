
#include <stdio.h>

#include <debug.h>

#include <expression/print.h>

#include "struct.h"
#include "print.h"

struct {
	const char* before, *after;
} lookup[number_of_kinds_of_if] = {
	[isk_ifelse] = {"IF", "THEN"},
	[isk_whiledo] = {"WHILE", "DO"},
};

void ifelse_statement_print(
	struct statement* super)
{
/*	int error = 0;*/
	struct ifelse_statement const* this = (typeof(this)) super;
	ENTER;
	
	assert(lookup[this->kind].before);
	assert(lookup[this->kind].after);
	
	printf("%s ", lookup[this->kind].before);
	
	expression_print(this->conditional);
	
	printf(" %s GOTO LINE %u;",
		lookup[this->kind].after,
		this->true_case->line);
	
	if (this->false_case)
		printf(" ELSE GOTO LINE %u; END", this->false_case->line);
	
	EXIT;
}






















