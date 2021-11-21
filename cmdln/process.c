
#include <stdbool.h>
#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include <debug.h>
#include <enums/error.h>

#include <defines/argv0.h>

#include <memory/smalloc.h>

#include <string/strstrip.h>

#include "flags.h"
#include "usage.h"
#include "free.h"
#include "process.h"

static int process_define_argument(
	struct cmdln_variable** variables,
	char* optarg)
{
	int error = 0;
	ENTER;
	
	dpvs(optarg);
	
	char *equals, *name, *value;
	
	if (!(equals = index(optarg, '=')))
	{
		TODO;
		error = 1;
	}
	
	if (!error)
	{
		*equals = '\0';
		
		name = optarg;
		value = equals + 1;
		
		strstrip(&name);
		strstrip(&value);
	}
	
	struct cmdln_variable* this = NULL;
	
	if (!error)
		error = smalloc((void**) &this, sizeof(*this));
	
	if (!error)
	{
		dpvs(name);
		dpvs(value);
		
		this->name = name, name = NULL;
		this->value = value;
		
		this->prev = *variables;
		*variables = this, this = NULL;
	}
	
	free(this);
	
	EXIT;
	return error;
}

int process_cmdln(struct cmdln_flags** retval, int argc, char* const* argv)
{
	int error = 0;
	ENTER;
	
	const char* input_path = NULL;
	
	bool verbose = false;
	
	struct cmdln_variable* variables = NULL;
	
	// for getopt:
	int opt, option_index;
	const struct option long_options[] = {
		{"define",  required_argument, 0, 'D'},
		{0, 0, 0, 0}
	};
	
	while (!error && (opt = getopt_long(argc, argv, "d:v", long_options, &option_index)) >= 0)
	{
		switch (opt)
		{
			case 'd':
				error = process_define_argument(&variables, optarg);
				break;
			
			case 'v':
				verbose = true;
				break;
			
			default:
				error = e_bad_cmdline_args;
				break;
		}
	}
	
	if (!error && !(input_path = argv[optind++]))
	{
		fprintf(stderr, "%s: input file not specified!\n", argv0);
		error = e_bad_cmdline_args;
	}
	
	if (error == e_bad_cmdline_args)
		usage();
	
	struct cmdln_flags* flags = NULL;
	
	if (!error)
		error = smalloc((void**) &flags, sizeof(*flags));
	
	if (!error)
	{
		flags->input_path = input_path;
		flags->variables = variables, variables = NULL;
		flags->verbose = verbose;
		
		*retval = flags, flags = NULL;
	}
	
	struct cmdln_variable* prev;
	while (variables)
	{
		prev = variables->prev;
		free(variables);
		variables = prev;
	}
	
	EXIT;
	return error;
}











