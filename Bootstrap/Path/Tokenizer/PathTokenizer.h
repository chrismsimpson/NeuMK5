#ifndef PATH_TOKENIZER_H
#define PATH_TOKENIZER_H

#include <stdbool.h>

#include "../../Scanner.h"

#include "../Tokens/PathToken.h"

struct PathTokenizer {

    const struct Scanner scanner;

    const struct ListOfPathTokens tokenList;

    int rawPosition;
};

///

extern void deinitTokenizer(
    struct PathTokenizer * tokenizer);

///

extern void getNextPathToken(
    struct PathTokenizer * tokenizer,
    struct OptionalPathToken * token);

///

extern void getPathTokenizerPosition(
    const struct PathTokenizer * tokenizer,
    struct SourceLocation * sourceLocation);

///

extern void initPathTokenizer(
    struct PathTokenizer * tokenizer,
    const struct Scanner * scanner);

extern void initPathTokenizerFromSource(
    struct PathTokenizer * tokenizer,
    const char * source);

///

extern bool isPathTokenizerAtEof(
    const struct PathTokenizer * tokenizer);

#endif