
#include <debug.h>

#include "struct.h"
#include "inc.h"

struct value* vinc(struct value* this)
{
	if (this)
		this->refcount++;
	
	return this;
}

