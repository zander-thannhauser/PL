
struct statement;
struct statement_ll;

int new_compound_statement(
	struct statement** new,
	struct statement_ll* substatements);
