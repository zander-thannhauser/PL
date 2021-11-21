
struct statement;
struct label_scope;

struct statement* label_scope_lookup(struct label_scope* this, const char* name);
