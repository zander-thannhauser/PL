
#ifndef ENUM_BINARY_EXPRESSION_KIND
#define ENUM_BINARY_EXPRESSION_KIND

enum binary_expression_kind
{
	bek_addition,
	bek_divide,
	bek_equals,
	bek_greater_than,
	bek_greater_than_equal,
	bek_less_than,
	bek_less_than_equal,
	bek_logical_and,
	bek_logical_or,
	bek_not_equals,
	bek_subtract,
	bek_times,
	
	number_of_binary_operators,
};

#endif
