
#include <stdio.h>

#include <debug.h>

#include "../print.h"

#include "struct.h"
#include "print.h"

void variable_expression_print(
	struct expression* super)
{
	struct variable_expression* const this = (typeof(this)) super;
	ENTER;
	
	dpvs(this->name);
	
	printf("%s", this->name);
	
	EXIT;
}

