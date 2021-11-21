
#include "kind.h"

struct ifelse_statement;
struct expression;
struct statement;

int new_ifelse_statement(
	struct ifelse_statement** new,
	unsigned line,
	enum ifelse_statement_kind kind,
	struct expression* conditional,
	struct statement* true_case,
	struct statement* false_case);
