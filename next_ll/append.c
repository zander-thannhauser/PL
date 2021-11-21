
#include <debug.h>

#include <memory/smalloc.h>

#include "struct.h"
#include "free_link.h"
#include "link_inc.h"
#include "append.h"

int next_ll_append(
	struct next_ll* this,
	struct statement** element)
{
	int error = 0;
	ENTER;
	
	struct next_link* link = NULL;
	
	error = smalloc((void**) &link, sizeof(*link));
	
	if (!error)
	{
		this->n++;
		
		link->refcount = 1;
		
		link->element = element;
		
		link->next = NULL;
		
		if (this->head)
		{
			this->tail->next = link_inc(link);
			free_link(this->tail);
			this->tail = link_inc(link);
		}
		else
		{
			this->head = link_inc(link);
			this->tail = link_inc(link);
		}
	}
	
	free_link(link);
	
	EXIT;
	return error;
}















