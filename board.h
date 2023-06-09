/* -- INCLUDES -- */

/* -- DEFINES -- */

#define RENT_LIST_LEN      (6)  // Size to hold rent per property status
#define LEN_P_COLOR        (9)  // Count of amount of colors represented in p_color
#define LEN_P_TYPE         (9)  // Count of amount of types represented in p_tyoe
#define MAX_PROP_NAME_LEN  (32) // Max size possible for a property name

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
    char * name;       /* Name of the property  */
    short * rent_list; /* Rent for each stage */
    p_type type;       /* Type of property      */
    p_color color;     /* Color of property     */
    short price;       /* Price of the property */
    short h_price;     /* House price of property */
    short ismorg;      /* If the place is morgaged */
} place_t;

/* -- GLOBALS -- */

extern place_t ** boardlist;           // Points to the beginning of the list
extern char * boardfilepath;           // Points to the name of the file stroring the board
extern short boardblocklen;            // The given amount of pointers in the block list (for realloc only)
extern short freeparktotal;            // The total amount of money in the free parking
extern short boardlistlen;             // Keeps track of the amount of items in the boardlist

/* -- PROTOTYPES -- */

void printplace(place_t *);
void printboardlist(place_t **);
void _init_board_list(char *);
short morgprice(place_t *);
short unmorgprice(place_t *);
