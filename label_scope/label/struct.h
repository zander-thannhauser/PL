
struct statement;

struct label
{
	char* name; // must be first!
	struct statement* statement;
};

