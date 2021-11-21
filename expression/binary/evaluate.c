
#include <gmp.h>

#include <debug.h>

#include <value/struct.h>
#include <value/new.h>
#include <value/inc.h>
#include <value/free.h>

#include <scope/struct.h>

#include "../evaluate.h"

#include "struct.h"
#include "evaluate.h"

int binary_expression_evaluate(
	struct expression* super,
	struct scope* scope,
	struct value** out_value)
{
	int error = 0;
	struct value* left = NULL;
	struct value* right = NULL;
	struct binary_expression* const this = (typeof(this)) super;
	ENTER;
	
	error = 0
		?: expression_evaluate(this->left, scope, &left)
		?: expression_evaluate(this->right, scope, &right);
	
	if (!error)
	{
		switch (this->kind)
		{
			mpz_t result;
			
			case bek_addition:
			{
				mpz_init(result);
				
				mpz_add(result, left->value, right->value);
				
				if ((error = new_value_from_mpz(out_value, result)))
					mpz_clear(result);
				break;
			}
			
			case bek_divide:
			{
				mpz_init(result);
				
				mpz_fdiv_q(result, left->value, right->value);
				
				if ((error = new_value_from_mpz(out_value, result)))
					mpz_clear(result);
				break;
			}
			
			case bek_equals:
				*out_value = mpz_cmp(left->value, right->value) == 0
					? vinc(scope->one)
					: vinc(scope->zero);
				break;
			
			case bek_greater_than:
				*out_value = mpz_cmp(left->value, right->value) > 0
					? vinc(scope->one)
					: vinc(scope->zero);
				break;
			
			case bek_greater_than_equal:
				*out_value = mpz_cmp(left->value, right->value) >= 0
					? vinc(scope->one)
					: vinc(scope->zero);
				break;
			
			case bek_less_than:
				*out_value = mpz_cmp(left->value, right->value) < 0
					? vinc(scope->one)
					: vinc(scope->zero);
				break;
			
			case bek_less_than_equal:
				*out_value = mpz_cmp(left->value, right->value) <= 0
					? vinc(scope->one)
					: vinc(scope->zero);
				break;
			
			case bek_logical_and:
				*out_value = mpz_sgn(left->value) && mpz_sgn(right->value)
					? vinc(scope->one)
					: vinc(scope->zero);
				break;
			
			case bek_logical_or:
				*out_value = mpz_sgn(left->value) || mpz_sgn(right->value)
					? vinc(scope->one)
					: vinc(scope->zero);
				break;
			
			case bek_not_equals:
				*out_value = mpz_cmp(left->value, right->value) != 0
					? vinc(scope->one)
					: vinc(scope->zero);
				break;
			
			case bek_subtract:
			{
				mpz_init(result);
				
				mpz_sub(result, left->value, right->value);
				
				if (mpz_sgn(result) < 0)
				{
					TODO; // set to zero
				}
				
				if ((error = new_value_from_mpz(out_value, result)))
					mpz_clear(result);
				break;
			}
			
			case bek_times:
			{
				mpz_init(result);
				
				mpz_mul(result, left->value, right->value);
				
				if ((error = new_value_from_mpz(out_value, result)))
					mpz_clear(result);
				break;
			}
			
			default:
				dpv(this->kind);
				TODO;
				break;
		}
	}
	
	free_value(left), free_value(right);
	
	EXIT;
	return error;
}















