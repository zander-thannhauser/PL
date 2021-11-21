
#include <stdio.h>
#include <debug.h>

#include <value/print.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

void literal_expression_print(
	struct expression* super)
{
	struct literal_expression* const this = (typeof(this)) super;
	ENTER;
	
	value_print(this->value, NULL);
	
	EXIT;
}

