
struct expression;
struct scope;
struct value;

int binary_expression_evaluate(
	struct expression* super,
	struct scope* scope,
	struct value** out_value);
