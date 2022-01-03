
#include "semantics.h"


char* printDef(int def) {
	switch (def) {

	case CHARPTR_:
		return "charptr";
		break;
	case INTPTR_:
		return "intptr";
		break;
	case STRING_:
		return "string";
		break;
	case INTEGER_:
		return "integer";
		break;
	case REAL_:
		return "real";
		break;
	case CHAR_:
		return "char";
		break;
	case BOOLEAN_:
		return "boolean";
		break;
	case NULL_LITERAL_:
		return "NULL";
		break;
	default:return NULL;
		break;
	}
}

// edit?
void printError(int errorType, int ln, int t1, int t2, symbol_ref* symbol) {

	//symbol->id;
	printf("line %d: ", ln);
	switch (errorType) {

	case ERROR_PLUS:
		printf("PLUS requires integers or real numbers or a pointer + integer/real - got %s + %s", printDef(t1), printDef(t2));
		break;

	case ERROR_MINUS:
		printf("MINUS requires integers or real numbers - got %s + %s", printDef(t1), printDef(t2));
		break;

	case ERROR_DIV:
		printf("DIV requires integers or real numbers - got %s + %s", printDef(t1), printDef(t2));
		break;

	case ERROR_MULTI:
		printf("MULTI requires integers or real numbers - got %s + %s", printDef(t1), printDef(t2));
		break;


	case ERROR_UMINUS:
		printf("UMINUS requires integer - got %s", printDef(t1));
		break;

	case ERROR_DEREFERENCE:
		printf("DEREFERENCE requires pointer - got %s", printDef(t1));
		break;


	case ERROR_ADDRESS_OF:
		printf("ADDRESS OF requires integer - got %s", printDef(t1));
		break;

	case ERROR_ABS:
		printf("ABS requires integer or string - got %s", printDef(t1));
		break;

	case ERROR_AND:
		printf("&& requires booleans - got %s + %s", printDef(t1), printDef(t2));
		break;

	case ERROR_OR:
		printf("|| requires booleans - got %s + %s", printDef(t1), printDef(t2));
		break;

	case ERROR_EQ:
		printf("== requires 2 of the same type - got %s + %s", printDef(t1), printDef(t2));
		break;

	case ERROR_NE:
		printf("!= requires 2 of the same type - got %s + %s", printDef(t1), printDef(t2));
		break;

	case ERROR_GE:
		printf(">= requires 2 integers or 2 real numbers - got %s + %s", printDef(t1), printDef(t2));
		break;

	case ERROR_GT:
		printf("> requires 2 integers or 2 real numbers - got %s + %s", printDef(t1), printDef(t2));
		break;

	case ERROR_LE:
		printf("<= requires 2 integers or 2 real numbers - got %s + %s", printDef(t1), printDef(t2));
		break;

	case ERROR_LT:
		printf("< requires 2 integers or 2 real numbers - got %s + %s", printDef(t1), printDef(t2));
		break;

	case ERROR_NOT:
		printf("! - (not) requires boolean - got %s", printDef(t1));
		break;

	case ERROR_VAR_DEC:
		printf("The variable %s has already been declared", symbol->id);
		break;
	case ERROR_PRO_MISMATCH:
		printf("The return type of %s is %s, but you are returning %s type!", symbol->id, printDef(t1), printDef(t2));
		break;
	case ERROR_UNDEC:
		printf("The variable %s is undeclared!", symbol->id);
		break;
	case ERROR_UNDEC_PROC:
		printf("The function %s is undeclared", symbol->id);
		break;
	case ERROR_PRO_DEC:
		printf("The function %s has already been declared!", symbol->id);
		break;
	default: printf("OH NO! UNKNOWN ERROR! :(");
		break;

	}

	printf("\n");


}

