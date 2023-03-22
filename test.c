#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "monopoly.h"

int main() {

    place_t * test_place = (place_t *) malloc(sizeof(place_t));
    test_place->name = strdup("Test Property\0");
    test_place->rent_list = (unsigned short *) malloc(sizeof(unsigned short) * 5);
    test_place->rent_list[0] = 0;
    test_place->rent_list[1] = 1;
    test_place->rent_list[2] = 2;
    test_place->rent_list[3] = 3;
    test_place->rent_list[4] = 4;
    test_place->color = BLUE;
    test_place->type = PROPERTY;
    test_place->price = 500;
    test_place->m_price = 300;
    test_place->h_price = 50;

    printplace(test_place);

    return 0;
}