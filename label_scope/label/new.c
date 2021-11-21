
#include <string.h>
#include <stdio.h>

#include <debug.h>

#include <defines/argv0.h>

#include <enums/error.h>

#include <memory/smalloc.h>

#include <statement/inc.h>

#include "struct.h"
#include "new.h"

int new_label(
	struct label** new,
	const char* name,
	struct statement* statement)
{
	int error = 0;
	char* dupname = NULL;
	ENTER;
	
	if (!(dupname = strdup(name)))
		fprintf(stderr, "%s: strdup(): %m\n", argv0),
		error = e_out_of_memory;
	
	struct label* this = NULL;
	if (!error)
		error = smalloc((void**) &this, sizeof(*this));
	
	if (!error)
	{
		this->name = dupname, dupname = NULL;
		this->statement = sinc(statement);
		
		*new = this;
	}
	
	free(dupname);
	
	EXIT;
	return error;
}








