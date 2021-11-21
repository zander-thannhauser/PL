
struct statement;
struct expression;

int while_callback(
	struct statement** out_start, struct next_ll** out_nexts,
	unsigned line,
	struct expression* conditional,
	struct statement* head_start, struct next_ll* head_nexts);
