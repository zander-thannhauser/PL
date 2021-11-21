
struct label_scope;
struct statement;
struct next_ll;

int label_callback(
	struct statement** out_start,
	struct next_ll** out_nexts,
	char* name,
	struct statement* inner_start,
	struct next_ll* inner_nexts,
	struct label_scope* label_scope);
