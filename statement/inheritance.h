
struct scope;
struct statement;

struct statement_inheritance
{
	int (*evaluate)(struct statement*, struct statement**, struct scope*);
	
	void (*print)(struct statement*);
	
	void (*free)(struct statement*);
};

