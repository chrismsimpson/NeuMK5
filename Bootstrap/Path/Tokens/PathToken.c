#include "PathToken.h"

void copyAndAppendPathToken(
    struct ListOfPathTokens * tokenList,
    const struct PathToken * token) {

    int newLength = tokenList->length + 1;

    ///

    struct PathToken newTokenList[newLength];

    ///

    for (int i = 1; i <= tokenList->length; i++) {

        struct PathToken existing = tokenList->tokens[i - 1];

        ///

        struct PathToken * new = &newTokenList[i];

        ///

        new = &existing;
    }

    ///

    struct PathToken * last = &newTokenList[newLength - 1];

    last = (struct PathToken *) token;
}

///

void getPathTokenStart(
    const struct PathToken * token,
    struct SourceLocation * sourceLocation) {

    switch (token->tokenType) {

    case pathTokenTypeComponent:

        break;

    ///

    case pathTokenTypePunc:

        break;

    ///
    
    default:

        break; // FIXME: throw an error
    }
}

///

void initEmptyListOfPathTokens(
    struct ListOfPathTokens * tokenList) {

    const struct PathToken tokens[0];

    tokenList->tokens = tokens;

    ///

    * (int *) &tokenList->length = 0;
}