int* get_params_type(params_list* ast) {
	//we got a param_list_ type;
	//param_L
	int i ,j;

	params* params_;
	symbol_node* symbol;
	symbol_ref* ref;
	int size, temp; 
	int* list = (int*)malloc(sizeof(int)*(size));

	size = get_numer_type(ast);
	temp = size;
	for (i = ast->i; i > 0; i--)
	{

		params_ = ast->list[i-1];//params

		for (j = params_->param_list->i; j > 0; j--) {

			ref = (symbol_ref*)(params_->param_list->list[j-1]);
			symbol = lookup(ref->id);
			if (symbol != NULL && currentScope == symbol->scope_lvl)//if there is a symbol
			{
				printError(ERROR_VAR_DEC, ref->line_num, EMPTY_, EMPTY_, ref);
				ref->symbol = symbol;
			}
			else {//inserting the new symbol to the table
				symbol = make_symbol(VAR_);
				symbol->type = params_->type_->type_;

				ref->symbol = symbol;
				insert(ref);
			}
			//adding the type to the list

			list[temp-1] = symbol->type;
			temp = temp - 1;
		}
	}
	return list;
}

int get_numer_type(params_list* ast)
{
	int i, j = 0;
	for (i = ast->i; i > 0; i--)
	{
		j = j + ast->list[i-1]->param_list->i;
	}
	return j;
}

//NOTE WE ALREADY CHECKED THAT THE LENGTH OF THE LISTS ARE THE SAME
int isEqual(int* p1, int l1, expr_list* p2) {
	int i = 0;

	while (i< l1 && p1[i] == checkSemantics(p2->list[i])) {
		i++;
	}

	if (i == l1)
		return 1;
	return 0;
}


