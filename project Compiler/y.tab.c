#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#include <stdlib.h>
#include <string.h>

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20070509

#define YYEMPTY (-1)
#define yyclearin    (yychar = YYEMPTY)
#define yyerrok      (yyerrflag = 0)
#define YYRECOVERING (yyerrflag != 0)

extern int yyparse(void);

static int yygrowstack(void);
#define YYPREFIX "yy"
#line 2 "parser.y"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ast.h"
#include "print_ast.h"
#include "symtab.h"

void yyerror(const char *c);

program* ast;

#line 17 "parser.y"
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
	lit_real* lit_real;
	lit_string* lit_s;
	lit_char* lit_c;
	lit_boolean* lit_b;
	lit_null* lit_n;					
	
} YYSTYPE;
#line 74 "y.tab.c"
#define NULL_LITERAL 257
#define KEY_PROCEDURE 258
#define KEY_VAR 259
#define KEY_CHARPTR 260
#define KEY_INTPTR 261
#define KEY_STRING 262
#define KEY_INTEGER 263
#define KEY_REAL 264
#define KEY_BOOLEAN 265
#define KEY_CHAR 266
#define KEY_ELSE 267
#define KEY_IF 268
#define KEY_RETURN 269
#define KEY_FOR 270
#define KEY_WHILE 271
#define OP_AND 272
#define OP_EQ 273
#define OP_GE 274
#define OP_LE 275
#define OP_NE 276
#define OP_OR 277
#define STRING_LITERAL 278
#define IDENTIFIER 279
#define CHAR_LITERAL 280
#define COMMA 281
#define COLON 282
#define DOT 283
#define SINGLE_QUOTE 284
#define QUOTE 285
#define SQ_BRA_C 286
#define SQ_BRA_O 287
#define PARAN_C 288
#define PARAN_O 289
#define SEMICOLON 290
#define BRA_C 291
#define BRA_O 292
#define OP_DEREFERENCE 293
#define OP_ADDRESS_OF 294
#define OP_MULTI 295
#define OP_PLUS 296
#define OP_NOT 297
#define OP_MINUS 298
#define OP_LT 299
#define OP_GT 300
#define ASSIGN 301
#define OP_DIV 302
#define OP_ABS 303
#define TRUE_LITERAL 304
#define FALSE_LITERAL 305
#define INTEGER_LITERAL 306
#define HEX_LITERAL 307
#define REAL_LITERAL 308
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    1,    1,    2,    3,    4,    5,    5,    5,    6,
    7,    7,    8,    9,    9,   10,   11,   11,   12,   12,
   12,   12,   12,   12,   13,   13,   13,   13,   13,   14,
   15,   16,   16,   16,   18,   17,   19,   20,   21,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   22,   22,   22,   22,   22,   22,   22,   22,   22,   22,
   23,   23,   23,   23,   23,   23,   24,   24,   25,   25,
   25,   25,   25,   27,   28,   26,   26,   26,   29,   29,
};
short yylen[] = {                                         2,
    1,    2,    0,   10,    1,    4,    1,    3,    0,    3,
    3,    1,    4,    2,    0,    5,    2,    0,    1,    1,
    1,    1,    1,    1,    4,    4,    5,    3,    3,    4,
    5,    3,    1,    0,    7,    5,    5,    5,    3,    3,
    3,    3,    3,    3,    3,    3,    3,    3,    3,    3,
    3,    2,    2,    2,    2,    3,    1,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    4,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    1,
};
short yydefred[] = {                                      0,
    0,    0,    1,    0,    5,    0,    2,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   11,    0,    8,   61,
   62,   63,   64,   65,   66,   10,    0,    0,    0,    0,
    0,    0,    0,    4,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   19,   24,   20,   21,   22,
   23,   14,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   13,   17,    0,   67,    0,   73,   74,   75,
    0,    0,    0,    0,    0,    0,   79,   80,   76,   77,
   78,   57,   59,    0,   60,   70,   69,   71,   72,    0,
    0,    0,    0,    0,    0,   28,    0,   29,    0,    0,
    0,   16,    0,   54,   55,   52,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    6,   30,    0,    0,   25,   26,   39,
    0,   58,   56,    0,    0,    0,    0,    0,    0,    0,
   42,    0,    0,    0,    0,   43,   37,   38,   27,    0,
    0,   68,    0,    0,    0,   35,   31,   32,
};
short yydgoto[] = {                                       2,
    3,    4,   82,   83,   10,   11,   12,   30,   32,   33,
   44,   45,   46,   47,   96,  150,   48,   49,   50,   51,
   63,  151,   26,   67,   85,   86,   87,   88,   89,
};
short yysindex[] = {                                   -246,
 -264,    0,    0, -246,    0, -272,    0, -264, -263, -259,
 -253, -250, -264, -221, -264, -114,    0, -114,    0,    0,
    0,    0,    0,    0,    0,    0, -219, -246, -184, -212,
 -264,  388, -184,    0, -200, -206, -203, -196, -193, -184,
 -264, -188, -187, -154,  388,    0,    0,    0,    0,    0,
    0,    0,  284, -202, -202, -202, -202,  388, -183, -202,
 -202, -202,    0,    0, -170,    0, -163,    0,    0,    0,
 -202, -202, -202, -202, -202, -202,    0,    0,    0,    0,
    0,    0,    0,  127,    0,    0,    0,    0,    0,  144,
  161,  178, -162, -202, -161,    0,  193,    0,  224,  235,
 -218,    0,  266,    0,    0,    0, -249,  -37, -202, -202,
 -202, -202, -202, -202, -160, -202, -202, -202, -202, -202,
 -202, -160, -160,    0,    0,  283, -202,    0,    0,    0,
 -141,    0,    0,  355,  343, -176, -176,  343,  -50, -113,
    0, -249, -249, -176, -176,    0,    0,    0,    0, -132,
  314,    0, -160, -128, -202,    0,    0,    0,
};
short yyrindex[] = {                                    164,
    0,    0,    0,    1,    0,    0,    0, -120, -105,    0,
 -104,    0,    0,    0, -120,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -243,  301,    0,
    0, -221, -110,    0,    0,    0,    0,    0, -165,  211,
    0,    0,    0,    0, -258,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -112,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  325,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -133,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -102,    0,    0,    0,
    0,    0,    0,  108,   83,    2,   23,  102, -247,  -78,
    0, -101,  -69,   43,   63,    0,    0,    0,    0,    0,
 -100,    0,    0,    0, -102,    0,    0,    0,
};
short yygindex[] = {                                      0,
    3,    0,   39,   40,  163,    0,   32,    0,   41,    0,
   -7,    0,    0, -109,  133,   45,    0,    0,    0,    0,
    0,  -52,  -18,    0,    0,   95,    0,    0,    0,
};
#define YYTABLESIZE 681
short yytable[] = {                                      27,
    3,   84,   90,   91,   92,  140,    7,   97,   99,  100,
   18,    1,  147,  148,    5,    3,    8,   13,  103,  104,
  105,  106,  107,  108,    3,    3,    3,    3,   14,   45,
   29,   16,   18,   45,   66,    3,   15,   64,   45,    6,
   45,  126,   45,  156,   17,  116,    9,   18,    3,    3,
   93,    9,  121,    9,   68,   45,  134,  135,  136,  137,
  138,  139,   35,  141,  142,  143,  144,  145,  146,    9,
   42,   43,   28,   52,   31,   69,   39,   70,   34,   59,
   58,   53,   54,   42,   43,   55,   71,   79,   80,   81,
   72,   73,   56,   57,   74,   75,   42,   43,   95,   95,
   76,   77,   78,   79,   80,   81,    5,    5,    5,    5,
    5,    5,   60,   61,   62,    5,  101,   94,  116,  117,
    5,  118,    5,    5,    5,  121,  102,  127,  125,    5,
    5,   40,    5,    5,    5,    5,    5,    5,   53,   53,
   53,   53,   53,   53,  152,   20,   21,   53,   22,   23,
   24,   25,   53,  153,   53,  154,   53,   15,   15,   15,
   15,  157,   53,    3,   53,   53,   53,    9,   15,   53,
   40,   40,   40,   40,   40,   40,   12,   19,   18,   40,
   15,   15,   15,    7,   40,   34,   40,   33,   40,   36,
   36,   36,   36,   98,   40,  131,   40,   40,   40,  158,
   36,   40,   41,   41,   41,   41,   41,   41,    0,    0,
    0,   41,   36,   36,   36,    0,   41,    0,   41,    0,
   41,  109,  110,  111,  112,  113,   41,    0,   41,   41,
   41,    0,    0,   41,  109,  110,  111,  112,  113,  114,
    0,    0,    0,    0,  116,  117,    0,  118,  119,  120,
    0,  121,    0,    0,    0,    0,    0,  116,  117,    3,
  118,  119,  120,    0,  121,  133,    0,    0,    3,    3,
    3,    3,    0,   48,   48,   48,   48,   48,   48,    3,
    0,    0,   48,    0,    0,    0,    0,   48,    0,   48,
    0,   48,    3,    3,   50,   50,   50,   50,   50,   50,
   48,   48,    0,   50,   48,    0,    0,    0,   50,    0,
   50,    0,   50,    0,   51,   51,   51,   51,   51,   51,
    0,   50,   50,   51,    0,   50,    0,    0,   51,    0,
   51,    0,   51,    0,   49,   49,   49,   49,   49,   49,
    0,   51,   51,   49,    0,   51,    0,    0,   49,    0,
   49,    0,   49,    0,   46,   46,    0,    0,   46,   46,
    0,   49,   49,   46,    0,   49,    0,    0,   46,    0,
   46,    0,   46,   47,   47,    0,    0,   47,   47,   44,
    0,    0,   47,    0,   44,   46,    0,   47,   44,   47,
    0,   47,    0,   44,    0,   44,    0,   44,  109,  110,
  111,  112,  113,  114,   47,    0,    0,    0,    0,    0,
   44,    0,    0,    0,  115,  109,  110,  111,  112,  113,
  114,  116,  117,    0,  118,  119,  120,    0,  121,    0,
    0,  122,  109,  110,  111,  112,  113,  114,  116,  117,
    0,  118,  119,  120,    0,  121,    0,    0,  123,  109,
  110,  111,  112,  113,  114,  116,  117,    0,  118,  119,
  120,    0,  121,  124,  109,  110,  111,  112,  113,  114,
    0,    0,  116,  117,    0,  118,  119,  120,   15,  121,
   15,   15,  128,    0,    0,    0,    0,  116,  117,   15,
  118,  119,  120,    0,  121,  109,  110,  111,  112,  113,
  114,   15,   15,   15,    0,    0,  109,  110,  111,  112,
  113,  114,    0,  129,    0,    0,    0,    0,  116,  117,
    0,  118,  119,  120,  130,  121,    0,    0,    0,  116,
  117,    0,  118,  119,  120,    0,  121,  109,  110,  111,
  112,  113,  114,   20,   21,   65,   22,   23,   24,   25,
    0,    0,    0,  132,  109,  110,  111,  112,  113,  114,
  116,  117,    0,  118,  119,  120,    0,  121,   15,   15,
   15,   15,  149,    0,    0,    0,    0,  116,  117,   15,
  118,  119,  120,    0,  121,  109,  110,  111,  112,  113,
  114,    0,   15,   15,  155,    0,   57,   57,   57,   57,
   57,   57,    0,    0,    0,    0,    0,    0,  116,  117,
    0,  118,  119,  120,   57,  121,  111,  112,    0,   57,
   57,    0,   57,   57,   57,    0,   57,  110,  111,  112,
  113,    0,    0,    0,    0,    0,    0,  116,  117,    0,
  118,  119,  120,    0,  121,    0,    0,    0,    0,  116,
  117,    0,  118,  119,  120,   36,  121,   37,   38,    0,
    0,    0,    0,    0,    0,    0,   39,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   40,
   41,
};
short yycheck[] = {                                      18,
    0,   54,   55,   56,   57,  115,    4,   60,   61,   62,
  269,  258,  122,  123,  279,  259,  289,  281,   71,   72,
   73,   74,   75,   76,  268,  269,  270,  271,  288,  277,
   28,  282,  291,  281,   53,  279,  290,   45,  286,    1,
  288,   94,  290,  153,   13,  295,    8,  269,  292,  293,
   58,   13,  302,   15,  257,  303,  109,  110,  111,  112,
  113,  114,   31,  116,  117,  118,  119,  120,  121,   31,
   32,   32,  292,   33,  259,  278,  279,  280,  291,   41,
   40,  282,  289,   45,   45,  289,  289,  306,  307,  308,
  293,  294,  289,  287,  297,  298,   58,   58,   60,   61,
  303,  304,  305,  306,  307,  308,  272,  273,  274,  275,
  276,  277,  301,  301,  269,  281,  287,  301,  295,  296,
  286,  298,  288,  289,  290,  302,  290,  289,  291,  295,
  296,  292,  298,  299,  300,  301,  302,  303,  272,  273,
  274,  275,  276,  277,  286,  260,  261,  281,  263,  264,
  265,  266,  286,  267,  288,  288,  290,  268,  269,  270,
  271,  290,  296,    0,  298,  299,  300,  288,  279,  303,
  272,  273,  274,  275,  276,  277,  282,   15,  291,  281,
  291,  292,  293,  288,  286,  288,  288,  288,  290,  268,
  269,  270,  271,   61,  296,  101,  298,  299,  300,  155,
  279,  303,  272,  273,  274,  275,  276,  277,   -1,   -1,
   -1,  281,  291,  292,  293,   -1,  286,   -1,  288,   -1,
  290,  272,  273,  274,  275,  276,  296,   -1,  298,  299,
  300,   -1,   -1,  303,  272,  273,  274,  275,  276,  277,
   -1,   -1,   -1,   -1,  295,  296,   -1,  298,  299,  300,
   -1,  302,   -1,   -1,   -1,   -1,   -1,  295,  296,  259,
  298,  299,  300,   -1,  302,  303,   -1,   -1,  268,  269,
  270,  271,   -1,  272,  273,  274,  275,  276,  277,  279,
   -1,   -1,  281,   -1,   -1,   -1,   -1,  286,   -1,  288,
   -1,  290,  292,  293,  272,  273,  274,  275,  276,  277,
  299,  300,   -1,  281,  303,   -1,   -1,   -1,  286,   -1,
  288,   -1,  290,   -1,  272,  273,  274,  275,  276,  277,
   -1,  299,  300,  281,   -1,  303,   -1,   -1,  286,   -1,
  288,   -1,  290,   -1,  272,  273,  274,  275,  276,  277,
   -1,  299,  300,  281,   -1,  303,   -1,   -1,  286,   -1,
  288,   -1,  290,   -1,  272,  273,   -1,   -1,  276,  277,
   -1,  299,  300,  281,   -1,  303,   -1,   -1,  286,   -1,
  288,   -1,  290,  272,  273,   -1,   -1,  276,  277,  272,
   -1,   -1,  281,   -1,  277,  303,   -1,  286,  281,  288,
   -1,  290,   -1,  286,   -1,  288,   -1,  290,  272,  273,
  274,  275,  276,  277,  303,   -1,   -1,   -1,   -1,   -1,
  303,   -1,   -1,   -1,  288,  272,  273,  274,  275,  276,
  277,  295,  296,   -1,  298,  299,  300,   -1,  302,   -1,
   -1,  288,  272,  273,  274,  275,  276,  277,  295,  296,
   -1,  298,  299,  300,   -1,  302,   -1,   -1,  288,  272,
  273,  274,  275,  276,  277,  295,  296,   -1,  298,  299,
  300,   -1,  302,  286,  272,  273,  274,  275,  276,  277,
   -1,   -1,  295,  296,   -1,  298,  299,  300,  268,  302,
  270,  271,  290,   -1,   -1,   -1,   -1,  295,  296,  279,
  298,  299,  300,   -1,  302,  272,  273,  274,  275,  276,
  277,  291,  292,  293,   -1,   -1,  272,  273,  274,  275,
  276,  277,   -1,  290,   -1,   -1,   -1,   -1,  295,  296,
   -1,  298,  299,  300,  290,  302,   -1,   -1,   -1,  295,
  296,   -1,  298,  299,  300,   -1,  302,  272,  273,  274,
  275,  276,  277,  260,  261,  262,  263,  264,  265,  266,
   -1,   -1,   -1,  288,  272,  273,  274,  275,  276,  277,
  295,  296,   -1,  298,  299,  300,   -1,  302,  268,  269,
  270,  271,  290,   -1,   -1,   -1,   -1,  295,  296,  279,
  298,  299,  300,   -1,  302,  272,  273,  274,  275,  276,
  277,   -1,  292,  293,  281,   -1,  272,  273,  274,  275,
  276,  277,   -1,   -1,   -1,   -1,   -1,   -1,  295,  296,
   -1,  298,  299,  300,  290,  302,  274,  275,   -1,  295,
  296,   -1,  298,  299,  300,   -1,  302,  273,  274,  275,
  276,   -1,   -1,   -1,   -1,   -1,   -1,  295,  296,   -1,
  298,  299,  300,   -1,  302,   -1,   -1,   -1,   -1,  295,
  296,   -1,  298,  299,  300,  268,  302,  270,  271,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  279,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  292,
  293,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 308
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"NULL_LITERAL","KEY_PROCEDURE",
"KEY_VAR","KEY_CHARPTR","KEY_INTPTR","KEY_STRING","KEY_INTEGER","KEY_REAL",
"KEY_BOOLEAN","KEY_CHAR","KEY_ELSE","KEY_IF","KEY_RETURN","KEY_FOR","KEY_WHILE",
"OP_AND","OP_EQ","OP_GE","OP_LE","OP_NE","OP_OR","STRING_LITERAL","IDENTIFIER",
"CHAR_LITERAL","COMMA","COLON","DOT","SINGLE_QUOTE","QUOTE","SQ_BRA_C",
"SQ_BRA_O","PARAN_C","PARAN_O","SEMICOLON","BRA_C","BRA_O","OP_DEREFERENCE",
"OP_ADDRESS_OF","OP_MULTI","OP_PLUS","OP_NOT","OP_MINUS","OP_LT","OP_GT",
"ASSIGN","OP_DIV","OP_ABS","TRUE_LITERAL","FALSE_LITERAL","INTEGER_LITERAL",
"HEX_LITERAL","REAL_LITERAL",
};
char *yyrule[] = {
"$accept : PROGRAM",
"PROGRAM : PROCEDURES",
"PROCEDURES : PROCEDURE PROCEDURES",
"PROCEDURES :",
"PROCEDURE : KEY_PROCEDURE IDENT PARAN_O PARAM_L PARAN_C KEY_RETURN TYPE BRA_O BODY BRA_C",
"IDENT : IDENTIFIER",
"IDENTARR : IDENTIFIER SQ_BRA_O EXPR SQ_BRA_C",
"PARAM_L : SPARAMS",
"PARAM_L : SPARAMS SEMICOLON PARAM_L",
"PARAM_L :",
"SPARAMS : PARAMS COLON TYPE",
"PARAMS : IDENT COMMA PARAMS",
"PARAMS : IDENT",
"BODY : PROCEDURES VAR_DECS STMTS RET_STMT",
"VAR_DECS : VAR_DEC VAR_DECS",
"VAR_DECS :",
"VAR_DEC : KEY_VAR PARAMS COLON ARTYPE SEMICOLON",
"STMTS : STMT STMTS",
"STMTS :",
"STMT : ASSIGNMENT",
"STMT : IF_STMT",
"STMT : IF_ELSE_STMT",
"STMT : FOR_STMT",
"STMT : WHILE_STMT",
"STMT : CODE_BLOCK",
"ASSIGNMENT : IDENT ASSIGN EXPR SEMICOLON",
"ASSIGNMENT : IDENTARR ASSIGN EXPR SEMICOLON",
"ASSIGNMENT : OP_DEREFERENCE IDENT ASSIGN EXPR SEMICOLON",
"ASSIGNMENT : IDENT ASSIGN FN_CALL",
"ASSIGNMENT : IDENTARR ASSIGN FN_CALL",
"CODE_BLOCK : BRA_O VAR_DECS STMTS BRA_C",
"FN_CALL : IDENT PARAN_O EXPR_LIST PARAN_C SEMICOLON",
"EXPR_LIST : EXPR COMMA EXPR_LIST",
"EXPR_LIST : EXPR",
"EXPR_LIST :",
"IF_ELSE_STMT : KEY_IF PARAN_O EXPR PARAN_C CODE_BLOCK KEY_ELSE CODE_BLOCK",
"IF_STMT : KEY_IF PARAN_O EXPR PARAN_C CODE_BLOCK",
"FOR_STMT : KEY_FOR PARAN_O EXPR PARAN_C CODE_BLOCK",
"WHILE_STMT : KEY_WHILE PARAN_O EXPR PARAN_C CODE_BLOCK",
"RET_STMT : KEY_RETURN EXPR SEMICOLON",
"EXPR : EXPR OP_PLUS EXPR",
"EXPR : EXPR OP_MINUS EXPR",
"EXPR : EXPR OP_MULTI EXPR",
"EXPR : EXPR OP_DIV EXPR",
"EXPR : EXPR OP_AND EXPR",
"EXPR : EXPR OP_OR EXPR",
"EXPR : EXPR OP_EQ EXPR",
"EXPR : EXPR OP_NE EXPR",
"EXPR : EXPR OP_GE EXPR",
"EXPR : EXPR OP_GT EXPR",
"EXPR : EXPR OP_LE EXPR",
"EXPR : EXPR OP_LT EXPR",
"EXPR : OP_NOT EXPR",
"EXPR : OP_MINUS EXPR",
"EXPR : OP_DEREFERENCE EXPR",
"EXPR : OP_ADDRESS_OF EXPR",
"EXPR : OP_ABS EXPR OP_ABS",
"EXPR : IDENT",
"EXPR : PARAN_O EXPR PARAN_C",
"EXPR : IDENTARR",
"EXPR : LITERAL",
"TYPE : KEY_CHARPTR",
"TYPE : KEY_INTPTR",
"TYPE : KEY_INTEGER",
"TYPE : KEY_REAL",
"TYPE : KEY_BOOLEAN",
"TYPE : KEY_CHAR",
"ARTYPE : TYPE",
"ARTYPE : KEY_STRING SQ_BRA_O LITERAL_NUM SQ_BRA_C",
"LITERAL : LITERAL_STRING",
"LITERAL : LITERAL_NUM",
"LITERAL : LITERAL_CHAR",
"LITERAL : LITERAL_BOOLEAN",
"LITERAL : NULL_LITERAL",
"LITERAL_STRING : STRING_LITERAL",
"LITERAL_CHAR : CHAR_LITERAL",
"LITERAL_NUM : INTEGER_LITERAL",
"LITERAL_NUM : HEX_LITERAL",
"LITERAL_NUM : REAL_LITERAL",
"LITERAL_BOOLEAN : TRUE_LITERAL",
"LITERAL_BOOLEAN : FALSE_LITERAL",
};
#endif
#if YYDEBUG
#include <stdio.h>
#endif

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  10000
#endif
#endif

