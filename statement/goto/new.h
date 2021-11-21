
struct goto_statement;
struct statement;

int new_goto_statement(
	struct goto_statement** new,
	unsigned line,
	struct statement* gotome);
