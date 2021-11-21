
#include <stdio.h>

#include <debug.h>

#include <enums/error.h>

#include <defines/argv0.h>

#include <macros/max.h>

#include <cmdln/flags.h>
#include <cmdln/process.h>
#include <cmdln/free.h>

#include <scope/new.h>
#include <scope/declare.h>
#include <scope/printout.h>
#include <scope/free.h>

#include <label_scope/new.h>
#include <label_scope/free.h>

#include <statement/struct.h>
#include <statement/evaluate.h>
#include <statement/print.h>
#include <statement/free.h>

#include <parser/scanner.h>
#include <parser/parser.h>

#include <value/new.h>
#include <value/free.h>

#ifdef DEBUGGING
int debug_depth;
#endif

int main(int argc, char* const* argv)
{
	int error = 0;
	struct cmdln_flags* flags = NULL;
	FILE *fin = NULL;
	struct statement* program = NULL;
	struct scope *scope = NULL;
	struct label_scope *lscope = NULL;
	unsigned line = 1;
	ENTER;
	
	error = 0
		?: process_cmdln(&flags, argc, argv)
		?: new_scope(&scope)
		?: new_label_scope(&lscope);
	
	// declare command-line variables:
	if (!error)
	{
		struct cmdln_variable* variable;
		
		for (variable = flags->variables;
			!error && variable; variable = variable->prev)
		{
			struct value* value = NULL;
			
			error = 0
				?: new_value(&value, variable->value)
				?: scope_declare(scope, variable->name, value);
			
			free_value(value);
		}
	}
	
	// try to open input file:
	if (!error && !(fin = fopen(flags->input_path, "r")))
		fprintf(stderr, "%s: fopen(\"%s\"): %m\n", argv0, flags->input_path),
		error = e_bad_input_file;
	
	// parse program:
	if (!error)
	{
		// pass `fin` to flex:
		yyin = fin;
		
		// invoke parser:
		yyparse(&error, &program, lscope, &line);
	}
	
	// execute program:
	int b, a, w = 0;
	for (struct statement* exeme = program; !error && exeme; )
	{
		if (flags->verbose)
		{
			printf("line %n%*u%n: ", &b, w, exeme->line, &a), w = max(w, a - b);
			scope_printout(scope);
			printf(" | ");
			statement_print(exeme);
			printf("\n");
		}
		
		error = statement_evaluate(exeme, &exeme, scope);
	}
	
	// print variables:
	if (!error)
		scope_printout(scope), puts("");
	
	free_statement(program);
	
	// shutdown flex:
	yylex_destroy();
	if (fin) fclose(fin);
	
	// free scopes:
	free_scope(scope);
	free_label_scope(lscope);
	
	// free cmdln flags:
	free_flags(flags);
	
	EXIT;
	return error;
}










