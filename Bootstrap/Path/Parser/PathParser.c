#include "PathParser.h"

void initPathParser(
    struct PathParser * parser,
    const struct PathTokenizer * tokenizer) {
    
    struct PathTokenizer * t = (struct PathTokenizer *) &parser->tokenizer;

    t = (struct PathTokenizer *) &tokenizer;
}

void initPathParserFromSource(
    struct PathParser * parser,
    const char * source) {

    const struct PathTokenizer tokenizer;

    initPathTokenizerFromSource((struct PathTokenizer *) &tokenizer, source);

    ///

    initPathParser(parser, (struct PathTokenizer *) &tokenizer);
}

///

void parsePath(
    struct PathParser * parser,
    struct Path * path) {

    struct ListOfPathTokens tokenList;

    parsePathTokens(parser, &tokenList);

    ///

    initPath(path, (struct ListOfPathTokens *) &tokenList);
}

void parsePathTokens(
    struct PathParser * parser,
    struct ListOfPathTokens * tokenList) {

    
}


