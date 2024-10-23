grammar Dream;

// 程序
program
    : packageDecl? importStmt* (stmt | fileCodeBlock)* EOF
    ;

// 包声明
packageDecl
    : PACKAGE packageName SEMICOLON
    ;

// 导入语句
importStmt
    : IMPORT importName SEMICOLON
    ;

packageName
    : IDENTIFIER (DOT IDENTIFIER)*
    ;

importName
    : IDENTIFIER (DOT IDENTIFIER)*
    ;

// 函数调用语句
funCallStmt
    : SLASH? IDENTIFIER (DOT IDENTIFIER)* LPAREN argList? RPAREN
    ;

// 文件语句
stmt
    : declaration
    | funCallStmt SEMICOLON
    | expr SEMICOLON
    | ifStmt
    | forStmt
    | tryCatchStmt
    | synchronizedStmt
    | deleteStmt
    ;

// 二元运算
binaryOpExpr
    : atomExpr (MOD | MUL | SLASH  | MINUS| PLUS | LT | GT | LE | GE | EQ | NEQ | AND | OR | BIT_AND | BIT_OR | XOR | LSHIFT | RSHIFT | URSHIFT) atomExpr
    ;


// 函数变量声明
funVarDeclaration
    : (VAR | IMT)?  type IDENTIFIER (BANG | QUESTION)? (ASSIGN expr)? SEMICOLON
    ;


