
#include "../inheritance.h"

#include "print.h"
#include "evaluate.h"
#include "inheritance.h"
#include "free.h"

struct expression_inheritance unary_expression_inheritance = {
	.evaluate = unary_expression_evaluate,
	.print = unary_expression_print,
	.free = free_unary_expression,
};

