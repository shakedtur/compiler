%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ast.h"
#include "print_ast.h"
#include "symtab.h"

void yyerror(const char *c);

program* ast;

%}


%union{
	char ch;
	char* str;
	int num;
	symbol_node* symbol;
	symbol_ref* ref;
	program* p;
	proc_list* pro_l;
	procedure_node* proc;
	params_list* params_l;
	symbol_list* symbol_l;
	params* param;
	body_node* body;
	var_dec_list* var_dec_l;
	var_decs* var_dec;
	assign* assign_;
	stmt* stmt_;
	stmt_list* stmt_l;
	code_block* block;
	fn_call* call;
	expr_list* expr_l;
	if_node* if_;
	if_else_node* if_else_;
	for_node* for_;
	while_node* while_;
	ret_stmt* ret;
	expr* exp;
	type* type_;
	lit* l;
	lit_integer* lit_i;
	lit_string* lit_s;
	lit_char* lit_c;
	lit_boolean* lit_b;
	lit_null* lit_n;					
	
}

%token  NULL_LITERAL KEY_PROCEDURE KEY_VAR KEY_CHARPTR KEY_INTPTR KEY_STRING KEY_INTEGER KEY_BOOLEAN KEY_CHAR KEY_ELSE KEY_IF KEY_RETURN KEY_FOR KEY_WHILE OP_AND OP_EQ OP_GE OP_LE OP_NE OP_OR OP_NE STRING_LITERAL IDENTIFIER

%token  CHAR_LITERAL COMMA COLON DOT SINGLE_QUOTE QUOTE SQ_BRA_C SQ_BRA_O PARAN_C PARAN_O SEMICOLON BRA_C BRA_O OP_DEREFERENCE OP_ADDRESS_OF OP_MULTI OP_PLUS OP_NOT OP_MINUS OP_LT OP_GT ASSIGN OP_DIV OP_ABS

%token  TRUE_LITERAL FALSE_LITERAL INTEGER_LITERAL HEX_LITERAL  





%left COMMA
%right ASSIGN
%left OP_OR
%left OP_AND
%left OP_EQ OP_NE
%left OP_GE OP_GT OP_LE OP_LT
%left OP_MINUS OP_PLUS
%left OP_DIV OP_MULTI
%left OP_NOT OP_DEREFERENCE OP_ADDRESS_OF 

%type <str> IDENTIFIER NULL_LITERAL STRING_LITERAL
%type <ch> CHAR_LITERAL
%type <num> INTEGER_LITERAL HEX_LITERAL

%type <p> PROGRAM
%type <pro_l> PROCEDURES
%type <proc> PROCEDURE
%type <ref> IDENT IDENTARR





%start PROGRAM





%type <p> PROGRAM
%type <pro_l> PROCEDURES
%type <proc> PROCEDURE
%type <ref> IDENT IDENTARR
%type <params_l> PARAM_L
%type <param> SPARAMS
%type <symbol_l> PARAMS
%type <body> BODY
%type <var_dec_l> VAR_DECS
%type <var_dec> VAR_DEC
%type <stmt_l> STMTS
%type <stmt_> STMT
%type <assign_> ASSIGNMENT
%type <block> CODE_BLOCK
%type <call> FN_CALL
%type <expr_l> EXPR_LIST
%type <if_> IF_STMT
%type <if_else_> IF_ELSE_STMT
%type <for_> FOR_STMT
%type <while_> WHILE_STMT
%type <ret> RET_STMT
%type <exp> EXPR
%type <type_> TYPE ARTYPE
%type <l> LITERAL
%type <lit_i> LITERAL_NUM
%type <lit_s> LITERAL_STRING
%type <lit_c> LITERAL_CHAR
%type <lit_b> LITERAL_BOOLEAN



%% 


PROGRAM	: PROCEDURES {printf("Syntax and Parsing: ok \n"); ast = make_program($1); }
		;

PROCEDURES : PROCEDURE PROCEDURES {$$ = $2;$2->list[$2->i++] = $1;}
		   | {$$ = make_proc_list();}
		   ;

PROCEDURE : KEY_PROCEDURE IDENT PARAN_O PARAM_L PARAN_C KEY_RETURN TYPE BRA_O BODY BRA_C {$$ = make_procedure_node($2,$4,$7,$9);}
		  ;		


