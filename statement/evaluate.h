
struct statement;
struct scope;

int statement_evaluate(
	struct statement* this,
	struct statement** next,
	struct scope* scope);
