
struct value;

struct variable
{
	char* name; // must be the first!
	int width;
	struct value* value;
};

