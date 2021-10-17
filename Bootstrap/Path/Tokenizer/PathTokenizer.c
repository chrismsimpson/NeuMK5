#include "PathTokenizer.h"

void rawGetNextPathToken(
    struct PathTokenizer * tokenizer,
    struct PathToken * token);

///

void deinitTokenizer(
    struct PathTokenizer * tokenizer) {

    deinitScanner((struct Scanner *) &tokenizer->scanner);
}

///

void getNextPathToken(
    struct PathTokenizer * tokenizer,
    struct OptionalPathToken * token) {

    const struct PathToken * v = &token->value;

    ///

    if (tokenizer->rawPosition + 1 <= tokenizer->tokenList.length) {

        const struct PathToken * t = &tokenizer->tokenList.tokens[tokenizer->rawPosition];

        ///

        tokenizer->rawPosition += 1;

        ///

        v = t;

        * (bool *) token->hasValue = true;

        return;
    }

    ///

    if (isScannerAtEof(&tokenizer->scanner)) {

        v = NULL;

        * (bool *) token->hasValue = false;
    }

    ///

    const struct PathToken next;

    rawGetNextPathToken(tokenizer, (struct PathToken *) &next);

    ///

    copyAndAppendPathToken((struct ListOfPathTokens *) &tokenizer->tokenList, &next);

    ///

    tokenizer->rawPosition += 1;

    ///

    v = &next;

    * (bool *) token->hasValue = true;
}

void rawGetNextPathToken(
    struct PathTokenizer * tokenizer,
    struct PathToken * token) {

    const char nextChar;

    rawNextLength((struct Scanner *) &tokenizer->scanner, 1, (char *) &nextChar);

    ///

    switch (nextChar) {

    case '/':

        break;

    ///

    case '\\':
        
        break;

    ///

    default:

        break;
    }
}

///

void getPathTokenizerPosition(
    const struct PathTokenizer * tokenizer,
    struct SourceLocation * sourceLocation) {

    if (tokenizer->rawPosition + 1 <= tokenizer->tokenList.length) {

        getPathTokenStart(&tokenizer->tokenList.tokens[tokenizer->rawPosition], (struct SourceLocation *) &sourceLocation);

        return;   
    }

    ///

    getScannerPosition(&tokenizer->scanner, sourceLocation);
}

///

void initPathTokenizer(
    struct PathTokenizer * tokenizer,
    const struct Scanner * scanner) {

    struct Scanner * s = (struct Scanner *) &tokenizer->scanner;

    s = (struct Scanner *) scanner;

    ///

    const struct ListOfPathTokens tokenList;

    initEmptyListOfPathTokens((struct ListOfPathTokens *) &tokenList);

    ///

    struct ListOfPathTokens * l = (struct ListOfPathTokens *) &tokenizer->tokenList;

    l = (struct ListOfPathTokens *) &tokenList;

    ///

    tokenizer->rawPosition = 0;
}

void initPathTokenizerFromSource(
    struct PathTokenizer * tokenizer,
    const char * source) {

    const struct Scanner scanner;

    initScannerFromSource((struct Scanner *) &scanner, source);

    ///

    initPathTokenizer(tokenizer, (const struct Scanner *) &scanner);
}

///

extern bool isPathTokenizerAtEof(
    const struct PathTokenizer * tokenizer) {

    

    return false;
}