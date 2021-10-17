#include "PathToken.h"

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