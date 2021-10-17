#include "PathToken.h"

void initEmptyListOfPathTokens(
    struct ListOfPathTokens * tokenList) {

    const struct PathToken tokens[0];

    tokenList->tokens = tokens;

    ///

    * (int *) &tokenList->length = 0;
}

// void initEmptyListOfPathTokens(
//     struct ListOfPathTokens * tokenList,
//     const struct PathToken * tokens,
//     const int length) {

//     tokenList->tokens = tokens;

//     * (int *) &tokenList->length = length;
// }