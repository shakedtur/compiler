#include "ir.h"



char* freshVar(){
	char* str = malloc(5);
	sprintf(str,"t%d",global_var_num++);

	return str;
}

char* freshLabel(){
	char* str = malloc(10);
	sprintf(str,"L%d",global_line_num);

	return str;
}



ir_vars* tacGeneration(void* ast) {

	int type1, i;
	int t1, t2;
	symbol_node* symbol;
	int tmp;
	int ln;
	ir_vars* irv;
	char temp[1000]  = "";
	if (ast) {
		program* program_ = (program*)ast;
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
		type* type_ = (type*)ast;
		lit* lit_ = (lit*)ast;
		lit_integer* lit_i = (lit_integer*)ast;
		lit_real* lit_r = (lit_real*)ast;
		lit_char* lit_c = (lit_char*)ast;
		lit_string* lit_s = (lit_string*)ast;
		lit_boolean* lit_b = (lit_boolean*)ast;
		lit_null* lit_n = (lit_null*)ast;
		symbol_ref* ref = (symbol_ref*)ast;

		type1 = program_->token;

		switch (type1) {
		case PROGRAM_:
			//go over the procedures
			for (i = program_->proc_l_->i; i>0; i--)
				printf("%s",tacGeneration(program_->proc_l_->list[i - 1])->code);

			break;

		case PROCEDURE_: 
			//go over the body
			proc_->irv->var = proc_->id->id;
			global_line_num = 2;
			snprintf(proc_->irv->code, CODE_SIZE,"%s:\n%s%s",proc_->irv->var,
				"\tBeginFunc\n",tacGeneration(proc_->body)->code);

			return proc_->irv;

			break;

		case BODY_: 
			
			for (i = body_->proc_l->i; i>0; i--){
            	snprintf(temp, CODE_SIZE,"%s", tacGeneration(body_->proc_l->list[i - 1])->code);
            	strcat(body_->irv->code, temp);				
			}
			//for (i = body_->var_dec_l->i; i>0; i--){
			//	snprintf(temp, CODE_SIZE,"%s", tacGeneration(body_->var_dec_l->list[i - 1])->code);
            //	strcat(body_->irv->code, temp);	
			//}
			for (i = body_->stmts_->i; i>0; i--){
				snprintf(temp, CODE_SIZE,"%s",tacGeneration(body_->stmts_->list[i - 1])->code);
            	strcat(body_->irv->code, temp);				
			}
			strcat(body_->irv->code, tacGeneration(body_->ret_stmt)->code);	
			return body_->irv;
			break;

		case VAR_DECS_:

			//NO NEED IN TAC

			break;

		case STMT_:

			stmt_->irv = tacGeneration(stmt_->stmt_);
			return stmt_->irv;
			
			break;

		case ASSIGN_: 
			//TODO ARRAY AND FUNCTION CALLS
			expr_ = assign_->rvalue;
			irv = tacGeneration(assign_->lvalue);
			expr_->irv = tacGeneration(assign_->rvalue);
			assign_->irv->var = assign_->lvalue->irv->var;
			global_line_num++;
			if(assign_->lvalue->length != NULL){
				temp[0] = '*';
			}
			snprintf(assign_->irv->code,CODE_SIZE,"%s%s\t%s%s = %s\n",irv->code,expr_->irv->code,
				temp,assign_->lvalue->irv->var,expr_->irv->var);
			//A DIRTY FIX FOR THE POPPARAMS ORDER. DO NOT ENCOURAGE
			if(expr_->token == FN_CALL_){
				global_line_num++;
				snprintf(temp,CODE_SIZE,"\tPopParams %d\n",((fn_call*)(expr_))->expr_l->i);
            	strcat(call_->irv->code, temp);	
        	}
			return assign_->irv;
			break;

		case ASSIGN_DER_:
			expr_ = assign_->rvalue;
			tacGeneration(assign_->lvalue);
			expr_->irv = tacGeneration(assign_->rvalue);
			assign_->irv->var = assign_->lvalue->irv->var;
			global_line_num++;
			snprintf(assign_->irv->code,CODE_SIZE,"%s\t*%s = %s\n",expr_->irv->code,
				assign_->irv->var,expr_->irv->var);
			//A DIRTY FIX FOR THE POPPARAMS ORDER. DO NOT ENCOURAGE
			if(expr_->token == FN_CALL_){
				global_line_num++;
				snprintf(temp,CODE_SIZE,"\tPopParams %d\n",((fn_call*)(expr_))->expr_l->i);
            	strcat(call_->irv->code, temp);	
        	}
			return assign_->irv;

			break;

		case IF_:
			if_->begin = freshLabel();
			tacGeneration(if_->cond);
			tacGeneration(if_->if_block);

			global_line_num +=1;
			if_->after = freshLabel();
			snprintf(if_->irv->code,CODE_SIZE,"%s\tif %s = 0 goto %s\n%s%s:",
				if_->cond->irv->code,if_->cond->irv->var,if_->after,
				if_->if_block->irv->code,
				if_->after);			
			return if_->irv;
			break;

		case IF_ELSE_:
			if_else_->begin = freshLabel();
			tacGeneration(if_else_->cond);
			tacGeneration(if_else_->if_block);
			global_line_num +=2;
			if_else_->if_block->next = freshLabel();
			tacGeneration(if_else_->else_block);

			if_else_->after = freshLabel();
			snprintf(if_else_->irv->code,CODE_SIZE,"%s\tif %s = 0 goto %s\n%s\tgoto %s\n%s:%s%s:",
				if_else_->cond->irv->code, if_else_->cond->irv->var,
				if_else_->if_block->next,
				if_else_->if_block->irv->code,
				if_else_->after,if_else_->if_block->next,
				if_else_->else_block->irv->code,
				if_else_->after);
			return if_else_->irv;
			break;

		case FOR_:
			for_->begin = freshLabel();
			tacGeneration(for_->cond);
			tacGeneration(for_->for_block);
						
			global_line_num +=2;
			for_->after = freshLabel();
			//for_->after = freshLabel();
			for_->for_block->next = for_->after;
			snprintf(for_->irv->code,CODE_SIZE,"%s:%s\tif %s = 0 goto %s\n%s\tgoto %s\n%s:",
				for_->begin,for_->cond->irv->code,for_->cond->irv->var,for_->after,
				for_->for_block->irv->code,
				for_->begin,for_->after);
			return for_->irv;
			break;


		case WHILE_:
			while_->begin = freshLabel();
			tacGeneration(while_->cond);
			tacGeneration(while_->while_block);
						
			global_line_num +=2;
			while_->after = freshLabel();
			//while_->after = freshLabel();
			while_->while_block->next = while_->after;
			snprintf(while_->irv->code,CODE_SIZE,"%s:%s\tif %s = 0 goto %s\n%s\tgoto %s\n%s:",
				while_->begin,while_->cond->irv->code,while_->cond->irv->var,while_->after,
				while_->while_block->irv->code,
				while_->begin,while_->after);
			return while_->irv;
			break;

		case CODE_BLOCK_:

			for (i = block_->stmts->i; i>0; i--){
				snprintf(temp, CODE_SIZE,"%s",tacGeneration(block_->stmts->list[i - 1])->code);
            	strcat(block_->irv->code, temp);					
			}
			//TODO SMART LABEL
			//block_->next = freshLabel();
			//snprintf(temp,CODE_SIZE,"%s:",block_->next);
			//strcat(block_->irv->code, temp);
			return block_->irv;

			break;

		case FN_CALL_: 
			strcat(call_->irv->var,"LCall ");
			strcat(call_->irv->var,call_->id->id);
			for(i = call_->expr_l->i;i>0;i--){
				irv = tacGeneration(call_->expr_l->list[i - 1]);
				global_line_num++;
				snprintf(temp, CODE_SIZE,"%s\tPushParam %s\n",
					irv->code,
					irv->var);
            	strcat(call_->irv->code, temp);	
			}	
				

			return call_->irv;
			break;

		case TYPE_:


			break;

		case IDENT_: 
			ref->irv->var = ref->id;
			if(ref->length != NULL){
				irv = tacGeneration(ref->length);
				ref->irv->var = freshVar();
				global_line_num++;
				snprintf(ref->irv->code,CODE_SIZE,"%s\t%s = %s + %s\n",irv->code,
					ref->irv->var,ref->id,irv->var);
			}
			else{
				ref->irv->code ="";
			}
			return ref->irv;
			break;

		case RET_STMT_: 
			tacGeneration(ret_->exp);
			//ret_->irv->var = freshVar();
			global_line_num+=2;
			snprintf(ret_->irv->code,CODE_SIZE,"%s\tReturn %s\n\tEndFunc\n\n",
				ret_->exp->irv->code,ret_->exp->irv->var);
			return ret_->irv;
			break;

		case EXPR_: 
			relop = expr_->exp;
			relop->irv = tacGeneration(expr_->exp);
			expr_->irv = relop->irv;

			return expr_->irv;
			break;

		case LITERAL_:
			lit_->irv = tacGeneration(lit_->value);
			return lit_->irv;
			break;

		case RELOP_:
			ln = relop->line_num;
			switch (relop->op_) {
			case AND_:
				tacGeneration(relop->left);
				tacGeneration(relop->right);
				relop->irv->var = freshVar();
				global_line_num++;
				snprintf(relop->irv->code, CODE_SIZE, "%s%s\t%s = %s && %s\n",
					relop->left->irv->code, relop->right->irv->code,
					relop->irv->var, relop->left->irv->var,
					relop->right->irv->var);

				return relop->irv;
				break;
			case OR_:
				tacGeneration(relop->left);
				tacGeneration(relop->right);
				relop->irv->var = freshVar();
				global_line_num++;
				snprintf(relop->irv->code, CODE_SIZE, "%s%s\t%s = %s || %s\n",
					relop->left->irv->code, relop->right->irv->code,
					relop->irv->var, relop->left->irv->var,
					relop->right->irv->var);

				return relop->irv;
				break;
			case EQ_:
				tacGeneration(relop->left);
				tacGeneration(relop->right);
				relop->irv->var = freshVar();
				global_line_num++;
				snprintf(relop->irv->code, CODE_SIZE, "%s%s\t%s = %s == %s\n",
					relop->left->irv->code, relop->right->irv->code,
					relop->irv->var, relop->left->irv->var,
					relop->right->irv->var);

				return relop->irv;
				break;
			case NE_:
				tacGeneration(relop->left);
				tacGeneration(relop->right);
				relop->irv->var = freshVar();
				global_line_num++;
				snprintf(relop->irv->code, CODE_SIZE, "%s%s\t%s = %s != %s\n",
					relop->left->irv->code, relop->right->irv->code,
					relop->irv->var, relop->left->irv->var,
					relop->right->irv->var);

				return relop->irv;
				break;
			case GE_:
				tacGeneration(relop->left);
				tacGeneration(relop->right);
				relop->irv->var = freshVar();
				global_line_num++;
				snprintf(relop->irv->code, CODE_SIZE, "%s%s\t%s = %s >= %s\n",
					relop->left->irv->code, relop->right->irv->code,
					relop->irv->var, relop->left->irv->var,
					relop->right->irv->var);

				return relop->irv;
				break;
			case GT_:
				tacGeneration(relop->left);
				tacGeneration(relop->right);
				relop->irv->var = freshVar();

				global_line_num++;
				snprintf(relop->irv->code, CODE_SIZE, "%s%s\t%s = %s > %s\n",
					relop->left->irv->code, relop->right->irv->code,
					relop->irv->var, relop->left->irv->var,
					relop->right->irv->var);

				return relop->irv;
				break;
			case LE_:
				tacGeneration(relop->left);
				tacGeneration(relop->right);
				relop->irv->var = freshVar();
				global_line_num++;
				snprintf(relop->irv->code, CODE_SIZE, "%s%s\t%s = %s <= %s\n",
					relop->left->irv->code, relop->right->irv->code,
					relop->irv->var, relop->left->irv->var,
					relop->right->irv->var);

				return relop->irv;
				break;
			case LT_:
				tacGeneration(relop->left);
				tacGeneration(relop->right);
				relop->irv->var = freshVar();
				global_line_num++;
				snprintf(relop->irv->code, CODE_SIZE, "%s%s\tif %s = %s < %s goto %s\n",
					relop->left->irv->code, relop->right->irv->code,
					relop->irv->var, relop->left->irv->var,
					relop->right->irv->var,relop->trueLabel);

				return relop->irv;
				break;
			case NOT_:
				tacGeneration(relop->left);
				relop->irv->var = freshVar();
				global_line_num++;
				snprintf(relop->irv->code, CODE_SIZE, "%s\t%s = !%s\n",
					relop->left->irv->code,
					relop->irv->var, relop->left->irv->var);

				return relop->irv;
				break;

			}

			break;

		case OP_:

			ln = op_->line_num;

			switch (op_->op_) {

			case PLUS_:
				tacGeneration(op_->left);
				tacGeneration(op_->right);
				op_->irv->var = freshVar();
				global_line_num++;
				snprintf(op_->irv->code, CODE_SIZE, "%s%s\t%s = %s + %s\n",
					op_->left->irv->code, op_->right->irv->code,
					op_->irv->var, op_->left->irv->var,
					op_->right->irv->var);

				return op_->irv;
				break;
			case MINUS_:
				tacGeneration(op_->left);
				tacGeneration(op_->right);
				op_->irv->var = freshVar();
				global_line_num++;
				snprintf(op_->irv->code, CODE_SIZE, "%s%s\t%s = %s - %s\n",
					op_->left->irv->code, op_->right->irv->code,
					op_->irv->var, op_->left->irv->var,
					op_->right->irv->var);


				return op_->irv;
				break;
			case MULTI_:
				tacGeneration(op_->left);
				tacGeneration(op_->right);
				op_->irv->var = freshVar();
				global_line_num++;
				snprintf(op_->irv->code, CODE_SIZE, "%s%s\t%s = %s * %s\n",
					op_->left->irv->code, op_->right->irv->code,
					op_->irv->var, op_->left->irv->var,
					op_->right->irv->var);


				return op_->irv;
				break;
			case DIV_:
				tacGeneration(op_->left);
				tacGeneration(op_->right);
				op_->irv->var = freshVar();
				global_line_num++;
				snprintf(op_->irv->code, CODE_SIZE, "%s%s\t%s = %s / %s\n",
					op_->left->irv->code, op_->right->irv->code,
					op_->irv->var, op_->left->irv->var,
					op_->right->irv->var);


				return op_->irv;
				break;
			case UMINUS_:
				tacGeneration(op_->left);
				op_->irv->var = freshVar();
				global_line_num++;
				snprintf(op_->irv->code, CODE_SIZE, "%s\t%s = -%s\n",
					op_->left->irv->code,op_->irv->var, op_->left->irv->var);


				return op_->irv;
				break;
			case DEREFERENCE_:
				tacGeneration(op_->left);
				op_->irv->var = freshVar();
				global_line_num++;
				snprintf(op_->irv->code, CODE_SIZE, "%s\t%s = *%s\n",
					op_->left->irv->code,op_->irv->var, op_->left->irv->var);


				return op_->irv;
				break;
			case ADDRESS_OF_:
				tacGeneration(op_->left);
				op_->irv->var = freshVar();
				global_line_num++;
				snprintf(op_->irv->code, CODE_SIZE, "%s\t%s = &%s\n",
					op_->left->irv->code,op_->irv->var, op_->left->irv->var);
				break;

			case ABS_:
				tacGeneration(op_->left);
				op_->irv->var = freshVar();
				global_line_num++;
				snprintf(op_->irv->code, CODE_SIZE, "%s\t%s = |%s|\n",
					op_->left->irv->code,op_->irv->var, op_->left->irv->var);		
				break;

			default:
				break;
			}
			break;


		case CHARPTR_:
			
			break;

		case INTPTR_:
			
			break;

		case REAL_:		
			break;

		case INTEGER_:
			
			break;

		case BOOLEAN_:
			
			break;

		case CHAR_:
			
			break;

		case STRING_:
			
			break;

		case STRING_LITERAL_:
			lit_s->irv->var = freshVar();
			global_line_num++;
			snprintf(lit_s->irv->code,CODE_SIZE,"\t%s = %s\n",lit_s->irv->var,lit_s->value);
			return lit_s->irv;
			break;

		case CHAR_LITERAL_:
			lit_c->irv->var = freshVar();
			global_line_num++;
			snprintf(lit_c->irv->code,CODE_SIZE,"\t%s = %c\n",lit_c->irv->var,lit_c->value);
			return lit_c->irv;			
			break;

		case INTEGER_LITERAL_:
			lit_i->irv->var = freshVar();
			global_line_num++;
			snprintf(lit_i->irv->code,CODE_SIZE,"\t%s = %d\n",lit_i->irv->var,lit_i->value);
			return lit_i->irv;			
			break;

		case REAL_LITERAL_:
			lit_r->irv->var = freshVar();
			global_line_num++;
			snprintf(lit_r->irv->code,CODE_SIZE,"\t%s = %d\n",lit_r->irv->var,lit_r->value);
			return lit_r->irv;			
			break;

		case BOOLEAN_LITERAL_:
			lit_b->irv->var = freshVar();
			global_line_num++;
			snprintf(lit_b->irv->code,CODE_SIZE,"\t%s = %d\n",lit_b->irv->var,lit_b->value);
			return lit_b->irv;			
			break;

		case NULL_LITERAL_:
			lit_n->irv->var = freshVar();
			global_line_num++;
			snprintf(lit_n->irv->code,CODE_SIZE,"\t%s = %s\n",lit_n->irv->var,"NULL");
			return lit_n->irv;			
			break;
		default: 
			break;

		}//switch

	}//if
}
