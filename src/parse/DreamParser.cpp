
// Generated from ./Dream.g4 by ANTLR 4.13.2


#include "DreamListener.h"

#include "DreamParser.h"


using namespace antlrcpp;

using namespace antlr4;

namespace {

struct DreamParserStaticData final {
  DreamParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  DreamParserStaticData(const DreamParserStaticData&) = delete;
  DreamParserStaticData(DreamParserStaticData&&) = delete;
  DreamParserStaticData& operator=(const DreamParserStaticData&) = delete;
  DreamParserStaticData& operator=(DreamParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag dreamParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<DreamParserStaticData> dreamParserStaticData = nullptr;

void dreamParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (dreamParserStaticData != nullptr) {
    return;
  }
#else
  assert(dreamParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<DreamParserStaticData>(
    std::vector<std::string>{
      "program", "packageDecl", "importStmt", "packageName", "importName", 
      "funCallStmt", "stmt", "binaryOpExpr", "funVarDeclaration", "argList", 
      "literal", "arrayInit", "castExpr", "assign", "unaryOpExpr", "ifExpr", 
      "ifStmt", "ifBlock", "atomExpr", "ifStmtBody", "returnStmt", "elseIfClause", 
      "elseClause", "expr", "assignExpr", "declaration", "structDeclaration", 
      "structMember", "varDeclaration", "functionDeclaration", "funBlock", 
      "funStmt", "throwStmt", "synchronizedStmt", "tryCatchStmt", "catches", 
      "catchClause", "catchFormalParameter", "catchType", "finally_", "memberModifier", 
      "visibilityModifier", "staticModifier", "paramList", "param", "type", 
      "singleType", "arrayType", "returnType", "forStmt", "forCondition", 
      "forBlock", "forBody", "forVarDecl", "fileCodeBlock", "fileCodeBlockBody", 
      "fileCodeBlockStmt", "funCodeBlock", "funCodeBlockBody", "funCodeBlockStmt", 
      "deleteStmt"
    },
    std::vector<std::string>{
      "", "", "'return'", "'if'", "'else'", "'for'", "'while'", "'package'", 
      "'import'", "'break'", "'continue'", "'try'", "'catch'", "'finally'", 
      "'var'", "'imt'", "'fun'", "'enum'", "'struct'", "'public'", "'private'", 
      "'protected'", "'static'", "'new'", "'override'", "'native'", "'synchronized'", 
      "'throw'", "'delete'", "'byte'", "'short'", "'int'", "", "'ushort'", 
      "'long'", "'ulong'", "'llong'", "'ullong'", "'float'", "'double'", 
      "'bool'", "'char'", "'string'", "'void'", "'const'", "", "", "", "'true'", 
      "'false'", "'@'", "'/'", "'='", "';'", "'('", "')'", "'{'", "'}'", 
      "'['", "']'", "','", "", "", "", "'.'", "'!'", "'\\u003F'", "':'", 
      "'%'", "'+'", "'-'", "'*'", "'<'", "'>'", "'<='", "'>='", "'=='", 
      "'!='", "'&&'", "'||'", "'&'", "'|'", "'^'", "'<<'", "'>>'", "'>>>'", 
      "", "'~'", "'++'", "'--'"
    },
    std::vector<std::string>{
      "", "STRING_LITERAL", "RETURN", "IF", "ELSE", "FOR", "WHILE", "PACKAGE", 
      "IMPORT", "BREAK", "CONTINUE", "TRY", "CATCH", "FINALLY", "VAR", "IMT", 
      "FUN", "ENUM", "STRUCT", "PUBLIC", "PRIVATE", "PROTECTED", "STATIC", 
      "NEW", "OVERRIDE", "NATIVE", "SYNCHRONIZED", "THROW", "DELETE", "BYTE", 
      "SHORT", "INT", "UINT", "USHORT", "LONG", "ULONG", "LONGLONG", "ULONGLONG", 
      "FLOAT", "DOUBLE", "BOOL", "CHAR", "STRING", "VOID", "CONST", "CHAR_LITERAL", 
      "INT_LITERAL", "FLOAT_LITERAL", "TRUE_LITERAL", "FALSE_LITERAL", "AT", 
      "SLASH", "ASSIGN", "SEMICOLON", "LPAREN", "RPAREN", "LBRACE", "RBRACE", 
      "LBRACK", "RBRACK", "COMMA", "LINE_COMMENT", "COMMENT", "WS", "DOT", 
      "BANG", "QUESTION", "COLON", "MOD", "PLUS", "MINUS", "MUL", "LT", 
      "GT", "LE", "GE", "EQ", "NEQ", "AND", "OR", "BIT_AND", "BIT_OR", "XOR", 
      "LSHIFT", "RSHIFT", "URSHIFT", "NOT", "TIBLE", "INC", "DEC", "IDENTIFIER"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,90,788,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,2,
  	7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,2,12,7,12,2,13,7,13,2,14,7,
  	14,2,15,7,15,2,16,7,16,2,17,7,17,2,18,7,18,2,19,7,19,2,20,7,20,2,21,7,
  	21,2,22,7,22,2,23,7,23,2,24,7,24,2,25,7,25,2,26,7,26,2,27,7,27,2,28,7,
  	28,2,29,7,29,2,30,7,30,2,31,7,31,2,32,7,32,2,33,7,33,2,34,7,34,2,35,7,
  	35,2,36,7,36,2,37,7,37,2,38,7,38,2,39,7,39,2,40,7,40,2,41,7,41,2,42,7,
  	42,2,43,7,43,2,44,7,44,2,45,7,45,2,46,7,46,2,47,7,47,2,48,7,48,2,49,7,
  	49,2,50,7,50,2,51,7,51,2,52,7,52,2,53,7,53,2,54,7,54,2,55,7,55,2,56,7,
  	56,2,57,7,57,2,58,7,58,2,59,7,59,2,60,7,60,1,0,3,0,124,8,0,1,0,5,0,127,
  	8,0,10,0,12,0,130,9,0,1,0,1,0,5,0,134,8,0,10,0,12,0,137,9,0,1,0,1,0,1,
  	1,1,1,1,1,1,1,1,2,1,2,1,2,1,2,1,3,1,3,1,3,5,3,152,8,3,10,3,12,3,155,9,
  	3,1,4,1,4,1,4,5,4,160,8,4,10,4,12,4,163,9,4,1,5,3,5,166,8,5,1,5,1,5,1,
  	5,5,5,171,8,5,10,5,12,5,174,9,5,1,5,1,5,3,5,178,8,5,1,5,1,5,1,6,1,6,1,
  	6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,1,6,3,6,194,8,6,1,7,1,7,1,7,1,7,1,8,
  	3,8,201,8,8,1,8,1,8,1,8,3,8,206,8,8,1,8,1,8,3,8,210,8,8,1,8,1,8,1,9,1,
  	9,1,9,5,9,217,8,9,10,9,12,9,220,9,9,1,10,1,10,1,11,1,11,1,11,1,11,5,11,
  	228,8,11,10,11,12,11,231,9,11,3,11,233,8,11,1,11,1,11,1,11,1,11,1,11,
  	5,11,240,8,11,10,11,12,11,243,9,11,3,11,245,8,11,1,11,3,11,248,8,11,1,
  	12,1,12,1,12,1,12,1,12,1,13,1,13,1,13,5,13,258,8,13,10,13,12,13,261,9,
  	13,1,13,1,13,1,13,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,14,1,
  	14,1,14,3,14,278,8,14,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,
  	15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,1,15,3,15,329,8,
  	15,1,16,1,16,1,16,1,16,5,16,335,8,16,10,16,12,16,338,9,16,1,16,3,16,341,
  	8,16,1,17,1,17,5,17,345,8,17,10,17,12,17,348,9,17,1,17,1,17,1,18,1,18,
  	1,18,5,18,355,8,18,10,18,12,18,358,9,18,1,18,1,18,1,18,1,18,3,18,364,
  	8,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,1,18,3,18,377,
  	8,18,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,1,19,
  	1,19,1,19,3,19,394,8,19,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,1,20,
  	5,20,405,8,20,10,20,12,20,408,9,20,1,20,1,20,1,20,1,20,1,20,3,20,415,
  	8,20,1,21,1,21,1,21,1,21,1,21,1,22,1,22,1,22,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,3,23,435,8,23,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,
  	1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,1,23,5,23,467,8,23,10,23,
  	12,23,470,9,23,1,24,1,24,1,24,1,24,1,24,1,24,3,24,478,8,24,1,25,1,25,
  	1,25,3,25,483,8,25,1,26,1,26,1,26,1,26,5,26,489,8,26,10,26,12,26,492,
  	9,26,1,26,1,26,1,26,1,27,1,27,1,28,3,28,500,8,28,1,28,1,28,1,28,3,28,
  	505,8,28,1,28,1,28,3,28,509,8,28,1,28,1,28,1,29,1,29,1,29,1,29,3,29,517,
  	8,29,1,29,1,29,3,29,521,8,29,1,29,1,29,1,30,1,30,5,30,527,8,30,10,30,
  	12,30,530,9,30,1,30,1,30,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,1,31,
  	1,31,1,31,1,31,3,31,546,8,31,1,32,1,32,1,32,1,32,1,33,1,33,1,33,1,33,
  	1,33,1,33,3,33,558,8,33,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,1,34,
  	3,34,569,8,34,1,35,1,35,5,35,573,8,35,10,35,12,35,576,9,35,1,36,1,36,
  	1,36,1,36,1,37,1,37,1,37,1,38,1,38,1,38,5,38,588,8,38,10,38,12,38,591,
  	9,38,1,39,1,39,1,39,5,39,596,8,39,10,39,12,39,599,9,39,1,39,1,39,1,40,
  	1,40,1,41,1,41,1,42,1,42,1,43,1,43,1,43,5,43,612,8,43,10,43,12,43,615,
  	9,43,1,44,3,44,618,8,44,1,44,1,44,1,44,3,44,623,8,44,1,45,1,45,3,45,627,
  	8,45,1,46,1,46,1,47,1,47,1,47,3,47,634,8,47,1,47,4,47,637,8,47,11,47,
  	12,47,638,1,48,1,48,3,48,643,8,48,1,48,1,48,1,48,3,48,648,8,48,1,48,1,
  	48,1,48,3,48,653,8,48,1,48,1,48,1,48,1,48,1,48,3,48,660,8,48,1,48,1,48,
  	1,48,3,48,665,8,48,1,48,1,48,1,48,3,48,670,8,48,1,48,3,48,673,8,48,1,
  	49,1,49,1,49,1,49,1,50,1,50,1,50,1,50,1,50,1,50,1,50,4,50,686,8,50,11,
  	50,12,50,687,3,50,690,8,50,1,51,1,51,5,51,694,8,51,10,51,12,51,697,9,
  	51,1,51,1,51,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,52,1,
  	52,1,52,1,52,1,52,3,52,716,8,52,1,53,1,53,1,53,1,53,1,53,1,54,1,54,5,
  	54,725,8,54,10,54,12,54,728,9,54,1,54,1,54,1,55,1,55,3,55,734,8,55,1,
  	56,1,56,1,56,1,56,1,56,1,56,1,56,1,56,1,56,1,56,1,56,1,56,1,56,1,56,3,
  	56,750,8,56,1,57,1,57,1,57,1,57,1,58,5,58,757,8,58,10,58,12,58,760,9,
  	58,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,59,1,
  	59,3,59,776,8,59,1,60,1,60,1,60,1,60,1,60,1,60,1,60,1,60,3,60,786,8,60,
  	1,60,0,1,46,61,0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,
  	40,42,44,46,48,50,52,54,56,58,60,62,64,66,68,70,72,74,76,78,80,82,84,
  	86,88,90,92,94,96,98,100,102,104,106,108,110,112,114,116,118,120,0,11,
  	2,0,51,51,68,85,1,0,14,15,1,0,65,66,2,0,1,1,45,49,3,0,51,51,68,68,71,
  	71,1,0,69,70,1,0,83,85,1,0,72,75,1,0,76,77,1,0,19,21,2,0,29,42,90,90,
  	881,0,123,1,0,0,0,2,140,1,0,0,0,4,144,1,0,0,0,6,148,1,0,0,0,8,156,1,0,
  	0,0,10,165,1,0,0,0,12,193,1,0,0,0,14,195,1,0,0,0,16,200,1,0,0,0,18,213,
  	1,0,0,0,20,221,1,0,0,0,22,247,1,0,0,0,24,249,1,0,0,0,26,254,1,0,0,0,28,
  	277,1,0,0,0,30,328,1,0,0,0,32,330,1,0,0,0,34,342,1,0,0,0,36,376,1,0,0,
  	0,38,393,1,0,0,0,40,414,1,0,0,0,42,416,1,0,0,0,44,421,1,0,0,0,46,434,
  	1,0,0,0,48,477,1,0,0,0,50,482,1,0,0,0,52,484,1,0,0,0,54,496,1,0,0,0,56,
  	499,1,0,0,0,58,512,1,0,0,0,60,524,1,0,0,0,62,545,1,0,0,0,64,547,1,0,0,
  	0,66,551,1,0,0,0,68,568,1,0,0,0,70,570,1,0,0,0,72,577,1,0,0,0,74,581,
  	1,0,0,0,76,584,1,0,0,0,78,592,1,0,0,0,80,602,1,0,0,0,82,604,1,0,0,0,84,
  	606,1,0,0,0,86,608,1,0,0,0,88,617,1,0,0,0,90,626,1,0,0,0,92,628,1,0,0,
  	0,94,630,1,0,0,0,96,672,1,0,0,0,98,674,1,0,0,0,100,689,1,0,0,0,102,691,
  	1,0,0,0,104,715,1,0,0,0,106,717,1,0,0,0,108,722,1,0,0,0,110,733,1,0,0,
  	0,112,749,1,0,0,0,114,751,1,0,0,0,116,758,1,0,0,0,118,775,1,0,0,0,120,
  	785,1,0,0,0,122,124,3,2,1,0,123,122,1,0,0,0,123,124,1,0,0,0,124,128,1,
  	0,0,0,125,127,3,4,2,0,126,125,1,0,0,0,127,130,1,0,0,0,128,126,1,0,0,0,
  	128,129,1,0,0,0,129,135,1,0,0,0,130,128,1,0,0,0,131,134,3,12,6,0,132,
  	134,3,108,54,0,133,131,1,0,0,0,133,132,1,0,0,0,134,137,1,0,0,0,135,133,
  	1,0,0,0,135,136,1,0,0,0,136,138,1,0,0,0,137,135,1,0,0,0,138,139,5,0,0,
  	1,139,1,1,0,0,0,140,141,5,7,0,0,141,142,3,6,3,0,142,143,5,53,0,0,143,
  	3,1,0,0,0,144,145,5,8,0,0,145,146,3,8,4,0,146,147,5,53,0,0,147,5,1,0,
  	0,0,148,153,5,90,0,0,149,150,5,64,0,0,150,152,5,90,0,0,151,149,1,0,0,
  	0,152,155,1,0,0,0,153,151,1,0,0,0,153,154,1,0,0,0,154,7,1,0,0,0,155,153,
  	1,0,0,0,156,161,5,90,0,0,157,158,5,64,0,0,158,160,5,90,0,0,159,157,1,
  	0,0,0,160,163,1,0,0,0,161,159,1,0,0,0,161,162,1,0,0,0,162,9,1,0,0,0,163,
  	161,1,0,0,0,164,166,5,51,0,0,165,164,1,0,0,0,165,166,1,0,0,0,166,167,
  	1,0,0,0,167,172,5,90,0,0,168,169,5,64,0,0,169,171,5,90,0,0,170,168,1,
  	0,0,0,171,174,1,0,0,0,172,170,1,0,0,0,172,173,1,0,0,0,173,175,1,0,0,0,
  	174,172,1,0,0,0,175,177,5,54,0,0,176,178,3,18,9,0,177,176,1,0,0,0,177,
  	178,1,0,0,0,178,179,1,0,0,0,179,180,5,55,0,0,180,11,1,0,0,0,181,194,3,
  	50,25,0,182,183,3,10,5,0,183,184,5,53,0,0,184,194,1,0,0,0,185,186,3,46,
  	23,0,186,187,5,53,0,0,187,194,1,0,0,0,188,194,3,32,16,0,189,194,3,98,
  	49,0,190,194,3,68,34,0,191,194,3,66,33,0,192,194,3,120,60,0,193,181,1,
  	0,0,0,193,182,1,0,0,0,193,185,1,0,0,0,193,188,1,0,0,0,193,189,1,0,0,0,
  	193,190,1,0,0,0,193,191,1,0,0,0,193,192,1,0,0,0,194,13,1,0,0,0,195,196,
  	3,36,18,0,196,197,7,0,0,0,197,198,3,36,18,0,198,15,1,0,0,0,199,201,7,
  	1,0,0,200,199,1,0,0,0,200,201,1,0,0,0,201,202,1,0,0,0,202,203,3,90,45,
  	0,203,205,5,90,0,0,204,206,7,2,0,0,205,204,1,0,0,0,205,206,1,0,0,0,206,
  	209,1,0,0,0,207,208,5,52,0,0,208,210,3,46,23,0,209,207,1,0,0,0,209,210,
  	1,0,0,0,210,211,1,0,0,0,211,212,5,53,0,0,212,17,1,0,0,0,213,218,3,46,
  	23,0,214,215,5,60,0,0,215,217,3,46,23,0,216,214,1,0,0,0,217,220,1,0,0,
  	0,218,216,1,0,0,0,218,219,1,0,0,0,219,19,1,0,0,0,220,218,1,0,0,0,221,
  	222,7,3,0,0,222,21,1,0,0,0,223,232,5,58,0,0,224,229,3,46,23,0,225,226,
  	5,60,0,0,226,228,3,46,23,0,227,225,1,0,0,0,228,231,1,0,0,0,229,227,1,
  	0,0,0,229,230,1,0,0,0,230,233,1,0,0,0,231,229,1,0,0,0,232,224,1,0,0,0,
  	232,233,1,0,0,0,233,234,1,0,0,0,234,248,5,59,0,0,235,244,5,58,0,0,236,
  	241,3,22,11,0,237,238,5,60,0,0,238,240,3,22,11,0,239,237,1,0,0,0,240,
  	243,1,0,0,0,241,239,1,0,0,0,241,242,1,0,0,0,242,245,1,0,0,0,243,241,1,
  	0,0,0,244,236,1,0,0,0,244,245,1,0,0,0,245,246,1,0,0,0,246,248,5,59,0,
  	0,247,223,1,0,0,0,247,235,1,0,0,0,248,23,1,0,0,0,249,250,5,54,0,0,250,
  	251,3,90,45,0,251,252,5,55,0,0,252,253,3,46,23,0,253,25,1,0,0,0,254,259,
  	5,90,0,0,255,256,5,64,0,0,256,258,5,90,0,0,257,255,1,0,0,0,258,261,1,
  	0,0,0,259,257,1,0,0,0,259,260,1,0,0,0,260,262,1,0,0,0,261,259,1,0,0,0,
  	262,263,5,52,0,0,263,264,3,46,23,0,264,27,1,0,0,0,265,266,5,65,0,0,266,
  	278,3,46,23,0,267,268,5,69,0,0,268,278,3,46,23,0,269,270,5,70,0,0,270,
  	278,3,46,23,0,271,272,5,88,0,0,272,278,3,46,23,0,273,274,5,89,0,0,274,
  	278,3,46,23,0,275,276,5,87,0,0,276,278,3,46,23,0,277,265,1,0,0,0,277,
  	267,1,0,0,0,277,269,1,0,0,0,277,271,1,0,0,0,277,273,1,0,0,0,277,275,1,
  	0,0,0,278,29,1,0,0,0,279,280,5,54,0,0,280,281,3,46,23,0,281,282,5,55,
  	0,0,282,329,1,0,0,0,283,329,3,10,5,0,284,329,3,28,14,0,285,286,3,46,23,
  	0,286,287,7,4,0,0,287,288,3,46,23,0,288,329,1,0,0,0,289,290,3,46,23,0,
  	290,291,7,5,0,0,291,292,3,46,23,0,292,329,1,0,0,0,293,294,3,46,23,0,294,
  	295,7,6,0,0,295,296,3,46,23,0,296,329,1,0,0,0,297,298,3,46,23,0,298,299,
  	7,7,0,0,299,300,3,46,23,0,300,329,1,0,0,0,301,302,3,46,23,0,302,303,7,
  	8,0,0,303,304,3,46,23,0,304,329,1,0,0,0,305,306,3,46,23,0,306,307,5,80,
  	0,0,307,308,3,46,23,0,308,329,1,0,0,0,309,310,3,46,23,0,310,311,5,82,
  	0,0,311,312,3,46,23,0,312,329,1,0,0,0,313,314,3,46,23,0,314,315,5,81,
  	0,0,315,316,3,46,23,0,316,329,1,0,0,0,317,318,3,46,23,0,318,319,5,78,
  	0,0,319,320,3,46,23,0,320,329,1,0,0,0,321,322,3,46,23,0,322,323,5,79,
  	0,0,323,324,3,46,23,0,324,329,1,0,0,0,325,329,3,36,18,0,326,329,3,24,
  	12,0,327,329,3,48,24,0,328,279,1,0,0,0,328,283,1,0,0,0,328,284,1,0,0,
  	0,328,285,1,0,0,0,328,289,1,0,0,0,328,293,1,0,0,0,328,297,1,0,0,0,328,
  	301,1,0,0,0,328,305,1,0,0,0,328,309,1,0,0,0,328,313,1,0,0,0,328,317,1,
  	0,0,0,328,321,1,0,0,0,328,325,1,0,0,0,328,326,1,0,0,0,328,327,1,0,0,0,
  	329,31,1,0,0,0,330,331,5,3,0,0,331,332,3,30,15,0,332,336,3,34,17,0,333,
  	335,3,42,21,0,334,333,1,0,0,0,335,338,1,0,0,0,336,334,1,0,0,0,336,337,
  	1,0,0,0,337,340,1,0,0,0,338,336,1,0,0,0,339,341,3,44,22,0,340,339,1,0,
  	0,0,340,341,1,0,0,0,341,33,1,0,0,0,342,346,5,56,0,0,343,345,3,38,19,0,
  	344,343,1,0,0,0,345,348,1,0,0,0,346,344,1,0,0,0,346,347,1,0,0,0,347,349,
  	1,0,0,0,348,346,1,0,0,0,349,350,5,57,0,0,350,35,1,0,0,0,351,356,5,90,
  	0,0,352,353,5,64,0,0,353,355,5,90,0,0,354,352,1,0,0,0,355,358,1,0,0,0,
  	356,354,1,0,0,0,356,357,1,0,0,0,357,377,1,0,0,0,358,356,1,0,0,0,359,360,
  	5,23,0,0,360,361,5,90,0,0,361,363,5,54,0,0,362,364,3,18,9,0,363,362,1,
  	0,0,0,363,364,1,0,0,0,364,365,1,0,0,0,365,377,5,55,0,0,366,367,5,90,0,
  	0,367,368,5,54,0,0,368,369,3,46,23,0,369,370,5,55,0,0,370,371,5,53,0,
  	0,371,377,1,0,0,0,372,377,3,20,10,0,373,377,3,22,11,0,374,377,3,24,12,
  	0,375,377,3,26,13,0,376,351,1,0,0,0,376,359,1,0,0,0,376,366,1,0,0,0,376,
  	372,1,0,0,0,376,373,1,0,0,0,376,374,1,0,0,0,376,375,1,0,0,0,377,37,1,
  	0,0,0,378,379,3,46,23,0,379,380,5,53,0,0,380,394,1,0,0,0,381,394,3,32,
  	16,0,382,394,3,40,20,0,383,394,3,98,49,0,384,394,3,68,34,0,385,394,3,
  	64,32,0,386,387,5,9,0,0,387,394,5,53,0,0,388,389,5,10,0,0,389,394,5,53,
  	0,0,390,391,3,10,5,0,391,392,5,53,0,0,392,394,1,0,0,0,393,378,1,0,0,0,
  	393,381,1,0,0,0,393,382,1,0,0,0,393,383,1,0,0,0,393,384,1,0,0,0,393,385,
  	1,0,0,0,393,386,1,0,0,0,393,388,1,0,0,0,393,390,1,0,0,0,394,39,1,0,0,
  	0,395,396,5,2,0,0,396,397,3,46,23,0,397,398,5,53,0,0,398,415,1,0,0,0,
  	399,400,5,2,0,0,400,401,5,54,0,0,401,406,3,46,23,0,402,403,5,60,0,0,403,
  	405,3,46,23,0,404,402,1,0,0,0,405,408,1,0,0,0,406,404,1,0,0,0,406,407,
  	1,0,0,0,407,409,1,0,0,0,408,406,1,0,0,0,409,410,5,55,0,0,410,411,5,53,
  	0,0,411,415,1,0,0,0,412,413,5,2,0,0,413,415,5,53,0,0,414,395,1,0,0,0,
  	414,399,1,0,0,0,414,412,1,0,0,0,415,41,1,0,0,0,416,417,5,4,0,0,417,418,
  	5,3,0,0,418,419,3,30,15,0,419,420,3,34,17,0,420,43,1,0,0,0,421,422,5,
  	4,0,0,422,423,3,34,17,0,423,45,1,0,0,0,424,425,6,23,-1,0,425,426,5,54,
  	0,0,426,427,3,46,23,0,427,428,5,55,0,0,428,435,1,0,0,0,429,435,3,10,5,
  	0,430,435,3,28,14,0,431,435,3,36,18,0,432,435,3,24,12,0,433,435,3,48,
  	24,0,434,424,1,0,0,0,434,429,1,0,0,0,434,430,1,0,0,0,434,431,1,0,0,0,
  	434,432,1,0,0,0,434,433,1,0,0,0,435,468,1,0,0,0,436,437,10,13,0,0,437,
  	438,7,4,0,0,438,467,3,46,23,14,439,440,10,12,0,0,440,441,7,5,0,0,441,
  	467,3,46,23,13,442,443,10,11,0,0,443,444,7,6,0,0,444,467,3,46,23,12,445,
  	446,10,10,0,0,446,447,7,7,0,0,447,467,3,46,23,11,448,449,10,9,0,0,449,
  	450,7,8,0,0,450,467,3,46,23,10,451,452,10,8,0,0,452,453,5,80,0,0,453,
  	467,3,46,23,9,454,455,10,7,0,0,455,456,5,82,0,0,456,467,3,46,23,8,457,
  	458,10,6,0,0,458,459,5,81,0,0,459,467,3,46,23,7,460,461,10,5,0,0,461,
  	462,5,78,0,0,462,467,3,46,23,6,463,464,10,4,0,0,464,465,5,79,0,0,465,
  	467,3,46,23,5,466,436,1,0,0,0,466,439,1,0,0,0,466,442,1,0,0,0,466,445,
  	1,0,0,0,466,448,1,0,0,0,466,451,1,0,0,0,466,454,1,0,0,0,466,457,1,0,0,
  	0,466,460,1,0,0,0,466,463,1,0,0,0,467,470,1,0,0,0,468,466,1,0,0,0,468,
  	469,1,0,0,0,469,47,1,0,0,0,470,468,1,0,0,0,471,472,3,90,45,0,472,473,
  	5,90,0,0,473,474,5,52,0,0,474,475,3,46,23,0,475,478,1,0,0,0,476,478,3,
  	26,13,0,477,471,1,0,0,0,477,476,1,0,0,0,478,49,1,0,0,0,479,483,3,56,28,
  	0,480,483,3,58,29,0,481,483,3,52,26,0,482,479,1,0,0,0,482,480,1,0,0,0,
  	482,481,1,0,0,0,483,51,1,0,0,0,484,485,5,18,0,0,485,486,5,90,0,0,486,
  	490,5,56,0,0,487,489,3,54,27,0,488,487,1,0,0,0,489,492,1,0,0,0,490,488,
  	1,0,0,0,490,491,1,0,0,0,491,493,1,0,0,0,492,490,1,0,0,0,493,494,5,57,
  	0,0,494,495,5,53,0,0,495,53,1,0,0,0,496,497,3,56,28,0,497,55,1,0,0,0,
  	498,500,7,1,0,0,499,498,1,0,0,0,499,500,1,0,0,0,500,501,1,0,0,0,501,502,
  	3,90,45,0,502,504,5,90,0,0,503,505,7,2,0,0,504,503,1,0,0,0,504,505,1,
  	0,0,0,505,508,1,0,0,0,506,507,5,52,0,0,507,509,3,46,23,0,508,506,1,0,
  	0,0,508,509,1,0,0,0,509,510,1,0,0,0,510,511,5,53,0,0,511,57,1,0,0,0,512,
  	513,5,16,0,0,513,514,5,90,0,0,514,516,5,54,0,0,515,517,3,86,43,0,516,
  	515,1,0,0,0,516,517,1,0,0,0,517,518,1,0,0,0,518,520,5,55,0,0,519,521,
  	3,96,48,0,520,519,1,0,0,0,520,521,1,0,0,0,521,522,1,0,0,0,522,523,3,60,
  	30,0,523,59,1,0,0,0,524,528,5,56,0,0,525,527,3,62,31,0,526,525,1,0,0,
  	0,527,530,1,0,0,0,528,526,1,0,0,0,528,529,1,0,0,0,529,531,1,0,0,0,530,
  	528,1,0,0,0,531,532,5,57,0,0,532,61,1,0,0,0,533,546,3,68,34,0,534,535,
  	5,25,0,0,535,546,5,53,0,0,536,546,3,32,16,0,537,546,3,98,49,0,538,546,
  	3,16,8,0,539,546,3,40,20,0,540,541,3,46,23,0,541,542,5,53,0,0,542,546,
  	1,0,0,0,543,546,3,64,32,0,544,546,3,108,54,0,545,533,1,0,0,0,545,534,
  	1,0,0,0,545,536,1,0,0,0,545,537,1,0,0,0,545,538,1,0,0,0,545,539,1,0,0,
  	0,545,540,1,0,0,0,545,543,1,0,0,0,545,544,1,0,0,0,546,63,1,0,0,0,547,
  	548,5,27,0,0,548,549,3,46,23,0,549,550,5,53,0,0,550,65,1,0,0,0,551,552,
  	5,26,0,0,552,553,5,54,0,0,553,554,3,46,23,0,554,557,5,55,0,0,555,558,
  	3,108,54,0,556,558,3,114,57,0,557,555,1,0,0,0,557,556,1,0,0,0,558,67,
  	1,0,0,0,559,560,5,11,0,0,560,561,3,114,57,0,561,562,3,70,35,0,562,569,
  	1,0,0,0,563,564,5,11,0,0,564,565,3,114,57,0,565,566,3,70,35,0,566,567,
  	3,78,39,0,567,569,1,0,0,0,568,559,1,0,0,0,568,563,1,0,0,0,569,69,1,0,
  	0,0,570,574,3,72,36,0,571,573,3,72,36,0,572,571,1,0,0,0,573,576,1,0,0,
  	0,574,572,1,0,0,0,574,575,1,0,0,0,575,71,1,0,0,0,576,574,1,0,0,0,577,
  	578,5,12,0,0,578,579,3,74,37,0,579,580,3,114,57,0,580,73,1,0,0,0,581,
  	582,3,76,38,0,582,583,5,90,0,0,583,75,1,0,0,0,584,589,5,90,0,0,585,586,
  	5,81,0,0,586,588,5,90,0,0,587,585,1,0,0,0,588,591,1,0,0,0,589,587,1,0,
  	0,0,589,590,1,0,0,0,590,77,1,0,0,0,591,589,1,0,0,0,592,593,5,13,0,0,593,
  	597,5,56,0,0,594,596,3,12,6,0,595,594,1,0,0,0,596,599,1,0,0,0,597,595,
  	1,0,0,0,597,598,1,0,0,0,598,600,1,0,0,0,599,597,1,0,0,0,600,601,5,57,
  	0,0,601,79,1,0,0,0,602,603,5,24,0,0,603,81,1,0,0,0,604,605,7,9,0,0,605,
  	83,1,0,0,0,606,607,5,22,0,0,607,85,1,0,0,0,608,613,3,88,44,0,609,610,
  	5,60,0,0,610,612,3,88,44,0,611,609,1,0,0,0,612,615,1,0,0,0,613,611,1,
  	0,0,0,613,614,1,0,0,0,614,87,1,0,0,0,615,613,1,0,0,0,616,618,7,1,0,0,
  	617,616,1,0,0,0,617,618,1,0,0,0,618,619,1,0,0,0,619,620,3,90,45,0,620,
  	622,5,90,0,0,621,623,7,2,0,0,622,621,1,0,0,0,622,623,1,0,0,0,623,89,1,
  	0,0,0,624,627,3,94,47,0,625,627,3,92,46,0,626,624,1,0,0,0,626,625,1,0,
  	0,0,627,91,1,0,0,0,628,629,7,10,0,0,629,93,1,0,0,0,630,636,3,92,46,0,
  	631,633,5,58,0,0,632,634,5,90,0,0,633,632,1,0,0,0,633,634,1,0,0,0,634,
  	635,1,0,0,0,635,637,5,59,0,0,636,631,1,0,0,0,637,638,1,0,0,0,638,636,
  	1,0,0,0,638,639,1,0,0,0,639,95,1,0,0,0,640,642,3,90,45,0,641,643,7,2,
  	0,0,642,641,1,0,0,0,642,643,1,0,0,0,643,673,1,0,0,0,644,645,5,54,0,0,
  	645,647,3,90,45,0,646,648,7,2,0,0,647,646,1,0,0,0,647,648,1,0,0,0,648,
  	649,1,0,0,0,649,650,5,60,0,0,650,652,3,90,45,0,651,653,7,2,0,0,652,651,
  	1,0,0,0,652,653,1,0,0,0,653,654,1,0,0,0,654,655,5,55,0,0,655,673,1,0,
  	0,0,656,673,5,43,0,0,657,659,5,90,0,0,658,660,7,2,0,0,659,658,1,0,0,0,
  	659,660,1,0,0,0,660,673,1,0,0,0,661,662,5,54,0,0,662,664,5,90,0,0,663,
  	665,7,2,0,0,664,663,1,0,0,0,664,665,1,0,0,0,665,666,1,0,0,0,666,667,5,
  	60,0,0,667,669,5,90,0,0,668,670,7,2,0,0,669,668,1,0,0,0,669,670,1,0,0,
  	0,670,671,1,0,0,0,671,673,5,55,0,0,672,640,1,0,0,0,672,644,1,0,0,0,672,
  	656,1,0,0,0,672,657,1,0,0,0,672,661,1,0,0,0,673,97,1,0,0,0,674,675,5,
  	5,0,0,675,676,3,100,50,0,676,677,3,102,51,0,677,99,1,0,0,0,678,679,3,
  	106,53,0,679,680,5,53,0,0,680,681,3,46,23,0,681,682,5,53,0,0,682,683,
  	3,46,23,0,683,690,1,0,0,0,684,686,3,46,23,0,685,684,1,0,0,0,686,687,1,
  	0,0,0,687,685,1,0,0,0,687,688,1,0,0,0,688,690,1,0,0,0,689,678,1,0,0,0,
  	689,685,1,0,0,0,690,101,1,0,0,0,691,695,5,56,0,0,692,694,3,104,52,0,693,
  	692,1,0,0,0,694,697,1,0,0,0,695,693,1,0,0,0,695,696,1,0,0,0,696,698,1,
  	0,0,0,697,695,1,0,0,0,698,699,5,57,0,0,699,103,1,0,0,0,700,701,3,46,23,
  	0,701,702,5,53,0,0,702,716,1,0,0,0,703,716,3,16,8,0,704,716,3,32,16,0,
  	705,716,3,98,49,0,706,716,3,40,20,0,707,708,5,9,0,0,708,716,5,53,0,0,
  	709,710,5,10,0,0,710,716,5,53,0,0,711,712,3,10,5,0,712,713,5,53,0,0,713,
  	716,1,0,0,0,714,716,3,120,60,0,715,700,1,0,0,0,715,703,1,0,0,0,715,704,
  	1,0,0,0,715,705,1,0,0,0,715,706,1,0,0,0,715,707,1,0,0,0,715,709,1,0,0,
  	0,715,711,1,0,0,0,715,714,1,0,0,0,716,105,1,0,0,0,717,718,3,90,45,0,718,
  	719,5,90,0,0,719,720,5,52,0,0,720,721,3,46,23,0,721,107,1,0,0,0,722,726,
  	5,56,0,0,723,725,3,110,55,0,724,723,1,0,0,0,725,728,1,0,0,0,726,724,1,
  	0,0,0,726,727,1,0,0,0,727,729,1,0,0,0,728,726,1,0,0,0,729,730,5,57,0,
  	0,730,109,1,0,0,0,731,734,3,112,56,0,732,734,3,108,54,0,733,731,1,0,0,
  	0,733,732,1,0,0,0,734,111,1,0,0,0,735,736,3,46,23,0,736,737,5,53,0,0,
  	737,750,1,0,0,0,738,750,3,50,25,0,739,750,3,32,16,0,740,750,3,98,49,0,
  	741,750,3,40,20,0,742,750,5,9,0,0,743,750,5,10,0,0,744,745,3,10,5,0,745,
  	746,5,53,0,0,746,750,1,0,0,0,747,750,3,64,32,0,748,750,3,68,34,0,749,
  	735,1,0,0,0,749,738,1,0,0,0,749,739,1,0,0,0,749,740,1,0,0,0,749,741,1,
  	0,0,0,749,742,1,0,0,0,749,743,1,0,0,0,749,744,1,0,0,0,749,747,1,0,0,0,
  	749,748,1,0,0,0,750,113,1,0,0,0,751,752,5,56,0,0,752,753,3,116,58,0,753,
  	754,5,57,0,0,754,115,1,0,0,0,755,757,3,118,59,0,756,755,1,0,0,0,757,760,
  	1,0,0,0,758,756,1,0,0,0,758,759,1,0,0,0,759,117,1,0,0,0,760,758,1,0,0,
  	0,761,762,3,46,23,0,762,763,5,53,0,0,763,776,1,0,0,0,764,776,3,32,16,
  	0,765,776,3,98,49,0,766,776,3,40,20,0,767,776,5,9,0,0,768,776,5,10,0,
  	0,769,770,3,10,5,0,770,771,5,53,0,0,771,776,1,0,0,0,772,776,3,64,32,0,
  	773,776,3,68,34,0,774,776,3,120,60,0,775,761,1,0,0,0,775,764,1,0,0,0,
  	775,765,1,0,0,0,775,766,1,0,0,0,775,767,1,0,0,0,775,768,1,0,0,0,775,769,
  	1,0,0,0,775,772,1,0,0,0,775,773,1,0,0,0,775,774,1,0,0,0,776,119,1,0,0,
  	0,777,778,5,28,0,0,778,779,3,46,23,0,779,780,5,53,0,0,780,786,1,0,0,0,
  	781,782,5,28,0,0,782,783,5,59,0,0,783,784,5,59,0,0,784,786,5,53,0,0,785,
  	777,1,0,0,0,785,781,1,0,0,0,786,121,1,0,0,0,72,123,128,133,135,153,161,
  	165,172,177,193,200,205,209,218,229,232,241,244,247,259,277,328,336,340,
  	346,356,363,376,393,406,414,434,466,468,477,482,490,499,504,508,516,520,
  	528,545,557,568,574,589,597,613,617,622,626,633,638,642,647,652,659,664,
  	669,672,687,689,695,715,726,733,749,758,775,785
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  dreamParserStaticData = std::move(staticData);
}

}

DreamParser::DreamParser(TokenStream *input) : DreamParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

DreamParser::DreamParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  DreamParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *dreamParserStaticData->atn, dreamParserStaticData->decisionToDFA, dreamParserStaticData->sharedContextCache, options);
}

DreamParser::~DreamParser() {
  delete _interpreter;
}

const atn::ATN& DreamParser::getATN() const {
  return *dreamParserStaticData->atn;
}

std::string DreamParser::getGrammarFileName() const {
  return "Dream.g4";
}

const std::vector<std::string>& DreamParser::getRuleNames() const {
  return dreamParserStaticData->ruleNames;
}

const dfa::Vocabulary& DreamParser::getVocabulary() const {
  return dreamParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView DreamParser::getSerializedATN() const {
  return dreamParserStaticData->serializedATN;
}


//----------------- ProgramContext ------------------------------------------------------------------

DreamParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::ProgramContext::EOF() {
  return getToken(DreamParser::EOF, 0);
}

DreamParser::PackageDeclContext* DreamParser::ProgramContext::packageDecl() {
  return getRuleContext<DreamParser::PackageDeclContext>(0);
}

std::vector<DreamParser::ImportStmtContext *> DreamParser::ProgramContext::importStmt() {
  return getRuleContexts<DreamParser::ImportStmtContext>();
}

DreamParser::ImportStmtContext* DreamParser::ProgramContext::importStmt(size_t i) {
  return getRuleContext<DreamParser::ImportStmtContext>(i);
}

std::vector<DreamParser::StmtContext *> DreamParser::ProgramContext::stmt() {
  return getRuleContexts<DreamParser::StmtContext>();
}

DreamParser::StmtContext* DreamParser::ProgramContext::stmt(size_t i) {
  return getRuleContext<DreamParser::StmtContext>(i);
}

std::vector<DreamParser::FileCodeBlockContext *> DreamParser::ProgramContext::fileCodeBlock() {
  return getRuleContexts<DreamParser::FileCodeBlockContext>();
}

DreamParser::FileCodeBlockContext* DreamParser::ProgramContext::fileCodeBlock(size_t i) {
  return getRuleContext<DreamParser::FileCodeBlockContext>(i);
}


size_t DreamParser::ProgramContext::getRuleIndex() const {
  return DreamParser::RuleProgram;
}

void DreamParser::ProgramContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterProgram(this);
}

void DreamParser::ProgramContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitProgram(this);
}

DreamParser::ProgramContext* DreamParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, DreamParser::RuleProgram);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(123);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DreamParser::PACKAGE) {
      setState(122);
      packageDecl();
    }
    setState(128);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DreamParser::IMPORT) {
      setState(125);
      importStmt();
      setState(130);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(135);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 381653679948023850) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 62914609) != 0)) {
      setState(133);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case DreamParser::STRING_LITERAL:
        case DreamParser::IF:
        case DreamParser::FOR:
        case DreamParser::TRY:
        case DreamParser::VAR:
        case DreamParser::IMT:
        case DreamParser::FUN:
        case DreamParser::STRUCT:
        case DreamParser::NEW:
        case DreamParser::SYNCHRONIZED:
        case DreamParser::DELETE:
        case DreamParser::BYTE:
        case DreamParser::SHORT:
        case DreamParser::INT:
        case DreamParser::UINT:
        case DreamParser::USHORT:
        case DreamParser::LONG:
        case DreamParser::ULONG:
        case DreamParser::LONGLONG:
        case DreamParser::ULONGLONG:
        case DreamParser::FLOAT:
        case DreamParser::DOUBLE:
        case DreamParser::BOOL:
        case DreamParser::CHAR:
        case DreamParser::STRING:
        case DreamParser::CHAR_LITERAL:
        case DreamParser::INT_LITERAL:
        case DreamParser::FLOAT_LITERAL:
        case DreamParser::TRUE_LITERAL:
        case DreamParser::FALSE_LITERAL:
        case DreamParser::SLASH:
        case DreamParser::LPAREN:
        case DreamParser::LBRACK:
        case DreamParser::BANG:
        case DreamParser::PLUS:
        case DreamParser::MINUS:
        case DreamParser::TIBLE:
        case DreamParser::INC:
        case DreamParser::DEC:
        case DreamParser::IDENTIFIER: {
          setState(131);
          stmt();
          break;
        }

        case DreamParser::LBRACE: {
          setState(132);
          fileCodeBlock();
          break;
        }

      default:
        throw NoViableAltException(this);
      }
      setState(137);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(138);
    match(DreamParser::EOF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PackageDeclContext ------------------------------------------------------------------

DreamParser::PackageDeclContext::PackageDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::PackageDeclContext::PACKAGE() {
  return getToken(DreamParser::PACKAGE, 0);
}

DreamParser::PackageNameContext* DreamParser::PackageDeclContext::packageName() {
  return getRuleContext<DreamParser::PackageNameContext>(0);
}

tree::TerminalNode* DreamParser::PackageDeclContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}


