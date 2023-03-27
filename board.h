/* -- DEFINES -- */

#define RENT_LIST_LEN   (6)  // Size to hold rent per property status
#define MAX_NAME_LEN    (32) // Max size possible for a name

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

typedef struct node { /* Singly linked list for handling board position */
    place_t * place;            /* place information at position */
    struct node * next_place;   /* next place in the board */
} place_list;

/* -- GLOBALS -- */

extern place_list * boardlist;        // Points to the beginning of the list
extern char * boardfilepath;          // Points to the name of the file stroring the board
extern unsigned short freeparktotal;  // The total amount of money in the free parking
extern unsigned short boardlistlen;   // Keeps track of the amount of items in the boardlist

/* -- PROTOTYPES -- */

void printplace(place_t *);
void printboardlist(place_list *);
void readboardfile(char *);
unsigned short unmorgprice(place_t * );
