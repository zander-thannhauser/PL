
struct statement;
struct scope;

int assignment_statement_evaluate(
	struct statement* super,
	struct statement** next,
	struct scope* scope);
