grammar Dream;

// 程序
program
    : packageDecl importStatement* statement* EOF
    ;

// 包声明
packageDecl
    : PACKAGE qualifiedName SEMICOLON
    ;

// 导入语句
importStatement
    : IMPORT qualifiedName SEMICOLON
    ;

// 语句
statement
    : declaration
    | expression SEMICOLON
    | ifStatement
    | forStatement
    | funCallStatement SEMICOLON
    ;

// 函数调用语句
funCallStatement
    : IDENTIFIER (DOT IDENTIFIER)* LPAREN paramList? RPAREN
    ;

// 二元运算
binaryOperation
    : atomExpr (PLUS | MINUS | MUL | DIV | MOD | LT | GT | LE | GE | EQ | NEQ | AND | OR | BIT_AND | BIT_OR | XOR | LSHIFT | RSHIFT | URSHIFT) atomExpr
    ;

// 原子表达式
atomExpr
    : (IDENTIFIER (DOT IDENTIFIER)*) 
    | NEW IDENTIFIER LPAREN argList? RPAREN 
    | IDENTIFIER LPAREN expression RPAREN SEMICOLON 
    | literal 
    | arrayInit 
    | castExpr 
    | assign
    ;

// 参数列表
argList
    : expression (COMMA expression)*
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
    : LBRACK expression (COMMA expression)* RBRACK
    ;

// 表达式
castExpr
    : LPAREN type RPAREN expression
    ;

// 赋值表达式
assign
    : (IDENTIFIER (DOT IDENTIFIER)*) ASSIGN expression
    ;

// 一元运算
unaryOp
    : NOT expression 
    | PLUS expression 
    | MINUS expression 
    | INC expression 
    | DEC expression
    ;

// if 表达式
ifStatement
    : IF expression ifBlock (elseIfClause)* (ELSE ifBlock)?
    ;

// if 块
ifBlock
    : LBRACE (ifStatementBody)* RBRACE
    ;

// if 语句
ifStatementBody
    : expression SEMICOLON 
    | ifStatement 
    | returnStatement 
    | forStatement 
    | BREAK SEMICOLON 
    | CONTINUE SEMICOLON 
    | funCallStatement SEMICOLON
    ;

// return 语句
returnStatement
    : RETURN expression SEMICOLON 
    | RETURN LPAREN expression (COMMA expression)* RPAREN SEMICOLON
    ;

// else if 子句
elseIfClause
    : ELSE IF expression ifBlock
    ;

// 表达式
expression
    : binaryOperation 
    | unaryOp 
    | atomExpr 
    | castExpr 
    | assignExpr 
    | IDENTIFIER (DOT IDENTIFIER)* LPAREN argList* RPAREN 
    | expression (PLUS | MINUS | MUL | DIV | MOD | LT | GT | LE | GE | EQ | NEQ | AND | OR | BIT_AND | BIT_OR | XOR | LSHIFT | RSHIFT | URSHIFT) expression 
    | LPAREN expression RPAREN
    ;

// 赋值表达式
assignExpr
    : type IDENTIFIER ASSIGN expression 
    | IDENTIFIER IDENTIFIER ASSIGN expression
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
    : (VAR | IMT) varModifiers? type IDENTIFIER (BANG | QUESTION)? (ASSIGN expression)? SEMICOLON
    ;

// 变量修饰符
varModifiers
    : annotation+
    ;

// 函数声明
functionDeclaration
    : funModifiers? FUN IDENTIFIER LPAREN (paramList)? RPAREN returnType? funBlock
    ;

// 函数块
funBlock
    : LBRACE (funStatement)* RBRACE
    ;

// 函数语句
funStatement
    : tryCatchStatement 
    | TRY SEMICOLON 
    | ifStatement 
    | forStatement 
    | funVarDeclaration 
    | returnStatement 
    | expression SEMICOLON 
    | throwStatement 
    | codeBlock
    ;

// 函数变量声明
funVarDeclaration
    : (VAR | IMT) varModifiers? type IDENTIFIER (BANG | QUESTION)? (ASSIGN expression)? SEMICOLON
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
    : LBRACE classBody* RBRACE
    ;

