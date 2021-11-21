
#include "../struct.h"

struct expression;

struct assignment_statement
{
	struct statement super;
	char* name;
	struct expression* expression;
	
	struct statement* next;
	
};

