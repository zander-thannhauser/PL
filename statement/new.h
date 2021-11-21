
#include <stdlib.h>

#include "kind.h"

struct statement;
struct statement_inheritance;

int new_statement(
	struct statement** new,
	enum statement_kind kind,
	struct statement_inheritance* inheritance,
	unsigned line,
	size_t alloc_size);
