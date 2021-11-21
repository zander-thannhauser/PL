
#include <gmp.h>

struct value
{
	mpz_t value;
	
	unsigned refcount;
};

