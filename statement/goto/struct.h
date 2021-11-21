
#include "../struct.h"

struct goto_statement
{
	struct statement super;
	
	struct statement* gotome;
};

