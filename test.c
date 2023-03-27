#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "monopoly.h"

int main() {
    /* Build the placelist */

    readboardfile(boardfilepath);

    printboardlist(boardlist);

    /* Exit blissfully */

    return EXIT_SUCCESS;
}