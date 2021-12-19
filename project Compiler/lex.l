%option yylineno

%{
#include <stdlib.h>
#include <string.h>

void yyerror(const char *);
int convertInt(char* num, int base) {
	if(strlen(num) > 10 && num[0] <= '2') {
		yyerror("INTEGER TOO BIG");
		exit(0);
	}
	int number = (int) strtol(yytext, 0, base);
	return number;
}

%}



ID [a-zA-Z][a-zA-Z0-9_]*
NPS [\@|\#|\$|\~|\?]+
PS [\!|\%|\^|\&|\*|\(|\)|\[|\]|\-|\+|=|\>|\/|\,|\;|\'|\{|\}|\<|\\]*
%%
"null"|"NULL" {return NULL_LITERAL;}
"procedure" {return KEY_PROCEDURE;}
"var" {return KEY_VAR; }
"charptr" {return KEY_CHARPTR;}
"intptr" {return KEY_INTPTR;}
"string" {return KEY_STRING;}
"integer" {return KEY_INTEGER;}
"boolean" {return KEY_BOOLEAN;}
"char" {return KEY_CHAR;}
"else" {return KEY_ELSE;}
"if" {return KEY_IF;}
"for" {return KEY_FOR;}
"return" {return KEY_RETURN;}
"while" {return KEY_WHILE;}
\&\& {return OP_AND;}
\/ {return OP_DIV;;}
\=\= {return OP_EQ;}
\= {return ASSIGN;}
\>\= {return OP_GE;}
\> {return OP_GT;}
\<\= {return OP_LE;}
\< {return OP_LT;}
\- {return OP_MINUS;}
\! {return OP_NOT;}
\!\= {return OP_NE;}
\|\| {return OP_OR;}
\| {return OP_ABS;}
\+ {return OP_PLUS;}
\* {return OP_MULTI;}
\& {return OP_ADDRESS_OF;}
\^ {return OP_DEREFERENCE;}
\{ {return BRA_O;}
\} {return BRA_C;}
\; {return SEMICOLON;}
\( {return PARAN_O;}
\) {return PARAN_C;}
\[ {return SQ_BRA_O;}
\] {return SQ_BRA_C;}
\" {return QUOTE;}
\' {return SINGLE_QUOTE;}
\. {return DOT;}
\: {return COLON;}
\, {return COMMA;}
true|TRUE {yylval.num = 1;return TRUE_LITERAL;}
false|FALSE {yylval.num = 0;return FALSE_LITERAL;}
"/%"([^%]|\%+[^%/])*\%+"/" {;}
'.'  {
        if(isprint(yytext[1]) != 0){
				yylval.ch = yytext[1];
                return CHAR_LITERAL;
		}
        else
                printf("NOT A PRINTABLE CHAR");
     }
0|[1-9][0-9]* {yylval.num=convertInt(yytext,10);return INTEGER_LITERAL;}
0[x|X][0-9A-F]* {yylval.num=convertInt(yytext,16);return HEX_LITERAL;}
\"[^\n\"]*\" {yylval.str=strdup(yytext);return STRING_LITERAL;}
{ID} {yylval.str=strdup(yytext);return IDENTIFIER;}

.|\n
%%
