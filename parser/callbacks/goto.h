
struct label_scope;
struct statement;
struct next_ll;

int goto_callback(
	struct statement** out_start,
	struct next_ll** out_nexts,
	unsigned line,
	char* name,
	struct label_scope* lscope);
