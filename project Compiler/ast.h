#ifndef AST_H
#define AST_H
#include "definitions.h"
#define MAX_SIZE 100
#define CODE_SIZE 1000



typedef struct tok
{
	int token;
}tok;

typedef struct ir_vars
{
	char* var;
	char* code;
}ir_vars;

typedef struct symbol_node
{
	int symbol_type;//VAR OR PROC
	int type;//RETURN TYPE OR TYPE OF VAR
	int scope_lvl;
	int length_type;
	int num_of_params;
	int* param_types;
	struct symbol_node* next;
}symbol_node;

typedef struct symbol_ref
{
	int token;
	char* id;
	int line_num;
	struct expr* length;
	struct symbol_node* symbol;
	ir_vars* irv;
}symbol_ref;


typedef struct program
{
	int token;
	struct proc_list* proc_l_;
	ir_vars* irv;
}program;


typedef struct proc_list{
	int i;
	struct procedure_node* list[MAX_SIZE];
}proc_list;



typedef struct procedure_node
{
	int token;
	struct symbol_ref* id;
	struct params_list* param_l;
	struct type* return_type;
	struct body_node* body;
	ir_vars* irv;
}procedure_node;


typedef struct params_list
{
	int i;
	struct params* list[MAX_SIZE];
}params_list;


typedef struct symbol_list
{
	int i;
	struct symbol_ref* list[MAX_SIZE];

}symbol_list;


typedef struct params
{
	int token;
	struct type* type_;
	struct symbol_list* param_list;
}params;





typedef struct body_node
{
	int token;
	struct proc_list* proc_l;
	struct var_dec_list* var_dec_l;
	struct stmt_list* stmts_;//
	struct ret_stmt* ret_stmt;
	ir_vars* irv;
}body_node;


typedef struct var_dec_list{
	int i;
	struct var_decs* list[MAX_SIZE];

}var_dec_list;

typedef struct var_decs
{
	int token;
	struct type* var_type;
	struct symbol_list* var_list;
}var_decs;




typedef struct assign
{
	int token;
	struct symbol_ref* lvalue;
	void* rvalue;//expr like op,relop and all that...
	ir_vars* irv;
}assign;




typedef struct stmt
{
	int token;
	void* stmt_; 
	ir_vars* irv;

}stmt;



typedef struct stmt_list
{
	int i;
	struct stmt* list[MAX_SIZE];
}stmt_list;


typedef struct code_block
{
	int token;
	struct var_dec_list* var_decs_l;
	struct stmt_list* stmts; 
	ir_vars* irv;
	char* next;
}code_block;

typedef struct fn_call
{
	int token;
	struct symbol_ref* id;
	struct expr_list* expr_l;
	ir_vars* irv;
}fn_call;


typedef struct expr_list
{
	int i;
	struct expr* list[MAX_SIZE];
}expr_list;

typedef struct if_node
{
	int token;
	int line_num;
	struct expr * cond;
	struct code_block * if_block;
	ir_vars* irv;
	char* begin;
	char* after;

}if_node;

typedef struct if_else_node
{
	int token;
	int line_num;
	struct expr * cond;
	struct code_block * if_block;
	struct code_block * else_block;
	ir_vars* irv;
	char* begin;
	char* after;
	
}if_else_node;


typedef struct for_node
{
	int token;
	int line_num;
	struct expr * cond;
	struct code_block * for_block;
	ir_vars* irv;
	char* begin;
	char* after;
}for_node;

//
typedef struct while_node
{
	int token;
	int line_num;
	struct expr * cond;
	struct code_block * while_block;
	ir_vars* irv;
	char* begin;
	char* after;
}while_node;


typedef struct ret_stmt
{
	int token;
	struct expr* exp;
	ir_vars* irv;

}ret_stmt;

typedef struct expr
{
	int token;
	ir_vars* irv;
	void* exp;
	char* trueLabel;
	char* falseLabel;	
}expr;

//
typedef struct rel
{

	int token;
	int op_;
	int line_num;
	struct expr * left;
	struct expr * right;
	ir_vars* irv;
	char* trueLabel;
	char* falseLabel;

}rel;

//
typedef struct op
{	
	int token;
	int op_;
	int line_num;
	struct expr * left;
	struct expr * right;	
	ir_vars* irv;



}op;




typedef struct type
{
	int token;
	int type_;
	int length;

}type;


typedef struct lit
{
	int token;
	void* value;
	ir_vars* irv;
}lit;

//
typedef struct lit_integer
{
	int token;
	int value;
	ir_vars* irv;
}lit_integer;

//
//
typedef struct lit_real
{
	int token;
	int value;
	ir_vars* irv;
}lit_real;

//
typedef struct lit_char
{
	int token;
	char value;
	ir_vars* irv;
}lit_char;

//
typedef struct lit_string
{
	int token;
	char* value;
	ir_vars* irv;
}lit_string;

//
typedef struct lit_boolean
{
	int token;
	int value;
	ir_vars* irv;
}lit_boolean;


typedef struct lit_null
{
	int token;
	ir_vars* irv;
}lit_null;










void * emalloc(size_t size);



#endif
