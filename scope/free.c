
#include <stdlib.h>

#include <avl/avl.h>

#include <debug.h>

#include <value/free.h>

#include "struct.h"
#include "free.h"

void free_scope(struct scope* this)
{
	ENTER;
	
	if (this)
	{
		avl_free_tree(this->tree);
		
		free_value(this->zero);
		free_value(this->one);
		
		free(this);
	}
	
	EXIT;
}

