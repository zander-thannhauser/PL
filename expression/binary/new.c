
#include <debug.h>

#include "../new.h"
#include "../free.h"

#include "struct.h"
#include "inheritance.h"
#include "new.h"

int new_binary_expression(
	struct expression** new,
	enum binary_expression_kind kind,
	struct expression* left,
	struct expression* right)
{
	int error = 0;
	struct binary_expression* this;
	ENTER;
	
	error = new_expression(
		(struct expression**) &this,
		ek_binary,
		&binary_expression_inheritance,
		sizeof(*this));
	
	if (!error)
	{
		this->kind = kind;
		this->left = left, left = NULL;
		this->right = right, right = NULL;
		
		*new = (struct expression*) this, this = NULL;
	}
	
	free_expression(left);
	free_expression(right);
	
	EXIT;
	return error;
}

