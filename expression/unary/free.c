
#include <debug.h>

#include "../free.h"

#include "struct.h"
#include "free.h"

void free_unary_expression(
	struct expression* super)
{
	struct unary_expression* const this = (typeof(this)) super;
	ENTER;
	
	free_expression(this->inner);
	
	EXIT;
}

