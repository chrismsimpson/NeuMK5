#ifndef PATH_TOKEN_H
#define PATH_TOKEN_H

#include "PathComponent.h"
#include "PathPunc.h"

struct ListOfPathTokens {

    const struct PathToken * tokens;

    const int length;
};

enum PathTokenType {

    pathTokenTypeComponent,
    pathTokenTypePunc
};

union PathTokenValue {

    const struct PathComponent component;

    const struct PathPunc punc;
};

struct PathToken {

    const enum PathTokenType tokenType;

    const union PathTokenValue value;
};

///

extern void initEmptyListOfPathTokens(
    struct ListOfPathTokens * tokenList);

// extern void initEmptyListOfPathTokens(
//     struct ListOfPathTokens * tokenList,
//     const struct PathToken * tokens,
//     const int length);

#endif