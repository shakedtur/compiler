#define NULL_LITERAL 257
#define KEY_PROCEDURE 258
#define KEY_VAR 259
#define KEY_CHARPTR 260
#define KEY_INTPTR 261
#define KEY_STRING 262
#define KEY_INTEGER 263
#define KEY_BOOLEAN 264
#define KEY_CHAR 265
#define KEY_ELSE 266
#define KEY_IF 267
#define KEY_RETURN 268
#define KEY_FOR 269
#define KEY_WHILE 270
#define OP_AND 271
#define OP_EQ 272
#define OP_GE 273
#define OP_LE 274
#define OP_NE 275
#define OP_OR 276
#define STRING_LITERAL 277
#define IDENTIFIER 278
#define CHAR_LITERAL 279
#define COMMA 280
#define COLON 281
#define DOT 282
#define SINGLE_QUOTE 283
#define QUOTE 284
#define SQ_BRA_C 285
#define SQ_BRA_O 286
#define PARAN_C 287
#define PARAN_O 288
#define SEMICOLON 289
#define BRA_C 290
#define BRA_O 291
#define OP_DEREFERENCE 292
#define OP_ADDRESS_OF 293
#define OP_MULTI 294
#define OP_PLUS 295
#define OP_NOT 296
#define OP_MINUS 297
#define OP_LT 298
#define OP_GT 299
#define ASSIGN 300
#define OP_DIV 301
#define OP_ABS 302
#define TRUE_LITERAL 303
#define FALSE_LITERAL 304
#define INTEGER_LITERAL 305
#define HEX_LITERAL 306
typedef union{
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
	
} YYSTYPE;
extern YYSTYPE yylval;
