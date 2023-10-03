#include <stdio.h>
#include "history.h" // project-related declarations

/* Initialize the linked list to keep the history. */
List* init_history() {
  List list;
  List* ptr = &list;

  return ptr;
}
  

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str) {
  if (*list.root == 0) { // Append on an empty list
    *list.*root.id = 1;
    *list.*root.str = str;
    return;
  }

  Item *temp = *list.root;
  while (temp.next != 0) {
    temp = *temp.next;
  }

  *temp.*next.id = *temp.id + 1;
  *temp.*next.str = str;
}

  

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id) {
  Item *temp = *list.root;

  while (*temp.id != id) {
    temp = *temp.next;
  }

  return *temp.str;
}

/*Print the entire contents of the list. */
void print_history(List *list) {
  Item *temp = *list.root;

  while (temp != 0) {
    printf("%d : %s", *temp.id, *temp.str);
    temp = *temp.next;
  }
}

/*Free the history list and the strings it references. */
void free_history(List *list) {
  Item *temp = *list.root;

  while (temp != 0) {
    free(*temp.str);
    temp = *temp.next;
  }

  free(list);
}
    
