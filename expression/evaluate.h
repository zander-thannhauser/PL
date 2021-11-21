
struct expression;
struct scope;
struct value;

int expression_evaluate(
	struct expression* this,
	struct scope* scope,
	struct value** out_value);
