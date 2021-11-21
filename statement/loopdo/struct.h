
#include <stdbool.h>
#include <gmp.h>

#include "../struct.h"

struct loopdo_statement
{
	struct statement super;
	
	struct expression* conditional;
	
	mpz_t loop_counter;
	
	bool reset;
	
	struct statement* body;
	struct statement* next;
};