size_t DreamParser::PackageDeclContext::getRuleIndex() const {
  return DreamParser::RulePackageDecl;
}

void DreamParser::PackageDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPackageDecl(this);
}

void DreamParser::PackageDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPackageDecl(this);
}

DreamParser::PackageDeclContext* DreamParser::packageDecl() {
  PackageDeclContext *_localctx = _tracker.createInstance<PackageDeclContext>(_ctx, getState());
  enterRule(_localctx, 2, DreamParser::RulePackageDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(140);
    match(DreamParser::PACKAGE);
    setState(141);
    packageName();
    setState(142);
    match(DreamParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportStmtContext ------------------------------------------------------------------

DreamParser::ImportStmtContext::ImportStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::ImportStmtContext::IMPORT() {
  return getToken(DreamParser::IMPORT, 0);
}

DreamParser::ImportNameContext* DreamParser::ImportStmtContext::importName() {
  return getRuleContext<DreamParser::ImportNameContext>(0);
}

tree::TerminalNode* DreamParser::ImportStmtContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}


size_t DreamParser::ImportStmtContext::getRuleIndex() const {
  return DreamParser::RuleImportStmt;
}

void DreamParser::ImportStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportStmt(this);
}

void DreamParser::ImportStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportStmt(this);
}

