#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "monopoly.h"

int main() {

    /* Open the file */

    FILE * board_file = NULL;
    if ((board_file = fopen(boardfilepath, "r")) == NULL) {
        perror("File can't be read\n");
        return EXIT_FAILURE;
    }
    fscanf(board_file, "%s\n", NULL); // Get rid of the csv header

    /* Begin reading the file */

    // char rname[MAX_NAME_LEN] = {'\0'};
    // int num_record[MAX_NUM_REC_LEN];
    char buffer[1024] = {'\0'};
    int checkEOF = 0;
    while ((checkEOF = fscanf(board_file, "%s\n", buffer) != EOF)) {
        // TODO : Translate new values into new board places

        // printf("%s, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n",
        //        rname, num_record[0], num_record[1], num_record[2],
        //        num_record[3], num_record[4], num_record[5], num_record[6],
        //        num_record[7], num_record[8], num_record[9], num_record[10]);

    }

    /* Close file */

    fclose(board_file);

    printf("Exited with %d\n", idk());

    return EXIT_SUCCESS;
}