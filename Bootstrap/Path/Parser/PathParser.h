#ifndef PATH_PARSER_H
#define PATH_PARSER_H

#include "../Tokenizer/PathTokenizer.h"
#include "../Tokens/PathToken.h"

#include "../Path.h"

struct PathParser {

    const struct PathTokenizer tokenizer;
};

///

extern void initPathParser(
    struct PathParser * parser,
    const struct PathTokenizer * tokenizer);

extern void initPathParserFromSource(
    struct PathParser * parser,
    const char * source);

///

extern void parsePath(
    struct PathParser * parser,
    struct Path * path);

extern void parsePathTokens(
    struct PathParser * parser,
    struct ListOfPathTokens * tokenList);

#endif