IDENT : IDENTIFIER {$$ = make_symbol_ref($1,yylineno,NULL);}
	  ;

IDENTARR : IDENTIFIER SQ_BRA_O EXPR SQ_BRA_C {$$ = make_symbol_ref($1,yylineno,$3);}

PARAM_L : SPARAMS {$$ = make_params_list();
				   $$->list[$$->i++] = $1;}
		| SPARAMS SEMICOLON PARAM_L {$$ = $3;
								  	 $3->list[$3->i++] = $1;}
		| {$$ = make_params_list();}
		;

SPARAMS : PARAMS COLON TYPE {$$ = make_params($3,$1);}
		;

PARAMS : IDENT COMMA PARAMS  {$$ = $3;
							  $3->list[$3->i++] = $1;}
	   | IDENT {$$ =  make_symbol_list();
	   	 		$$->list[$$->i++] = $1;}
	   ;
 
BODY : PROCEDURES VAR_DECS STMTS RET_STMT {$$ = make_body_node($1,$2,$3,$4);} 
	 ;
	 
VAR_DECS : VAR_DEC VAR_DECS {$$ = $2; $2->list[$2->i++] = $1;}
		 | {$$ = make_var_dec_list();}
		 ;

VAR_DEC : KEY_VAR PARAMS COLON ARTYPE SEMICOLON {$$ = make_var_decs($4,$2);}
		;


STMTS : STMT STMTS {$$ = $2;
					$2->list[$2->i++] = $1;}
	  | {$$ = make_stmt_list();}
	  ;

STMT : ASSIGNMENT {$$ = make_stmt($1);}
	 | IF_STMT  {$$ = make_stmt($1);}
	 | IF_ELSE_STMT  {$$ = make_stmt($1);}
	 | FOR_STMT {$$ = make_stmt($1);}
	 | WHILE_STMT  {$$ = make_stmt($1);}
	 | CODE_BLOCK  {$$ = make_stmt($1);}
	 ;

ASSIGNMENT : IDENT ASSIGN EXPR SEMICOLON {$$ = make_assign(ASSIGN_,$1,$3);}
		   | IDENTARR ASSIGN EXPR SEMICOLON  {$$ = make_assign(ASSIGN_,$1,$3);}
		   | OP_DEREFERENCE IDENT ASSIGN EXPR SEMICOLON {$$ = make_assign(ASSIGN_DER_,$2,$4);}
		   | IDENT ASSIGN FN_CALL {$$ = make_assign(ASSIGN_,$1,$3);}
		   | IDENTARR ASSIGN FN_CALL {$$ = make_assign(ASSIGN_,$1,$3);}
		   ;

CODE_BLOCK : BRA_O VAR_DECS STMTS BRA_C {$$ = make_code_block($2,$3);}
		  ;


FN_CALL : IDENT PARAN_O EXPR_LIST PARAN_C SEMICOLON {$$ = make_fn_call($1,$3);}
		;

EXPR_LIST : EXPR COMMA EXPR_LIST {$$ = $3;
	  							  $3->list[$3->i++] = $1;}
		  | EXPR {$$ = make_expr_list();
		  		  $$->list[$$->i++] = $1; }
		  | {$$ = make_expr_list();}
		  ;

IF_ELSE_STMT : KEY_IF PARAN_O EXPR PARAN_C CODE_BLOCK KEY_ELSE CODE_BLOCK  {$$ = make_if_else_node(yylineno,$3,$5,$7);} 
			 ;

IF_STMT :  KEY_IF PARAN_O EXPR PARAN_C CODE_BLOCK {$$ = make_if_node(yylineno,$3,$5);} 
		;

FOR_STMT : KEY_FOR PARAN_O EXPR PARAN_C CODE_BLOCK {$$=make_for_node(yylineno,$3,$5);}
		;

WHILE_STMT : KEY_WHILE PARAN_O EXPR PARAN_C CODE_BLOCK  {$$ = make_while_node(yylineno,$3,$5);} 
		   ;

RET_STMT : KEY_RETURN EXPR SEMICOLON {$$ = make_ret_stmt($2);}
		 ;

