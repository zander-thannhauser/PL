
struct scope;
struct value;

int scope_declare(
	struct scope* this,
	const char* name,
	struct value* value);
