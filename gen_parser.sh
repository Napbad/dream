bison ./src/core/parser/parser.y -d -o ./src/core/parser/parser.cpp

flex -o ./src/core/parser/tokens.cpp ./src/core/parser/tokens.l