DreamParser::ImportStmtContext* DreamParser::importStmt() {
  ImportStmtContext *_localctx = _tracker.createInstance<ImportStmtContext>(_ctx, getState());
  enterRule(_localctx, 4, DreamParser::RuleImportStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(144);
    match(DreamParser::IMPORT);
    setState(145);
    importName();
    setState(146);
    match(DreamParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- PackageNameContext ------------------------------------------------------------------

DreamParser::PackageNameContext::PackageNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DreamParser::PackageNameContext::IDENTIFIER() {
  return getTokens(DreamParser::IDENTIFIER);
}

tree::TerminalNode* DreamParser::PackageNameContext::IDENTIFIER(size_t i) {
  return getToken(DreamParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> DreamParser::PackageNameContext::DOT() {
  return getTokens(DreamParser::DOT);
}

tree::TerminalNode* DreamParser::PackageNameContext::DOT(size_t i) {
  return getToken(DreamParser::DOT, i);
}


size_t DreamParser::PackageNameContext::getRuleIndex() const {
  return DreamParser::RulePackageName;
}

void DreamParser::PackageNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPackageName(this);
}

void DreamParser::PackageNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPackageName(this);
}

DreamParser::PackageNameContext* DreamParser::packageName() {
  PackageNameContext *_localctx = _tracker.createInstance<PackageNameContext>(_ctx, getState());
  enterRule(_localctx, 6, DreamParser::RulePackageName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(148);
    match(DreamParser::IDENTIFIER);
    setState(153);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DreamParser::DOT) {
      setState(149);
      match(DreamParser::DOT);
      setState(150);
      match(DreamParser::IDENTIFIER);
      setState(155);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ImportNameContext ------------------------------------------------------------------

DreamParser::ImportNameContext::ImportNameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DreamParser::ImportNameContext::IDENTIFIER() {
  return getTokens(DreamParser::IDENTIFIER);
}

tree::TerminalNode* DreamParser::ImportNameContext::IDENTIFIER(size_t i) {
  return getToken(DreamParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> DreamParser::ImportNameContext::DOT() {
  return getTokens(DreamParser::DOT);
}

tree::TerminalNode* DreamParser::ImportNameContext::DOT(size_t i) {
  return getToken(DreamParser::DOT, i);
}


size_t DreamParser::ImportNameContext::getRuleIndex() const {
  return DreamParser::RuleImportName;
}

void DreamParser::ImportNameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterImportName(this);
}

void DreamParser::ImportNameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitImportName(this);
}

DreamParser::ImportNameContext* DreamParser::importName() {
  ImportNameContext *_localctx = _tracker.createInstance<ImportNameContext>(_ctx, getState());
  enterRule(_localctx, 8, DreamParser::RuleImportName);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(DreamParser::IDENTIFIER);
    setState(161);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DreamParser::DOT) {
      setState(157);
      match(DreamParser::DOT);
      setState(158);
      match(DreamParser::IDENTIFIER);
      setState(163);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunCallStmtContext ------------------------------------------------------------------

DreamParser::FunCallStmtContext::FunCallStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DreamParser::FunCallStmtContext::IDENTIFIER() {
  return getTokens(DreamParser::IDENTIFIER);
}

tree::TerminalNode* DreamParser::FunCallStmtContext::IDENTIFIER(size_t i) {
  return getToken(DreamParser::IDENTIFIER, i);
}

tree::TerminalNode* DreamParser::FunCallStmtContext::LPAREN() {
  return getToken(DreamParser::LPAREN, 0);
}

tree::TerminalNode* DreamParser::FunCallStmtContext::RPAREN() {
  return getToken(DreamParser::RPAREN, 0);
}

tree::TerminalNode* DreamParser::FunCallStmtContext::SLASH() {
  return getToken(DreamParser::SLASH, 0);
}

std::vector<tree::TerminalNode *> DreamParser::FunCallStmtContext::DOT() {
  return getTokens(DreamParser::DOT);
}

tree::TerminalNode* DreamParser::FunCallStmtContext::DOT(size_t i) {
  return getToken(DreamParser::DOT, i);
}

DreamParser::ArgListContext* DreamParser::FunCallStmtContext::argList() {
  return getRuleContext<DreamParser::ArgListContext>(0);
}


size_t DreamParser::FunCallStmtContext::getRuleIndex() const {
  return DreamParser::RuleFunCallStmt;
}

void DreamParser::FunCallStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunCallStmt(this);
}

void DreamParser::FunCallStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunCallStmt(this);
}

DreamParser::FunCallStmtContext* DreamParser::funCallStmt() {
  FunCallStmtContext *_localctx = _tracker.createInstance<FunCallStmtContext>(_ctx, getState());
  enterRule(_localctx, 10, DreamParser::RuleFunCallStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(165);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DreamParser::SLASH) {
      setState(164);
      match(DreamParser::SLASH);
    }
    setState(167);
    match(DreamParser::IDENTIFIER);
    setState(172);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DreamParser::DOT) {
      setState(168);
      match(DreamParser::DOT);
      setState(169);
      match(DreamParser::IDENTIFIER);
      setState(174);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(175);
    match(DreamParser::LPAREN);
    setState(177);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 309596085574172674) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 62914609) != 0)) {
      setState(176);
      argList();
    }
    setState(179);
    match(DreamParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StmtContext ------------------------------------------------------------------

DreamParser::StmtContext::StmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::DeclarationContext* DreamParser::StmtContext::declaration() {
  return getRuleContext<DreamParser::DeclarationContext>(0);
}

DreamParser::FunCallStmtContext* DreamParser::StmtContext::funCallStmt() {
  return getRuleContext<DreamParser::FunCallStmtContext>(0);
}

tree::TerminalNode* DreamParser::StmtContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}

DreamParser::ExprContext* DreamParser::StmtContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

DreamParser::IfStmtContext* DreamParser::StmtContext::ifStmt() {
  return getRuleContext<DreamParser::IfStmtContext>(0);
}

DreamParser::ForStmtContext* DreamParser::StmtContext::forStmt() {
  return getRuleContext<DreamParser::ForStmtContext>(0);
}

DreamParser::TryCatchStmtContext* DreamParser::StmtContext::tryCatchStmt() {
  return getRuleContext<DreamParser::TryCatchStmtContext>(0);
}

DreamParser::SynchronizedStmtContext* DreamParser::StmtContext::synchronizedStmt() {
  return getRuleContext<DreamParser::SynchronizedStmtContext>(0);
}

DreamParser::DeleteStmtContext* DreamParser::StmtContext::deleteStmt() {
  return getRuleContext<DreamParser::DeleteStmtContext>(0);
}


size_t DreamParser::StmtContext::getRuleIndex() const {
  return DreamParser::RuleStmt;
}

void DreamParser::StmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStmt(this);
}

void DreamParser::StmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStmt(this);
}

