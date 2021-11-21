
#include <gmp.h>

#include <debug.h>

#include <macros/max.h>

#include "struct.h"
#include "print.h"

void value_print(
	struct value* this, int* width)
{
	ENTER;
	
	if (width)
	{
		int a, w = *width;
		
		gmp_printf("%*Zi%n", w, this->value, &a);
		
		*width = max(w, a);
	}
	else
	{
		gmp_printf("%Zi", this->value);
	}
	
	EXIT;
}














