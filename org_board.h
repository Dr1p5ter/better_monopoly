/* -- DEFINES -- */

/* -- ENUMS -- */

typedef enum {  /* type of board place */
    GO,         /* Go space             */
    JAIL,       /* Visit or in jail     */
    GO_TO_JAIL, /* Spot to go to jail   */
    CHEST,      /* Community chest card */
    CHANCE,     /* Chance card          */
    TAX,        /* Tax spaces           */
    UTIL,       /* Custom utils         */
    RAILROAD,   /* Quadrant properties  */
    PROPERTY    /* Generic properties   */
} p_type;

typedef enum {   /* type of color a the property */
    BLANK,       /* Value for non-properties */
    BROWN,
    LIGHT_BLUE,
    PURPLE,
    ORANGE,
    RED,
    YELLOW,
    GREEN,
    BLUE
} p_color;

/* -- STRUCTS -- */

typedef struct board_place { /* entry for the board place */
    char * name;                /* Name of the property  */
    unsigned short * rent_list; /* Rent for each stage */
    p_type type;                /* Type of property      */
    p_color color;              /* Color of property     */
    unsigned short price;       /* Price of the property */
    unsigned short m_price;     /* Morgage Value of the property */
    unsigned short h_price;     /* House price of property */
} place_t;

/* -- PROTOTYPES -- */

void printplace(place_t *);
unsigned short unmorgage_price(place_t * );
