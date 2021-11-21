
#include <stdio.h>

#include <debug.h>

#include <enums/error.h>

#include <avl/avl.h>

#include <defines/argv0.h>

#include <memory/smalloc.h>

#include <value/new.h>
#include <value/inc.h>
#include <value/free.h>

#include "variable/compare.h"
#include "variable/free.h"

#include "struct.h"
#include "new.h"

int new_scope(
	struct scope** new)
{
	int error = 0;
	struct value* zero = NULL;
	struct value* one = NULL;
	struct avl_tree_t* tree = NULL;
	struct scope* this;
	ENTER;
	
	if (!(tree = avl_alloc_tree(
		(int (*)(const void*, const void*)) compare_variable,
		(void (*)(void*)) free_variable)))
	{
		fprintf(stderr, "%s: malloc(): %m\n", argv0),
		error = e_out_of_memory;
	}
	else error = 0
		?: new_value(&zero, "0")
		?: new_value(&one, "1")
		?: smalloc((void**) &this, sizeof(*this));
	
	if (!error)
	{
		this->tree = tree, tree = NULL;
		this->zero = vinc(zero);
		this->one = vinc(one);
		
		*new = this;
	}
	
	free_value(zero);
	free_value(one);
	avl_free_tree(tree);
	
	EXIT;
	return error;
}















