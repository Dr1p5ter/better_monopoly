#include <stdio.h>
#include "board.h"

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
        for (int i = 0; i < 5; i++) {
            printf("\tHouse count [%d] = %d\n", i, place->rent_list[i]);
        }
    } else {
        printf("* Rent list unavailable *\n");
    }
    return;
} /* printplace() */

unsigned short unmorgage_price(place_t * place) {
    return place->m_price * 1.10;
} /* unmorgage_price() */
