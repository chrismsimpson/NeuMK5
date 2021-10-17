#include <stdio.h>

#include "Path/Path.h"

#include "Scanner.h"

int main() {

    const struct Path path;

    getCurrentDirectoryPath((struct Path *) &path);

    ///

    printf("hello foo!\n");

    ///

    return 0;
}