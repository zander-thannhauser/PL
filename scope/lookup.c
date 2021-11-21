
#include <avl/avl.h>

#include <debug.h>

#include <value/inc.h>

#include "variable/struct.h"
#include "struct.h"
#include "lookup.h"

int scope_lookup(
	struct scope* this,
	const char* name,
	struct value** out_value)
{
	int error = 0;
	ENTER;
	
	struct avl_node_t* node;
	
	if ((node = avl_search(this->tree, &name)))
	{
		struct variable* const variable = node->item;
		
		*out_value = vinc(variable->value);
	}
	else
	{
		*out_value = vinc(this->zero);
	}
	
	EXIT;
	return error;
}













