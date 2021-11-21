
#include <stdlib.h>

#include <avl/avl.h>

#include <debug.h>

#include "struct.h"
#include "free.h"

void free_label_scope(struct label_scope* this)
{
	ENTER;
	
	if (this)
	{
		avl_free_tree(this->tree);
		
		free(this);
	}
	
	EXIT;
}

