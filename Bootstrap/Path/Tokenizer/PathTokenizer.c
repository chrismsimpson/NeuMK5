#include "PathTokenizer.h"

void deinitTokenizer(
    struct PathTokenizer * tokenizer) {

    deinitScanner((struct Scanner *) &tokenizer->scanner);
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