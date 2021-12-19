#include "ast.h"

void * emalloc(size_t size)
{
	void * pointer = malloc(size);
	if(!pointer)
		printf("ERROR - NOT ENOUGH MEMORY");

	return pointer;
}


char* getStr(char* str)
{
	char* new_str = emalloc(sizeof(str)+1);
	strcpy(new_str,str);
	return new_str;
}

ir_vars* make_ir_vars(){
	ir_vars* ir = emalloc(sizeof(ir_vars));
	ir->var = emalloc(sizeof(char)*CODE_SIZE);
	ir->code = emalloc(sizeof(char)*CODE_SIZE);
	return ir;
}

lit_boolean* make_lit_boolean(int value)
{
	lit_boolean* lit = emalloc(sizeof(lit_boolean));
	lit->token = BOOLEAN_LITERAL_;
	lit->value = value;
	lit->irv = make_ir_vars();

	return lit;
}

lit_string* make_lit_string(char* value)
{
	lit_string* lit = emalloc(sizeof(lit_string));
	lit->token = STRING_LITERAL_;
	lit->value = getStr(value);
	lit->irv = make_ir_vars();

	return lit;
}

lit_char* make_lit_char(char value)
{
	lit_char* lit = emalloc(sizeof(lit_char));
	lit->token = CHAR_LITERAL_;
	lit->value = value;
	lit->irv = make_ir_vars();

	return lit;
}

lit_integer* make_lit_integer(int value)
{
	lit_integer* lit = emalloc(sizeof(lit_integer));
	lit->token = INTEGER_LITERAL_;
	lit->value = value;
	lit->irv = make_ir_vars();

	return lit;
}

lit_null* make_lit_null()
{
	lit_null* lit = emalloc(sizeof(lit_null));
	lit->token = NULL_LITERAL_;
	lit->irv = make_ir_vars();
	return lit;
}



rel * make_rel(int op_,int ln,expr * left,expr* right)
{
	rel * node = emalloc(sizeof(rel));
	node->token = RELOP_;
	node->op_ = op_;
	node->left = left;
	node->right = right;
	node->line_num = ln;
	node->irv = make_ir_vars();
	node->trueLabel = emalloc(9);
	node->falseLabel = emalloc(9);
	return node;
	
}


op * make_op(int op_,int ln,expr * left,expr * right)
{
	op * node = emalloc(sizeof(op));
	node->token = OP_;
	node->op_ = op_;
	node->left = left;
	node->right = right;
	node->line_num = ln;
	node->irv = make_ir_vars();
	return node;
	
}


expr* make_expr(void* exp)
{
	expr* e = emalloc(sizeof(expr));
	e->token = EXPR_;
	e->exp = exp;
	e->irv = make_ir_vars();
	e->trueLabel = emalloc(9);
	e->falseLabel = emalloc(9);	
	return e;
}

ret_stmt* make_ret_stmt(expr* exp)
{
	ret_stmt* ret = emalloc(sizeof(ret_stmt));
	ret->token = RET_STMT_;
	ret->exp = exp;
	ret->irv = make_ir_vars();
	return ret;
}



if_node * make_if_node(int ln,expr * cond,code_block * if_block)
{
	if_node * node = emalloc(sizeof(if_node));
	node->token = IF_;
	node->line_num = ln;
	node->cond = cond;
	node->if_block = if_block;

	node->irv = make_ir_vars();
	node->begin = emalloc(9);
	node->after = emalloc(9);
	return node;
}

if_else_node * make_if_else_node(int ln,expr * cond,code_block * if_block,code_block* else_block)
{
	if_else_node * node = emalloc(sizeof(if_else_node));
	node->token = IF_ELSE_;
	node->line_num = ln;
	node->cond = cond;
	node->if_block = if_block;
	node->else_block = else_block;
	node->irv = make_ir_vars();
	node->begin = emalloc(9);
	node->after = emalloc(9);
	return node;
}

for_node * make_for_node(int ln,expr * cond,code_block * for_block)
{
	for_node * node = emalloc(sizeof(for_node));
	node->token = FOR_;
	node->line_num = ln;
	node->cond = cond;
	node->for_block = for_block;
	node->irv = make_ir_vars();
	node->begin = emalloc(9);
	node->after = emalloc(9);
	return node;
}


while_node * make_while_node(int ln,expr * cond,code_block * while_block)
{
	while_node * node = emalloc(sizeof(while_node));
	node->token = WHILE_;
	node->line_num = ln;
	node->cond = cond;
	node->while_block = while_block;
	node->irv = make_ir_vars();
	node->begin = emalloc(9);
	node->after = emalloc(9);
	return node;
}


