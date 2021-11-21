
#include <stdio.h>
#include <string.h>

#include <debug.h>

#include <memory/smalloc.h>

#include <enums/error.h>

#include <defines/argv0.h>

#include <value/inc.h>

#include "struct.h"
#include "new.h"

int new_variable(
	struct variable** new,
	const char* name,
	struct value* value)
{
	int error = 0;
	ENTER;
	
	char* dupname = NULL;
	struct variable* this = NULL;
	
	if (!(dupname = strdup(name)))
		fprintf(stderr, "%s: strdup(): %m\n", argv0),
		error = e_out_of_memory;
	
	if (!error)
		error = smalloc((void**) &this, sizeof(*this));
	
	if (!error)
	{
		this->name = dupname, dupname = NULL;
		this->value = vinc(value);
		this->width = 0;
		
		*new = this;
	}
	
	free(dupname);
	
	EXIT;
	return error;
}


















