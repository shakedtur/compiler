
%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "node.h"

int yylex(void);
void yyerror(char *);
extern int yylineno;

int isSimple(node* head);
node* mkNode(char *value,int count,...);
node* mkParent(char* value, node* child);
void printTree(node* ast, int indent, int s, int l);
%}



%union{
	char *value;
	node *next;
};

%token <value> INTEGER MAIN VOID CHAR CHAR_LITERAL CHARPTR  BOOLEAN REAL BOOLEAN_LITERAL
%token <value> VAR FUNCTION RETURN IDENTIFIER INTPTR DECIMAL_NUM REALPTR MAIN HEX_NUM NULL_LITERAL REAL_NUM 
%token <value> AND DIV EQUALS GE GREATER LE MINUS NOT NE OR PLUS MULTI ADDRESS_OP FUNC_ID PUT
%token <value> DEREFERENCE STRING_ARR IF ELSE WHILE STRING LESS FOR VOID DO PLUS_PLUS MINUS_MINUS

/* priority of operators*/
%left OR
%left AND NOT
%left EQUALS NOT_EQ PUT
%left GREATER GREATER_EQ LESS_EQ LESS
%left ADDRESS_OP
%left PLUS MINUS
%left MUL DIV
%right UNARY


%type <next> code function void_main exp identifiers 
%type <next> param_list param_list_new func_body statement assignment lhs  function_call
%type <next> exp expressions expressions_new if if_else while do_while statements statement code_block do_while for inits variable_declaration statements_ne
%type <next> variable_declarations variable_declarations_ne functions var_identifier void_func update declare
%type <value> const_value integer_literal


/* Rules*/
%%

code :	functions void_main { printTree(mkNode("CODE",2,mkParent("FUNC",$1),$2),0,0,1);
	printf("\n");}
	| void_main {printTree(mkNode("CODE",1,$1),0,0,1);
	printf("\n");}

void_main : VOID MAIN '(' ')' '{' func_body '}' {$$=mkNode("MAIN",1,$6);};

functions: function {$$=$1;}
			| functions function {$$=mkNode("",2,$1,$2);};

function: type IDENTIFIER '(' param_list ')' '{' func_body RETURN exp ';' '}' {$$=mkNode($2,3,mkParent("ARGS",$4),$7,mkParent("RETURN",$9));}
			|void_func;

void_func: VOID IDENTIFIER '(' param_list ')' '{' func_body RETURN ';' '}' {$$=mkNode($2,3,mkParent("ARGS",$4),$7,mkNode("RETURN",0));}
			|VOID IDENTIFIER '(' param_list ')' '{' '}' {$$=mkNode($2,2,mkNode("EMPTY FUNCTION",0));};

type :
	CHAR
	|	INTEGER
	|	REAL	
	|	BOOLEAN
	|	CHARPTR
	|	INTPTR
	|	REALPTR;


param_list: {$$=NULL;}
		| param_list_new {$$=$1;};

param_list_new: declare {$$=$1;}
		|param_list_new ',' declare {$$=mkNode("",2,$1,$3);};

declare: type IDENTIFIER {$$ = mkNode($2,0);};

identifiers: IDENTIFIER { $$ = mkNode($1,0);} 
		|identifiers ',' IDENTIFIER {$$ = mkNode("",2,$1,mkNode($3,0));};
var_identifier: type identifiers {$$ = $2;}
		|STRING identifiers '[' integer_literal ']' {$$ = $2;};

func_body: variable_declarations statements {$$ = mkNode("BODY",2,mkParent("VAR",$1),$2);}
		|functions variable_declarations statements {$$ = mkNode("BODY",3,$1,mkParent("VAR",$2),$3);};





const_value:	CHAR_LITERAL
		|HEX_NUM
		|DECIMAL_NUM
		|REAL_NUM
		|BOOLEAN_LITERAL
		|NULL_LITERAL ;
			
