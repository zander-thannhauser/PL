
#include <stdbool.h>

struct cmdln_flags
{
	const char* input_path;
	
	bool verbose;
	
	struct cmdln_variable {
		const char *name, *value;
		struct cmdln_variable* prev;
	}* variables;
};