expr_list* make_expr_list()
{
	expr_list* list = emalloc(sizeof(expr_list));
	list->i=0;

	return list;
}

fn_call* make_fn_call(symbol_ref* id,expr_list* list)
{
	fn_call* call = emalloc(sizeof(fn_call));
	call->token = FN_CALL_;
	call->id = id;
	call->expr_l = list;
	call->irv = make_ir_vars();
	return call;
}

code_block* make_code_block(var_dec_list* dec_list,stmt_list* stmts)
{
	code_block* block = emalloc(sizeof(code_block));
	block->token = CODE_BLOCK_;
	block->var_decs_l = dec_list;
	block->stmts = stmts;
	block->irv = make_ir_vars();
	block->next = emalloc(9);
	return block;
}

stmt_list* make_stmt_list()
{
	stmt_list* list = emalloc(sizeof(stmt_list));
	list->i=0;

	return list;
}

stmt* make_stmt(void* stmt_)
{
	stmt* s = emalloc(sizeof(stmt));
	s->token = STMT_;
	s->stmt_ = stmt_;
	s->irv = make_ir_vars();
	return s;
}


assign* make_assign(int token,symbol_ref* lvalue,void* rvalue)
{
	assign* a = emalloc(sizeof(assign));
	a->token = token;
	a->lvalue = lvalue;
	a->rvalue = rvalue;
	a->irv = make_ir_vars();
	return a;
}


var_decs* make_var_decs(void* type_,symbol_list* list)
{
	var_decs* decs = emalloc(sizeof(var_decs));
	decs->token = VAR_DECS_;
	decs->var_type = type_;
	decs->var_list = list;
	return decs;
}

var_dec_list* make_var_dec_list()
{
	var_dec_list* list = emalloc(sizeof(var_dec_list));
	list->i=0;

	return list;
}

body_node* make_body_node(proc_list* proc_l,var_dec_list* var_dec_l,stmt_list* stmts_,ret_stmt* ret_stmt_)
{
	body_node* body = emalloc(sizeof(body_node));
	body->token = BODY_;
	body->proc_l = proc_l;
	body->var_dec_l = var_dec_l;
	body->stmts_ = stmts_;
	body->ret_stmt = ret_stmt_;
	body->irv = make_ir_vars();
	return body;
}

params* make_params(type* type_,symbol_list* param_list)
{
	params* p = emalloc(sizeof(params));
	p->token = PARAMS_;
	p->type_ = type_;
	p->param_list = param_list;
	return p;

}



symbol_list* make_symbol_list()
{
	symbol_list* list = emalloc(sizeof(symbol_list));
	list->i=0;

	return list;
}

params_list* make_params_list()
{
	params_list* list = emalloc(sizeof(params_list));
	list->i=0;

	return list;
}


procedure_node* make_procedure_node(symbol_ref* id,params_list* param_l,type* return_type,body_node* body){
	procedure_node* proc = emalloc(sizeof(procedure_node));
	proc->token = PROCEDURE_;
	proc->id = id;
	proc->param_l =param_l;
	proc->return_type = return_type;
	proc->body = body;
	proc->irv = make_ir_vars();

	return proc;
}


proc_list* make_proc_list()
{
	proc_list* list = emalloc(sizeof(proc_list));
	list->i=0;

	return list;
}

program* make_program(proc_list* proc_l_)
{
	program* p = emalloc(sizeof(program));
	p->token = PROGRAM_;
	p->proc_l_ = proc_l_;
	p->irv = make_ir_vars();
	return p;
}


type* make_type(int type_,int length)
{
	type* t = emalloc(sizeof(type));
	t->token = TYPE_;
	t->type_=type_;
	t->length = length;
	return t;
}


lit* make_lit(void* value)
{
	lit* l = emalloc(sizeof(lit));
	l->token = LITERAL_;
	l->value = value;
	l->irv = make_ir_vars();
	return l;
}


symbol_node* make_symbol(int s_type){
	symbol_node * symbol = (symbol_node*)emalloc(sizeof(symbol_node));
	symbol->symbol_type = s_type;
	symbol->type = EMPTY_;
	symbol->scope_lvl = currentScope;
	symbol->param_types = NULL;
	symbol->num_of_params = 0;
	symbol->length_type = -1;

	symbol->next = NULL;
	return symbol;
}



symbol_ref * make_symbol_ref (char * ident,int line,expr* length)
{
	symbol_ref * node = emalloc(sizeof(symbol_ref));	
	node->token = IDENT_;
	node->id = getStr(ident);
	node->line_num = line;
	node->length = length;
	node->symbol = NULL;
	node->irv = make_ir_vars();
	return node;
}

