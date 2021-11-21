
struct statement;
struct next_ll;

int statement_plus_callback(
	struct statement** out_start, struct next_ll** out_nexts,
	struct statement* head_start, struct next_ll* head_nexts,
	struct statement* tail_start, struct next_ll* tail_nexts);
