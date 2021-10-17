#ifndef PATH_H
#define PATH_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Tokens/PathToken.h"

struct Path {

    const struct ListOfPathTokens tokens;
};

///

extern void initPath(
    struct Path * path,
    const struct ListOfPathTokens * tokens);

///

extern void getCurrentDirectoryPath(
    struct Path * path);

#endif