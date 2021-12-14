
#include <stdlib.h>

#include <debug.h>

#include "flags.h"
#include "free.h"

void free_flags(struct cmdln_flags* flags)
{
	ENTER;
	
	if (flags)
	{
		struct cmdln_variable* prev;
		while (flags->variables)
		{
			prev = flags->variables->prev;
			free(flags->variables);
			flags->variables = prev;
		}
		
		free(flags);
	}
	
	EXIT;
}

