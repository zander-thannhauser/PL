
#include "../inheritance.h"

#include "print.h"
#include "evaluate.h"
#include "free.h"
#include "inheritance.h"

struct statement_inheritance assignment_statement_inheritance = {
	.evaluate = assignment_statement_evaluate,
	.print = assignment_statement_print,
	.free = free_assignment_statement,
};

