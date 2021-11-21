
struct statement;
struct next_ll;

int ifelse_callback(
	struct statement** out_start,
	struct next_ll** out_nexts,
	unsigned line,
	struct expression* conditional,
	struct statement* true_start,
	struct next_ll* true_nexts,
	struct statement* false_start,
	struct next_ll* false_nexts);
