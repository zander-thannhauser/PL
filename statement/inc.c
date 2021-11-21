
#include "struct.h"
#include "inc.h"

struct statement* sinc(struct statement* this)
{
	if (this)
		this->refcount++;
	return this;
}

