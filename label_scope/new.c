
#include <stdio.h>

#include <debug.h>
#include <enums/error.h>

#include <avl/avl.h>

#include <defines/argv0.h>

#include <memory/smalloc.h>

#include "label/compare.h"
#include "label/free.h"

#include "struct.h"
#include "new.h"

int new_label_scope(
	struct label_scope** new)
{
	int error = 0;
	struct label_scope* this;
	struct avl_tree_t* tree = NULL;
	ENTER;
	
	if (!(tree = avl_alloc_tree(
		(int (*)(const void*, const void*)) compare_label,
		(void (*)(void*)) free_label)))
		fprintf(stderr, "%s: malloc(): %m\n", argv0),
		error = e_out_of_memory;
	
	if (!error)
		error = smalloc((void**) &this, sizeof(*this));
	
	if (!error)
	{
		this->tree = tree, tree = NULL;
		
		*new = this;
	}
	
	avl_free_tree(tree);
	
	EXIT;
	return error;
}

