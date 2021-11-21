
#include "../inheritance.h"

#include "print.h"
#include "evaluate.h"
#include "free.h"
#include "inheritance.h"

struct statement_inheritance loopdo_statement_inheritance = {
	.evaluate = loopdo_statement_evaluate,
	.print = loopdo_statement_print,
	.free = free_loopdo_statement,
};