EXPR : EXPR OP_PLUS EXPR {$$ = make_expr(make_op(PLUS_,yylineno,$1,$3));}
	 | EXPR OP_MINUS EXPR {$$ = make_expr(make_op(MINUS_,yylineno,$1,$3));}
	 | EXPR OP_MULTI EXPR {$$ = make_expr(make_op(MULTI_,yylineno,$1,$3));}
	 | EXPR OP_DIV EXPR {$$ = make_expr(make_op(DIV_,yylineno,$1,$3));}
	 | EXPR OP_AND EXPR {$$ = make_expr(make_rel(AND_,yylineno,$1,$3));}
	 | EXPR OP_OR EXPR {$$ = make_expr(make_rel(OR_,yylineno,$1,$3));}
	 | EXPR OP_EQ EXPR {$$ = make_expr(make_rel(EQ_,yylineno,$1,$3));}
	 | EXPR OP_NE EXPR {$$ = make_expr(make_rel(NE_,yylineno,$1,$3));}
	 | EXPR OP_GE EXPR {$$ = make_expr(make_rel(GE_,yylineno,$1,$3));}
	 | EXPR OP_GT EXPR {$$ = make_expr(make_rel(GT_,yylineno,$1,$3));}
	 | EXPR OP_LE EXPR {$$ = make_expr(make_rel(LE_,yylineno,$1,$3));}
	 | EXPR OP_LT EXPR {$$ = make_expr(make_rel(LT_,yylineno,$1,$3));}
	 | OP_NOT EXPR {$$ = make_expr(make_rel(NOT_,yylineno,$2,NULL));}
	 | OP_MINUS EXPR {$$ = make_expr(make_op(UMINUS_,yylineno,$2,NULL));}
	 | OP_DEREFERENCE EXPR {$$ = make_expr(make_op(DEREFERENCE_,yylineno,$2,NULL));}
	 | OP_ADDRESS_OF EXPR  {$$ = make_expr(make_op(ADDRESS_OF_,yylineno,$2,NULL));}
	 | OP_ABS EXPR OP_ABS {$$ = make_expr(make_op(ABS_,yylineno,$2,NULL)); }
	 | IDENT {$$ = make_expr($1);}
	 | PARAN_O EXPR PARAN_C {$$ = $2;}
	 | IDENTARR {$$ = make_expr($1);}
	 | LITERAL {$$ = make_expr($1);}
	 ;



TYPE : KEY_CHARPTR { $$ = make_type(CHARPTR_,0);}
	 | KEY_INTPTR { $$ = make_type(INTPTR_,0);}
	 | KEY_INTEGER { $$ = make_type(INTEGER_,0);}
	 | KEY_BOOLEAN  { $$ = make_type(BOOLEAN_,0);}
	 | KEY_CHAR { $$ = make_type(CHAR_,0);}
	 ;

ARTYPE : TYPE 
	   | KEY_STRING SQ_BRA_O LITERAL_NUM SQ_BRA_C { $$ = make_type(STRING_,$3->value);}
	   ;


LITERAL : LITERAL_STRING { $$ = make_lit($1);}
		| LITERAL_NUM { $$ = make_lit($1);}
		| LITERAL_CHAR { $$ = make_lit($1);}
		| LITERAL_BOOLEAN { $$ = make_lit($1);}
		| NULL_LITERAL { $$ = make_lit(make_lit_null());}
		;

LITERAL_STRING : STRING_LITERAL { $$ = make_lit_string($1);}
			   ;

LITERAL_CHAR : CHAR_LITERAL { $$ = make_lit_char($1);}
			 ;

LITERAL_NUM : INTEGER_LITERAL { $$ = make_lit_integer($1);}
			| HEX_LITERAL   { $$ = make_lit_integer($1);}
			;
	
LITERAL_BOOLEAN : TRUE_LITERAL { $$ = make_lit_boolean(1);}
				| FALSE_LITERAL { $$ = make_lit_boolean(0);}
				;

%%

int currentScope;

#include "lex.yy.c"
#include "ast.c"
#include "print_ast.c"
#include "symtab.c"
#include "semantics.c"
#include "ir.c"

int main(){
	symtable = make_symtable(HASHTABLE_SIZE);
	int i,max;
	currentScope = 0;
	yyparse();

	//print_ast(ast);

	checkSemantics(ast);

	//print_table(symtable);

	tacGeneration(ast);
}


void yyerror(const char *c){
	fprintf(stderr,"line %d: %s\n",yylineno - 1,c);
	
}





