
#include "../struct.h"

#include "kind.h"

struct ifelse_statement
{
	struct statement super;
	
	enum ifelse_statement_kind kind;
	
	struct expression* conditional;
	
	struct statement* true_case;
	struct statement* false_case;
	
	struct value* loop_counter;
};

