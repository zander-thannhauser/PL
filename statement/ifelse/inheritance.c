
#include "../inheritance.h"

#include "print.h"
#include "evaluate.h"
#include "free.h"
#include "inheritance.h"

struct statement_inheritance ifelse_statement_inheritance = {
	.evaluate = ifelse_statement_evaluate,
	.print = ifelse_statement_print,
	.free = free_ifelse_statement,
};

