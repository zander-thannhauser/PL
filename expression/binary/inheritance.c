
#include "../inheritance.h"

#include "print.h"
#include "evaluate.h"
#include "inheritance.h"
#include "free.h"

struct expression_inheritance binary_expression_inheritance = {
	.evaluate = binary_expression_evaluate,
	.print = binary_expression_print,
	.free = free_binary_expression,
};

