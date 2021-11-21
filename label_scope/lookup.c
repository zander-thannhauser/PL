
#include <stdio.h>

#include <avl/avl.h>

#include <debug.h>

#include <statement/inc.h>

#include "label/struct.h"
#include "struct.h"
#include "lookup.h"

struct statement* label_scope_lookup(struct label_scope* this, const char* name)
{
	struct statement* retval = NULL;
	ENTER;
	
	struct avl_node_t* node;
	
	if ((node = avl_search(this->tree, &name)))
	{
		struct label* const label = node->item;
		
		retval = label->statement;
	}
	
	EXIT;
	return retval;
}