integer_literal:
		|DECIMAL_NUM
		|REAL_NUM ;

exp	:	IDENTIFIER	{ $$ = mkNode ($1,0);}
	|	IDENTIFIER '[' exp ']' {$$ = mkNode($1,3,mkNode("[",0),$3,mkNode("]",0));}
	|	const_value {$$=mkNode($1,0);}
	|	'('	exp	')'	{ $$ = $2;}
	|	'|' exp '|' {$$ = $2;}
	|	exp	AND 	exp	{ $$ = mkNode ("&&", 2,$1,$3);}
	|	exp	DIV	exp	{ $$ = mkNode ("/", 2,$1,$3);}
	|	exp	PUT	exp	{ $$ = mkNode ("=", 2,$1,$3);}
	|	exp	EQUALS	exp	{ $$ = mkNode ("==", 2,$1,$3);}
	|	exp	GREATER exp	{ $$ = mkNode (">", 2,$1,$3);}
	|	exp	GREATER_EQ	exp { $$ = mkNode (">=", 2,$1,$3);}
	|	exp	LESS 	exp	{ $$ = mkNode ("<", 2,$1,$3);}
	|	exp	LESS_EQ	exp	{ $$ = mkNode (">=", 2,$1,$3);}
	|	exp	MINUS	exp	{ $$ = mkNode ("-", 2,$1,$3);}
	|	exp	NOT	exp	{ $$ = mkNode ("!", 2,$1,$3);}
	|	exp	NOT_EQ	exp	{ $$ = mkNode ("!=", 2,$1,$3);}
	|	exp	OR 	exp	{ $$ = mkNode("||",2,$1,$3);}
	| 	exp	PLUS	exp	{ $$ = mkNode("+",2,$1,$3);}
	|	exp	MUL	exp	{ $$ = mkNode("*",2,$1,$3);}
	|	exp	ADDRESS_OP	exp	{ $$ = mkNode ("&", 2,$1,$3);}
	/*|	NUM {$$=mkNode(yytext,0,NULL,NULL);};	*/
	;



statement: assignment
	| function_call
	| if
	| if_else
	| while
	| do_while
	| for
	| '{' code_block '}' { $$ = $2 ;} ;					

function_call: lhs '=' IDENTIFIER '(' expressions ')' ';' {$$ = mkNode("=",3,$1,mkNode($3,0),mkParent("ARGS",$5));}
	| IDENTIFIER '(' expressions ')' ';' {$$ = mkNode($1,2,mkNode(" ",0),mkParent("ARGS",$3)); } ;

expressions:   {$$ = NULL;}
	|	expressions_new {$$ = $1;} ;

expressions_new:	exp {$$ = $1;}
	|	expressions_new ',' exp {$$ = mkNode("",2,$1,$3);} ;

if: IF '(' exp ')' '{' code_block '}' {$$ = mkNode("if",2,$3,$6);};

if_else: IF '(' exp ')' '{' code_block '}' ELSE '{' code_block '}' {$$ = mkNode("IF",3,$3,$6,mkNode("ELSE",1,$10));};

while: WHILE '(' exp ')' '{' code_block '}'	{$$ = mkNode("WHILE",2,$3,$6);};

do_while: DO '{' code_block '}' WHILE '(' exp ')' ';' {$$ = mkNode("DO_WHILE",2,$3,$7);};

for: FOR '(' inits ';' exp ';' update ')' '{' code_block '}' {$$ = mkNode("FOR",4, $3, $5,$7,$10);};

inits: IDENTIFIER '=' DECIMAL_NUM { $$ = mkNode("INIT", 1, mkNode($1,0));};

assignment: lhs '=' exp ';' {$$ = mkNode("=",2,$1,$3);}
		|	lhs '=' STRING_ARR ';' {$$ = mkNode("=",2,$1,mkNode($3,0));};

