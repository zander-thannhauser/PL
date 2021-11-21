
struct variable;
struct value;

int new_variable(
	struct variable** new,
	const char* name,
	struct value* value);
