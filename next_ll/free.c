
#include <stdlib.h>

#include <debug.h>

#include "free_link.h"
#include "struct.h"
#include "free.h"

void free_next_ll(struct next_ll* this)
{
	if (this)
	{
		free_link(this->head);
		free_link(this->tail);
		free(this);
	}
}