lhs: IDENTIFIER {$$ = mkNode($1,0);}
	| '*' IDENTIFIER {$$ = mkNode("*",1,mkNode($2,0));}			
	| IDENTIFIER '[' exp ']' {$$ = mkNode($1,3,mkNode("[",0),$3,mkNode("]",0));};

code_block:	variable_declarations statements {$$ = mkNode("BLOCK",2,mkParent("VAR",$1),$2);};



variable_declaration: var_identifier ';' {$$ = $1;};
									
variable_declarations: {$$ = NULL;}
	| variable_declarations_ne {$$ = $1;};
							
							
variable_declarations_ne: variable_declaration {$$ = $1;}
	|	variable_declarations_ne variable_declaration {$$ = mkNode("",2,$1,$2);};

update: IDENTIFIER '=' exp { $$=mkNode("UPDATE",1,$3);};

statements: {$$=NULL;}
		|statements_ne {$$=$1;};

statements_ne: statement {$$=$1;}
		|statements_ne statement {$$=mkNode("",2,$1,$2);};


%%


int isSimple(node* head) 
{
	int i;
	if(head == NULL)
		return 0;
	if(head->count == 0)
		return 0;
	for(i = 0;i<head->count;i++)
		if(head->children[i]!= NULL && head->children[i]->count > 0)
			return 0;
	return 1;
}


node* mkNode(char *value, int count,...) 
{
    va_list ap;
    node *p;
    node **s;
    int i;
    int flag = 1;

    if ((p = (node*)malloc(sizeof(node))) == NULL)
        yyerror("out of memory");
	
    p->value = value;
    p->count = count;
	if(count != 0)
	{
		if ((s = (node**)malloc(count * sizeof(node*))) == NULL)
			yyerror("Memory error!");
		va_start(ap, count);
		for (i = 0; i < count; i++)
		{
			s[i] = va_arg(ap, node*);
			if(s[i] != NULL)
				flag = 0;
		}
		va_end(ap);
		p->children = s;
		if(flag)
			return NULL;
    }
	else
	{
		p->children = NULL;
	}
	return p;
}


node* mkParent(char* value, node* child)
{
	if(child == NULL)
		return NULL;
	if(child->value != "")
	{
		return mkNode(value,1,child);
	}
	child->value = value;
	return child;
}

void printTree(node* ast, int indent, int s, int l)
{
	int i = 0;
	int flag = 0;
	if(ast == NULL)
		return;
	if(ast->count > 0 && ast->value != "")
		printf("\n%*s( ",indent,"");
	if(!s && ast->count == 0)
		printf("\n%*s",indent,"");
	if(ast->value != "")	
	{
		printf("%s ",ast->value);
	}
	else
		indent--;
	for(i = 0; i < ast->count; i++)
	{
		if(ast->children[i] != NULL)
		{
			if(isSimple(ast) || ast->value == "" || ast->value == "ARGS" || ast->value == "VAR")
				s = 1;
			else	
				s = 0;
			if(l)
			{
				if(strlen(ast->value) == 0)
					l = 0; 
				printTree(ast->children[i],indent + strlen(ast->value)+1,s, l);
			}
			else
			{
				if(strlen(ast->value) != 0)
				{
					l = 1;
					printTree(ast->children[i],indent + strlen(ast->value)+1,s, l);
				}
				else
					printTree(ast->children[i],indent + 1,s, l);
			}
			if(ast->children[i]->count > 0)
				flag = 1;
		}
	}
	
	if(flag == 1 && ast->value != "" && ast->value != "ARGS" && ast->value != "VAR")
		printf("\n%*s%s",indent,"",")");
	else if ((ast->count > 0 && ast->value != "") || ast->value == "ARGS" || ast->value == "VAR")
		printf(")");
}

/*errors*/
void yyerror(char *s) {
	fprintf(stderr, "%s at line:%d\n", s, yylineno+1);
}
	
/*C user routines*/
int main(void){
	yyprase();
	return 0;
}
