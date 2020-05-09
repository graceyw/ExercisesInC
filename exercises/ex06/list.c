/* Example code for Exercises in C.

Based on an example from http://www.learn-c.org/en/Linked_lists

Copyright 2016 Allen Downey
License: Creative Commons Attribution-ShareAlike 3.0

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} Node;


/* Makes a new node structure.
*
* val: value to store in the node.
* next: pointer to the next node
*
* returns: pointer to a new node
*/
Node *make_node(int val, Node *next) {
    Node *node = malloc(sizeof(Node));
    node->val = val;
    node->next = next;
    return node;
}


/* Prints the values in a list.
*
* list: pointer to pointer to Node
*/
void print_list(Node **list) {
    Node *curr = *list;

    printf("[ ");
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("]\n");
}


/* Removes and returns the first element of a list.
*
* list: pointer to pointer to Node
*
* returns: int or -1 if the list is empty
*/
int pop(Node **list) {
    Node *head = *list;
    if (head != NULL) {   // as long as list isn't empty
      int h = head->val;
      *list = head->next;  //set the 2nd element as the new head
      free(head);
      return h;            // return original head value
    }
    return -1;            // if it didn't catch that if statement, it's null
}


/* Adds a new element to the beginning of the list.
*
* list: pointer to pointer to Node
* val: value to add
*/
void push(Node **list, int val) {
    Node *head = *list;
    Node *newNode = make_node(val, head);
    *list = newNode;

//     Node *newNode = make_node(val, *list);
//     *list = newNode;
}


/* Removes the first element with the given value
*
* Frees the removed node.
*
* list: pointer to pointer to Node
* val: value to remove
*
* returns: number of nodes removed
*/
int remove_by_value(Node **list, int val) {
    Node *curr = *list;
    Node *prev;

    while (curr != NULL) {
        if (curr->val == val) {  // found one!
          if (prev->next == NULL) {    // it's the head node
            *list = curr->next;  // make the one after curr the new head
          }
          else {
            prev->next = curr->next;
          }
          free(curr);
          return 1;
        }
        else {
          prev = curr;   // saving the prev node
          curr = curr->next;
        }
    }

    return 0; // if we get here, no nodes were removed
}


/* Reverses the elements of the list.
*
* Does not allocate or free nodes.
*
* list: pointer to pointer to Node
*/
void reverse(Node **list) {
    // make pointer to next be to prev. so similar to remove with the prev
    Node *prev = NULL;
    Node *curr = *list;
    Node *next = NULL;

    while (curr != NULL) {
      next = curr->next;    // store next
      curr->next = prev;    // reverse curr's pointer
      prev = curr;          // move pointer along
      curr = next;          // move pointer along
    }
    *list = prev;           // new head
}


int main() {
    Node *head = make_node(1, NULL);
    head->next = make_node(2, NULL);
    head->next->next = make_node(3, NULL);
    head->next->next->next = make_node(4, NULL);

    Node **list = &head;
    print_list(list);

    int retval = pop(list);
    printf("%i\n", retval); // test pop
    print_list(list);

    push(list, retval+10);  //should push 11 to the list
    print_list(list);

    remove_by_value(list, 3);
    print_list(list);

    remove_by_value(list, 7);
    print_list(list);

    reverse(list);
    print_list(list);
}
