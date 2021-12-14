
#include <stdio.h>

#include <avl/avl.h>

#include <debug.h>

#include <enums/error.h>

#include <defines/argv0.h>

#include <statement/inc.h>
#include <statement/free.h>

#include "label/struct.h"
#include "label/new.h"
#include "label/free.h"

#include "struct.h"
#include "declare.h"

int label_scope_declare(
	struct label_scope* this,
	const char* name,
	struct statement* statement)
{
	int error = 0;
	struct avl_node_t* node;
	ENTER;
	
	dpvs(name);
	
	if ((node = avl_search(this->tree, &name)))
	{
		struct label* const label = node->item;
		
		free_statement(label->statement);
		label->statement = sinc(statement);
	}
	else
	{
		struct label* label = NULL;
		
		error = new_label(&label, name, statement);
		
		if (!error)
		{
			if (avl_insert(this->tree, label))
				label = NULL;
			else
			{
				fprintf(stderr, "%s: malloc(): %m\n", argv0);
				error = e_out_of_memory;
			}
		}
		
		free_label(label);
	}
	
	EXIT;
	return error;
}








