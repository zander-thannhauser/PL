
struct next_link
{
	unsigned refcount;
	struct statement **element;
	struct next_link* next;
};

struct next_ll
{
	unsigned n;
	struct next_link* head;
	struct next_link* tail;
};

