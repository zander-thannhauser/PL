
#include <string.h>

#include <debug.h>

#include "struct.h"
#include "compare.h"

int compare_variable(
	const struct variable* a,
	const struct variable* b)
{
	dpvs(a->name);
	dpvs(b->name);
	return strcmp(a->name, b->name);
}

