
struct statement;
struct next_ll;
struct expression;

int assignment_callback(
	struct statement** out_start,
	struct next_ll** out_nexts,
	unsigned line,
	char* name,
	struct expression* expression);
