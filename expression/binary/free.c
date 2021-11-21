
#include <debug.h>

#include "../free.h"

#include "struct.h"
#include "free.h"

void free_binary_expression(
	struct expression* super)
{
	struct binary_expression* const this = (typeof(this)) super;
	ENTER;
	
	free_expression(this->left);
	free_expression(this->right);
	
	EXIT;
}

