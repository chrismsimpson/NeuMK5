#ifndef PATH_TOKENIZER_H
#define PATH_TOKENIZER_H

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

extern void initPathTokenizer(
    struct PathTokenizer * tokenizer,
    const struct Scanner * scanner);

#endif