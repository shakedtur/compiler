%{
#include <stdlib.h>
#include <string.h>
#include "node.h"
#include "y.tab.h"
void yyerror(char *);
int yylineno;
%}

%%

"boolean"		{ return BOOLEAN; }
"char"			{ return CHAR; }
"int" 			{ return INTEGER; }
"real"			{ return REAL;	}
"string"		{ return STRING ; }
"intp"			{ return INTPTR ; }
"charp"  		{ return CHARPTR; }
"realp"			{ return REALPTR; }
"if" 	       		{ return IF; }
"else" 			{ return ELSE; }
"while" 		{ return WHILE; }
"for"			{ return FOR;	}
"var"			{ return VAR; }
"function" 		{ return FUNCTION; }
"null"	 		{ return NULL_LITERAL; }
"main"			{ return MAIN; }
"void"			{ return VOID;	}
"do"			{ return DO;	}	

\&\& 			{ yylval.value = strdup(yytext); return AND; }
\/ 			{ yylval.value = strdup(yytext); return DIV; }
\=			{ yylval.value = strdup(yytext); return '='; }
\=\= 	        	{ yylval.value = strdup(yytext); return EQUALS; }
\> 			{ yylval.value = strdup(yytext); return GREATER; }
\>\= 			{ yylval.value = strdup(yytext); return GREATER_EQ; }
\<\= 			{ yylval.value = strdup(yytext); return LESS_EQ; }
\< 			{ yylval.value = strdup(yytext); return LESS; }
\- 			{ yylval.value = strdup(yytext); return MINUS; }
\! 			{ yylval.value = strdup(yytext); return NOT; }
\!\= 			{ yylval.value = strdup(yytext); return NOT_EQ; }
\|\|			{ yylval.value = strdup(yytext); return OR; }
\+ 			{ yylval.value = strdup(yytext); return PLUS; }
\* 			{ yylval.value = strdup(yytext); return MUL; }
& 			{ yylval.value = strdup(yytext); return ADDRESS_OP; }

true|false 		{ yylval.value = strdup(yytext); return BOOLEAN_LITERAL; }
([1-9][0-9]*)|0 	{ yylval.value = strdup(yytext); return DECIMAL_NUM; }
0[x|X][0-9A-F]+ 	{ yylval.value = strdup(yytext); return HEX_NUM; }

[-|+]([1-9][0-9]*)|0[.]([1-9][0-9]*)[e|E][-|+]([1-9][0-9]*) { yylval.value = strdup(yytext); return REAL_NUM;}


[a-zA-Z][a-zA-Z0-9_]* 	{ yylval.value = strdup(yytext); return IDENTIFIER; }


; 			{ return ';'; }
, 			{ return ','; }
\|			{ return '|'; }
\{			{ return '{'; }
\}			{ return '}'; }
\(			{ return '('; }
\)			{ return ')'; }
\[			{ return '['; }
\]			{ return ']'; }

[ \t\r\f]+ 		;
\n			++yylineno;
. 			yyerror("Error, unexpected character!");
%%
int yywrap(void) {
	return 1;
}
