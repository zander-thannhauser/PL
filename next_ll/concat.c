
#include <debug.h>

#include <memory/smalloc.h>

#include "struct.h"
#include "free.h"
#include "link_inc.h"
#include "concat.h"

int next_ll_concat(
	struct next_ll** new,
	struct next_ll* first_half,
	struct next_ll* second_half)
{
	int error = 0;
	struct next_ll* this;
	ENTER;
	
	dpv(first_half)
	dpv(second_half);
	
	error = smalloc((void**) &this, sizeof(*this));
	
	if (!error)
	{
		dpv(first_half->n);
		dpv(second_half->n);
		
		if (!first_half->n)
		{
			this->head = link_inc(second_half->head);
			this->tail = link_inc(second_half->tail);
		}
		else if (!second_half->n)
		{
			this->head = link_inc(first_half->head);
			this->tail = link_inc(first_half->tail);
		}
		else
		{
			this->n = first_half->n + second_half->n;
			
			first_half->tail->next = link_inc(second_half->head);
			
			this->head = link_inc(first_half->head);
			this->tail = link_inc(second_half->tail);
		}
		
		*new = this;
	}
	
	free_next_ll(first_half);
	free_next_ll(second_half);
	
	EXIT;
	return error;
}










