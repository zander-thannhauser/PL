
#if 0
#include <debug.h>

#include <memory/smalloc.h>

#include <statement/free.h>

#include "struct.h"
#include "free_link.h"
#include "append.h"

int statement_ll_append(
	struct statement_ll* this,
	struct statement* element)
{
	int error = 0;
	ENTER;
	
	struct statement_link* link = NULL;
	
	error = smalloc((void**) &link, sizeof(*link));
	
	if (!error)
	{
		link->element = element, element = NULL;
		
		link->next = this->head;
		this->head = link, link = NULL;
	}
	
	free_statement(element);
	free_link(link);
	
	EXIT;
	return error;
}
#endif
