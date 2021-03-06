#include "print_ast.h"
#include "symtab.h"



void print_ast(void* ast)
{
	int token;
	int i;


	if(ast == NULL)
		return;

	program* program_= (program*)ast;
	procedure_node* proc_ = (procedure_node*)ast;
	params* params_ = (params*)ast;
	body_node* body_ = (body_node*)ast;
	var_decs* var_decs_ = (var_decs*)ast;
	assign* assign_ = (assign*)ast;
	stmt* stmt_ = (stmt*)ast;
	code_block* block_ = (code_block*)ast;
	fn_call* call_ = (fn_call*)ast;
	if_node* if_ = (if_node*)ast;
	if_else_node* if_else_ = (if_else_node*)ast;
	for_node* for_ = (for_node*)ast;
	while_node* while_ = (while_node*)ast;
	ret_stmt* ret_ = (ret_stmt*)ast;
	expr* expr_ = (expr*)ast;
	rel* relop = (rel*)ast;
	op* op_ = (op*)ast;
	type* type_  = (type*)ast;
	lit* lit_ = (lit*)ast;
	lit_integer* lit_i = (lit_integer*)ast;
	lit_char* lit_c = (lit_char*)ast;
	lit_string* lit_s = (lit_string*)ast;
	lit_boolean* lit_b = (lit_boolean*)ast;
	lit_null* lit_n = (lit_null*)ast;
	symbol_ref* ref = (symbol_ref*)ast;
	//for semantics
	symbol_node* symbol;


	token = program_->token;
	switch(token){

		case PROGRAM_:
			printf("(CODE:\n");
			for(i = program_->proc_l_->i;i>0;i--)
				print_ast(program_->proc_l_->list[i - 1]);

			break;

		case PROCEDURE_:

			printf("\t(FUNC\n");
			print_ast(proc_->id);

			printf("(");
			for(i = proc_->param_l->i;i>0;i--)
				print_ast(proc_->param_l->list[i - 1]);
			printf(")");
			printf("\tRETURN %s",proc_->return_type);
			print_ast(proc_->return_type);
			printf("\n");
			print_ast(proc_->body);
			printf("\n");
			break;

		case IDENT_:
			printf(" %s ",ref->id);
			if(ref->length != NULL){
				printf("[ ");
				print_ast(ref->length);
				printf(" ]");
			}	
			break;
			

		case PARAMS_:
			printf("\n\tARGS(");
			for(i=params_->param_list->i;i>0;i--)
			{
				print_ast(params_->param_list->list[i - 1]);
				printf(",");
			}
			printf("\b)");
			print_ast(params_->type_);
			break;

		case TYPE_:
			printf("%d",type_->type_);
			if(type_->length != 0)
				printf("[%d]",type_->length);
			break;


		case BODY_:
			printf("\t(BODY",type_->type_);
			for(i = body_->proc_l->i;i>0;i--)
				print_ast(body_->proc_l->list[i - 1]);
			printf("\n\t\t(BLOCK");

			for(i = body_->var_dec_l->i;i>0;i--){
				printf("\t");
				print_ast(body_->var_dec_l->list[i - 1]);
				printf("\n");	
			}

			for(i = body_->stmts_->i;i>0;i--)
				print_ast(body_->stmts_->list[i - 1]);

			printf("\n)");
			print_ast(body_->ret_stmt);
			break;

		case VAR_DECS_:
			printf("type");
			print_ast(var_decs_->var_type);
			for(i = var_decs_->var_list->i;i>0;i--){
				print_ast(var_decs_->var_list->list[i -1]);
				printf(",");	
			}
			break;

		case STMT_:
			print_ast(stmt_->stmt_);
			printf("\n");
			break;

		case ASSIGN_:
			printf("\t\t");
			print_ast(assign_->lvalue);
			printf("( = ");
			print_ast(assign_->rvalue);
			printf(")");
			break;

		case ASSIGN_DER_:
			printf("\t\t");
			print_ast(assign_->lvalue);
			printf(" )");
			printf(" = ");
			print_ast(assign_->rvalue);
			break;

		case EXPR_:
			print_ast(expr_->exp);
			break;

		case LITERAL_:
			print_ast(lit_->value);
			break;

		case INTEGER_LITERAL_:
			printf(" %d ",lit_i->value);
			break;

		case CHAR_LITERAL_:
			printf(" %c ",lit_c->value);
			break;

		case STRING_LITERAL_:
			printf(" %s ",lit_s->value);
			break;

		case BOOLEAN_LITERAL_:
			printf(" (BOOL %d ) ",lit_b->value);
			break;

		case NULL_LITERAL_:
			printf(" (NULLS) ");
			break;

		case RELOP_:
			switch(relop->op_){
				case AND_:
					printf("&& ");
					print_ast(relop->left);
					print_ast(relop->right);
					break;
				case OR_:
					printf("|| ");
					print_ast(relop->left);
					print_ast(relop->right);					
					break;
				case EQ_:
					printf("== ");
					print_ast(relop->left);
					print_ast(relop->right);					
					break;
				case NE_:
					printf("!= ");
					print_ast(relop->left);
					print_ast(relop->right);					
					break;
				case GE_:
					printf(">= ");
					print_ast(relop->left);
					print_ast(relop->right);					
					break;
				case GT_:
					printf("> ");
					print_ast(relop->left);
					print_ast(relop->right);					
					break;
				case LE_:
					printf("<= ");
					print_ast(relop->left);
					print_ast(relop->right);					
					break;
				case LT_:
					printf("< ");
					print_ast(relop->left);
					print_ast(relop->right);					
					break;
				case NOT_:
					printf("! ");
					print_ast(relop->left);
					print_ast(relop->right);					
					break;

			}
			break;

		case OP_:
			switch(op_->op_){
				case PLUS_:

					printf("+ ");
					print_ast(op_->left);
					print_ast(op_->right);
					break;
				case MINUS_:
					printf("- ");
					print_ast(op_->left);
					print_ast(op_->right);					
					break;
				case MULTI_:
					printf("* ");
					print_ast(op_->left);
					print_ast(op_->right);					
					break;
				case DIV_:
					printf("/ ");
					print_ast(op_->left);
					print_ast(op_->right);					
					break;
				case UMINUS_:
					printf("- ");
					print_ast(op_->left);
					break;
				case DEREFERENCE_:
					printf("DEREF ");
					print_ast(op_->left);					
					break;
				case ADDRESS_OF_:
					printf("ADDRESS ");
					print_ast(op_->left);					
					break;

				case ABS_:
					printf("|");
					print_ast(op_->left);
					printf("|");
					break;
				default: break;
			}
			break;

		case RET_STMT_:
			printf("\t(RET ");
			print_ast(ret_->exp);
			break;

		case FOR_:
			printf("\n\t(FOR ");
			print_ast(for_->cond);
			print_ast(for_->for_block);
			break;

		case WHILE_:
			printf("\n\t(WHILE ");
			print_ast(while_->cond);
			print_ast(while_->while_block);
			break;

		case IF_:
			printf("\n\t(IF ");
			print_ast(if_->cond);
			print_ast(if_->if_block);
			break;

		case IF_ELSE_:
			printf("\n\t(IF-EL");
			print_ast(if_else_->cond);
			print_ast(if_else_->if_block);
			printf("\n\tELSE ");
			print_ast(if_else_->else_block);			
			break;

		case CODE_BLOCK_:
			printf("\n\tBLOCK\n");

			for(i = block_->var_decs_l->i;i>0;i--){
				printf("\t");
				print_ast(block_->var_decs_l->list[i - 1]);
				printf("\n");	
			}

			for(i = block_->stmts->i;i>0;i--)
				print_ast(block_->stmts->list[i - 1]);

			printf("\n)\n");
			break;

		case FN_CALL_:
			print_ast(call_->id);
			printf("\t( ");
			for(i = call_->expr_l->i;i>0;i--){
				print_ast(call_->expr_l->list[i - 1]);
				printf(" , ");
			}
			printf(" )\n");

			break;



		

		default: printf("\nERROR - NO SUCH CASE\n");

	}
}
