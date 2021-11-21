
#include "kind.h"

struct statement
{
	enum statement_kind kind;
	struct statement_inheritance* inheritance;
	
	unsigned line;
	unsigned refcount;
};

