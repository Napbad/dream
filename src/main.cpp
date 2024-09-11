#include <iostream>

#ifdef _WIN32

static char buffer[2048];

char *readline(char *prompt)
{
    fputs(prompt, stdout);
    fgets(buffer, 2048, stdin);
    char *cpy = malloc(strlen(buffer) + 1);
    strcpy(cpy, buffer);
    cpy[strlen(cpy) - 1] = '\0';
    return cpy;
}

void add_history(char *unused) {}

#else
#include <editline/readline.h>
#endif

#include "model/val.h"
#include "parse/DreamBaseListener.h"
#include "parse/DreamParser.h"
#include "parse/DreamLexer.h"
#include "model/Global.h"
#include "parse/DreamCommonParserListener.h"

using namespace std;
using namespace antlr4;


int main(int argc, const char *argv[]) {
    std::ifstream stream;
    stream.open("../test.drm", ios::in);

    if (!stream.is_open()) {
        cout << "Could not open file" << endl;
        return 1;
    }

    Global * global = init();

    ANTLRInputStream inputStream(stream);
    DreamLexer lexer(&inputStream);
    CommonTokenStream tokens(&lexer);
    DreamParser parser(&tokens);

    tree::ParseTree *tree = parser.program();
    DreamCommonParserListener listener(global);
    tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

    std::ifstream stream2;
    stream2.open("../test2.drm", ios::in);

    if (!stream2.is_open()) {
        cout << "Could not open file" << endl;
        return 1;
    }

    ANTLRInputStream inputStream2(stream2);
    DreamLexer lexer2(&inputStream2);
    CommonTokenStream tokens2(&lexer2);
    DreamParser parser2(&tokens2);

    tree::ParseTree *tree2 = parser2.program();
    DreamCommonParserListener listener2(global);
    tree::ParseTreeWalker::DEFAULT.walk(&listener2, tree2);

    return 0;
}
