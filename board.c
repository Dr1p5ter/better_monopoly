#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "board.h"

/* Globals */

place_list * boardlist = NULL;
char * boardfilepath = "boardlist.csv";
short freeparktotal = 0;
short boardlistlen = 0;

/* Functions */

/**
 * This function will print the information stored in a place_t structure. If the place is null,
 * then the function will simply return and not print anything.
*/

void printplace(place_t * place) {
    /* Check if the place is null */

    if (!place) {
        return;
    }

    /* Print the name of the place */

    printf(" __________________________________________________\n");
    printf("|Name = %s\n", place->name);

    /* Print the type of the place */

    printf("|Type = ");
    switch(place->type) {
        case GO : printf("GO\n"); break;
        case JAIL : printf("Jail\n"); break;
        case GO_TO_JAIL : printf("Go to jail\n"); break;
        case CHEST : printf("Chest\n"); break;
        case TAX : printf("Tax\n"); break;
        case UTIL : printf("Util\n"); break;
        case RAILROAD : printf("Railroad\n"); break;
        case PROPERTY : printf("Property\n"); break;
        default : printf("Not specified\n"); break;
    }

    /* Print the color of the place */

    printf("|Color = ");
    switch(place->color) {
        case BLANK : printf("No affiliated color\n"); break;
        case BROWN : printf("Brown\n"); break;
        case LIGHT_BLUE : printf("Light blue\n"); break;
        case PURPLE : printf("Purple\n"); break;
        case ORANGE : printf("Orange\n"); break;
        case RED : printf("Red\n"); break;
        case YELLOW : printf("Yellow\n"); break;
        case GREEN : printf("Green\n"); break;
        case BLUE : printf("Blue\n"); break;
        default : printf("Not specified\n"); break;
    }

    /* Print the price holdings */

    if ((place->type == PROPERTY) || (place->type == RAILROAD) || (place->type == UTIL)) {
        printf("|Price = %d\n", place->price);
        printf("|Morgage value = %d\n", morgprice(place));
        printf("|Morgage price = %d\n", unmorgprice(place));
        printf("|Is it morgaged = %s\n", ((place->ismorg) ? "Yes" : "No"));
        printf("|Price for house = %d\n", place->h_price);

        /* Print rent costs */

        if (place->rent_list) {
            printf("|Rent = \n");
            for (int i = 0; i < RENT_LIST_LEN - 1; i++) {
                printf("|\tRent given %d houses = %d\n", i, place->rent_list[i]);
            }
            printf("|\tRent w/ hotel = %d\n", place->rent_list[RENT_LIST_LEN - 1]);
        }
    }

    if (place->type == TAX)
        printf("|Tax = %d\n", place->price);

    /* Tape off the end to make it look alone */

    printf("|__________________________________________________\n");
} /* printplace() */

/**
 * This function will print the place_list data structure. If the list is null, then it doesn't
 * print anything. Used for debugging purposes.
*/

void printboardlist(place_list * list) {
    /* Check if the list pointer is null */

    if (!list) {
        return;
    }

    /* Move down the list printing the places */

    place_list * curr = list;
    while (curr) {
        printplace(curr->place);
        curr = curr->next_place;
    }
} /* printboardlist() */

/**
 * This function will read the csv containing all the board pieces and will then store them in a
 * global variable boardlist. If the boardlist is not null, this will stop the application since
 * this should be read only once. Additionally if the filename is not able to be read, it will stop
 * the program from running.
*/

void readboardfile(char * filename) {
    /* check that the board list is not null */

    if (boardlist != NULL) {
        fprintf(stderr, "boardlist already defined! Exiting now...\n");
        exit(EXIT_FAILURE);
    }

    /* Open the file */

    FILE * board_file = NULL;
    if ((board_file = fopen(boardfilepath, "r")) == NULL) {
        fprintf(stderr, "File can't be opened! Exiting now...\n");
        exit(EXIT_FAILURE);
    }

    /* Set up board for new reads */

    boardlist = (place_list *) malloc(sizeof(place_list));
    boardlist->next_place = NULL;
    boardlist->place = NULL;
    place_list * currPlace = boardlist;

    /* Begin reading the file */

    char buffer[1024] = {'\0'};
    int checkEOF = 0;
    fscanf(board_file, "%[^\n]\n", buffer); // Get rid of the csv header
    while ((checkEOF = fscanf(board_file, "%[^\n]\n", buffer) != EOF)) {
        /* Allocate memory for place_t */

        currPlace->place = (place_t *) malloc(sizeof(place_t));

        /* Grab the values in the string and store them in place_t */

        currPlace->place->name = (char *) strdup(strtok(buffer, ","));
        currPlace->place->type = (short) atoi(strtok(NULL, ","));
        currPlace->place->color = (short) atoi(strtok(NULL, ","));
        currPlace->place->price = (short) atoi(strtok(NULL, ","));
        currPlace->place->h_price = (short) atoi(strtok(NULL, ","));
        currPlace->place->rent_list = (short *) malloc(sizeof(short) * RENT_LIST_LEN);
        for (int i = 0; i < RENT_LIST_LEN; i++)
            currPlace->place->rent_list[i] = atoi(strtok(NULL, ","));
        currPlace->place->ismorg = 0;

        /* Clear junk from strtok */

        while (strtok(NULL, ","));

        /* Update the board list */

        currPlace->next_place = (place_list *) malloc(sizeof(place_list));
        currPlace->next_place->next_place = NULL;
        currPlace->next_place->place = NULL;
        currPlace = currPlace->next_place;
        boardlistlen++;
    }
} /* readBoardFile*/

/**
 * This function will return the morgage price used to sell the property. This is settled by the
 * formula price / 2.
*/

short morgprice(place_t * place) {
    return (short) place->price / 2;
}

/**
 * This function will return the unmorgage price used to buy back properties that have been
 * morgaged. Unmorgage price is 110% what the original morgage price was.
*/

short unmorgprice(place_t * place) {
    return (short) morgprice(place) * 1.10;
} /* unmorgprice() */
