#include "Path.h"

#include "Parser/PathParser.h"

extern void initPath(
    struct Path * path,
    const struct ListOfPathTokens * tokens) {

    struct ListOfPathTokens * l = (struct ListOfPathTokens *) &path->tokens;

    l = (struct ListOfPathTokens *) &tokens;    
}

///

void getCurrentDirectoryPath(
    struct Path * path) {

    char currentDirectory[PATH_MAX];

    getcwd(currentDirectory, sizeof(currentDirectory));

    ///

    struct PathParser parser;

    initPathParserFromSource(&parser, currentDirectory);

    ///

    parsePath(&parser, path);    
}