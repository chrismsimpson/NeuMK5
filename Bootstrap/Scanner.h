#ifndef SCANNER_H
#define SCANNER_H

#include <stdbool.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

#include "SourceLocation.h"

enum ScannerType {

    scannerTypeFile,
    scannerTypeSource
};


union ScannerValue {

    const FILE * file;

    const char * source;
};

struct Scanner {

    const enum ScannerType scannerType;

    const union ScannerValue value;

    const int length;

    ///

    int rawPosition;
    
    int lineNumber;

    int column;
};

///

extern void deinitScanner(
    struct Scanner * scanner);

///

extern void initScanner(
    struct Scanner * scanner,
    const enum ScannerType scannerType,
    const union ScannerValue * value,
    const int length);

extern void initScannerFromFilename(
    struct Scanner * scanner,
    const char * filename);

extern void initScannerFromSource(
    struct Scanner * scanner,
    const char * source);

const bool isScannerAtEof(
    const struct Scanner * scanner);

#endif