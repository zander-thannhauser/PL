
#include "../inheritance.h"

#include "print.h"
#include "evaluate.h"
#include "free.h"
#include "inheritance.h"

struct statement_inheritance goto_statement_inheritance = {
	.evaluate = goto_statement_evaluate,
	.print = goto_statement_print,
	.free = free_goto_statement,
};