DreamParser::StmtContext* DreamParser::stmt() {
  StmtContext *_localctx = _tracker.createInstance<StmtContext>(_ctx, getState());
  enterRule(_localctx, 12, DreamParser::RuleStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(193);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(181);
      declaration();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(182);
      funCallStmt();
      setState(183);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(185);
      expr(0);
      setState(186);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(188);
      ifStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(189);
      forStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(190);
      tryCatchStmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(191);
      synchronizedStmt();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(192);
      deleteStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- BinaryOpExprContext ------------------------------------------------------------------

DreamParser::BinaryOpExprContext::BinaryOpExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DreamParser::AtomExprContext *> DreamParser::BinaryOpExprContext::atomExpr() {
  return getRuleContexts<DreamParser::AtomExprContext>();
}

DreamParser::AtomExprContext* DreamParser::BinaryOpExprContext::atomExpr(size_t i) {
  return getRuleContext<DreamParser::AtomExprContext>(i);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::MOD() {
  return getToken(DreamParser::MOD, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::MUL() {
  return getToken(DreamParser::MUL, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::SLASH() {
  return getToken(DreamParser::SLASH, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::MINUS() {
  return getToken(DreamParser::MINUS, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::PLUS() {
  return getToken(DreamParser::PLUS, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::LT() {
  return getToken(DreamParser::LT, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::GT() {
  return getToken(DreamParser::GT, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::LE() {
  return getToken(DreamParser::LE, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::GE() {
  return getToken(DreamParser::GE, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::EQ() {
  return getToken(DreamParser::EQ, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::NEQ() {
  return getToken(DreamParser::NEQ, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::AND() {
  return getToken(DreamParser::AND, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::OR() {
  return getToken(DreamParser::OR, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::BIT_AND() {
  return getToken(DreamParser::BIT_AND, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::BIT_OR() {
  return getToken(DreamParser::BIT_OR, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::XOR() {
  return getToken(DreamParser::XOR, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::LSHIFT() {
  return getToken(DreamParser::LSHIFT, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::RSHIFT() {
  return getToken(DreamParser::RSHIFT, 0);
}

tree::TerminalNode* DreamParser::BinaryOpExprContext::URSHIFT() {
  return getToken(DreamParser::URSHIFT, 0);
}


size_t DreamParser::BinaryOpExprContext::getRuleIndex() const {
  return DreamParser::RuleBinaryOpExpr;
}

void DreamParser::BinaryOpExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterBinaryOpExpr(this);
}

void DreamParser::BinaryOpExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitBinaryOpExpr(this);
}

DreamParser::BinaryOpExprContext* DreamParser::binaryOpExpr() {
  BinaryOpExprContext *_localctx = _tracker.createInstance<BinaryOpExprContext>(_ctx, getState());
  enterRule(_localctx, 14, DreamParser::RuleBinaryOpExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(195);
    atomExpr();
    setState(196);
    _la = _input->LA(1);
    if (!(((((_la - 51) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 51)) & 34359607297) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(197);
    atomExpr();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunVarDeclarationContext ------------------------------------------------------------------

DreamParser::FunVarDeclarationContext::FunVarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::TypeContext* DreamParser::FunVarDeclarationContext::type() {
  return getRuleContext<DreamParser::TypeContext>(0);
}

tree::TerminalNode* DreamParser::FunVarDeclarationContext::IDENTIFIER() {
  return getToken(DreamParser::IDENTIFIER, 0);
}

tree::TerminalNode* DreamParser::FunVarDeclarationContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}

tree::TerminalNode* DreamParser::FunVarDeclarationContext::ASSIGN() {
  return getToken(DreamParser::ASSIGN, 0);
}

DreamParser::ExprContext* DreamParser::FunVarDeclarationContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

tree::TerminalNode* DreamParser::FunVarDeclarationContext::VAR() {
  return getToken(DreamParser::VAR, 0);
}

tree::TerminalNode* DreamParser::FunVarDeclarationContext::IMT() {
  return getToken(DreamParser::IMT, 0);
}

tree::TerminalNode* DreamParser::FunVarDeclarationContext::BANG() {
  return getToken(DreamParser::BANG, 0);
}

tree::TerminalNode* DreamParser::FunVarDeclarationContext::QUESTION() {
  return getToken(DreamParser::QUESTION, 0);
}


size_t DreamParser::FunVarDeclarationContext::getRuleIndex() const {
  return DreamParser::RuleFunVarDeclaration;
}

void DreamParser::FunVarDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunVarDeclaration(this);
}

void DreamParser::FunVarDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunVarDeclaration(this);
}

DreamParser::FunVarDeclarationContext* DreamParser::funVarDeclaration() {
  FunVarDeclarationContext *_localctx = _tracker.createInstance<FunVarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 16, DreamParser::RuleFunVarDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DreamParser::VAR

    || _la == DreamParser::IMT) {
      setState(199);
      _la = _input->LA(1);
      if (!(_la == DreamParser::VAR

      || _la == DreamParser::IMT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(202);
    type();
    setState(203);
    match(DreamParser::IDENTIFIER);
    setState(205);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DreamParser::BANG

    || _la == DreamParser::QUESTION) {
      setState(204);
      _la = _input->LA(1);
      if (!(_la == DreamParser::BANG

      || _la == DreamParser::QUESTION)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(209);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DreamParser::ASSIGN) {
      setState(207);
      match(DreamParser::ASSIGN);
      setState(208);
      expr(0);
    }
    setState(211);
    match(DreamParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgListContext ------------------------------------------------------------------

DreamParser::ArgListContext::ArgListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DreamParser::ExprContext *> DreamParser::ArgListContext::expr() {
  return getRuleContexts<DreamParser::ExprContext>();
}

DreamParser::ExprContext* DreamParser::ArgListContext::expr(size_t i) {
  return getRuleContext<DreamParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> DreamParser::ArgListContext::COMMA() {
  return getTokens(DreamParser::COMMA);
}

tree::TerminalNode* DreamParser::ArgListContext::COMMA(size_t i) {
  return getToken(DreamParser::COMMA, i);
}


size_t DreamParser::ArgListContext::getRuleIndex() const {
  return DreamParser::RuleArgList;
}

void DreamParser::ArgListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArgList(this);
}

void DreamParser::ArgListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArgList(this);
}

DreamParser::ArgListContext* DreamParser::argList() {
  ArgListContext *_localctx = _tracker.createInstance<ArgListContext>(_ctx, getState());
  enterRule(_localctx, 18, DreamParser::RuleArgList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(213);
    expr(0);
    setState(218);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DreamParser::COMMA) {
      setState(214);
      match(DreamParser::COMMA);
      setState(215);
      expr(0);
      setState(220);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- LiteralContext ------------------------------------------------------------------

DreamParser::LiteralContext::LiteralContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::LiteralContext::INT_LITERAL() {
  return getToken(DreamParser::INT_LITERAL, 0);
}

tree::TerminalNode* DreamParser::LiteralContext::FLOAT_LITERAL() {
  return getToken(DreamParser::FLOAT_LITERAL, 0);
}

tree::TerminalNode* DreamParser::LiteralContext::STRING_LITERAL() {
  return getToken(DreamParser::STRING_LITERAL, 0);
}

tree::TerminalNode* DreamParser::LiteralContext::CHAR_LITERAL() {
  return getToken(DreamParser::CHAR_LITERAL, 0);
}

tree::TerminalNode* DreamParser::LiteralContext::TRUE_LITERAL() {
  return getToken(DreamParser::TRUE_LITERAL, 0);
}

tree::TerminalNode* DreamParser::LiteralContext::FALSE_LITERAL() {
  return getToken(DreamParser::FALSE_LITERAL, 0);
}


size_t DreamParser::LiteralContext::getRuleIndex() const {
  return DreamParser::RuleLiteral;
}

void DreamParser::LiteralContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral(this);
}

void DreamParser::LiteralContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral(this);
}

DreamParser::LiteralContext* DreamParser::literal() {
  LiteralContext *_localctx = _tracker.createInstance<LiteralContext>(_ctx, getState());
  enterRule(_localctx, 20, DreamParser::RuleLiteral);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 1090715534753794) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayInitContext ------------------------------------------------------------------

DreamParser::ArrayInitContext::ArrayInitContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::ArrayInitContext::LBRACK() {
  return getToken(DreamParser::LBRACK, 0);
}

tree::TerminalNode* DreamParser::ArrayInitContext::RBRACK() {
  return getToken(DreamParser::RBRACK, 0);
}

std::vector<DreamParser::ExprContext *> DreamParser::ArrayInitContext::expr() {
  return getRuleContexts<DreamParser::ExprContext>();
}

DreamParser::ExprContext* DreamParser::ArrayInitContext::expr(size_t i) {
  return getRuleContext<DreamParser::ExprContext>(i);
}

std::vector<tree::TerminalNode *> DreamParser::ArrayInitContext::COMMA() {
  return getTokens(DreamParser::COMMA);
}

tree::TerminalNode* DreamParser::ArrayInitContext::COMMA(size_t i) {
  return getToken(DreamParser::COMMA, i);
}

std::vector<DreamParser::ArrayInitContext *> DreamParser::ArrayInitContext::arrayInit() {
  return getRuleContexts<DreamParser::ArrayInitContext>();
}

DreamParser::ArrayInitContext* DreamParser::ArrayInitContext::arrayInit(size_t i) {
  return getRuleContext<DreamParser::ArrayInitContext>(i);
}


size_t DreamParser::ArrayInitContext::getRuleIndex() const {
  return DreamParser::RuleArrayInit;
}

void DreamParser::ArrayInitContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayInit(this);
}

void DreamParser::ArrayInitContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayInit(this);
}

DreamParser::ArrayInitContext* DreamParser::arrayInit() {
  ArrayInitContext *_localctx = _tracker.createInstance<ArrayInitContext>(_ctx, getState());
  enterRule(_localctx, 22, DreamParser::RuleArrayInit);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(247);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 18, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(223);
      match(DreamParser::LBRACK);
      setState(232);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 309596085574172674) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & 62914609) != 0)) {
        setState(224);
        expr(0);
        setState(229);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == DreamParser::COMMA) {
          setState(225);
          match(DreamParser::COMMA);
          setState(226);
          expr(0);
          setState(231);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(234);
      match(DreamParser::RBRACK);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(235);
      match(DreamParser::LBRACK);
      setState(244);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DreamParser::LBRACK) {
        setState(236);
        arrayInit();
        setState(241);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == DreamParser::COMMA) {
          setState(237);
          match(DreamParser::COMMA);
          setState(238);
          arrayInit();
          setState(243);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
      }
      setState(246);
      match(DreamParser::RBRACK);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CastExprContext ------------------------------------------------------------------

DreamParser::CastExprContext::CastExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::CastExprContext::LPAREN() {
  return getToken(DreamParser::LPAREN, 0);
}

DreamParser::TypeContext* DreamParser::CastExprContext::type() {
  return getRuleContext<DreamParser::TypeContext>(0);
}

tree::TerminalNode* DreamParser::CastExprContext::RPAREN() {
  return getToken(DreamParser::RPAREN, 0);
}

DreamParser::ExprContext* DreamParser::CastExprContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}


size_t DreamParser::CastExprContext::getRuleIndex() const {
  return DreamParser::RuleCastExpr;
}

void DreamParser::CastExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCastExpr(this);
}

void DreamParser::CastExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCastExpr(this);
}

DreamParser::CastExprContext* DreamParser::castExpr() {
  CastExprContext *_localctx = _tracker.createInstance<CastExprContext>(_ctx, getState());
  enterRule(_localctx, 24, DreamParser::RuleCastExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(249);
    match(DreamParser::LPAREN);
    setState(250);
    type();
    setState(251);
    match(DreamParser::RPAREN);
    setState(252);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AssignContext ------------------------------------------------------------------

DreamParser::AssignContext::AssignContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::AssignContext::ASSIGN() {
  return getToken(DreamParser::ASSIGN, 0);
}

DreamParser::ExprContext* DreamParser::AssignContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

std::vector<tree::TerminalNode *> DreamParser::AssignContext::IDENTIFIER() {
  return getTokens(DreamParser::IDENTIFIER);
}

tree::TerminalNode* DreamParser::AssignContext::IDENTIFIER(size_t i) {
  return getToken(DreamParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> DreamParser::AssignContext::DOT() {
  return getTokens(DreamParser::DOT);
}

tree::TerminalNode* DreamParser::AssignContext::DOT(size_t i) {
  return getToken(DreamParser::DOT, i);
}


size_t DreamParser::AssignContext::getRuleIndex() const {
  return DreamParser::RuleAssign;
}

void DreamParser::AssignContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssign(this);
}

void DreamParser::AssignContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssign(this);
}

DreamParser::AssignContext* DreamParser::assign() {
  AssignContext *_localctx = _tracker.createInstance<AssignContext>(_ctx, getState());
  enterRule(_localctx, 26, DreamParser::RuleAssign);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(254);
    match(DreamParser::IDENTIFIER);
    setState(259);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DreamParser::DOT) {
      setState(255);
      match(DreamParser::DOT);
      setState(256);
      match(DreamParser::IDENTIFIER);
      setState(261);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(262);
    match(DreamParser::ASSIGN);
    setState(263);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- UnaryOpExprContext ------------------------------------------------------------------

DreamParser::UnaryOpExprContext::UnaryOpExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::UnaryOpExprContext::BANG() {
  return getToken(DreamParser::BANG, 0);
}

DreamParser::ExprContext* DreamParser::UnaryOpExprContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

tree::TerminalNode* DreamParser::UnaryOpExprContext::PLUS() {
  return getToken(DreamParser::PLUS, 0);
}

tree::TerminalNode* DreamParser::UnaryOpExprContext::MINUS() {
  return getToken(DreamParser::MINUS, 0);
}

tree::TerminalNode* DreamParser::UnaryOpExprContext::INC() {
  return getToken(DreamParser::INC, 0);
}

tree::TerminalNode* DreamParser::UnaryOpExprContext::DEC() {
  return getToken(DreamParser::DEC, 0);
}

tree::TerminalNode* DreamParser::UnaryOpExprContext::TIBLE() {
  return getToken(DreamParser::TIBLE, 0);
}


size_t DreamParser::UnaryOpExprContext::getRuleIndex() const {
  return DreamParser::RuleUnaryOpExpr;
}

void DreamParser::UnaryOpExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnaryOpExpr(this);
}

void DreamParser::UnaryOpExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnaryOpExpr(this);
}

DreamParser::UnaryOpExprContext* DreamParser::unaryOpExpr() {
  UnaryOpExprContext *_localctx = _tracker.createInstance<UnaryOpExprContext>(_ctx, getState());
  enterRule(_localctx, 28, DreamParser::RuleUnaryOpExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(277);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DreamParser::BANG: {
        enterOuterAlt(_localctx, 1);
        setState(265);
        match(DreamParser::BANG);
        setState(266);
        expr(0);
        break;
      }

      case DreamParser::PLUS: {
        enterOuterAlt(_localctx, 2);
        setState(267);
        match(DreamParser::PLUS);
        setState(268);
        expr(0);
        break;
      }

      case DreamParser::MINUS: {
        enterOuterAlt(_localctx, 3);
        setState(269);
        match(DreamParser::MINUS);
        setState(270);
        expr(0);
        break;
      }

      case DreamParser::INC: {
        enterOuterAlt(_localctx, 4);
        setState(271);
        match(DreamParser::INC);
        setState(272);
        expr(0);
        break;
      }

      case DreamParser::DEC: {
        enterOuterAlt(_localctx, 5);
        setState(273);
        match(DreamParser::DEC);
        setState(274);
        expr(0);
        break;
      }

      case DreamParser::TIBLE: {
        enterOuterAlt(_localctx, 6);
        setState(275);
        match(DreamParser::TIBLE);
        setState(276);
        expr(0);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfExprContext ------------------------------------------------------------------

DreamParser::IfExprContext::IfExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::IfExprContext::LPAREN() {
  return getToken(DreamParser::LPAREN, 0);
}

std::vector<DreamParser::ExprContext *> DreamParser::IfExprContext::expr() {
  return getRuleContexts<DreamParser::ExprContext>();
}

DreamParser::ExprContext* DreamParser::IfExprContext::expr(size_t i) {
  return getRuleContext<DreamParser::ExprContext>(i);
}

tree::TerminalNode* DreamParser::IfExprContext::RPAREN() {
  return getToken(DreamParser::RPAREN, 0);
}

DreamParser::FunCallStmtContext* DreamParser::IfExprContext::funCallStmt() {
  return getRuleContext<DreamParser::FunCallStmtContext>(0);
}

DreamParser::UnaryOpExprContext* DreamParser::IfExprContext::unaryOpExpr() {
  return getRuleContext<DreamParser::UnaryOpExprContext>(0);
}

tree::TerminalNode* DreamParser::IfExprContext::MUL() {
  return getToken(DreamParser::MUL, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::SLASH() {
  return getToken(DreamParser::SLASH, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::MOD() {
  return getToken(DreamParser::MOD, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::PLUS() {
  return getToken(DreamParser::PLUS, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::MINUS() {
  return getToken(DreamParser::MINUS, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::LSHIFT() {
  return getToken(DreamParser::LSHIFT, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::RSHIFT() {
  return getToken(DreamParser::RSHIFT, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::URSHIFT() {
  return getToken(DreamParser::URSHIFT, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::LT() {
  return getToken(DreamParser::LT, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::GT() {
  return getToken(DreamParser::GT, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::LE() {
  return getToken(DreamParser::LE, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::GE() {
  return getToken(DreamParser::GE, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::EQ() {
  return getToken(DreamParser::EQ, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::NEQ() {
  return getToken(DreamParser::NEQ, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::BIT_AND() {
  return getToken(DreamParser::BIT_AND, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::XOR() {
  return getToken(DreamParser::XOR, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::BIT_OR() {
  return getToken(DreamParser::BIT_OR, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::AND() {
  return getToken(DreamParser::AND, 0);
}

tree::TerminalNode* DreamParser::IfExprContext::OR() {
  return getToken(DreamParser::OR, 0);
}

DreamParser::AtomExprContext* DreamParser::IfExprContext::atomExpr() {
  return getRuleContext<DreamParser::AtomExprContext>(0);
}

DreamParser::CastExprContext* DreamParser::IfExprContext::castExpr() {
  return getRuleContext<DreamParser::CastExprContext>(0);
}

DreamParser::AssignExprContext* DreamParser::IfExprContext::assignExpr() {
  return getRuleContext<DreamParser::AssignExprContext>(0);
}


size_t DreamParser::IfExprContext::getRuleIndex() const {
  return DreamParser::RuleIfExpr;
}

void DreamParser::IfExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfExpr(this);
}

void DreamParser::IfExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfExpr(this);
}

DreamParser::IfExprContext* DreamParser::ifExpr() {
  IfExprContext *_localctx = _tracker.createInstance<IfExprContext>(_ctx, getState());
  enterRule(_localctx, 30, DreamParser::RuleIfExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(328);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(279);
      match(DreamParser::LPAREN);
      setState(280);
      expr(0);
      setState(281);
      match(DreamParser::RPAREN);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(283);
      funCallStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(284);
      unaryOpExpr();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(285);
      expr(0);
      setState(286);
      _la = _input->LA(1);
      if (!(((((_la - 51) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 51)) & 1179649) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(287);
      expr(0);
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(289);
      expr(0);
      setState(290);
      _la = _input->LA(1);
      if (!(_la == DreamParser::PLUS

      || _la == DreamParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(291);
      expr(0);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(293);
      expr(0);
      setState(294);
      _la = _input->LA(1);
      if (!(((((_la - 83) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 83)) & 7) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(295);
      expr(0);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(297);
      expr(0);
      setState(298);
      _la = _input->LA(1);
      if (!(((((_la - 72) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 72)) & 15) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(299);
      expr(0);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(301);
      expr(0);
      setState(302);
      _la = _input->LA(1);
      if (!(_la == DreamParser::EQ

      || _la == DreamParser::NEQ)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(303);
      expr(0);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(305);
      expr(0);
      setState(306);
      match(DreamParser::BIT_AND);
      setState(307);
      expr(0);
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(309);
      expr(0);
      setState(310);
      match(DreamParser::XOR);
      setState(311);
      expr(0);
      break;
    }

    case 11: {
      enterOuterAlt(_localctx, 11);
      setState(313);
      expr(0);
      setState(314);
      match(DreamParser::BIT_OR);
      setState(315);
      expr(0);
      break;
    }

    case 12: {
      enterOuterAlt(_localctx, 12);
      setState(317);
      expr(0);
      setState(318);
      match(DreamParser::AND);
      setState(319);
      expr(0);
      break;
    }

    case 13: {
      enterOuterAlt(_localctx, 13);
      setState(321);
      expr(0);
      setState(322);
      match(DreamParser::OR);
      setState(323);
      expr(0);
      break;
    }

    case 14: {
      enterOuterAlt(_localctx, 14);
      setState(325);
      atomExpr();
      break;
    }

    case 15: {
      enterOuterAlt(_localctx, 15);
      setState(326);
      castExpr();
      break;
    }

    case 16: {
      enterOuterAlt(_localctx, 16);
      setState(327);
      assignExpr();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtContext ------------------------------------------------------------------

DreamParser::IfStmtContext::IfStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::IfStmtContext::IF() {
  return getToken(DreamParser::IF, 0);
}

DreamParser::IfExprContext* DreamParser::IfStmtContext::ifExpr() {
  return getRuleContext<DreamParser::IfExprContext>(0);
}

DreamParser::IfBlockContext* DreamParser::IfStmtContext::ifBlock() {
  return getRuleContext<DreamParser::IfBlockContext>(0);
}

std::vector<DreamParser::ElseIfClauseContext *> DreamParser::IfStmtContext::elseIfClause() {
  return getRuleContexts<DreamParser::ElseIfClauseContext>();
}

DreamParser::ElseIfClauseContext* DreamParser::IfStmtContext::elseIfClause(size_t i) {
  return getRuleContext<DreamParser::ElseIfClauseContext>(i);
}

DreamParser::ElseClauseContext* DreamParser::IfStmtContext::elseClause() {
  return getRuleContext<DreamParser::ElseClauseContext>(0);
}


size_t DreamParser::IfStmtContext::getRuleIndex() const {
  return DreamParser::RuleIfStmt;
}

void DreamParser::IfStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmt(this);
}

void DreamParser::IfStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmt(this);
}

DreamParser::IfStmtContext* DreamParser::ifStmt() {
  IfStmtContext *_localctx = _tracker.createInstance<IfStmtContext>(_ctx, getState());
  enterRule(_localctx, 32, DreamParser::RuleIfStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(330);
    match(DreamParser::IF);
    setState(331);
    ifExpr();
    setState(332);
    ifBlock();
    setState(336);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(333);
        elseIfClause(); 
      }
      setState(338);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx);
    }
    setState(340);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DreamParser::ELSE) {
      setState(339);
      elseClause();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfBlockContext ------------------------------------------------------------------

DreamParser::IfBlockContext::IfBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::IfBlockContext::LBRACE() {
  return getToken(DreamParser::LBRACE, 0);
}

tree::TerminalNode* DreamParser::IfBlockContext::RBRACE() {
  return getToken(DreamParser::RBRACE, 0);
}

std::vector<DreamParser::IfStmtBodyContext *> DreamParser::IfBlockContext::ifStmtBody() {
  return getRuleContexts<DreamParser::IfStmtBodyContext>();
}

DreamParser::IfStmtBodyContext* DreamParser::IfBlockContext::ifStmtBody(size_t i) {
  return getRuleContext<DreamParser::IfStmtBodyContext>(i);
}


size_t DreamParser::IfBlockContext::getRuleIndex() const {
  return DreamParser::RuleIfBlock;
}

void DreamParser::IfBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfBlock(this);
}

void DreamParser::IfBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfBlock(this);
}

DreamParser::IfBlockContext* DreamParser::ifBlock() {
  IfBlockContext *_localctx = _tracker.createInstance<IfBlockContext>(_ctx, getState());
  enterRule(_localctx, 34, DreamParser::RuleIfBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(342);
    match(DreamParser::LBRACE);
    setState(346);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 309596085708394030) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 62914609) != 0)) {
      setState(343);
      ifStmtBody();
      setState(348);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(349);
    match(DreamParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- AtomExprContext ------------------------------------------------------------------

DreamParser::AtomExprContext::AtomExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DreamParser::AtomExprContext::IDENTIFIER() {
  return getTokens(DreamParser::IDENTIFIER);
}

tree::TerminalNode* DreamParser::AtomExprContext::IDENTIFIER(size_t i) {
  return getToken(DreamParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> DreamParser::AtomExprContext::DOT() {
  return getTokens(DreamParser::DOT);
}

tree::TerminalNode* DreamParser::AtomExprContext::DOT(size_t i) {
  return getToken(DreamParser::DOT, i);
}

tree::TerminalNode* DreamParser::AtomExprContext::NEW() {
  return getToken(DreamParser::NEW, 0);
}

tree::TerminalNode* DreamParser::AtomExprContext::LPAREN() {
  return getToken(DreamParser::LPAREN, 0);
}

tree::TerminalNode* DreamParser::AtomExprContext::RPAREN() {
  return getToken(DreamParser::RPAREN, 0);
}

DreamParser::ArgListContext* DreamParser::AtomExprContext::argList() {
  return getRuleContext<DreamParser::ArgListContext>(0);
}

DreamParser::ExprContext* DreamParser::AtomExprContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

tree::TerminalNode* DreamParser::AtomExprContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}

DreamParser::LiteralContext* DreamParser::AtomExprContext::literal() {
  return getRuleContext<DreamParser::LiteralContext>(0);
}

DreamParser::ArrayInitContext* DreamParser::AtomExprContext::arrayInit() {
  return getRuleContext<DreamParser::ArrayInitContext>(0);
}

DreamParser::CastExprContext* DreamParser::AtomExprContext::castExpr() {
  return getRuleContext<DreamParser::CastExprContext>(0);
}

DreamParser::AssignContext* DreamParser::AtomExprContext::assign() {
  return getRuleContext<DreamParser::AssignContext>(0);
}


size_t DreamParser::AtomExprContext::getRuleIndex() const {
  return DreamParser::RuleAtomExpr;
}

void DreamParser::AtomExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAtomExpr(this);
}

void DreamParser::AtomExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAtomExpr(this);
}

DreamParser::AtomExprContext* DreamParser::atomExpr() {
  AtomExprContext *_localctx = _tracker.createInstance<AtomExprContext>(_ctx, getState());
  enterRule(_localctx, 36, DreamParser::RuleAtomExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    size_t alt;
    setState(376);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(351);
      match(DreamParser::IDENTIFIER);
      setState(356);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
      while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
        if (alt == 1) {
          setState(352);
          match(DreamParser::DOT);
          setState(353);
          match(DreamParser::IDENTIFIER); 
        }
        setState(358);
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx);
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(359);
      match(DreamParser::NEW);
      setState(360);
      match(DreamParser::IDENTIFIER);
      setState(361);
      match(DreamParser::LPAREN);
      setState(363);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 309596085574172674) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & 62914609) != 0)) {
        setState(362);
        argList();
      }
      setState(365);
      match(DreamParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(366);
      match(DreamParser::IDENTIFIER);
      setState(367);
      match(DreamParser::LPAREN);
      setState(368);
      expr(0);
      setState(369);
      match(DreamParser::RPAREN);
      setState(370);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(372);
      literal();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(373);
      arrayInit();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(374);
      castExpr();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(375);
      assign();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IfStmtBodyContext ------------------------------------------------------------------

DreamParser::IfStmtBodyContext::IfStmtBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::ExprContext* DreamParser::IfStmtBodyContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

tree::TerminalNode* DreamParser::IfStmtBodyContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}

DreamParser::IfStmtContext* DreamParser::IfStmtBodyContext::ifStmt() {
  return getRuleContext<DreamParser::IfStmtContext>(0);
}

DreamParser::ReturnStmtContext* DreamParser::IfStmtBodyContext::returnStmt() {
  return getRuleContext<DreamParser::ReturnStmtContext>(0);
}

DreamParser::ForStmtContext* DreamParser::IfStmtBodyContext::forStmt() {
  return getRuleContext<DreamParser::ForStmtContext>(0);
}

DreamParser::TryCatchStmtContext* DreamParser::IfStmtBodyContext::tryCatchStmt() {
  return getRuleContext<DreamParser::TryCatchStmtContext>(0);
}

DreamParser::ThrowStmtContext* DreamParser::IfStmtBodyContext::throwStmt() {
  return getRuleContext<DreamParser::ThrowStmtContext>(0);
}

tree::TerminalNode* DreamParser::IfStmtBodyContext::BREAK() {
  return getToken(DreamParser::BREAK, 0);
}

tree::TerminalNode* DreamParser::IfStmtBodyContext::CONTINUE() {
  return getToken(DreamParser::CONTINUE, 0);
}

DreamParser::FunCallStmtContext* DreamParser::IfStmtBodyContext::funCallStmt() {
  return getRuleContext<DreamParser::FunCallStmtContext>(0);
}


size_t DreamParser::IfStmtBodyContext::getRuleIndex() const {
  return DreamParser::RuleIfStmtBody;
}

void DreamParser::IfStmtBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIfStmtBody(this);
}

void DreamParser::IfStmtBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIfStmtBody(this);
}

DreamParser::IfStmtBodyContext* DreamParser::ifStmtBody() {
  IfStmtBodyContext *_localctx = _tracker.createInstance<IfStmtBodyContext>(_ctx, getState());
  enterRule(_localctx, 38, DreamParser::RuleIfStmtBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(393);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(378);
      expr(0);
      setState(379);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(381);
      ifStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(382);
      returnStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(383);
      forStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(384);
      tryCatchStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(385);
      throwStmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(386);
      match(DreamParser::BREAK);
      setState(387);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(388);
      match(DreamParser::CONTINUE);
      setState(389);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(390);
      funCallStmt();
      setState(391);
      match(DreamParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnStmtContext ------------------------------------------------------------------

DreamParser::ReturnStmtContext::ReturnStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::ReturnStmtContext::RETURN() {
  return getToken(DreamParser::RETURN, 0);
}

std::vector<DreamParser::ExprContext *> DreamParser::ReturnStmtContext::expr() {
  return getRuleContexts<DreamParser::ExprContext>();
}

DreamParser::ExprContext* DreamParser::ReturnStmtContext::expr(size_t i) {
  return getRuleContext<DreamParser::ExprContext>(i);
}

tree::TerminalNode* DreamParser::ReturnStmtContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}

tree::TerminalNode* DreamParser::ReturnStmtContext::LPAREN() {
  return getToken(DreamParser::LPAREN, 0);
}

tree::TerminalNode* DreamParser::ReturnStmtContext::RPAREN() {
  return getToken(DreamParser::RPAREN, 0);
}

std::vector<tree::TerminalNode *> DreamParser::ReturnStmtContext::COMMA() {
  return getTokens(DreamParser::COMMA);
}

tree::TerminalNode* DreamParser::ReturnStmtContext::COMMA(size_t i) {
  return getToken(DreamParser::COMMA, i);
}


size_t DreamParser::ReturnStmtContext::getRuleIndex() const {
  return DreamParser::RuleReturnStmt;
}

void DreamParser::ReturnStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnStmt(this);
}

void DreamParser::ReturnStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnStmt(this);
}

DreamParser::ReturnStmtContext* DreamParser::returnStmt() {
  ReturnStmtContext *_localctx = _tracker.createInstance<ReturnStmtContext>(_ctx, getState());
  enterRule(_localctx, 40, DreamParser::RuleReturnStmt);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(414);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(395);
      match(DreamParser::RETURN);
      setState(396);
      expr(0);
      setState(397);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(399);
      match(DreamParser::RETURN);
      setState(400);
      match(DreamParser::LPAREN);
      setState(401);
      expr(0);
      setState(406);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while (_la == DreamParser::COMMA) {
        setState(402);
        match(DreamParser::COMMA);
        setState(403);
        expr(0);
        setState(408);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(409);
      match(DreamParser::RPAREN);
      setState(410);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(412);
      match(DreamParser::RETURN);
      setState(413);
      match(DreamParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseIfClauseContext ------------------------------------------------------------------

DreamParser::ElseIfClauseContext::ElseIfClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::ElseIfClauseContext::ELSE() {
  return getToken(DreamParser::ELSE, 0);
}

tree::TerminalNode* DreamParser::ElseIfClauseContext::IF() {
  return getToken(DreamParser::IF, 0);
}

DreamParser::IfExprContext* DreamParser::ElseIfClauseContext::ifExpr() {
  return getRuleContext<DreamParser::IfExprContext>(0);
}

DreamParser::IfBlockContext* DreamParser::ElseIfClauseContext::ifBlock() {
  return getRuleContext<DreamParser::IfBlockContext>(0);
}


size_t DreamParser::ElseIfClauseContext::getRuleIndex() const {
  return DreamParser::RuleElseIfClause;
}

void DreamParser::ElseIfClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseIfClause(this);
}

void DreamParser::ElseIfClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseIfClause(this);
}

DreamParser::ElseIfClauseContext* DreamParser::elseIfClause() {
  ElseIfClauseContext *_localctx = _tracker.createInstance<ElseIfClauseContext>(_ctx, getState());
  enterRule(_localctx, 42, DreamParser::RuleElseIfClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(416);
    match(DreamParser::ELSE);
    setState(417);
    match(DreamParser::IF);
    setState(418);
    ifExpr();
    setState(419);
    ifBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElseClauseContext ------------------------------------------------------------------

DreamParser::ElseClauseContext::ElseClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::ElseClauseContext::ELSE() {
  return getToken(DreamParser::ELSE, 0);
}

DreamParser::IfBlockContext* DreamParser::ElseClauseContext::ifBlock() {
  return getRuleContext<DreamParser::IfBlockContext>(0);
}


size_t DreamParser::ElseClauseContext::getRuleIndex() const {
  return DreamParser::RuleElseClause;
}

void DreamParser::ElseClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterElseClause(this);
}

void DreamParser::ElseClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitElseClause(this);
}

DreamParser::ElseClauseContext* DreamParser::elseClause() {
  ElseClauseContext *_localctx = _tracker.createInstance<ElseClauseContext>(_ctx, getState());
  enterRule(_localctx, 44, DreamParser::RuleElseClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(421);
    match(DreamParser::ELSE);
    setState(422);
    ifBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

DreamParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::ExprContext::LPAREN() {
  return getToken(DreamParser::LPAREN, 0);
}

std::vector<DreamParser::ExprContext *> DreamParser::ExprContext::expr() {
  return getRuleContexts<DreamParser::ExprContext>();
}

DreamParser::ExprContext* DreamParser::ExprContext::expr(size_t i) {
  return getRuleContext<DreamParser::ExprContext>(i);
}

tree::TerminalNode* DreamParser::ExprContext::RPAREN() {
  return getToken(DreamParser::RPAREN, 0);
}

DreamParser::FunCallStmtContext* DreamParser::ExprContext::funCallStmt() {
  return getRuleContext<DreamParser::FunCallStmtContext>(0);
}

DreamParser::UnaryOpExprContext* DreamParser::ExprContext::unaryOpExpr() {
  return getRuleContext<DreamParser::UnaryOpExprContext>(0);
}

DreamParser::AtomExprContext* DreamParser::ExprContext::atomExpr() {
  return getRuleContext<DreamParser::AtomExprContext>(0);
}

DreamParser::CastExprContext* DreamParser::ExprContext::castExpr() {
  return getRuleContext<DreamParser::CastExprContext>(0);
}

DreamParser::AssignExprContext* DreamParser::ExprContext::assignExpr() {
  return getRuleContext<DreamParser::AssignExprContext>(0);
}

tree::TerminalNode* DreamParser::ExprContext::MUL() {
  return getToken(DreamParser::MUL, 0);
}

tree::TerminalNode* DreamParser::ExprContext::SLASH() {
  return getToken(DreamParser::SLASH, 0);
}

tree::TerminalNode* DreamParser::ExprContext::MOD() {
  return getToken(DreamParser::MOD, 0);
}

tree::TerminalNode* DreamParser::ExprContext::PLUS() {
  return getToken(DreamParser::PLUS, 0);
}

tree::TerminalNode* DreamParser::ExprContext::MINUS() {
  return getToken(DreamParser::MINUS, 0);
}

tree::TerminalNode* DreamParser::ExprContext::LSHIFT() {
  return getToken(DreamParser::LSHIFT, 0);
}

tree::TerminalNode* DreamParser::ExprContext::RSHIFT() {
  return getToken(DreamParser::RSHIFT, 0);
}

tree::TerminalNode* DreamParser::ExprContext::URSHIFT() {
  return getToken(DreamParser::URSHIFT, 0);
}

tree::TerminalNode* DreamParser::ExprContext::LT() {
  return getToken(DreamParser::LT, 0);
}

tree::TerminalNode* DreamParser::ExprContext::GT() {
  return getToken(DreamParser::GT, 0);
}

tree::TerminalNode* DreamParser::ExprContext::LE() {
  return getToken(DreamParser::LE, 0);
}

tree::TerminalNode* DreamParser::ExprContext::GE() {
  return getToken(DreamParser::GE, 0);
}

tree::TerminalNode* DreamParser::ExprContext::EQ() {
  return getToken(DreamParser::EQ, 0);
}

tree::TerminalNode* DreamParser::ExprContext::NEQ() {
  return getToken(DreamParser::NEQ, 0);
}

tree::TerminalNode* DreamParser::ExprContext::BIT_AND() {
  return getToken(DreamParser::BIT_AND, 0);
}

tree::TerminalNode* DreamParser::ExprContext::XOR() {
  return getToken(DreamParser::XOR, 0);
}

tree::TerminalNode* DreamParser::ExprContext::BIT_OR() {
  return getToken(DreamParser::BIT_OR, 0);
}

tree::TerminalNode* DreamParser::ExprContext::AND() {
  return getToken(DreamParser::AND, 0);
}

tree::TerminalNode* DreamParser::ExprContext::OR() {
  return getToken(DreamParser::OR, 0);
}


size_t DreamParser::ExprContext::getRuleIndex() const {
  return DreamParser::RuleExpr;
}

void DreamParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void DreamParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


DreamParser::ExprContext* DreamParser::expr() {
   return expr(0);
}

DreamParser::ExprContext* DreamParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  DreamParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  DreamParser::ExprContext *previousContext = _localctx;
  (void)previousContext; // Silence compiler, in case the context is not used by generated code.
  size_t startState = 46;
  enterRecursionRule(_localctx, 46, DreamParser::RuleExpr, precedence);

    size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(434);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 31, _ctx)) {
    case 1: {
      setState(425);
      match(DreamParser::LPAREN);
      setState(426);
      expr(0);
      setState(427);
      match(DreamParser::RPAREN);
      break;
    }

    case 2: {
      setState(429);
      funCallStmt();
      break;
    }

    case 3: {
      setState(430);
      unaryOpExpr();
      break;
    }

    case 4: {
      setState(431);
      atomExpr();
      break;
    }

    case 5: {
      setState(432);
      castExpr();
      break;
    }

    case 6: {
      setState(433);
      assignExpr();
      break;
    }

    default:
      break;
    }
    _ctx->stop = _input->LT(-1);
    setState(468);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(466);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(436);

          if (!(precpred(_ctx, 13))) throw FailedPredicateException(this, "precpred(_ctx, 13)");
          setState(437);
          _la = _input->LA(1);
          if (!(((((_la - 51) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 51)) & 1179649) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(438);
          expr(14);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(439);

          if (!(precpred(_ctx, 12))) throw FailedPredicateException(this, "precpred(_ctx, 12)");
          setState(440);
          _la = _input->LA(1);
          if (!(_la == DreamParser::PLUS

          || _la == DreamParser::MINUS)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(441);
          expr(13);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(442);

          if (!(precpred(_ctx, 11))) throw FailedPredicateException(this, "precpred(_ctx, 11)");
          setState(443);
          _la = _input->LA(1);
          if (!(((((_la - 83) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 83)) & 7) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(444);
          expr(12);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(445);

          if (!(precpred(_ctx, 10))) throw FailedPredicateException(this, "precpred(_ctx, 10)");
          setState(446);
          _la = _input->LA(1);
          if (!(((((_la - 72) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 72)) & 15) != 0))) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(447);
          expr(11);
          break;
        }

        case 5: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(448);

          if (!(precpred(_ctx, 9))) throw FailedPredicateException(this, "precpred(_ctx, 9)");
          setState(449);
          _la = _input->LA(1);
          if (!(_la == DreamParser::EQ

          || _la == DreamParser::NEQ)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(450);
          expr(10);
          break;
        }

        case 6: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(451);

          if (!(precpred(_ctx, 8))) throw FailedPredicateException(this, "precpred(_ctx, 8)");
          setState(452);
          match(DreamParser::BIT_AND);
          setState(453);
          expr(9);
          break;
        }

        case 7: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(454);

          if (!(precpred(_ctx, 7))) throw FailedPredicateException(this, "precpred(_ctx, 7)");
          setState(455);
          match(DreamParser::XOR);
          setState(456);
          expr(8);
          break;
        }

        case 8: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(457);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(458);
          match(DreamParser::BIT_OR);
          setState(459);
          expr(7);
          break;
        }

        case 9: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(460);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(461);
          match(DreamParser::AND);
          setState(462);
          expr(6);
          break;
        }

        case 10: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(463);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(464);
          match(DreamParser::OR);
          setState(465);
          expr(5);
          break;
        }

        default:
          break;
        } 
      }
      setState(470);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 33, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- AssignExprContext ------------------------------------------------------------------

DreamParser::AssignExprContext::AssignExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::TypeContext* DreamParser::AssignExprContext::type() {
  return getRuleContext<DreamParser::TypeContext>(0);
}

tree::TerminalNode* DreamParser::AssignExprContext::IDENTIFIER() {
  return getToken(DreamParser::IDENTIFIER, 0);
}

tree::TerminalNode* DreamParser::AssignExprContext::ASSIGN() {
  return getToken(DreamParser::ASSIGN, 0);
}

DreamParser::ExprContext* DreamParser::AssignExprContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

DreamParser::AssignContext* DreamParser::AssignExprContext::assign() {
  return getRuleContext<DreamParser::AssignContext>(0);
}


size_t DreamParser::AssignExprContext::getRuleIndex() const {
  return DreamParser::RuleAssignExpr;
}

void DreamParser::AssignExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAssignExpr(this);
}

void DreamParser::AssignExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAssignExpr(this);
}

DreamParser::AssignExprContext* DreamParser::assignExpr() {
  AssignExprContext *_localctx = _tracker.createInstance<AssignExprContext>(_ctx, getState());
  enterRule(_localctx, 48, DreamParser::RuleAssignExpr);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(477);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 34, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(471);
      type();
      setState(472);
      match(DreamParser::IDENTIFIER);
      setState(473);
      match(DreamParser::ASSIGN);
      setState(474);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(476);
      assign();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationContext ------------------------------------------------------------------

DreamParser::DeclarationContext::DeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::VarDeclarationContext* DreamParser::DeclarationContext::varDeclaration() {
  return getRuleContext<DreamParser::VarDeclarationContext>(0);
}

DreamParser::FunctionDeclarationContext* DreamParser::DeclarationContext::functionDeclaration() {
  return getRuleContext<DreamParser::FunctionDeclarationContext>(0);
}

DreamParser::StructDeclarationContext* DreamParser::DeclarationContext::structDeclaration() {
  return getRuleContext<DreamParser::StructDeclarationContext>(0);
}


size_t DreamParser::DeclarationContext::getRuleIndex() const {
  return DreamParser::RuleDeclaration;
}

void DreamParser::DeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeclaration(this);
}

void DreamParser::DeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeclaration(this);
}

DreamParser::DeclarationContext* DreamParser::declaration() {
  DeclarationContext *_localctx = _tracker.createInstance<DeclarationContext>(_ctx, getState());
  enterRule(_localctx, 50, DreamParser::RuleDeclaration);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(482);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DreamParser::VAR:
      case DreamParser::IMT:
      case DreamParser::BYTE:
      case DreamParser::SHORT:
      case DreamParser::INT:
      case DreamParser::UINT:
      case DreamParser::USHORT:
      case DreamParser::LONG:
      case DreamParser::ULONG:
      case DreamParser::LONGLONG:
      case DreamParser::ULONGLONG:
      case DreamParser::FLOAT:
      case DreamParser::DOUBLE:
      case DreamParser::BOOL:
      case DreamParser::CHAR:
      case DreamParser::STRING:
      case DreamParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(479);
        varDeclaration();
        break;
      }

      case DreamParser::FUN: {
        enterOuterAlt(_localctx, 2);
        setState(480);
        functionDeclaration();
        break;
      }

      case DreamParser::STRUCT: {
        enterOuterAlt(_localctx, 3);
        setState(481);
        structDeclaration();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructDeclarationContext ------------------------------------------------------------------

DreamParser::StructDeclarationContext::StructDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::StructDeclarationContext::STRUCT() {
  return getToken(DreamParser::STRUCT, 0);
}

tree::TerminalNode* DreamParser::StructDeclarationContext::IDENTIFIER() {
  return getToken(DreamParser::IDENTIFIER, 0);
}

tree::TerminalNode* DreamParser::StructDeclarationContext::LBRACE() {
  return getToken(DreamParser::LBRACE, 0);
}

tree::TerminalNode* DreamParser::StructDeclarationContext::RBRACE() {
  return getToken(DreamParser::RBRACE, 0);
}

tree::TerminalNode* DreamParser::StructDeclarationContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}

std::vector<DreamParser::StructMemberContext *> DreamParser::StructDeclarationContext::structMember() {
  return getRuleContexts<DreamParser::StructMemberContext>();
}

DreamParser::StructMemberContext* DreamParser::StructDeclarationContext::structMember(size_t i) {
  return getRuleContext<DreamParser::StructMemberContext>(i);
}


size_t DreamParser::StructDeclarationContext::getRuleIndex() const {
  return DreamParser::RuleStructDeclaration;
}

void DreamParser::StructDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructDeclaration(this);
}

void DreamParser::StructDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructDeclaration(this);
}

DreamParser::StructDeclarationContext* DreamParser::structDeclaration() {
  StructDeclarationContext *_localctx = _tracker.createInstance<StructDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 52, DreamParser::RuleStructDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(484);
    match(DreamParser::STRUCT);
    setState(485);
    match(DreamParser::IDENTIFIER);
    setState(486);
    match(DreamParser::LBRACE);
    setState(490);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8795556200448) != 0) || _la == DreamParser::IDENTIFIER) {
      setState(487);
      structMember();
      setState(492);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(493);
    match(DreamParser::RBRACE);
    setState(494);
    match(DreamParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StructMemberContext ------------------------------------------------------------------

DreamParser::StructMemberContext::StructMemberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::VarDeclarationContext* DreamParser::StructMemberContext::varDeclaration() {
  return getRuleContext<DreamParser::VarDeclarationContext>(0);
}


size_t DreamParser::StructMemberContext::getRuleIndex() const {
  return DreamParser::RuleStructMember;
}

void DreamParser::StructMemberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStructMember(this);
}

void DreamParser::StructMemberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStructMember(this);
}

DreamParser::StructMemberContext* DreamParser::structMember() {
  StructMemberContext *_localctx = _tracker.createInstance<StructMemberContext>(_ctx, getState());
  enterRule(_localctx, 54, DreamParser::RuleStructMember);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(496);
    varDeclaration();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VarDeclarationContext ------------------------------------------------------------------

DreamParser::VarDeclarationContext::VarDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::TypeContext* DreamParser::VarDeclarationContext::type() {
  return getRuleContext<DreamParser::TypeContext>(0);
}

tree::TerminalNode* DreamParser::VarDeclarationContext::IDENTIFIER() {
  return getToken(DreamParser::IDENTIFIER, 0);
}

tree::TerminalNode* DreamParser::VarDeclarationContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}

tree::TerminalNode* DreamParser::VarDeclarationContext::ASSIGN() {
  return getToken(DreamParser::ASSIGN, 0);
}

DreamParser::ExprContext* DreamParser::VarDeclarationContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

tree::TerminalNode* DreamParser::VarDeclarationContext::VAR() {
  return getToken(DreamParser::VAR, 0);
}

tree::TerminalNode* DreamParser::VarDeclarationContext::IMT() {
  return getToken(DreamParser::IMT, 0);
}

tree::TerminalNode* DreamParser::VarDeclarationContext::BANG() {
  return getToken(DreamParser::BANG, 0);
}

tree::TerminalNode* DreamParser::VarDeclarationContext::QUESTION() {
  return getToken(DreamParser::QUESTION, 0);
}


size_t DreamParser::VarDeclarationContext::getRuleIndex() const {
  return DreamParser::RuleVarDeclaration;
}

void DreamParser::VarDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVarDeclaration(this);
}

void DreamParser::VarDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVarDeclaration(this);
}

DreamParser::VarDeclarationContext* DreamParser::varDeclaration() {
  VarDeclarationContext *_localctx = _tracker.createInstance<VarDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 56, DreamParser::RuleVarDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(499);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DreamParser::VAR

    || _la == DreamParser::IMT) {
      setState(498);
      _la = _input->LA(1);
      if (!(_la == DreamParser::VAR

      || _la == DreamParser::IMT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(501);
    type();
    setState(502);
    match(DreamParser::IDENTIFIER);
    setState(504);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DreamParser::BANG

    || _la == DreamParser::QUESTION) {
      setState(503);
      _la = _input->LA(1);
      if (!(_la == DreamParser::BANG

      || _la == DreamParser::QUESTION)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(508);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DreamParser::ASSIGN) {
      setState(506);
      match(DreamParser::ASSIGN);
      setState(507);
      expr(0);
    }
    setState(510);
    match(DreamParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionDeclarationContext ------------------------------------------------------------------

DreamParser::FunctionDeclarationContext::FunctionDeclarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::FunctionDeclarationContext::FUN() {
  return getToken(DreamParser::FUN, 0);
}

tree::TerminalNode* DreamParser::FunctionDeclarationContext::IDENTIFIER() {
  return getToken(DreamParser::IDENTIFIER, 0);
}

tree::TerminalNode* DreamParser::FunctionDeclarationContext::LPAREN() {
  return getToken(DreamParser::LPAREN, 0);
}

tree::TerminalNode* DreamParser::FunctionDeclarationContext::RPAREN() {
  return getToken(DreamParser::RPAREN, 0);
}

DreamParser::FunBlockContext* DreamParser::FunctionDeclarationContext::funBlock() {
  return getRuleContext<DreamParser::FunBlockContext>(0);
}

DreamParser::ParamListContext* DreamParser::FunctionDeclarationContext::paramList() {
  return getRuleContext<DreamParser::ParamListContext>(0);
}

DreamParser::ReturnTypeContext* DreamParser::FunctionDeclarationContext::returnType() {
  return getRuleContext<DreamParser::ReturnTypeContext>(0);
}


size_t DreamParser::FunctionDeclarationContext::getRuleIndex() const {
  return DreamParser::RuleFunctionDeclaration;
}

void DreamParser::FunctionDeclarationContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunctionDeclaration(this);
}

void DreamParser::FunctionDeclarationContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunctionDeclaration(this);
}

DreamParser::FunctionDeclarationContext* DreamParser::functionDeclaration() {
  FunctionDeclarationContext *_localctx = _tracker.createInstance<FunctionDeclarationContext>(_ctx, getState());
  enterRule(_localctx, 58, DreamParser::RuleFunctionDeclaration);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(512);
    match(DreamParser::FUN);
    setState(513);
    match(DreamParser::IDENTIFIER);
    setState(514);
    match(DreamParser::LPAREN);
    setState(516);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 8795556200448) != 0) || _la == DreamParser::IDENTIFIER) {
      setState(515);
      paramList();
    }
    setState(518);
    match(DreamParser::RPAREN);
    setState(520);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (((((_la - 29) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 29)) & 2305843009247281151) != 0)) {
      setState(519);
      returnType();
    }
    setState(522);
    funBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunBlockContext ------------------------------------------------------------------

DreamParser::FunBlockContext::FunBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::FunBlockContext::LBRACE() {
  return getToken(DreamParser::LBRACE, 0);
}

tree::TerminalNode* DreamParser::FunBlockContext::RBRACE() {
  return getToken(DreamParser::RBRACE, 0);
}

std::vector<DreamParser::FunStmtContext *> DreamParser::FunBlockContext::funStmt() {
  return getRuleContexts<DreamParser::FunStmtContext>();
}

DreamParser::FunStmtContext* DreamParser::FunBlockContext::funStmt(size_t i) {
  return getRuleContext<DreamParser::FunStmtContext>(i);
}


size_t DreamParser::FunBlockContext::getRuleIndex() const {
  return DreamParser::RuleFunBlock;
}

void DreamParser::FunBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunBlock(this);
}

void DreamParser::FunBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunBlock(this);
}

DreamParser::FunBlockContext* DreamParser::funBlock() {
  FunBlockContext *_localctx = _tracker.createInstance<FunBlockContext>(_ctx, getState());
  enterRule(_localctx, 60, DreamParser::RuleFunBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(524);
    match(DreamParser::LBRACE);
    setState(528);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 381653679779924014) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 62914609) != 0)) {
      setState(525);
      funStmt();
      setState(530);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(531);
    match(DreamParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunStmtContext ------------------------------------------------------------------

DreamParser::FunStmtContext::FunStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::TryCatchStmtContext* DreamParser::FunStmtContext::tryCatchStmt() {
  return getRuleContext<DreamParser::TryCatchStmtContext>(0);
}

tree::TerminalNode* DreamParser::FunStmtContext::NATIVE() {
  return getToken(DreamParser::NATIVE, 0);
}

tree::TerminalNode* DreamParser::FunStmtContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}

DreamParser::IfStmtContext* DreamParser::FunStmtContext::ifStmt() {
  return getRuleContext<DreamParser::IfStmtContext>(0);
}

DreamParser::ForStmtContext* DreamParser::FunStmtContext::forStmt() {
  return getRuleContext<DreamParser::ForStmtContext>(0);
}

DreamParser::FunVarDeclarationContext* DreamParser::FunStmtContext::funVarDeclaration() {
  return getRuleContext<DreamParser::FunVarDeclarationContext>(0);
}

DreamParser::ReturnStmtContext* DreamParser::FunStmtContext::returnStmt() {
  return getRuleContext<DreamParser::ReturnStmtContext>(0);
}

DreamParser::ExprContext* DreamParser::FunStmtContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

DreamParser::ThrowStmtContext* DreamParser::FunStmtContext::throwStmt() {
  return getRuleContext<DreamParser::ThrowStmtContext>(0);
}

DreamParser::FileCodeBlockContext* DreamParser::FunStmtContext::fileCodeBlock() {
  return getRuleContext<DreamParser::FileCodeBlockContext>(0);
}


size_t DreamParser::FunStmtContext::getRuleIndex() const {
  return DreamParser::RuleFunStmt;
}

void DreamParser::FunStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunStmt(this);
}

void DreamParser::FunStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunStmt(this);
}

DreamParser::FunStmtContext* DreamParser::funStmt() {
  FunStmtContext *_localctx = _tracker.createInstance<FunStmtContext>(_ctx, getState());
  enterRule(_localctx, 62, DreamParser::RuleFunStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(545);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 43, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(533);
      tryCatchStmt();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(534);
      match(DreamParser::NATIVE);
      setState(535);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(536);
      ifStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(537);
      forStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(538);
      funVarDeclaration();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(539);
      returnStmt();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(540);
      expr(0);
      setState(541);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(543);
      throwStmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(544);
      fileCodeBlock();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ThrowStmtContext ------------------------------------------------------------------

DreamParser::ThrowStmtContext::ThrowStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::ThrowStmtContext::THROW() {
  return getToken(DreamParser::THROW, 0);
}

DreamParser::ExprContext* DreamParser::ThrowStmtContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

tree::TerminalNode* DreamParser::ThrowStmtContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}


size_t DreamParser::ThrowStmtContext::getRuleIndex() const {
  return DreamParser::RuleThrowStmt;
}

void DreamParser::ThrowStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterThrowStmt(this);
}

void DreamParser::ThrowStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitThrowStmt(this);
}

DreamParser::ThrowStmtContext* DreamParser::throwStmt() {
  ThrowStmtContext *_localctx = _tracker.createInstance<ThrowStmtContext>(_ctx, getState());
  enterRule(_localctx, 64, DreamParser::RuleThrowStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(547);
    match(DreamParser::THROW);
    setState(548);
    expr(0);
    setState(549);
    match(DreamParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SynchronizedStmtContext ------------------------------------------------------------------

DreamParser::SynchronizedStmtContext::SynchronizedStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::SynchronizedStmtContext::SYNCHRONIZED() {
  return getToken(DreamParser::SYNCHRONIZED, 0);
}

tree::TerminalNode* DreamParser::SynchronizedStmtContext::LPAREN() {
  return getToken(DreamParser::LPAREN, 0);
}

DreamParser::ExprContext* DreamParser::SynchronizedStmtContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

tree::TerminalNode* DreamParser::SynchronizedStmtContext::RPAREN() {
  return getToken(DreamParser::RPAREN, 0);
}

DreamParser::FileCodeBlockContext* DreamParser::SynchronizedStmtContext::fileCodeBlock() {
  return getRuleContext<DreamParser::FileCodeBlockContext>(0);
}

DreamParser::FunCodeBlockContext* DreamParser::SynchronizedStmtContext::funCodeBlock() {
  return getRuleContext<DreamParser::FunCodeBlockContext>(0);
}


size_t DreamParser::SynchronizedStmtContext::getRuleIndex() const {
  return DreamParser::RuleSynchronizedStmt;
}

void DreamParser::SynchronizedStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSynchronizedStmt(this);
}

void DreamParser::SynchronizedStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSynchronizedStmt(this);
}

DreamParser::SynchronizedStmtContext* DreamParser::synchronizedStmt() {
  SynchronizedStmtContext *_localctx = _tracker.createInstance<SynchronizedStmtContext>(_ctx, getState());
  enterRule(_localctx, 66, DreamParser::RuleSynchronizedStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(551);
    match(DreamParser::SYNCHRONIZED);
    setState(552);
    match(DreamParser::LPAREN);
    setState(553);
    expr(0);
    setState(554);
    match(DreamParser::RPAREN);
    setState(557);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 44, _ctx)) {
    case 1: {
      setState(555);
      fileCodeBlock();
      break;
    }

    case 2: {
      setState(556);
      funCodeBlock();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TryCatchStmtContext ------------------------------------------------------------------

DreamParser::TryCatchStmtContext::TryCatchStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::TryCatchStmtContext::TRY() {
  return getToken(DreamParser::TRY, 0);
}

DreamParser::FunCodeBlockContext* DreamParser::TryCatchStmtContext::funCodeBlock() {
  return getRuleContext<DreamParser::FunCodeBlockContext>(0);
}

DreamParser::CatchesContext* DreamParser::TryCatchStmtContext::catches() {
  return getRuleContext<DreamParser::CatchesContext>(0);
}

DreamParser::Finally_Context* DreamParser::TryCatchStmtContext::finally_() {
  return getRuleContext<DreamParser::Finally_Context>(0);
}


size_t DreamParser::TryCatchStmtContext::getRuleIndex() const {
  return DreamParser::RuleTryCatchStmt;
}

void DreamParser::TryCatchStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTryCatchStmt(this);
}

void DreamParser::TryCatchStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTryCatchStmt(this);
}

DreamParser::TryCatchStmtContext* DreamParser::tryCatchStmt() {
  TryCatchStmtContext *_localctx = _tracker.createInstance<TryCatchStmtContext>(_ctx, getState());
  enterRule(_localctx, 68, DreamParser::RuleTryCatchStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(568);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 45, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(559);
      match(DreamParser::TRY);
      setState(560);
      funCodeBlock();
      setState(561);
      catches();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(563);
      match(DreamParser::TRY);
      setState(564);
      funCodeBlock();
      setState(565);
      catches();
      setState(566);
      finally_();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatchesContext ------------------------------------------------------------------

DreamParser::CatchesContext::CatchesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DreamParser::CatchClauseContext *> DreamParser::CatchesContext::catchClause() {
  return getRuleContexts<DreamParser::CatchClauseContext>();
}

DreamParser::CatchClauseContext* DreamParser::CatchesContext::catchClause(size_t i) {
  return getRuleContext<DreamParser::CatchClauseContext>(i);
}


size_t DreamParser::CatchesContext::getRuleIndex() const {
  return DreamParser::RuleCatches;
}

void DreamParser::CatchesContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCatches(this);
}

void DreamParser::CatchesContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCatches(this);
}

DreamParser::CatchesContext* DreamParser::catches() {
  CatchesContext *_localctx = _tracker.createInstance<CatchesContext>(_ctx, getState());
  enterRule(_localctx, 70, DreamParser::RuleCatches);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(570);
    catchClause();
    setState(574);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DreamParser::CATCH) {
      setState(571);
      catchClause();
      setState(576);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatchClauseContext ------------------------------------------------------------------

DreamParser::CatchClauseContext::CatchClauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::CatchClauseContext::CATCH() {
  return getToken(DreamParser::CATCH, 0);
}

DreamParser::CatchFormalParameterContext* DreamParser::CatchClauseContext::catchFormalParameter() {
  return getRuleContext<DreamParser::CatchFormalParameterContext>(0);
}

DreamParser::FunCodeBlockContext* DreamParser::CatchClauseContext::funCodeBlock() {
  return getRuleContext<DreamParser::FunCodeBlockContext>(0);
}


size_t DreamParser::CatchClauseContext::getRuleIndex() const {
  return DreamParser::RuleCatchClause;
}

void DreamParser::CatchClauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCatchClause(this);
}

void DreamParser::CatchClauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCatchClause(this);
}

DreamParser::CatchClauseContext* DreamParser::catchClause() {
  CatchClauseContext *_localctx = _tracker.createInstance<CatchClauseContext>(_ctx, getState());
  enterRule(_localctx, 72, DreamParser::RuleCatchClause);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(577);
    match(DreamParser::CATCH);
    setState(578);
    catchFormalParameter();
    setState(579);
    funCodeBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatchFormalParameterContext ------------------------------------------------------------------

DreamParser::CatchFormalParameterContext::CatchFormalParameterContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::CatchTypeContext* DreamParser::CatchFormalParameterContext::catchType() {
  return getRuleContext<DreamParser::CatchTypeContext>(0);
}

tree::TerminalNode* DreamParser::CatchFormalParameterContext::IDENTIFIER() {
  return getToken(DreamParser::IDENTIFIER, 0);
}


size_t DreamParser::CatchFormalParameterContext::getRuleIndex() const {
  return DreamParser::RuleCatchFormalParameter;
}

void DreamParser::CatchFormalParameterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCatchFormalParameter(this);
}

void DreamParser::CatchFormalParameterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCatchFormalParameter(this);
}

DreamParser::CatchFormalParameterContext* DreamParser::catchFormalParameter() {
  CatchFormalParameterContext *_localctx = _tracker.createInstance<CatchFormalParameterContext>(_ctx, getState());
  enterRule(_localctx, 74, DreamParser::RuleCatchFormalParameter);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(581);
    catchType();
    setState(582);
    match(DreamParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- CatchTypeContext ------------------------------------------------------------------

DreamParser::CatchTypeContext::CatchTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> DreamParser::CatchTypeContext::IDENTIFIER() {
  return getTokens(DreamParser::IDENTIFIER);
}

tree::TerminalNode* DreamParser::CatchTypeContext::IDENTIFIER(size_t i) {
  return getToken(DreamParser::IDENTIFIER, i);
}

std::vector<tree::TerminalNode *> DreamParser::CatchTypeContext::BIT_OR() {
  return getTokens(DreamParser::BIT_OR);
}

tree::TerminalNode* DreamParser::CatchTypeContext::BIT_OR(size_t i) {
  return getToken(DreamParser::BIT_OR, i);
}


size_t DreamParser::CatchTypeContext::getRuleIndex() const {
  return DreamParser::RuleCatchType;
}

void DreamParser::CatchTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCatchType(this);
}

void DreamParser::CatchTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCatchType(this);
}

DreamParser::CatchTypeContext* DreamParser::catchType() {
  CatchTypeContext *_localctx = _tracker.createInstance<CatchTypeContext>(_ctx, getState());
  enterRule(_localctx, 76, DreamParser::RuleCatchType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(584);
    match(DreamParser::IDENTIFIER);
    setState(589);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DreamParser::BIT_OR) {
      setState(585);
      match(DreamParser::BIT_OR);
      setState(586);
      match(DreamParser::IDENTIFIER);
      setState(591);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Finally_Context ------------------------------------------------------------------

DreamParser::Finally_Context::Finally_Context(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::Finally_Context::FINALLY() {
  return getToken(DreamParser::FINALLY, 0);
}

tree::TerminalNode* DreamParser::Finally_Context::LBRACE() {
  return getToken(DreamParser::LBRACE, 0);
}

tree::TerminalNode* DreamParser::Finally_Context::RBRACE() {
  return getToken(DreamParser::RBRACE, 0);
}

std::vector<DreamParser::StmtContext *> DreamParser::Finally_Context::stmt() {
  return getRuleContexts<DreamParser::StmtContext>();
}

DreamParser::StmtContext* DreamParser::Finally_Context::stmt(size_t i) {
  return getRuleContext<DreamParser::StmtContext>(i);
}


size_t DreamParser::Finally_Context::getRuleIndex() const {
  return DreamParser::RuleFinally_;
}

void DreamParser::Finally_Context::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFinally_(this);
}

void DreamParser::Finally_Context::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFinally_(this);
}

DreamParser::Finally_Context* DreamParser::finally_() {
  Finally_Context *_localctx = _tracker.createInstance<Finally_Context>(_ctx, getState());
  enterRule(_localctx, 78, DreamParser::RuleFinally_);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(592);
    match(DreamParser::FINALLY);
    setState(593);
    match(DreamParser::LBRACE);
    setState(597);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 309596085910095914) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 62914609) != 0)) {
      setState(594);
      stmt();
      setState(599);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(600);
    match(DreamParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- MemberModifierContext ------------------------------------------------------------------

DreamParser::MemberModifierContext::MemberModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::MemberModifierContext::OVERRIDE() {
  return getToken(DreamParser::OVERRIDE, 0);
}


size_t DreamParser::MemberModifierContext::getRuleIndex() const {
  return DreamParser::RuleMemberModifier;
}

void DreamParser::MemberModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterMemberModifier(this);
}

void DreamParser::MemberModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitMemberModifier(this);
}

DreamParser::MemberModifierContext* DreamParser::memberModifier() {
  MemberModifierContext *_localctx = _tracker.createInstance<MemberModifierContext>(_ctx, getState());
  enterRule(_localctx, 80, DreamParser::RuleMemberModifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(602);
    match(DreamParser::OVERRIDE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VisibilityModifierContext ------------------------------------------------------------------

DreamParser::VisibilityModifierContext::VisibilityModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::VisibilityModifierContext::PUBLIC() {
  return getToken(DreamParser::PUBLIC, 0);
}

tree::TerminalNode* DreamParser::VisibilityModifierContext::PRIVATE() {
  return getToken(DreamParser::PRIVATE, 0);
}

tree::TerminalNode* DreamParser::VisibilityModifierContext::PROTECTED() {
  return getToken(DreamParser::PROTECTED, 0);
}


size_t DreamParser::VisibilityModifierContext::getRuleIndex() const {
  return DreamParser::RuleVisibilityModifier;
}

void DreamParser::VisibilityModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterVisibilityModifier(this);
}

void DreamParser::VisibilityModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitVisibilityModifier(this);
}

DreamParser::VisibilityModifierContext* DreamParser::visibilityModifier() {
  VisibilityModifierContext *_localctx = _tracker.createInstance<VisibilityModifierContext>(_ctx, getState());
  enterRule(_localctx, 82, DreamParser::RuleVisibilityModifier);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(604);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 3670016) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StaticModifierContext ------------------------------------------------------------------

DreamParser::StaticModifierContext::StaticModifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::StaticModifierContext::STATIC() {
  return getToken(DreamParser::STATIC, 0);
}


size_t DreamParser::StaticModifierContext::getRuleIndex() const {
  return DreamParser::RuleStaticModifier;
}

void DreamParser::StaticModifierContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterStaticModifier(this);
}

void DreamParser::StaticModifierContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitStaticModifier(this);
}

DreamParser::StaticModifierContext* DreamParser::staticModifier() {
  StaticModifierContext *_localctx = _tracker.createInstance<StaticModifierContext>(_ctx, getState());
  enterRule(_localctx, 84, DreamParser::RuleStaticModifier);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(606);
    match(DreamParser::STATIC);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamListContext ------------------------------------------------------------------

DreamParser::ParamListContext::ParamListContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DreamParser::ParamContext *> DreamParser::ParamListContext::param() {
  return getRuleContexts<DreamParser::ParamContext>();
}

DreamParser::ParamContext* DreamParser::ParamListContext::param(size_t i) {
  return getRuleContext<DreamParser::ParamContext>(i);
}

std::vector<tree::TerminalNode *> DreamParser::ParamListContext::COMMA() {
  return getTokens(DreamParser::COMMA);
}

tree::TerminalNode* DreamParser::ParamListContext::COMMA(size_t i) {
  return getToken(DreamParser::COMMA, i);
}


size_t DreamParser::ParamListContext::getRuleIndex() const {
  return DreamParser::RuleParamList;
}

void DreamParser::ParamListContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParamList(this);
}

void DreamParser::ParamListContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParamList(this);
}

DreamParser::ParamListContext* DreamParser::paramList() {
  ParamListContext *_localctx = _tracker.createInstance<ParamListContext>(_ctx, getState());
  enterRule(_localctx, 86, DreamParser::RuleParamList);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(608);
    param();
    setState(613);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == DreamParser::COMMA) {
      setState(609);
      match(DreamParser::COMMA);
      setState(610);
      param();
      setState(615);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParamContext ------------------------------------------------------------------

DreamParser::ParamContext::ParamContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::TypeContext* DreamParser::ParamContext::type() {
  return getRuleContext<DreamParser::TypeContext>(0);
}

tree::TerminalNode* DreamParser::ParamContext::IDENTIFIER() {
  return getToken(DreamParser::IDENTIFIER, 0);
}

tree::TerminalNode* DreamParser::ParamContext::IMT() {
  return getToken(DreamParser::IMT, 0);
}

tree::TerminalNode* DreamParser::ParamContext::VAR() {
  return getToken(DreamParser::VAR, 0);
}

tree::TerminalNode* DreamParser::ParamContext::BANG() {
  return getToken(DreamParser::BANG, 0);
}

tree::TerminalNode* DreamParser::ParamContext::QUESTION() {
  return getToken(DreamParser::QUESTION, 0);
}


size_t DreamParser::ParamContext::getRuleIndex() const {
  return DreamParser::RuleParam;
}

void DreamParser::ParamContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParam(this);
}

void DreamParser::ParamContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParam(this);
}

DreamParser::ParamContext* DreamParser::param() {
  ParamContext *_localctx = _tracker.createInstance<ParamContext>(_ctx, getState());
  enterRule(_localctx, 88, DreamParser::RuleParam);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(617);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DreamParser::VAR

    || _la == DreamParser::IMT) {
      setState(616);
      _la = _input->LA(1);
      if (!(_la == DreamParser::VAR

      || _la == DreamParser::IMT)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(619);
    type();
    setState(620);
    match(DreamParser::IDENTIFIER);
    setState(622);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == DreamParser::BANG

    || _la == DreamParser::QUESTION) {
      setState(621);
      _la = _input->LA(1);
      if (!(_la == DreamParser::BANG

      || _la == DreamParser::QUESTION)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypeContext ------------------------------------------------------------------

DreamParser::TypeContext::TypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::ArrayTypeContext* DreamParser::TypeContext::arrayType() {
  return getRuleContext<DreamParser::ArrayTypeContext>(0);
}

DreamParser::SingleTypeContext* DreamParser::TypeContext::singleType() {
  return getRuleContext<DreamParser::SingleTypeContext>(0);
}


size_t DreamParser::TypeContext::getRuleIndex() const {
  return DreamParser::RuleType;
}

void DreamParser::TypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterType(this);
}

void DreamParser::TypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitType(this);
}

DreamParser::TypeContext* DreamParser::type() {
  TypeContext *_localctx = _tracker.createInstance<TypeContext>(_ctx, getState());
  enterRule(_localctx, 90, DreamParser::RuleType);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(626);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 52, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(624);
      arrayType();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(625);
      singleType();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SingleTypeContext ------------------------------------------------------------------

DreamParser::SingleTypeContext::SingleTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::SingleTypeContext::BYTE() {
  return getToken(DreamParser::BYTE, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::SHORT() {
  return getToken(DreamParser::SHORT, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::INT() {
  return getToken(DreamParser::INT, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::LONG() {
  return getToken(DreamParser::LONG, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::USHORT() {
  return getToken(DreamParser::USHORT, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::UINT() {
  return getToken(DreamParser::UINT, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::ULONG() {
  return getToken(DreamParser::ULONG, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::LONGLONG() {
  return getToken(DreamParser::LONGLONG, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::ULONGLONG() {
  return getToken(DreamParser::ULONGLONG, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::FLOAT() {
  return getToken(DreamParser::FLOAT, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::DOUBLE() {
  return getToken(DreamParser::DOUBLE, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::BOOL() {
  return getToken(DreamParser::BOOL, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::CHAR() {
  return getToken(DreamParser::CHAR, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::STRING() {
  return getToken(DreamParser::STRING, 0);
}

tree::TerminalNode* DreamParser::SingleTypeContext::IDENTIFIER() {
  return getToken(DreamParser::IDENTIFIER, 0);
}


size_t DreamParser::SingleTypeContext::getRuleIndex() const {
  return DreamParser::RuleSingleType;
}

void DreamParser::SingleTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSingleType(this);
}

void DreamParser::SingleTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSingleType(this);
}

DreamParser::SingleTypeContext* DreamParser::singleType() {
  SingleTypeContext *_localctx = _tracker.createInstance<SingleTypeContext>(_ctx, getState());
  enterRule(_localctx, 92, DreamParser::RuleSingleType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(628);
    _la = _input->LA(1);
    if (!(((((_la - 29) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 29)) & 2305843009213710335) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArrayTypeContext ------------------------------------------------------------------

DreamParser::ArrayTypeContext::ArrayTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::SingleTypeContext* DreamParser::ArrayTypeContext::singleType() {
  return getRuleContext<DreamParser::SingleTypeContext>(0);
}

std::vector<tree::TerminalNode *> DreamParser::ArrayTypeContext::LBRACK() {
  return getTokens(DreamParser::LBRACK);
}

tree::TerminalNode* DreamParser::ArrayTypeContext::LBRACK(size_t i) {
  return getToken(DreamParser::LBRACK, i);
}

std::vector<tree::TerminalNode *> DreamParser::ArrayTypeContext::RBRACK() {
  return getTokens(DreamParser::RBRACK);
}

tree::TerminalNode* DreamParser::ArrayTypeContext::RBRACK(size_t i) {
  return getToken(DreamParser::RBRACK, i);
}

std::vector<tree::TerminalNode *> DreamParser::ArrayTypeContext::IDENTIFIER() {
  return getTokens(DreamParser::IDENTIFIER);
}

tree::TerminalNode* DreamParser::ArrayTypeContext::IDENTIFIER(size_t i) {
  return getToken(DreamParser::IDENTIFIER, i);
}


size_t DreamParser::ArrayTypeContext::getRuleIndex() const {
  return DreamParser::RuleArrayType;
}

void DreamParser::ArrayTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterArrayType(this);
}

void DreamParser::ArrayTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitArrayType(this);
}

DreamParser::ArrayTypeContext* DreamParser::arrayType() {
  ArrayTypeContext *_localctx = _tracker.createInstance<ArrayTypeContext>(_ctx, getState());
  enterRule(_localctx, 94, DreamParser::RuleArrayType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(630);
    singleType();
    setState(636); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(631);
      match(DreamParser::LBRACK);
      setState(633);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DreamParser::IDENTIFIER) {
        setState(632);
        match(DreamParser::IDENTIFIER);
      }
      setState(635);
      match(DreamParser::RBRACK);
      setState(638); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == DreamParser::LBRACK);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ReturnTypeContext ------------------------------------------------------------------

DreamParser::ReturnTypeContext::ReturnTypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DreamParser::TypeContext *> DreamParser::ReturnTypeContext::type() {
  return getRuleContexts<DreamParser::TypeContext>();
}

DreamParser::TypeContext* DreamParser::ReturnTypeContext::type(size_t i) {
  return getRuleContext<DreamParser::TypeContext>(i);
}

std::vector<tree::TerminalNode *> DreamParser::ReturnTypeContext::BANG() {
  return getTokens(DreamParser::BANG);
}

tree::TerminalNode* DreamParser::ReturnTypeContext::BANG(size_t i) {
  return getToken(DreamParser::BANG, i);
}

std::vector<tree::TerminalNode *> DreamParser::ReturnTypeContext::QUESTION() {
  return getTokens(DreamParser::QUESTION);
}

tree::TerminalNode* DreamParser::ReturnTypeContext::QUESTION(size_t i) {
  return getToken(DreamParser::QUESTION, i);
}

tree::TerminalNode* DreamParser::ReturnTypeContext::LPAREN() {
  return getToken(DreamParser::LPAREN, 0);
}

tree::TerminalNode* DreamParser::ReturnTypeContext::RPAREN() {
  return getToken(DreamParser::RPAREN, 0);
}

tree::TerminalNode* DreamParser::ReturnTypeContext::COMMA() {
  return getToken(DreamParser::COMMA, 0);
}

tree::TerminalNode* DreamParser::ReturnTypeContext::VOID() {
  return getToken(DreamParser::VOID, 0);
}

std::vector<tree::TerminalNode *> DreamParser::ReturnTypeContext::IDENTIFIER() {
  return getTokens(DreamParser::IDENTIFIER);
}

tree::TerminalNode* DreamParser::ReturnTypeContext::IDENTIFIER(size_t i) {
  return getToken(DreamParser::IDENTIFIER, i);
}


size_t DreamParser::ReturnTypeContext::getRuleIndex() const {
  return DreamParser::RuleReturnType;
}

void DreamParser::ReturnTypeContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterReturnType(this);
}

void DreamParser::ReturnTypeContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitReturnType(this);
}

DreamParser::ReturnTypeContext* DreamParser::returnType() {
  ReturnTypeContext *_localctx = _tracker.createInstance<ReturnTypeContext>(_ctx, getState());
  enterRule(_localctx, 96, DreamParser::RuleReturnType);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(672);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 61, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(640);
      type();
      setState(642);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DreamParser::BANG

      || _la == DreamParser::QUESTION) {
        setState(641);
        _la = _input->LA(1);
        if (!(_la == DreamParser::BANG

        || _la == DreamParser::QUESTION)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(644);
      match(DreamParser::LPAREN);
      setState(645);
      type();
      setState(647);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DreamParser::BANG

      || _la == DreamParser::QUESTION) {
        setState(646);
        _la = _input->LA(1);
        if (!(_la == DreamParser::BANG

        || _la == DreamParser::QUESTION)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }

      setState(649);
      match(DreamParser::COMMA);
      setState(650);
      type();
      setState(652);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DreamParser::BANG

      || _la == DreamParser::QUESTION) {
        setState(651);
        _la = _input->LA(1);
        if (!(_la == DreamParser::BANG

        || _la == DreamParser::QUESTION)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(654);
      match(DreamParser::RPAREN);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(656);
      match(DreamParser::VOID);
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(657);
      match(DreamParser::IDENTIFIER);
      setState(659);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DreamParser::BANG

      || _la == DreamParser::QUESTION) {
        setState(658);
        _la = _input->LA(1);
        if (!(_la == DreamParser::BANG

        || _la == DreamParser::QUESTION)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(661);
      match(DreamParser::LPAREN);
      setState(662);
      match(DreamParser::IDENTIFIER);
      setState(664);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DreamParser::BANG

      || _la == DreamParser::QUESTION) {
        setState(663);
        _la = _input->LA(1);
        if (!(_la == DreamParser::BANG

        || _la == DreamParser::QUESTION)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }

      setState(666);
      match(DreamParser::COMMA);
      setState(667);
      match(DreamParser::IDENTIFIER);
      setState(669);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == DreamParser::BANG

      || _la == DreamParser::QUESTION) {
        setState(668);
        _la = _input->LA(1);
        if (!(_la == DreamParser::BANG

        || _la == DreamParser::QUESTION)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
      }
      setState(671);
      match(DreamParser::RPAREN);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForStmtContext ------------------------------------------------------------------

DreamParser::ForStmtContext::ForStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::ForStmtContext::FOR() {
  return getToken(DreamParser::FOR, 0);
}

DreamParser::ForConditionContext* DreamParser::ForStmtContext::forCondition() {
  return getRuleContext<DreamParser::ForConditionContext>(0);
}

DreamParser::ForBlockContext* DreamParser::ForStmtContext::forBlock() {
  return getRuleContext<DreamParser::ForBlockContext>(0);
}


size_t DreamParser::ForStmtContext::getRuleIndex() const {
  return DreamParser::RuleForStmt;
}

void DreamParser::ForStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForStmt(this);
}

void DreamParser::ForStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForStmt(this);
}

DreamParser::ForStmtContext* DreamParser::forStmt() {
  ForStmtContext *_localctx = _tracker.createInstance<ForStmtContext>(_ctx, getState());
  enterRule(_localctx, 98, DreamParser::RuleForStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(674);
    match(DreamParser::FOR);
    setState(675);
    forCondition();
    setState(676);
    forBlock();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForConditionContext ------------------------------------------------------------------

DreamParser::ForConditionContext::ForConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::ForVarDeclContext* DreamParser::ForConditionContext::forVarDecl() {
  return getRuleContext<DreamParser::ForVarDeclContext>(0);
}

std::vector<tree::TerminalNode *> DreamParser::ForConditionContext::SEMICOLON() {
  return getTokens(DreamParser::SEMICOLON);
}

tree::TerminalNode* DreamParser::ForConditionContext::SEMICOLON(size_t i) {
  return getToken(DreamParser::SEMICOLON, i);
}

std::vector<DreamParser::ExprContext *> DreamParser::ForConditionContext::expr() {
  return getRuleContexts<DreamParser::ExprContext>();
}

DreamParser::ExprContext* DreamParser::ForConditionContext::expr(size_t i) {
  return getRuleContext<DreamParser::ExprContext>(i);
}


size_t DreamParser::ForConditionContext::getRuleIndex() const {
  return DreamParser::RuleForCondition;
}

void DreamParser::ForConditionContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForCondition(this);
}

void DreamParser::ForConditionContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForCondition(this);
}

DreamParser::ForConditionContext* DreamParser::forCondition() {
  ForConditionContext *_localctx = _tracker.createInstance<ForConditionContext>(_ctx, getState());
  enterRule(_localctx, 100, DreamParser::RuleForCondition);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(689);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 63, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(678);
      forVarDecl();
      setState(679);
      match(DreamParser::SEMICOLON);
      setState(680);
      expr(0);
      setState(681);
      match(DreamParser::SEMICOLON);
      setState(682);
      expr(0);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(685); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(684);
        expr(0);
        setState(687); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & 309596085574172674) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 65)) & 62914609) != 0));
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForBlockContext ------------------------------------------------------------------

DreamParser::ForBlockContext::ForBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::ForBlockContext::LBRACE() {
  return getToken(DreamParser::LBRACE, 0);
}

tree::TerminalNode* DreamParser::ForBlockContext::RBRACE() {
  return getToken(DreamParser::RBRACE, 0);
}

std::vector<DreamParser::ForBodyContext *> DreamParser::ForBlockContext::forBody() {
  return getRuleContexts<DreamParser::ForBodyContext>();
}

DreamParser::ForBodyContext* DreamParser::ForBlockContext::forBody(size_t i) {
  return getRuleContext<DreamParser::ForBodyContext>(i);
}


size_t DreamParser::ForBlockContext::getRuleIndex() const {
  return DreamParser::RuleForBlock;
}

void DreamParser::ForBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForBlock(this);
}

void DreamParser::ForBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForBlock(this);
}

DreamParser::ForBlockContext* DreamParser::forBlock() {
  ForBlockContext *_localctx = _tracker.createInstance<ForBlockContext>(_ctx, getState());
  enterRule(_localctx, 102, DreamParser::RuleForBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(691);
    match(DreamParser::LBRACE);
    setState(695);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 309596085842658862) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 62914609) != 0)) {
      setState(692);
      forBody();
      setState(697);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(698);
    match(DreamParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForBodyContext ------------------------------------------------------------------

DreamParser::ForBodyContext::ForBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::ExprContext* DreamParser::ForBodyContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

tree::TerminalNode* DreamParser::ForBodyContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}

DreamParser::FunVarDeclarationContext* DreamParser::ForBodyContext::funVarDeclaration() {
  return getRuleContext<DreamParser::FunVarDeclarationContext>(0);
}

DreamParser::IfStmtContext* DreamParser::ForBodyContext::ifStmt() {
  return getRuleContext<DreamParser::IfStmtContext>(0);
}

DreamParser::ForStmtContext* DreamParser::ForBodyContext::forStmt() {
  return getRuleContext<DreamParser::ForStmtContext>(0);
}

DreamParser::ReturnStmtContext* DreamParser::ForBodyContext::returnStmt() {
  return getRuleContext<DreamParser::ReturnStmtContext>(0);
}

tree::TerminalNode* DreamParser::ForBodyContext::BREAK() {
  return getToken(DreamParser::BREAK, 0);
}

tree::TerminalNode* DreamParser::ForBodyContext::CONTINUE() {
  return getToken(DreamParser::CONTINUE, 0);
}

DreamParser::FunCallStmtContext* DreamParser::ForBodyContext::funCallStmt() {
  return getRuleContext<DreamParser::FunCallStmtContext>(0);
}

DreamParser::DeleteStmtContext* DreamParser::ForBodyContext::deleteStmt() {
  return getRuleContext<DreamParser::DeleteStmtContext>(0);
}


size_t DreamParser::ForBodyContext::getRuleIndex() const {
  return DreamParser::RuleForBody;
}

void DreamParser::ForBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForBody(this);
}

void DreamParser::ForBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForBody(this);
}

DreamParser::ForBodyContext* DreamParser::forBody() {
  ForBodyContext *_localctx = _tracker.createInstance<ForBodyContext>(_ctx, getState());
  enterRule(_localctx, 104, DreamParser::RuleForBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(715);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 65, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(700);
      expr(0);
      setState(701);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(703);
      funVarDeclaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(704);
      ifStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(705);
      forStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(706);
      returnStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(707);
      match(DreamParser::BREAK);
      setState(708);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(709);
      match(DreamParser::CONTINUE);
      setState(710);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(711);
      funCallStmt();
      setState(712);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(714);
      deleteStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ForVarDeclContext ------------------------------------------------------------------

DreamParser::ForVarDeclContext::ForVarDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::TypeContext* DreamParser::ForVarDeclContext::type() {
  return getRuleContext<DreamParser::TypeContext>(0);
}

tree::TerminalNode* DreamParser::ForVarDeclContext::IDENTIFIER() {
  return getToken(DreamParser::IDENTIFIER, 0);
}

tree::TerminalNode* DreamParser::ForVarDeclContext::ASSIGN() {
  return getToken(DreamParser::ASSIGN, 0);
}

DreamParser::ExprContext* DreamParser::ForVarDeclContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}


size_t DreamParser::ForVarDeclContext::getRuleIndex() const {
  return DreamParser::RuleForVarDecl;
}

void DreamParser::ForVarDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForVarDecl(this);
}

void DreamParser::ForVarDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForVarDecl(this);
}

DreamParser::ForVarDeclContext* DreamParser::forVarDecl() {
  ForVarDeclContext *_localctx = _tracker.createInstance<ForVarDeclContext>(_ctx, getState());
  enterRule(_localctx, 106, DreamParser::RuleForVarDecl);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(717);
    type();
    setState(718);
    match(DreamParser::IDENTIFIER);
    setState(719);
    match(DreamParser::ASSIGN);
    setState(720);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FileCodeBlockContext ------------------------------------------------------------------

DreamParser::FileCodeBlockContext::FileCodeBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::FileCodeBlockContext::LBRACE() {
  return getToken(DreamParser::LBRACE, 0);
}

tree::TerminalNode* DreamParser::FileCodeBlockContext::RBRACE() {
  return getToken(DreamParser::RBRACE, 0);
}

std::vector<DreamParser::FileCodeBlockBodyContext *> DreamParser::FileCodeBlockContext::fileCodeBlockBody() {
  return getRuleContexts<DreamParser::FileCodeBlockBodyContext>();
}

DreamParser::FileCodeBlockBodyContext* DreamParser::FileCodeBlockContext::fileCodeBlockBody(size_t i) {
  return getRuleContext<DreamParser::FileCodeBlockBodyContext>(i);
}


size_t DreamParser::FileCodeBlockContext::getRuleIndex() const {
  return DreamParser::RuleFileCodeBlock;
}

void DreamParser::FileCodeBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFileCodeBlock(this);
}

void DreamParser::FileCodeBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFileCodeBlock(this);
}

DreamParser::FileCodeBlockContext* DreamParser::fileCodeBlock() {
  FileCodeBlockContext *_localctx = _tracker.createInstance<FileCodeBlockContext>(_ctx, getState());
  enterRule(_localctx, 108, DreamParser::RuleFileCodeBlock);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(722);
    match(DreamParser::LBRACE);
    setState(726);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 381653679746698798) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 62914609) != 0)) {
      setState(723);
      fileCodeBlockBody();
      setState(728);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
    setState(729);
    match(DreamParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FileCodeBlockBodyContext ------------------------------------------------------------------

DreamParser::FileCodeBlockBodyContext::FileCodeBlockBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::FileCodeBlockStmtContext* DreamParser::FileCodeBlockBodyContext::fileCodeBlockStmt() {
  return getRuleContext<DreamParser::FileCodeBlockStmtContext>(0);
}

DreamParser::FileCodeBlockContext* DreamParser::FileCodeBlockBodyContext::fileCodeBlock() {
  return getRuleContext<DreamParser::FileCodeBlockContext>(0);
}


size_t DreamParser::FileCodeBlockBodyContext::getRuleIndex() const {
  return DreamParser::RuleFileCodeBlockBody;
}

void DreamParser::FileCodeBlockBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFileCodeBlockBody(this);
}

void DreamParser::FileCodeBlockBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFileCodeBlockBody(this);
}

DreamParser::FileCodeBlockBodyContext* DreamParser::fileCodeBlockBody() {
  FileCodeBlockBodyContext *_localctx = _tracker.createInstance<FileCodeBlockBodyContext>(_ctx, getState());
  enterRule(_localctx, 110, DreamParser::RuleFileCodeBlockBody);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(733);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case DreamParser::STRING_LITERAL:
      case DreamParser::RETURN:
      case DreamParser::IF:
      case DreamParser::FOR:
      case DreamParser::BREAK:
      case DreamParser::CONTINUE:
      case DreamParser::TRY:
      case DreamParser::VAR:
      case DreamParser::IMT:
      case DreamParser::FUN:
      case DreamParser::STRUCT:
      case DreamParser::NEW:
      case DreamParser::THROW:
      case DreamParser::BYTE:
      case DreamParser::SHORT:
      case DreamParser::INT:
      case DreamParser::UINT:
      case DreamParser::USHORT:
      case DreamParser::LONG:
      case DreamParser::ULONG:
      case DreamParser::LONGLONG:
      case DreamParser::ULONGLONG:
      case DreamParser::FLOAT:
      case DreamParser::DOUBLE:
      case DreamParser::BOOL:
      case DreamParser::CHAR:
      case DreamParser::STRING:
      case DreamParser::CHAR_LITERAL:
      case DreamParser::INT_LITERAL:
      case DreamParser::FLOAT_LITERAL:
      case DreamParser::TRUE_LITERAL:
      case DreamParser::FALSE_LITERAL:
      case DreamParser::SLASH:
      case DreamParser::LPAREN:
      case DreamParser::LBRACK:
      case DreamParser::BANG:
      case DreamParser::PLUS:
      case DreamParser::MINUS:
      case DreamParser::TIBLE:
      case DreamParser::INC:
      case DreamParser::DEC:
      case DreamParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(731);
        fileCodeBlockStmt();
        break;
      }

      case DreamParser::LBRACE: {
        enterOuterAlt(_localctx, 2);
        setState(732);
        fileCodeBlock();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FileCodeBlockStmtContext ------------------------------------------------------------------

DreamParser::FileCodeBlockStmtContext::FileCodeBlockStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::ExprContext* DreamParser::FileCodeBlockStmtContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

tree::TerminalNode* DreamParser::FileCodeBlockStmtContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}

DreamParser::DeclarationContext* DreamParser::FileCodeBlockStmtContext::declaration() {
  return getRuleContext<DreamParser::DeclarationContext>(0);
}

DreamParser::IfStmtContext* DreamParser::FileCodeBlockStmtContext::ifStmt() {
  return getRuleContext<DreamParser::IfStmtContext>(0);
}

DreamParser::ForStmtContext* DreamParser::FileCodeBlockStmtContext::forStmt() {
  return getRuleContext<DreamParser::ForStmtContext>(0);
}

DreamParser::ReturnStmtContext* DreamParser::FileCodeBlockStmtContext::returnStmt() {
  return getRuleContext<DreamParser::ReturnStmtContext>(0);
}

tree::TerminalNode* DreamParser::FileCodeBlockStmtContext::BREAK() {
  return getToken(DreamParser::BREAK, 0);
}

tree::TerminalNode* DreamParser::FileCodeBlockStmtContext::CONTINUE() {
  return getToken(DreamParser::CONTINUE, 0);
}

DreamParser::FunCallStmtContext* DreamParser::FileCodeBlockStmtContext::funCallStmt() {
  return getRuleContext<DreamParser::FunCallStmtContext>(0);
}

DreamParser::ThrowStmtContext* DreamParser::FileCodeBlockStmtContext::throwStmt() {
  return getRuleContext<DreamParser::ThrowStmtContext>(0);
}

DreamParser::TryCatchStmtContext* DreamParser::FileCodeBlockStmtContext::tryCatchStmt() {
  return getRuleContext<DreamParser::TryCatchStmtContext>(0);
}


size_t DreamParser::FileCodeBlockStmtContext::getRuleIndex() const {
  return DreamParser::RuleFileCodeBlockStmt;
}

void DreamParser::FileCodeBlockStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFileCodeBlockStmt(this);
}

void DreamParser::FileCodeBlockStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFileCodeBlockStmt(this);
}

DreamParser::FileCodeBlockStmtContext* DreamParser::fileCodeBlockStmt() {
  FileCodeBlockStmtContext *_localctx = _tracker.createInstance<FileCodeBlockStmtContext>(_ctx, getState());
  enterRule(_localctx, 112, DreamParser::RuleFileCodeBlockStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(749);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 68, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(735);
      expr(0);
      setState(736);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(738);
      declaration();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(739);
      ifStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(740);
      forStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(741);
      returnStmt();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(742);
      match(DreamParser::BREAK);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(743);
      match(DreamParser::CONTINUE);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(744);
      funCallStmt();
      setState(745);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(747);
      throwStmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(748);
      tryCatchStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunCodeBlockContext ------------------------------------------------------------------

DreamParser::FunCodeBlockContext::FunCodeBlockContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::FunCodeBlockContext::LBRACE() {
  return getToken(DreamParser::LBRACE, 0);
}

DreamParser::FunCodeBlockBodyContext* DreamParser::FunCodeBlockContext::funCodeBlockBody() {
  return getRuleContext<DreamParser::FunCodeBlockBodyContext>(0);
}

tree::TerminalNode* DreamParser::FunCodeBlockContext::RBRACE() {
  return getToken(DreamParser::RBRACE, 0);
}


size_t DreamParser::FunCodeBlockContext::getRuleIndex() const {
  return DreamParser::RuleFunCodeBlock;
}

void DreamParser::FunCodeBlockContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunCodeBlock(this);
}

void DreamParser::FunCodeBlockContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunCodeBlock(this);
}

DreamParser::FunCodeBlockContext* DreamParser::funCodeBlock() {
  FunCodeBlockContext *_localctx = _tracker.createInstance<FunCodeBlockContext>(_ctx, getState());
  enterRule(_localctx, 114, DreamParser::RuleFunCodeBlock);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(751);
    match(DreamParser::LBRACE);
    setState(752);
    funCodeBlockBody();
    setState(753);
    match(DreamParser::RBRACE);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunCodeBlockBodyContext ------------------------------------------------------------------

DreamParser::FunCodeBlockBodyContext::FunCodeBlockBodyContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<DreamParser::FunCodeBlockStmtContext *> DreamParser::FunCodeBlockBodyContext::funCodeBlockStmt() {
  return getRuleContexts<DreamParser::FunCodeBlockStmtContext>();
}

DreamParser::FunCodeBlockStmtContext* DreamParser::FunCodeBlockBodyContext::funCodeBlockStmt(size_t i) {
  return getRuleContext<DreamParser::FunCodeBlockStmtContext>(i);
}


size_t DreamParser::FunCodeBlockBodyContext::getRuleIndex() const {
  return DreamParser::RuleFunCodeBlockBody;
}

void DreamParser::FunCodeBlockBodyContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunCodeBlockBody(this);
}

void DreamParser::FunCodeBlockBodyContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunCodeBlockBody(this);
}

DreamParser::FunCodeBlockBodyContext* DreamParser::funCodeBlockBody() {
  FunCodeBlockBodyContext *_localctx = _tracker.createInstance<FunCodeBlockBodyContext>(_ctx, getState());
  enterRule(_localctx, 116, DreamParser::RuleFunCodeBlockBody);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(758);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & 309596085976829486) != 0) || ((((_la - 65) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 65)) & 62914609) != 0)) {
      setState(755);
      funCodeBlockStmt();
      setState(760);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunCodeBlockStmtContext ------------------------------------------------------------------

DreamParser::FunCodeBlockStmtContext::FunCodeBlockStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

DreamParser::ExprContext* DreamParser::FunCodeBlockStmtContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

tree::TerminalNode* DreamParser::FunCodeBlockStmtContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}

DreamParser::IfStmtContext* DreamParser::FunCodeBlockStmtContext::ifStmt() {
  return getRuleContext<DreamParser::IfStmtContext>(0);
}

DreamParser::ForStmtContext* DreamParser::FunCodeBlockStmtContext::forStmt() {
  return getRuleContext<DreamParser::ForStmtContext>(0);
}

DreamParser::ReturnStmtContext* DreamParser::FunCodeBlockStmtContext::returnStmt() {
  return getRuleContext<DreamParser::ReturnStmtContext>(0);
}

tree::TerminalNode* DreamParser::FunCodeBlockStmtContext::BREAK() {
  return getToken(DreamParser::BREAK, 0);
}

tree::TerminalNode* DreamParser::FunCodeBlockStmtContext::CONTINUE() {
  return getToken(DreamParser::CONTINUE, 0);
}

DreamParser::FunCallStmtContext* DreamParser::FunCodeBlockStmtContext::funCallStmt() {
  return getRuleContext<DreamParser::FunCallStmtContext>(0);
}

DreamParser::ThrowStmtContext* DreamParser::FunCodeBlockStmtContext::throwStmt() {
  return getRuleContext<DreamParser::ThrowStmtContext>(0);
}

DreamParser::TryCatchStmtContext* DreamParser::FunCodeBlockStmtContext::tryCatchStmt() {
  return getRuleContext<DreamParser::TryCatchStmtContext>(0);
}

DreamParser::DeleteStmtContext* DreamParser::FunCodeBlockStmtContext::deleteStmt() {
  return getRuleContext<DreamParser::DeleteStmtContext>(0);
}


size_t DreamParser::FunCodeBlockStmtContext::getRuleIndex() const {
  return DreamParser::RuleFunCodeBlockStmt;
}

void DreamParser::FunCodeBlockStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunCodeBlockStmt(this);
}

void DreamParser::FunCodeBlockStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunCodeBlockStmt(this);
}

DreamParser::FunCodeBlockStmtContext* DreamParser::funCodeBlockStmt() {
  FunCodeBlockStmtContext *_localctx = _tracker.createInstance<FunCodeBlockStmtContext>(_ctx, getState());
  enterRule(_localctx, 118, DreamParser::RuleFunCodeBlockStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(775);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 70, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(761);
      expr(0);
      setState(762);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(764);
      ifStmt();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(765);
      forStmt();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(766);
      returnStmt();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(767);
      match(DreamParser::BREAK);
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(768);
      match(DreamParser::CONTINUE);
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(769);
      funCallStmt();
      setState(770);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(772);
      throwStmt();
      break;
    }

    case 9: {
      enterOuterAlt(_localctx, 9);
      setState(773);
      tryCatchStmt();
      break;
    }

    case 10: {
      enterOuterAlt(_localctx, 10);
      setState(774);
      deleteStmt();
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeleteStmtContext ------------------------------------------------------------------

DreamParser::DeleteStmtContext::DeleteStmtContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* DreamParser::DeleteStmtContext::DELETE() {
  return getToken(DreamParser::DELETE, 0);
}

DreamParser::ExprContext* DreamParser::DeleteStmtContext::expr() {
  return getRuleContext<DreamParser::ExprContext>(0);
}

tree::TerminalNode* DreamParser::DeleteStmtContext::SEMICOLON() {
  return getToken(DreamParser::SEMICOLON, 0);
}

std::vector<tree::TerminalNode *> DreamParser::DeleteStmtContext::RBRACK() {
  return getTokens(DreamParser::RBRACK);
}

tree::TerminalNode* DreamParser::DeleteStmtContext::RBRACK(size_t i) {
  return getToken(DreamParser::RBRACK, i);
}


size_t DreamParser::DeleteStmtContext::getRuleIndex() const {
  return DreamParser::RuleDeleteStmt;
}

void DreamParser::DeleteStmtContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDeleteStmt(this);
}

void DreamParser::DeleteStmtContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<DreamListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDeleteStmt(this);
}

DreamParser::DeleteStmtContext* DreamParser::deleteStmt() {
  DeleteStmtContext *_localctx = _tracker.createInstance<DeleteStmtContext>(_ctx, getState());
  enterRule(_localctx, 120, DreamParser::RuleDeleteStmt);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(785);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 71, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(777);
      match(DreamParser::DELETE);
      setState(778);
      expr(0);
      setState(779);
      match(DreamParser::SEMICOLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(781);
      match(DreamParser::DELETE);
      setState(782);
      match(DreamParser::RBRACK);
      setState(783);
      match(DreamParser::RBRACK);
      setState(784);
      match(DreamParser::SEMICOLON);
      break;
    }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool DreamParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 23: return exprSempred(antlrcpp::downCast<ExprContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool DreamParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 13);
    case 1: return precpred(_ctx, 12);
    case 2: return precpred(_ctx, 11);
    case 3: return precpred(_ctx, 10);
    case 4: return precpred(_ctx, 9);
    case 5: return precpred(_ctx, 8);
    case 6: return precpred(_ctx, 7);
    case 7: return precpred(_ctx, 6);
    case 8: return precpred(_ctx, 5);
    case 9: return precpred(_ctx, 4);

  default:
    break;
  }
  return true;
}

void DreamParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  dreamParserInitialize();
#else
  ::antlr4::internal::call_once(dreamParserOnceFlag, dreamParserInitialize);
#endif
}
