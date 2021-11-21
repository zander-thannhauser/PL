
struct assignment_statement;
struct expression;

int new_assignment_statement(
	struct assignment_statement** new,
	unsigned line,
	char* name,
	struct expression* expression);