int checkSemantics(void* ast) {

	int type1, i;
	int t1, t2;
	symbol_node* symbol;
	int tmp;
	int ln;

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
		case PROGRAM_: // done
			for (i = program_->proc_l_->i; i>0; i--)
				checkSemantics(program_->proc_l_->list[i - 1]);
			
			//checking if the main function exists
			symbol = lookup("main");
			if (symbol == NULL)//if there is a symbol
			{
				printf("Global: main function has not been declared\n");
			}
			else if (symbol->num_of_params != 0)
				printf("Global: main function cannot contain a parameter list\n");
			break;

		case PROCEDURE_: //done?
			ref = proc_->id;
			//checking if the symbol already exists
			symbol = lookup(ref->id);
			if (symbol != NULL)//if there is a symbol
			{
				printError(ERROR_PRO_DEC, ref->line_num, EMPTY_, EMPTY_, ref);
				//printf("%s has been already declared!\n",ref->id);
				ref->symbol = symbol;
				currentScope += 1;
			}
			else {
				//creating a new symbol
				symbol = make_symbol(PROCEDURE_);
				symbol->type = checkSemantics(proc_->return_type);
				symbol->scope_lvl = currentScope;
				//opening a new scope
				currentScope += 1;
				/*
				    RETURN TO HERE
					NEED "get_params_type" -------------------------------------------------------------------><
				*/
				symbol->param_types = get_params_type(proc_->param_l);
				symbol->num_of_params = get_numer_type(proc_->param_l);
				ref->symbol = symbol;
				insert(ref);
			}
			// ----------------------------------------------------
			// need to check the return type of the body
			// ----------------------------------------------------
			tmp = checkSemantics(proc_->body);
			if (tmp != symbol->type)
				printError(ERROR_PRO_MISMATCH, ref->line_num, symbol->type, tmp, ref);
			deleteFromScope();
			//closing the scope
			currentScope -= 1;

			break;

		case BODY_: // done
			for (i = body_->proc_l->i; i>0; i--) // proc list
				checkSemantics(body_->proc_l->list[i - 1]);
			for (i = body_->var_dec_l->i; i>0; i--) // var desc
				checkSemantics(body_->var_dec_l->list[i - 1]);
			for (i = body_->stmts_->i; i>0; i--) // stmts
				checkSemantics(body_->stmts_->list[i - 1]);

			return checkSemantics(body_->ret_stmt);
			break;

		case VAR_DECS_: // now edit
			
			for (i = var_decs_->var_list->i; i > 0; i--) 
			{
				ref = var_decs_->var_list->list[i - 1];
				symbol = lookup(ref->id);
				if (symbol != NULL && currentScope == symbol->scope_lvl)//if there is a symbol
				{
					printError(ERROR_VAR_DEC, ref->line_num, EMPTY_, EMPTY_, ref);
					ref->symbol = symbol;
				}
				else 
				{ //inserting the new symbol to the table
					symbol = make_symbol(VAR_);
					symbol->type = var_decs_->var_type->type_;
					ref->symbol = symbol;
					insert(ref);
				}
			}

			break;

		case STMT_:
			checkSemantics(stmt_->stmt_);
			
			break;

		case ASSIGN_: // doing... done?
			ref = assign_->lvalue;
			//checking if the symbol already exists
			symbol = lookup(ref->id);
			if (symbol == NULL)//if there is a symbol
			{
				printError(ERROR_UNDEC, ref->line_num, EMPTY_, EMPTY_, ref);
				//printf("%s has not been declared!\n",ref->id);
				ref->symbol = symbol;
			}
			else {

				if (symbol->symbol_type == PROCEDURE_)
					printf("line %d: %s is a function... you cannot assign to it\n", ref->line_num, ref->id);
				else if (ref->length != NULL) { // a string array
					if (symbol->type != STRING_)
						printf("line %d: %s has to be a string in order to be an array!\n", ref->line_num, ref->id);
					else if (checkSemantics(ref->length) != INTEGER_)
						printf("line %d: %s - array index has to be of type Integer\n", ref->line_num, ref->id);
					else if (checkSemantics(assign_->rvalue) != CHAR_)// check ........
						printf("line %d: %s is of type string[expr] cant be assigned to a different type\n", ref->line_num, ref->id);
				}
				else {
					tmp = checkSemantics(assign_->rvalue);
					if (tmp == NULL_LITERAL_) {
						if (symbol->type != CHARPTR_ && symbol->type != INTPTR_)
							printf("line %d: %s is of type %s cant be assigned a different type!\n", ref->line_num, ref->id, printDef(symbol->type));
					}
					else if (symbol->type != tmp) {
						printf("line %d: %s cant be assigned a different type!\n", ref->line_num, ref->id);
					}
				}
			}
			break;

		case ASSIGN_DER_:
			ref = assign_->lvalue;
			//checking if the symbol already exists
			symbol = lookup(ref->id);
			if (symbol == NULL)//if there is a symbol
			{

				printError(ERROR_UNDEC, ref->line_num, EMPTY_, EMPTY_, ref);

				ref->symbol = symbol;
			}
			else {
				if (symbol->symbol_type == PROCEDURE_)
					printf("%s is a function... you cannot assign to it\n", ref->id);
				else if (symbol->type != CHARPTR_ && symbol->type != INTPTR_)
					printf("%s is not a pointer\n", ref->id);
				else {
					tmp = checkSemantics(assign_->rvalue);

					if (symbol->type == CHARPTR_ && tmp != CHAR_ ||
						symbol->type == INTPTR_ && tmp != INTEGER_) {
						printf("%s cant be assigned a different type!\n", ref->id);
					}
				}
			}
			break;

		case IF_:
			tmp = checkSemantics(if_->cond);
			if (tmp != BOOLEAN_) {
				printf("line %d: If cond has to be a boolean, got %s\n", if_->line_num, printDef(tmp));
			}
			checkSemantics(if_->if_block);

			break;

		case IF_ELSE_:
			tmp = checkSemantics(if_else_->cond);
			if (tmp != BOOLEAN_) {
				printf("line %d: If cond has to be a boolean, got %s\n", if_else_->line_num, printDef(tmp));
			}
			checkSemantics(if_else_->if_block);
			checkSemantics(if_else_->else_block);
			break;


		case FOR_:
			tmp = checkSemantics(for_->cond);
			if (tmp != BOOLEAN_) {
				printf("line %d: for cond has to be a boolean, got %s\n", for_->line_num, printDef(tmp));
			}
			checkSemantics(for_->for_block);
			break;

		case WHILE_:
			tmp = checkSemantics(while_->cond);
			if (tmp != BOOLEAN_) {
				printf("line %d: while cond has to be a boolean, got %s\n", while_->line_num, printDef(tmp));
			}
			checkSemantics(while_->while_block);
			break;

		case CODE_BLOCK_:
			currentScope += 1;
			for (i = block_->var_decs_l->i; i>0; i--)
				checkSemantics(block_->var_decs_l->list[i - 1]);

			for (i = block_->stmts->i; i>0; i--)
				checkSemantics(block_->stmts->list[i - 1]);

			deleteFromScope();
			currentScope -= 1;
			break;

		case FN_CALL_: // done
			ref = call_->id;
			//checking if the symbol already exists
			symbol = lookup(ref->id);
			if (symbol == NULL)//if there is a symbol
			{
				printError(ERROR_UNDEC_PROC, ref->line_num, EMPTY_, EMPTY_, ref);

				ref->symbol = symbol;
			}
			else if (symbol->symbol_type == VAR_)
				printf("line %d: You cannot use the variable %s as a function!\n", ref->line_num, ref->id);
			else {
				tmp = symbol->type;
				t1 = call_->expr_l->i;//length
				if (symbol->num_of_params > t1)
					printf("line %d: %s function call has fewer parameters than needed\n", ref->line_num, ref->id);
				else if (symbol->num_of_params < t1)
					printf("line %d: %s function call has too many parameters than needed\n", ref->line_num, ref->id);
					
				else if (isEqual(symbol->param_types, symbol->num_of_params, call_->expr_l) == 0)
					printf("line %d: %s function call does not match the arguments of the declaretion\n", ref->line_num, ref->id);

				return symbol->type;
			}

			break;

		case TYPE_:
			return type_->type_;

			break;

		case IDENT_: // done?
			symbol = lookup(ref->id);
			if (symbol == NULL)//if there is a no symbol
			{

				printError(ERROR_UNDEC, ref->line_num, EMPTY_, EMPTY_, ref);

				ref->symbol = symbol;
				return EMPTY_;
			}

			//generate code for symbol
			
			return symbol->type;
			break;

		case RET_STMT_: // done
			return checkSemantics(ret_->exp);
			break;

		case EXPR_: // done
			return checkSemantics(expr_->exp);
			break;

		case LITERAL_:
			return checkSemantics(lit_->value);
			break;

		case RELOP_:
			ln = relop->line_num;
			switch (relop->op_) {
			case AND_:

				t1 = checkSemantics(relop->left);
				t2 = checkSemantics(relop->right);
				if (t1 != t2 || t1 != BOOLEAN_)
					printError(ERROR_AND, ln, t1, t2, NULL);
				return BOOLEAN_;
				break;
			case OR_:
				t1 = checkSemantics(relop->left);
				t2 = checkSemantics(relop->right);
				if (t1 != t2 || t1 != BOOLEAN_)
					printError(ERROR_OR, ln, t1, t2, NULL);
				return BOOLEAN_;
				break;
			case EQ_:
				t1 = checkSemantics(relop->left);
				t2 = checkSemantics(relop->right);
				if (t1 == t2 && t1 == STRING_)
					printf("line %d: == can't be used on two strings.\n", ln);
				else {
					if (t1 != t2 ||
						(t1 != BOOLEAN_&&
							t1 != INTEGER_ &&
							t1 != CHAR_&&
							t1 != REAL_&&
							t1 != CHARPTR_&&
							t1 != INTPTR_))
						printError(ERROR_EQ, ln, t1, t2, NULL);
				}
				return BOOLEAN_;
				break;
			case NE_:
				t1 = checkSemantics(relop->left);
				t2 = checkSemantics(relop->right);
				if (t1 == t2 && t1 == STRING_)
					printf("line %d: != can't be used on two strings\n", ln);
				else {
					if (t1 != t2 ||
						(t1 != BOOLEAN_&&
							t1 != INTEGER_ &&
							t1 != CHAR_&&
							t1 != CHARPTR_&&
							t1 != INTPTR_))
						printError(ERROR_NE, ln, t1, t2, NULL);
				}
				return BOOLEAN_;
				break;
			case GE_:
				t1 = checkSemantics(relop->left);
				t2 = checkSemantics(relop->right);
				if (t1 != t2 || t1 != INTEGER_)
					printError(ERROR_GE, ln, t1, t2, NULL);
				return BOOLEAN_;
				break;
			case GT_:
				t1 = checkSemantics(relop->left);
				t2 = checkSemantics(relop->right);
				if (t1 != t2 || t1 != INTEGER_)
					printError(ERROR_GT, ln, t1, t2, NULL);
				return BOOLEAN_;
				break;
			case LE_:
				t1 = checkSemantics(relop->left);
				t2 = checkSemantics(relop->right);
				if (t1 != t2 || t1 != INTEGER_)
					printError(ERROR_LE, ln, t1, t2, NULL);
				return BOOLEAN_;
				break;
			case LT_:
				t1 = checkSemantics(relop->left);
				t2 = checkSemantics(relop->right);
				if (t1 != t2 || t1 != INTEGER_)
					printError(ERROR_LT, ln, t1, t2, NULL);
				return BOOLEAN_;
				break;
			case NOT_:
				t1 = checkSemantics(relop->left);
				if (t1 != BOOLEAN_)
					printError(ERROR_NOT, ln, t1, EMPTY_, NULL);
				return BOOLEAN_;
				break;

			}

			break;

		case OP_:

			ln = op_->line_num;

			switch (op_->op_) {

			case PLUS_:
				t1 = checkSemantics(op_->left);
				t2 = checkSemantics(op_->right);
				if ((t1 == CHARPTR_ || t2 == CHARPTR_ || t1 == INTPTR_ || t2 == INTPTR_) 
					&& t1 != INTEGER_ && t2 == INTEGER_) {//checking if we are changing the pointer
					printError(ERROR_PLUS, ln, t1, t2, NULL);//change later
					return EMPTY_;
				}
				else if (t1 != t2 || t1 != INTEGER_)
					printError(ERROR_PLUS, ln, t1, t2, NULL);
				return INTEGER_;
				break;
			case MINUS_:
				t1 = checkSemantics(op_->left);
				t2 = checkSemantics(op_->right);
				if (t1 == CHARPTR_ || t1 == INTPTR_) {//checking if we are changing the pointer
					if (t2 != INTEGER_)
						printError(ERROR_MINUS, ln, t1, t2, NULL);
					return t1;
				}
				else if (t1 != t2 || t1 != INTEGER_)
					printError(ERROR_MINUS, ln, t1, t2, NULL);
				return INTEGER_;
				break;
			case MULTI_:
				t1 = checkSemantics(op_->left);
				t2 = checkSemantics(op_->right);
				if (t1 != t2 || t1 != INTEGER_)
					printError(ERROR_MULTI, ln, t1, t2, NULL);
				return INTEGER_;
				break;
			case DIV_:
				t1 = checkSemantics(op_->left);
				t2 = checkSemantics(op_->right);
				if (t1 != t2 || t1 != INTEGER_)
					printError(ERROR_DIV, ln, t1, t2, NULL);
				return INTEGER_;
				break;
			case UMINUS_:
				t1 = checkSemantics(op_->left);
				if (t1 != INTEGER_)
					printError(ERROR_UMINUS, ln, t1, EMPTY_, NULL);
				return INTEGER_;
				break;
			case DEREFERENCE_:
				t1 = checkSemantics(op_->left);
				if (t1 != CHARPTR_ && t1 != INTPTR_)
					printError(ERROR_DEREFERENCE, ln, t1, EMPTY_, NULL);
				else if (t1 == CHARPTR_)
					return CHAR_;
				else if (t1 == INTPTR_)
					return INTEGER_;
				return t1;
				break;
			case ADDRESS_OF_:
				t1 = checkSemantics(op_->left);
				if (t1 == CHAR_ || t1 == STRING_)
					return CHARPTR_;
				else if (t1 == INTEGER_)
					return INTPTR_;
				else printError(ERROR_ADDRESS_OF, ln, t1, EMPTY_, NULL);
				break;

			case ABS_:
				t1 = checkSemantics(op_->left);
				if (t1 != INTEGER_ && t1 != STRING_)
					printError(ERROR_ABS, ln, t1, EMPTY_, NULL);
				return INTEGER_;

				break;

			default:
				break;
			}
			break;


		case CHARPTR_:
			return CHARPTR_;
			break;

		case INTPTR_:
			return INTPTR_;
			break;

		case INTEGER_:
			return INTEGER_;
			break;

		case REAL_:
			return REAL_;
			break;

		case BOOLEAN_:
			return BOOLEAN_;
			break;

		case CHAR_:
			return CHAR_;
			break;

		case STRING_:
			return STRING_;
			break;

		case STRING_LITERAL_:
			return STRING_;
			break;

		case CHAR_LITERAL_:
			return CHAR_;
			break;

		case INTEGER_LITERAL_:
			return INTEGER_;
			break;

		case REAL_LITERAL_:
			return REAL_;
			break;

		case BOOLEAN_LITERAL_:
			return BOOLEAN_;
			break;

		case NULL_LITERAL_:
			return NULL_LITERAL_;
			break;
		default: return EMPTY_;
			break;

		}//switch

	}//if
}//print_ast



