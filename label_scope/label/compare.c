
#include <string.h>

#include <debug.h>

#include "struct.h"
#include "compare.h"

int compare_label(
	const struct label* a,
	const struct label* b)
{
	dpvs(a->name);
	dpvs(b->name);
	return strcmp(a->name, b->name);
}

