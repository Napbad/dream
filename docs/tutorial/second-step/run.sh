bison ./parser.y -d -o ./parser.cpp
flex -o ./lex.cpp ./lex.l

#gcc ./lex.cpp ./ast.hpp ./ast.cpp ./parser.hpp ./parser.cpp -o parser -lstdc++ -std=c++14