// 类体
classBody
    : classVarDecl 
    | classFuncDecl 
    | constructorDecl
    ;

// 类成员变量声明
classVarDecl
    : classMemberModifier* (annotation)* (VAR | IMT) type IDENTIFIER (BANG | QUESTION)? ('=' expression)? SEMICOLON
    ;

// 类成员函数声明
classFuncDecl
    : classMemberModifier? (annotation)* FUN IDENTIFIER LPAREN (paramList)? RPAREN returnType? funBlock
    ;

// 类成员修饰符
classMemberModifier
    : memberModifier 
    | visibilityModifier 
    | staticModifier
    ;

// 构造函数声明
constructorDecl
    : classMemberModifier? (annotation)* IDENTIFIER LPAREN (paramList)? RPAREN LBRACE classFunStatementBlock* RBRACE
    ;

// 类函数语句块
classFunStatementBlock
    : expression SEMICOLON 
    | ifStatement 
    | forStatement 
    | funVarDeclaration 
    | returnStatement 
    | tryCatchStatement 
    | throwStatement
    ;

// try-catch 语句
tryCatchStatement
    : tryStatement
    ;

// 抛出语句
throwStatement
    : THROW expression SEMICOLON
    ;

// 同步语句
synchronizedStatement
    : SYNCHRONIZED LPAREN expression RPAREN funBlock
    ;

// try 语句
tryStatement
    : TRY codeBlock? catches? 
    | TRY codeBlock? catches? finally_
    ;

// catch 子句
catches
    : catchClause catchClause*
    ;

// catch 子句
catchClause
    : CATCH LPAREN catchFormalParameter RPAREN LBRACE statement* RBRACE
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
    : FINALLY LBRACE statement* RBRACE
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

// 参数列表
paramList
    : param (COMMA param)*
    ;

// 参数
param
    : type IDENTIFIER (BANG | QUESTION)?
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
    | FLOAT 
    | DOUBLE 
    | BOOL 
    | CHAR 
    | STRING 
    | IDENTIFIER
    ;

// 数组类型
arrayType
    : singleType LBRACK+ RBRACK
    ;

// 返回类型
returnType
    : type (BANG | QUESTION)?
    | LPAREN type (BANG | QUESTION)? (COMMA type (BANG | QUESTION)?) RPAREN
    ;

// for 循环
forStatement
    : FOR forCondition forBlock
    ;

// for 条件
forCondition
    : forVarDecl SEMICOLON expression SEMICOLON expression
    | expression*
    ;

// for 块
forBlock
    : LBRACE forBody* RBRACE
    ;

// for 体
forBody
    : expression SEMICOLON 
    | ifStatement 
    | forStatement 
    | returnStatement 
    | BREAK SEMICOLON 
    | CONTINUE SEMICOLON 
    | funCallStatement SEMICOLON
    ;

// for 变量声明
forVarDecl
    : type IDENTIFIER ASSIGN expression
    ;

// 代码块
codeBlock
    : LBRACE codeBlockBody RBRACE
    ;

// 代码块体
codeBlockBody
    : codeBlockStatement*
    ;

// 代码块语句
codeBlockStatement
    : expression SEMICOLON 
    | ifStatement 
    | forStatement 
    | returnStatement 
    | BREAK 
    | CONTINUE 
    | funCallStatement SEMICOLON 
    | throwStatement 
    | tryStatement 
    | tryCatchStatement
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

SYNCHRONIZED: 'synchronized';
THROW : 'throw';

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
LONG : 'long';
FLOAT : 'float';
DOUBLE : 'double';
BOOL : 'bool';
CHAR : 'char';
STRING : 'string';

AT : '@';

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
PLUS : '+';
MINUS : '-';
MUL : '*';
DIV : '/';
MOD : '%';
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
// 增减操作符
INC : '++';
DEC : '--';

// 字面量
IDENTIFIER : [a-zA-Z_][a-zA-Z_0-9]*;