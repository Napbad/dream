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
    : (VAR | IMT) varModifiers? type IDENTIFIER (BANG | QUESTION)? (ASSIGN expr)? SEMICOLON
    ;

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
    : NOT expr
    | PLUS expr
    | MINUS expr
    | INC expr
    | DEC expr
    | TIBLE expr
    ;

// if 表达式
ifStmt
    : IF expr ifBlock (elseIfClause)* (elseClause)?
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
    : ELSE IF expr ifBlock
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
    | classDeclaration
    | interfaceDeclaration
    | annotationDeclaration
    ;

// 变量声明
varDeclaration
    : (VAR | IMT) varModifiers? type IDENTIFIER (BANG | QUESTION)? (ASSIGN expr)? SEMICOLON
    ;

// 变量修饰符
varModifiers
    : annotation+
    ;

// 文件函数声明
functionDeclaration
    : funModifiers? FUN IDENTIFIER LPAREN (paramList)? RPAREN returnType? funBlock
    ;

// 类成员变量声明
classVarDecl
    : classMemberModifier* (annotation)* (VAR | IMT) type IDENTIFIER (BANG | QUESTION)? ('=' expr)? SEMICOLON
    ;

// 类成员函数声明
classFuncDecl
    : classMemberModifier* (annotation)* CONST? FUN IDENTIFIER LPAREN (paramList)? RPAREN returnType? funBlock
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


// 函数修饰符
funModifiers
    : annotation+
    ;

// 类声明
classDeclaration
    : classModifiers* CLASS IDENTIFIER (COLON (IDENTIFIER (COMMA IDENTIFIER)*))? classBlock
    ;

// 类修饰符
classModifiers
    : annotation+
    | classModifier
    ;

// 类修饰符
classModifier
    : ENUM
    | ANNOTATION
    ;

// 类块
classBlock
    : LBRACE RBRACE
    | LBRACE classBody RBRACE
    ;

// 类体
classBody
    : classStmt*
    ;

classStmt
    : classVarDecl
    | classFuncDecl
    ;


// 类成员修饰符
classMemberModifier
    : memberModifier
    | visibilityModifier
    | staticModifier
    ;

// 构造函数声明
constructorDecl
    : classMemberModifier? (annotation)* IDENTIFIER LPAREN (paramList)? RPAREN LBRACE classFunStmtBlock* RBRACE
    ;

// 类函数语句块
classFunStmtBlock
    : expr SEMICOLON
    | ifStmt
    | forStmt
    | funVarDeclaration
    | returnStmt
    | tryCatchStmt
    | throwStmt
    | deleteStmt
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
    : varModifiers* catchType IDENTIFIER
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

// 接口声明
interfaceDeclaration
    : INTERFACE IDENTIFIER interfaceBlock
    ;

// 接口块
interfaceBlock
    : LBRACE interfaceBody* RBRACE
    ;

// 接口体
interfaceBody
    : interfaceVarDecl
    | interfaceFuncDecl
    ;

// 接口变量声明
interfaceVarDecl
    : VAR type IDENTIFIER SEMICOLON
    ;

// 接口函数声明
interfaceFuncDecl
    : FUN IDENTIFIER LPAREN (paramList)? RPAREN returnType? SEMICOLON
    ;

// 注解声明
annotationDeclaration
    : ANNOTATION CLASS IDENTIFIER annotationBlock
    ;

// 注解块
annotationBlock
    : LBRACE varDeclaration* RBRACE
    ;

// 注解
annotation
    : AT IDENTIFIER (LBRACE assign* RBRACE)?
    ;

// 合格名称
qualifiedName
    : IDENTIFIER (DOT IDENTIFIER)*
    ;

//argBody
//    : argElement (COMMA argElement)*
//    ;
//
//argElement
//    : expr
//    | IDENTIFIER
//    ;

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
CLASS : 'class';
ENUM : 'enum';
INTERFACE : 'interface';
ANNOTATION : 'annotation';
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

// 字符串字面量
STRING_LITERAL : '"' (~[\n\r"\\]|'\\"'|'\\u'('0'..'9'|'a'..'f'|'A'..'F')+)* '"';

// 字符字面量
CHAR_LITERAL : '\'' (~[\n\r'\\]|'\''|'\\u'('0'..'9'|'a'..'f'|'A'..'F')+)* '\'';

// 数字字面量
INT_LITERAL : ('0'..'9')+;
FLOAT_LITERAL : ('0'..'9')+ '.' ('0'..'9')*;
TRUE_LITERAL : 'true';
FALSE_LITERAL : 'false';

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

