// ======================================================================

#define ERROR   (-1)

// ======================================================================

#define MAX_LIST_SIZE   5

// ======================================================================
// Only natural numbers for items.

typedef struct {
	int items[MAX_LIST_SIZE];
	int length;
} LIST;

// ======================================================================

LIST *create_list(void);
void print_list(LIST * list);
int length_list(LIST * list);
int add_list(LIST * list, int position, int item);
int delete_list(LIST * list, int position);

// ======================================================================