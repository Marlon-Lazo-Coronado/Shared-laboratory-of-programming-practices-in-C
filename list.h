// Header file for Lista enlazada

typedef struct node {
  int data;          // data
  struct node *next; // pointer to next element
} node_t;

// caso 1
node_t *createList(int first_value);

// caso 2
//void printList(node_t* head);

// caso 3
//int pushBack(node_t* head, int value);

// caso 4
//int pushFront(node_t** head, int value);

// caso 5
//int popBack(node_t* head);

// caso 6
//int popFront(node_t** head);

//caso 7
//int insertNode(node_t** head, int pos, int value);

//caso 8
//int removeNode(node_t** head, int pos);

//caso 9
//int freelist(node_t** head);

//caso 10
//int getElement(node_t* head, int pos, int* valid);

//caso 11
//void printElement(node_t* head, int pos);

//caso 12
//void sortList(node_t* head);