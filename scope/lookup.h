
struct scope;
struct value;

int scope_lookup(
	struct scope* this,
	const char* name,
	struct value** out_value);
