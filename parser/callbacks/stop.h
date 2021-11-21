
struct statement;
struct next_ll;

int stop_callback(
	struct statement** out_start,
	struct next_ll** out_nexts,
	unsigned line);
