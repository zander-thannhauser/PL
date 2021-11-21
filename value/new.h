
#include <gmp.h>

struct value;

int new_value_from_mpz(
	struct value** new,
	mpz_t mpz);

int new_value(
	struct value** new,
	const char* value);
