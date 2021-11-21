
#include "kind.h"

struct expression;

int new_unary_expression(
	struct expression** new,
	enum unary_expression_kind kind,
	struct expression* inner);
