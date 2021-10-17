#include "Scanner.h"

void deinitScanner(
    struct Scanner * scanner) {

    // TODO
}

///

void getScannerPosition(
    const struct Scanner * scanner,
    struct SourceLocation * sourceLocation) {

    
}

///

void initScanner(
    struct Scanner * scanner,
    const enum ScannerType scannerType,
    const union ScannerValue * value,
    const int length) {

    * (enum ScannerType *) &scanner->scannerType = scannerType;

    * (union ScannerValue *) &scanner->value = * (union ScannerValue *) value;
    
    * (int *) &scanner->length = length;

    ///

    scanner->rawPosition = 0;

    scanner->lineNumber = 1;

    scanner->column = 1;
}

void initScannerFromFilename(
    struct Scanner * scanner,
    const char * filename) {

    struct stat s;

    if (stat(filename, &s) == -1) {

        // FIXME: throw an error
    }

    int length = s.st_size;

    ///

    union ScannerValue value = { .file = fopen(filename, "r") };

    ///

    initScanner(scanner, scannerTypeFile, &value, length);
}

void initScannerFromSource(
    struct Scanner * scanner,
    const char * source) {

    int length = strlen(source);

    ///

    union ScannerValue value = { .source = source };

    ///

    return initScanner(scanner, scannerTypeSource, &value, length);
}

///

const bool isScannerAtEof(
    const struct Scanner * scanner) {

    return scanner->rawPosition >= scanner->length;
}

///

void rawNextLength(
    struct Scanner * scanner,
    int length,
    char * buffer) {

    switch (scanner->scannerType) {

    case scannerTypeFile:

        if (fseek((FILE *) scanner->value.file, scanner->rawPosition, SEEK_SET) != 0) {

            // FIXME: throw error
        }

        ///

        if (fread(buffer, sizeof(char), length, (FILE *) scanner->value.file) != length) {

            // FIXME: throw error
        }

        return;

    ///

    case scannerTypeSource:

        strncpy(buffer, &scanner->value.source[scanner->rawPosition], length);

        return;

    ///

    default:

        break; // FIXME: throw error
    }
}