
#include <debug.h>

#include "struct.h"
#include "link_inc.h"

struct next_link* link_inc(struct next_link* link)
{
	if (link)
		link->refcount++;
	return link;
}

