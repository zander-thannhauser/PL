
struct scope;
struct value;
struct expression;

struct expression_inheritance
{
	int (*evaluate)(struct expression*, struct scope*, struct value**);
	
	void (*print)(struct expression*);
	
	void (*free)(struct expression*);
};

