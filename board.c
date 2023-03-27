#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include "board.h"

/* Globals */

place_list * boardlist = NULL;
char * boardfilepath = "property.csv";
unsigned short freeparktotal = 0;
unsigned short boardlistlen = 0;

/* Functions */

void printplace(place_t * place) {
    printf("-- %s --\n", place->name);

    /* print the type of the place */

    printf("type = ");
    switch(place->type) {
        case GO :
            printf("GO\n");
            break;
        case JAIL :
            printf("Jail\n");
            break;
        case GO_TO_JAIL :
            printf("Go to jail\n");
            break;
        case CHEST :
            printf("Chest\n");
            break;
        case TAX :
            printf("Tax\n");
            break;
        case UTIL :
            printf("Util\n");
            break;
        case RAILROAD :
            printf("Railroad\n");
            break;
        case PROPERTY :
            printf("Property\n");
            break;
        default :
            printf("Not specified\n");
            break;
    }

    /* print the color of the place */

    printf("color = ");
    switch(place->color) {
        case BLANK :
            printf("Non-colored\n");
            break;
        case BROWN :
            printf("Brown\n");
            break;
        case LIGHT_BLUE :
            printf("Light blue\n");
            break;
        case PURPLE :
            printf("Purple\n");
            break;
        case ORANGE :
            printf("Orange\n");
            break;
        case RED :
            printf("Red\n");
            break;
        case YELLOW :
            printf("Yellow\n");
            break;
        case GREEN :
            printf("Green\n");
            break;
        case BLUE :
            printf("Blue\n");
            break;
        default :
            printf("Not specified\n");
            break;
    }

    /* print the price holdings */

    printf("Price = %d\n", place->price);
    printf("Return for Morgage = %d\n", place->m_price);
    printf("Price per house = %d\n", place->h_price);

    /* print rent costs */

    if (place->rent_list) {
        printf("Rent list = \n");
        for (int i = 0; i < RENT_LIST_LEN - 2; i++) {
            printf("\tHouse Cost given house count %d = %d\n", i, place->rent_list[i]);
        }
        printf("\tHotel Cost = %d\n", place->rent_list[RENT_LIST_LEN - 1]);
    } else {
        printf("* Rent list unavailable *\n");
    }
    return;
} /* printplace() */

void readBoardFile(char * filename) {
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
        /* grab the values in the string and store them in place_t */
        char * token = strtok(buffer, ",");
        int type = atoi(strtok(NULL, ","));
        printf("type = %d\n", type);
    }
}

unsigned short unmorgage_price(place_t * place) {
    return (unsigned short) place->m_price * 1.10;
} /* unmorgage_price() */
