
#include <stdio.h>

#include <avl/avl.h>

#include <debug.h>

#include <value/print.h>

#include "variable/struct.h"

#include "struct.h"
#include "printout.h"

void scope_printout(
	struct scope* this)
{
	ENTER;
	
	struct avl_node_t* node;
	
	for (node = this->tree->head; node; node = node->next)
	{
		struct variable* const variable = node->item;
		
		dpvs(variable->name);
		
		printf("%s = ", variable->name);
		
		value_print(variable->value, &variable->width);
		
		if (node->next)
			printf(", ");
	}
	
	EXIT;
}

















