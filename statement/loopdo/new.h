
struct loopdo_statement;
struct expression;
struct statement;

int new_loopdo_statement(
	struct loopdo_statement** new,
	unsigned line,
	struct expression* conditional,
	struct statement* body);
