
struct label;
struct statement;

int new_label(
	struct label** new,
	const char* name,
	struct statement* statement);