// 字符串字面量
STRING_LITERAL
    : '"' (~["\\\r\n] | EscapeSequence)* '"'
    ;

fragment EscapeSequence:
    '\\' 'u005c'? [btnfr"'\\]
    | '\\' 'u005c'? ([0-3]? [0-7])? [0-7]
    | '\\' 'u'+ HexDigit HexDigit HexDigit HexDigit
    ;

fragment HexDigit: [0-9a-fA-F];

// 参数列表
argList
    : expr (COMMA expr)*
    ;

// 字面量
literal
    : INT_LITERAL
    | FLOAT_LITERAL
    | STRING_LITERAL
    | CHAR_LITERAL
    | TRUE_LITERAL
    | FALSE_LITERAL
    ;

// 数组初始化
arrayInit
    : LBRACK (expr (COMMA expr)*)? RBRACK
    | LBRACK (arrayInit (COMMA arrayInit)*)? RBRACK
    ;

// 表达式
castExpr
    : LPAREN type RPAREN expr
    ;

// 赋值表达式
assign
    : (IDENTIFIER (DOT IDENTIFIER)*) ASSIGN expr
    ;

// 一元运算
unaryOpExpr
    : BANG expr
    | PLUS expr
    | MINUS expr
    | INC expr
    | DEC expr
    | TIBLE expr
    ;

ifExpr
    : LPAREN expr RPAREN
    | funCallStmt
    | unaryOpExpr
    | expr (MUL | SLASH | MOD) expr
    | expr (PLUS | MINUS) expr
    | expr (LSHIFT | RSHIFT | URSHIFT) expr
    | expr (LT | GT | LE | GE) expr
    | expr (EQ | NEQ) expr
    | expr BIT_AND expr
    | expr XOR expr
    | expr BIT_OR expr
    | expr AND expr
    | expr OR expr
    | atomExpr
    | castExpr
    | assignExpr
    ;

// if 表达式
ifStmt
    : IF ifExpr ifBlock (elseIfClause)* (elseClause)?
    ;

// if 块
ifBlock
    : LBRACE (ifStmtBody)* RBRACE
    ;

// 原子表达式
atomExpr
    : (IDENTIFIER (DOT IDENTIFIER)*)
    | NEW IDENTIFIER LPAREN argList? RPAREN
    | IDENTIFIER LPAREN expr RPAREN SEMICOLON
    | literal
    | arrayInit
    | castExpr
    | assign
    ;

// if 语句
ifStmtBody
    : expr SEMICOLON
    | ifStmt
    | returnStmt
    | forStmt
    | tryCatchStmt
    | throwStmt
    | BREAK SEMICOLON
    | CONTINUE SEMICOLON
    | funCallStmt SEMICOLON
    ;

// return 语句
returnStmt
    : RETURN expr SEMICOLON
    | RETURN LPAREN expr (COMMA expr)* RPAREN SEMICOLON
    | RETURN SEMICOLON
    ;

// else if 子句
elseIfClause
    : ELSE IF ifExpr ifBlock
    ;

elseClause
    : ELSE ifBlock
    ;

expr
    : LPAREN expr RPAREN
    | funCallStmt
    | unaryOpExpr
    | expr (MUL | SLASH | MOD) expr
    | expr (PLUS | MINUS) expr
    | expr (LSHIFT | RSHIFT | URSHIFT) expr
    | expr (LT | GT | LE | GE) expr
    | expr (EQ | NEQ) expr
    | expr BIT_AND expr
    | expr XOR expr
    | expr BIT_OR expr
    | expr AND expr
    | expr OR expr
    | atomExpr
    | castExpr
    | assignExpr
    ;


// 赋值表达式
assignExpr
    : type IDENTIFIER ASSIGN expr
    | assign
    ;

// 声明
declaration
    : varDeclaration
    | functionDeclaration
    | structDeclaration
    ;

structDeclaration: STRUCT IDENTIFIER LBRACE (structMember)* RBRACE SEMICOLON;

structMember
    : varDeclaration
    ;

// 变量声明
varDeclaration
    : (VAR | IMT)?  type IDENTIFIER (BANG | QUESTION)? (ASSIGN expr)? SEMICOLON
    ;
functionDeclaration
    :  FUN IDENTIFIER LPAREN (paramList)? RPAREN returnType? funBlock
    ;


// 函数块
funBlock
    : LBRACE (funStmt)* RBRACE
    ;

// 函数语句
funStmt
    : tryCatchStmt
    | NATIVE SEMICOLON
    | ifStmt
    | forStmt
    | funVarDeclaration
    | returnStmt
    | expr SEMICOLON
    | throwStmt
    | fileCodeBlock
    ;

// 抛出语句
throwStmt
    : THROW expr SEMICOLON
    ;

// 同步语句
synchronizedStmt
    : SYNCHRONIZED LPAREN expr RPAREN (fileCodeBlock | funCodeBlock)
    ;

// try-catch 语句
tryCatchStmt
    : TRY funCodeBlock catches
    | TRY funCodeBlock catches finally_
    ;

// catch 子句
catches
    : catchClause catchClause*
    ;

// catch 子句
catchClause
    : CATCH catchFormalParameter funCodeBlock
    ;

// catch 形参
catchFormalParameter
    :  catchType IDENTIFIER
    ;

// catch 类型
catchType
    : IDENTIFIER ('|' IDENTIFIER)*
    ;

// finally 块
finally_
    : FINALLY LBRACE stmt* RBRACE
    ;

// 成员修饰符
memberModifier
    : OVERRIDE
    ;

// 可见性修饰符
visibilityModifier
    : PUBLIC
    | PRIVATE
    | PROTECTED
    ;

// 静态修饰符
staticModifier
    : STATIC
    ;
// 参数列表
paramList
    : param (COMMA param)*
    ;

// 参数
param
    : (IMT | VAR)? type IDENTIFIER (BANG | QUESTION)?
    ;

// 类型
type
    : arrayType
    | singleType
    ;

// 单个类型
singleType
    : BYTE
    | SHORT
    | INT
    | LONG
    | USHORT
    | UINT
    | ULONG
    | LONG
    | LONGLONG
    | ULONGLONG
    | FLOAT
    | DOUBLE
    | BOOL
    | CHAR
    | STRING
    | IDENTIFIER
    ;

// 数组类型
arrayType
    : singleType (LBRACK IDENTIFIER? RBRACK)+
    ;

// 返回类型
returnType
    : type (BANG | QUESTION)?
    | LPAREN type (BANG | QUESTION)? (COMMA type (BANG | QUESTION)?) RPAREN
    | VOID
    | IDENTIFIER (BANG | QUESTION)?
    | LPAREN IDENTIFIER (BANG | QUESTION)? (COMMA IDENTIFIER (BANG | QUESTION)?) RPAREN
    ;

// for 循环
forStmt
    : FOR forCondition forBlock
    ;

// for 条件
forCondition
    : forVarDecl SEMICOLON expr SEMICOLON expr
    | expr+
    ;

// for 块
forBlock
    : LBRACE forBody* RBRACE
    ;

// for 体
forBody
    : expr SEMICOLON
    | funVarDeclaration
    | ifStmt
    | forStmt
    | returnStmt
    | BREAK SEMICOLON
    | CONTINUE SEMICOLON
    | funCallStmt SEMICOLON
    | deleteStmt
    ;

// for 变量声明
forVarDecl
    : type IDENTIFIER ASSIGN expr
    ;

// 代码块
fileCodeBlock
    : LBRACE fileCodeBlockBody* RBRACE
    ;

// 代码块体
fileCodeBlockBody
    : fileCodeBlockStmt
    | fileCodeBlock
    ;

// 代码块语句
fileCodeBlockStmt
    : expr SEMICOLON
    | declaration
    | ifStmt
    | forStmt
    | returnStmt
    | BREAK
    | CONTINUE
    | funCallStmt SEMICOLON
    | throwStmt
    | tryCatchStmt
    ;

funCodeBlock
    :LBRACE funCodeBlockBody RBRACE
    ;

funCodeBlockBody
    : funCodeBlockStmt*
    ;

funCodeBlockStmt
    : expr SEMICOLON
    | ifStmt
    | forStmt
    | returnStmt
    | BREAK
    | CONTINUE
    | funCallStmt SEMICOLON
    | throwStmt
    | tryCatchStmt
    | deleteStmt
    ;

deleteStmt
    : DELETE expr SEMICOLON
    | DELETE RBRACK RBRACK SEMICOLON
    ;

// 关键字
RETURN : 'return';
IF : 'if';
ELSE : 'else';
FOR : 'for';
WHILE : 'while';
PACKAGE : 'package';
IMPORT : 'import';

BREAK : 'break';
CONTINUE : 'continue';
TRY : 'try';
CATCH : 'catch';
FINALLY : 'finally';

VAR : 'var';
IMT : 'imt';
FUN : 'fun';
ENUM : 'enum';
STRUCT : 'struct';
PUBLIC : 'public';
PRIVATE : 'private';
PROTECTED : 'protected';
STATIC : 'static';
NEW : 'new';
OVERRIDE : 'override';
NATIVE : 'native';
SYNCHRONIZED: 'synchronized';
THROW : 'throw';

DELETE: 'delete';


// 类型关键字
BYTE : 'byte';
SHORT : 'short';
INT : 'int';
UINT: 'u' INT;
USHORT : 'ushort';
LONG : 'long';
ULONG : 'ulong';
LONGLONG: 'llong';
ULONGLONG : 'ullong';
FLOAT : 'float';
DOUBLE : 'double';
BOOL : 'bool';
CHAR : 'char';
STRING : 'string';
VOID: 'void';

CONST : 'const';


// 字符字面量
CHAR_LITERAL : '\'' (~[\n\r'\\]|'\''|'\\u'('0'..'9'|'a'..'f'|'A'..'F')+)* '\'';

// 数字字面量
INT_LITERAL : ('0'..'9')+;
FLOAT_LITERAL : ('0'..'9')+ '.' ('0'..'9')*;
TRUE_LITERAL : 'true';
FALSE_LITERAL : 'false';


AT : '@';
SLASH : '/';

// 操作符
ASSIGN : '=';
SEMICOLON : ';';
LPAREN : '(';
RPAREN : ')';
LBRACE : '{';
RBRACE : '}';
LBRACK : '[';
RBRACK : ']';
COMMA : ',';

// 注释
LINE_COMMENT : '//' ~[\r\n]* -> channel(HIDDEN);
COMMENT : '/*' .*? '*/' -> channel(HIDDEN);

// 白空格
WS : [ \t\r\n]+ -> skip;

// 其他符号
DOT : '.';
BANG : '!';
QUESTION : '?';
COLON : ':';
MOD : '%';
PLUS : '+';
MINUS : '-';
MUL : '*';
LT : '<';
GT : '>';
LE : '<=';
GE : '>=';
EQ : '==';
NEQ : '!=';
AND : '&&';
OR : '||';
BIT_AND : '&';
BIT_OR : '|';
XOR : '^';
LSHIFT : '<<';
RSHIFT : '>>';
URSHIFT : '>>>';
NOT : BANG;
TIBLE : '~';
// 增减操作符
INC : '++';
DEC : '--';


// 字面量
IDENTIFIER : [a-zA-Z_][a-zA-Z_0-9]*;
