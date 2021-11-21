
#include "../inheritance.h"

#include "print.h"
#include "evaluate.h"
#include "inheritance.h"
#include "free.h"

struct expression_inheritance variable_expression_inheritance = {
	.evaluate = variable_expression_evaluate,
	.print = variable_expression_print,
	.free = free_variable_expression,
};

