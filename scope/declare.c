
#include <stdio.h>

#include <avl/avl.h>

#include <debug.h>

#include <enums/error.h>

#include <defines/argv0.h>

#include <value/inc.h>
#include <value/free.h>

#include "variable/struct.h"
#include "variable/new.h"
#include "variable/free.h"

#include "struct.h"
#include "declare.h"

int scope_declare(
	struct scope* this,
	const char* name,
	struct value* value)
{
	int error = 0;
	struct avl_node_t* node;
	ENTER;
	
	dpvs(name);
	
	if ((node = avl_search(this->tree, &name)))
	{
		struct variable* const variable = node->item;
		
		free_value(variable->value);
		variable->value = vinc(value);
	}
	else
	{
		struct variable* variable = NULL;
		
		error = new_variable(&variable, name, value);
		
		if (!error && !avl_insert(this->tree, variable))
		{
			fprintf(stderr, "%s: malloc(): %m\n", argv0);
			error = e_out_of_memory;
		}
		
		if (error)
			free_variable(variable);
	}
	
	
	EXIT;
	return error;
}













