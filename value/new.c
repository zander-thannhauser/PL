
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include <gmp.h>

#include <debug.h>

#include <enums/error.h>

#include <defines/argv0.h>

#include <memory/smalloc.h>

#include "struct.h"
#include "new.h"

int new_value_from_mpz(
	struct value** new,
	mpz_t mpz)
{
	int error = 0;
	ENTER;
	
	struct value* this;
	
	if (!error)
		error = smalloc((void**) &this, sizeof(*this));
	
	if (!error)
	{
		this->refcount = 1;
		
		memcpy(this->value, mpz, sizeof(__mpz_struct));
		
		*new = this;
	}
	
	EXIT;
	return error;
}

int new_value(
	struct value** new,
	const char* value)
{
	int error = 0;
	mpz_t mpz;
	bool mpz_init = false;
	ENTER;
	
	if (mpz_init_set_str(mpz, value, 0) < 0)
	{
		fprintf(stderr, "%s: strtoul(\"%s\"): %m\n", argv0, value),
		error = e_bad_input_file;
	}
	else
		mpz_init = true;
	
	struct value* this;
	
	if (!error)
		error = smalloc((void**) &this, sizeof(*this));
	
	if (!error)
	{
		this->refcount = 1;
		
		memcpy(this->value, mpz, sizeof(__mpz_struct)), mpz_init = false;
		
		*new = this;
	}
	
	if (mpz_init)
		mpz_clear(mpz);
	
	EXIT;
	return error;
}










