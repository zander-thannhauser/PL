
#include "kind.h"

struct expression;

int new_binary_expression(
	struct expression** new,
	enum binary_expression_kind kind,
	struct expression* left,
	struct expression* right);