#define YYINITSTACKSIZE 500

int      yydebug;
int      yynerrs;
int      yyerrflag;
int      yychar;
short   *yyssp;
YYSTYPE *yyvsp;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* variables for the parser stack */
static short   *yyss;
static short   *yysslim;
static YYSTYPE *yyvs;
static int      yystacksize;
#line 282 "parser.y"

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





#line 531 "y.tab.c"
/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(void)
{
    int newsize, i;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = yystacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = yyssp - yyss;
    newss = (yyss != 0)
          ? (short *)realloc(yyss, newsize * sizeof(*newss))
          : (short *)malloc(newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    yyss  = newss;
    yyssp = newss + i;
    newvs = (yyvs != 0)
          ? (YYSTYPE *)realloc(yyvs, newsize * sizeof(*newvs))
          : (YYSTYPE *)malloc(newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    yyvs = newvs;
    yyvsp = newvs + i;
    yystacksize = newsize;
    yysslim = yyss + newsize - 1;
    return 0;
}

#define YYABORT goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(void)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;

    if (yyss == NULL && yygrowstack()) goto yyoverflow;
    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yyssp >= yysslim && yygrowstack())
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

#ifdef lint
    goto yyerrlab;
#endif

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yysslim && yygrowstack())
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yyvsp[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 129 "parser.y"
{printf("Syntax and Parsing: ok \n"); ast = make_program(yyvsp[0].pro_l); }
break;
case 2:
#line 132 "parser.y"
{yyval.pro_l = yyvsp[0].pro_l;yyvsp[0].pro_l->list[yyvsp[0].pro_l->i++] = yyvsp[-1].proc;}
break;
case 3:
#line 133 "parser.y"
{yyval.pro_l = make_proc_list();}
break;
case 4:
#line 136 "parser.y"
{yyval.proc = make_procedure_node(yyvsp[-8].ref,yyvsp[-6].params_l,yyvsp[-3].type_,yyvsp[-1].body);}
break;
case 5:
#line 140 "parser.y"
{yyval.ref = make_symbol_ref(yyvsp[0].str,yylineno,NULL);}
break;
case 6:
#line 143 "parser.y"
{yyval.ref = make_symbol_ref(yyvsp[-3].str,yylineno,yyvsp[-1].exp);}
break;
case 7:
#line 145 "parser.y"
{yyval.params_l = make_params_list();
				   yyval.params_l->list[yyval.params_l->i++] = yyvsp[0].param;}
break;
case 8:
#line 147 "parser.y"
{yyval.params_l = yyvsp[0].params_l;
								  	 yyvsp[0].params_l->list[yyvsp[0].params_l->i++] = yyvsp[-2].param;}
break;
case 9:
#line 149 "parser.y"
{yyval.params_l = make_params_list();}
break;
case 10:
#line 152 "parser.y"
{yyval.param = make_params(yyvsp[0].type_,yyvsp[-2].symbol_l);}
break;
case 11:
#line 155 "parser.y"
{yyval.symbol_l = yyvsp[0].symbol_l;
							  yyvsp[0].symbol_l->list[yyvsp[0].symbol_l->i++] = yyvsp[-2].ref;}
break;
case 12:
#line 157 "parser.y"
{yyval.symbol_l =  make_symbol_list();
	   	 		yyval.symbol_l->list[yyval.symbol_l->i++] = yyvsp[0].ref;}
break;
case 13:
#line 161 "parser.y"
{yyval.body = make_body_node(yyvsp[-3].pro_l,yyvsp[-2].var_dec_l,yyvsp[-1].stmt_l,yyvsp[0].ret);}
break;
case 14:
#line 164 "parser.y"
{yyval.var_dec_l = yyvsp[0].var_dec_l; yyvsp[0].var_dec_l->list[yyvsp[0].var_dec_l->i++] = yyvsp[-1].var_dec;}
break;
case 15:
#line 165 "parser.y"
{yyval.var_dec_l = make_var_dec_list();}
break;
case 16:
#line 168 "parser.y"
{yyval.var_dec = make_var_decs(yyvsp[-1].type_,yyvsp[-3].symbol_l);}
break;
case 17:
#line 172 "parser.y"
{yyval.stmt_l = yyvsp[0].stmt_l;
					yyvsp[0].stmt_l->list[yyvsp[0].stmt_l->i++] = yyvsp[-1].stmt_;}
break;
case 18:
#line 174 "parser.y"
{yyval.stmt_l = make_stmt_list();}
break;
case 19:
#line 177 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].assign_);}
break;
case 20:
#line 178 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].if_);}
break;
case 21:
#line 179 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].if_else_);}
break;
case 22:
#line 180 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].for_);}
break;
case 23:
#line 181 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].while_);}
break;
case 24:
#line 182 "parser.y"
{yyval.stmt_ = make_stmt(yyvsp[0].block);}
break;
case 25:
#line 185 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_,yyvsp[-3].ref,yyvsp[-1].exp);}
break;
case 26:
#line 186 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_,yyvsp[-3].ref,yyvsp[-1].exp);}
break;
case 27:
#line 187 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_DER_,yyvsp[-3].ref,yyvsp[-1].exp);}
break;
case 28:
#line 188 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_,yyvsp[-2].ref,yyvsp[0].call);}
break;
case 29:
#line 189 "parser.y"
{yyval.assign_ = make_assign(ASSIGN_,yyvsp[-2].ref,yyvsp[0].call);}
break;
case 30:
#line 192 "parser.y"
{yyval.block = make_code_block(yyvsp[-2].var_dec_l,yyvsp[-1].stmt_l);}
break;
case 31:
#line 196 "parser.y"
{yyval.call = make_fn_call(yyvsp[-4].ref,yyvsp[-2].expr_l);}
break;
case 32:
#line 199 "parser.y"
{yyval.expr_l = yyvsp[0].expr_l;
	  							  yyvsp[0].expr_l->list[yyvsp[0].expr_l->i++] = yyvsp[-2].exp;}
break;
case 33:
#line 201 "parser.y"
{yyval.expr_l = make_expr_list();
		  		  yyval.expr_l->list[yyval.expr_l->i++] = yyvsp[0].exp; }
break;
case 34:
#line 203 "parser.y"
{yyval.expr_l = make_expr_list();}
break;
case 35:
#line 206 "parser.y"
{yyval.if_else_ = make_if_else_node(yylineno,yyvsp[-4].exp,yyvsp[-2].block,yyvsp[0].block);}
break;
case 36:
#line 209 "parser.y"
{yyval.if_ = make_if_node(yylineno,yyvsp[-2].exp,yyvsp[0].block);}
break;
case 37:
#line 212 "parser.y"
{yyval.for_=make_for_node(yylineno,yyvsp[-2].exp,yyvsp[0].block);}
break;
case 38:
#line 215 "parser.y"
{yyval.while_ = make_while_node(yylineno,yyvsp[-2].exp,yyvsp[0].block);}
break;
case 39:
#line 218 "parser.y"
{yyval.ret = make_ret_stmt(yyvsp[-1].exp);}
break;
case 40:
#line 221 "parser.y"
{yyval.exp = make_expr(make_op(PLUS_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 41:
#line 222 "parser.y"
{yyval.exp = make_expr(make_op(MINUS_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 42:
#line 223 "parser.y"
{yyval.exp = make_expr(make_op(MULTI_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 43:
#line 224 "parser.y"
{yyval.exp = make_expr(make_op(DIV_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 44:
#line 225 "parser.y"
{yyval.exp = make_expr(make_rel(AND_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 45:
#line 226 "parser.y"
{yyval.exp = make_expr(make_rel(OR_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 46:
#line 227 "parser.y"
{yyval.exp = make_expr(make_rel(EQ_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 47:
#line 228 "parser.y"
{yyval.exp = make_expr(make_rel(NE_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 48:
#line 229 "parser.y"
{yyval.exp = make_expr(make_rel(GE_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 49:
#line 230 "parser.y"
{yyval.exp = make_expr(make_rel(GT_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 50:
#line 231 "parser.y"
{yyval.exp = make_expr(make_rel(LE_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 51:
#line 232 "parser.y"
{yyval.exp = make_expr(make_rel(LT_,yylineno,yyvsp[-2].exp,yyvsp[0].exp));}
break;
case 52:
#line 233 "parser.y"
{yyval.exp = make_expr(make_rel(NOT_,yylineno,yyvsp[0].exp,NULL));}
break;
case 53:
#line 234 "parser.y"
{yyval.exp = make_expr(make_op(UMINUS_,yylineno,yyvsp[0].exp,NULL));}
break;
case 54:
#line 235 "parser.y"
{yyval.exp = make_expr(make_op(DEREFERENCE_,yylineno,yyvsp[0].exp,NULL));}
break;
case 55:
#line 236 "parser.y"
{yyval.exp = make_expr(make_op(ADDRESS_OF_,yylineno,yyvsp[0].exp,NULL));}
break;
case 56:
#line 237 "parser.y"
{yyval.exp = make_expr(make_op(ABS_,yylineno,yyvsp[-1].exp,NULL)); }
break;
case 57:
#line 238 "parser.y"
{yyval.exp = make_expr(yyvsp[0].ref);}
break;
case 58:
#line 239 "parser.y"
{yyval.exp = yyvsp[-1].exp;}
break;
case 59:
#line 240 "parser.y"
{yyval.exp = make_expr(yyvsp[0].ref);}
break;
case 60:
#line 241 "parser.y"
{yyval.exp = make_expr(yyvsp[0].l);}
break;
case 61:
#line 246 "parser.y"
{ yyval.type_ = make_type(CHARPTR_,0);}
break;
case 62:
#line 247 "parser.y"
{ yyval.type_ = make_type(INTPTR_,0);}
break;
case 63:
#line 248 "parser.y"
{ yyval.type_ = make_type(INTEGER_,0);}
break;
case 64:
#line 249 "parser.y"
{ yyval.type_ = make_type(REAL_,0);}
break;
case 65:
#line 250 "parser.y"
{ yyval.type_ = make_type(BOOLEAN_,0);}
break;
case 66:
#line 251 "parser.y"
{ yyval.type_ = make_type(CHAR_,0);}
break;
case 68:
#line 255 "parser.y"
{ yyval.type_ = make_type(STRING_,yyvsp[-1].lit_i->value);}
break;
case 69:
#line 259 "parser.y"
{ yyval.l = make_lit(yyvsp[0].lit_s);}
break;
case 70:
#line 260 "parser.y"
{ yyval.l = make_lit(yyvsp[0].lit_i);}
break;
case 71:
#line 261 "parser.y"
{ yyval.l = make_lit(yyvsp[0].lit_c);}
break;
case 72:
#line 262 "parser.y"
{ yyval.l = make_lit(yyvsp[0].lit_b);}
break;
case 73:
#line 263 "parser.y"
{ yyval.l = make_lit(make_lit_null());}
break;
case 74:
#line 266 "parser.y"
{ yyval.lit_s = make_lit_string(yyvsp[0].str);}
break;
case 75:
#line 269 "parser.y"
{ yyval.lit_c = make_lit_char(yyvsp[0].ch);}
break;
case 76:
#line 272 "parser.y"
{ yyval.lit_i = make_lit_integer(yyvsp[0].num);}
break;
case 77:
#line 273 "parser.y"
{ yyval.lit_i = make_lit_integer(yyvsp[0].num);}
break;
case 78:
#line 274 "parser.y"
{ yyval.lit_i = make_lit_real(yyvsp[0].num);}
break;
case 79:
#line 277 "parser.y"
{ yyval.lit_b = make_lit_boolean(1);}
break;
case 80:
#line 278 "parser.y"
{ yyval.lit_b = make_lit_boolean(0);}
break;
#line 1035 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yyssp, yystate);
#endif
    if (yyssp >= yysslim && yygrowstack())
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    return (1);

yyaccept:
    return (0);
}
