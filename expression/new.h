
#include <stdlib.h>

#include "kind.h"

struct expression;
struct expression_inheritance;

int new_expression(
	struct expression** new,
	enum expression_kind kind,
	struct expression_inheritance* inheritance,
	size_t alloc_size);
