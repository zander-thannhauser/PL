
struct label_scope;
struct statement;

int label_scope_declare(
	struct label_scope* this,
	const char* name,
	struct statement* statement);
