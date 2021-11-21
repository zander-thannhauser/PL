

%token<name> NAME
%token<value> NUMERAL

%token IF ELSE THEN END SEMICOLON ASSIGN LOOP WHILE STOP GOTO COLON
%token LESS_THAN LESS_THAN_EQUAL GREATER_THAN GREATER_THAN_EQUAL
%token PLUS MINUS TIMES DIVIDE
%token OPEN_PAREN CLOSE_PAREN
%token EQUALS NOT_EQUALS DO
%token LOGICAL_AND LOGICAL_OR
%token NOT

%start program

%define parse.error verbose

%parse-param {int *error}
%parse-param {struct statement** program}
%parse-param {struct label_scope* lscope}
%parse-param {unsigned* line}

%lex-param {unsigned* line}

%code requires {
	#include <gmp.h>
	
	struct label_scope;
}

%code top {
	struct expression;
	struct next_ll;
}

%union {
	char* name;
	unsigned line;
	struct value* value;
	struct expression* expression;
	struct statement* statement;
	struct {
		struct statement* start;
		struct next_ll* nexts;
	} sbundle;
};

%destructor { free_value($$); } <value>

//%destructor {  } <>

%{

#include <stdio.h>
#include <stdlib.h>

#include <debug.h>

#include <expression/literal/new.h>
#include <expression/binary/new.h>
#include <expression/unary/new.h>
#include <expression/variable/new.h>

#include <next_ll/free.h>

#include <value/free.h>

#include "callbacks/assignment.h"
#include "callbacks/ifelse.h"
#include "callbacks/while.h"
#include "callbacks/label.h"
#include "callbacks/loop.h"
#include "callbacks/statement_plus.h"
#include "callbacks/goto.h"
#include "callbacks/stop.h"

#include "yyerror.h"

int yylex();

%}

%type <expression> primary_expression
%type <expression> prefix_expression
%type <expression> multiplicative_expression
%type <expression> additive_expression
%type <expression> relational_expression
%type <expression> equality_expression
%type <expression> logical_and_expression
%type <expression> expression

%type <sbundle> statement
%type <sbundle> statement_plus
%type <sbundle> maybe_else

%%

primary_expression
	: NAME {
		if ((*error = new_variable_expression(&$$, $1)))
			YYABORT;
	} | NUMERAL {
		if ((*error = new_literal_expression(&$$, $1)))
			YYABORT;
	} | OPEN_PAREN expression CLOSE_PAREN {
		$$ = $2;
	};

prefix_expression
	: primary_expression {
		$$ = $1;
	} | NOT primary_expression {
		if ((*error = new_unary_expression(&$$, uek_logical_not, $2)))
			YYABORT;
	} ;

multiplicative_expression
	: prefix_expression {
		$$ = $1;
	} | multiplicative_expression TIMES prefix_expression {
		if ((*error = new_binary_expression(&$$, bek_times, $1, $3)))
			YYABORT;
	} | multiplicative_expression DIVIDE prefix_expression {
		if ((*error = new_binary_expression(&$$, bek_divide, $1, $3)))
			YYABORT;
	} ;

additive_expression
	: multiplicative_expression {
		$$ = $1;
	} | additive_expression PLUS multiplicative_expression {
		if ((*error = new_binary_expression(&$$, bek_addition, $1, $3)))
			YYABORT;
	} | additive_expression MINUS multiplicative_expression {
		if ((*error = new_binary_expression(&$$, bek_subtract, $1, $3)))
			YYABORT;
	};

relational_expression
	: additive_expression {
		$$ = $1;
	} | relational_expression LESS_THAN additive_expression {
		if ((*error = new_binary_expression(&$$, bek_less_than, $1, $3)))
			YYABORT;
	} | relational_expression GREATER_THAN additive_expression {
		if ((*error = new_binary_expression(&$$, bek_greater_than, $1, $3)))
			YYABORT;
	} | relational_expression LESS_THAN_EQUAL additive_expression {
		if ((*error = new_binary_expression(&$$, bek_less_than_equal, $1, $3)))
			YYABORT;
	} | relational_expression GREATER_THAN_EQUAL additive_expression {
		if ((*error = new_binary_expression(&$$, bek_greater_than_equal, $1, $3)))
			YYABORT;
	};

equality_expression
	: relational_expression {
		$$ = $1;
	} | equality_expression EQUALS relational_expression {
		if ((*error = new_binary_expression(&$$, bek_equals, $1, $3)))
			YYABORT;
	} | equality_expression NOT_EQUALS relational_expression {
		if ((*error = new_binary_expression(&$$, bek_not_equals, $1, $3)))
			YYABORT;
	};

logical_and_expression
	: equality_expression {
		$$ = $1;
	} | logical_and_expression LOGICAL_AND equality_expression {
		if ((*error = new_binary_expression(&$$, bek_logical_and, $1, $3)))
			YYABORT;
	};

expression
	: logical_and_expression {
		$$ = $1;
	} | expression LOGICAL_OR logical_and_expression {
		if ((*error = new_binary_expression(&$$, bek_logical_or, $1, $3)))
			YYABORT;
	};

maybe_else:
	%empty {
		$$.start = NULL;
		$$.nexts = NULL;
	} | ELSE statement_plus {
		$$ = $2;
	};

statement
	: NAME COLON statement {
		if ((*error = label_callback(&$$.start, &$$.nexts, $1, $3.start, $3.nexts, lscope)))
			YYABORT;
	} | NAME ASSIGN <line> { $$ = *line; } expression SEMICOLON {
		if ((*error = assignment_callback(&$$.start, &$$.nexts, $3, $1, $4)))
			YYABORT;
	} | GOTO <line> { $$ = *line; } NAME SEMICOLON {
		if ((*error = goto_callback(&$$.start, &$$.nexts, $2, $3, lscope)))
			YYABORT;
	} | STOP <line> { $$ = *line; } SEMICOLON {
		if ((*error = stop_callback(&$$.start, &$$.nexts, $2)))
			YYABORT;
	} | LOOP <line>{ $$ = *line; } expression DO statement_plus END {
		if ((*error = loop_callback(&$$.start, &$$.nexts, $2, $3, $5.start, $5.nexts)))
			YYABORT;
	} | WHILE <line>{ $$ = *line; } expression DO statement_plus END {
		if ((*error = while_callback(&$$.start, &$$.nexts, $2, $3, $5.start, $5.nexts)))
			YYABORT;
	} | IF <line>{ $$ = *line; } expression THEN statement_plus maybe_else END {
		if ((*error = ifelse_callback(&$$.start, &$$.nexts, $2, $3, $5.start, $5.nexts, $6.start, $6.nexts)))
			YYABORT;
	};

statement_plus: statement {
		$$ = $1;
	} | statement_plus statement {
		if ((*error = statement_plus_callback(&$$.start, &$$.nexts, $1.start, $1.nexts, $2.start, $2.nexts)))
			YYABORT;
	};

program: statement_plus {
	*program = $1.start;
	free_next_ll($1.nexts);
};

%%
























