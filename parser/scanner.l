
D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+

%{

#include <stdio.h>
#include <gmp.h>

#include <debug.h>

#include <enums/error.h>

#include <defines/argv0.h>

#include <value/new.h>

#include "parser.h"

#define YY_DECL int yylex(unsigned* line)

static int process_name();
static int process_numeral();

%}

%option nounput
%option noinput

%%

"#".* { /* comment */ }

"goto"	{ return (GOTO); }
"stop"	{ return (STOP); }
"do"	{ return (DO); }
"loop"	{ return (LOOP); }
"if"	{ return (IF); }
"then"	{ return (THEN); }
"end"	{ return (END); }
"else"	{ return (ELSE); }
"while"	{ return (WHILE); }

{L}({L}|{D})*	{ return (process_name()); }

0[xX]{H}+	{ return (process_numeral()); }
0{D}+		{ return (process_numeral()); }
{D}+		{ return (process_numeral()); }

":"		{ return (COLON); }
"+"		{ return (PLUS); }
"-"		{ return (MINUS); }
"*"		{ return (TIMES); }
"/"		{ return (DIVIDE); }
"="		{ return (EQUALS); }
"!="	{ return (NOT_EQUALS); }
">="	{ return (GREATER_THAN_EQUAL); }
">"		{ return (GREATER_THAN); }
"<="	{ return (LESS_THAN); }
"<-"	{ return (ASSIGN); }
"<"		{ return (LESS_THAN); }
"||"	{ return (LOGICAL_OR); }
"&&"	{ return (LOGICAL_AND); }
"!"		{ return (NOT); }
";"		{ return (SEMICOLON); }

"\n"		{ (*line)++; }
[ \t\v\f]	{ }
.			{ /* ignore bad characters */ }

%%

int yywrap()
{
	return(1);
}

static int process_name()
{
	int error = 0;
	ENTER;
	
	dpvs(yytext);
	
	if (!(yylval.name = strdup(yytext)))
		fprintf(stderr, "%s: strdup(): %m\n", argv0),
		error = e_out_of_memory;
	
	if (error)
	{
		abort();
	}
	
	EXIT;
	return NAME;
}


static int process_numeral()
{
	int error = 0;
	ENTER;
	
	dpvs(yytext);
	
	error = new_value(&yylval.value, yytext);
	
	if (error)
	{
		abort();
	}
	
	EXIT;
	return NUMERAL;
}


















