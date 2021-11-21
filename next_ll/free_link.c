
#include <stdlib.h>

#include <debug.h>

#include "struct.h"
#include "free_link.h"

void free_link(struct next_link* link)
{
	if (link && !--link->refcount)
	{
		free_link(link->next);
		free(link);
	}
}

