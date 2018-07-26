#include<iostream>
using namespace std;

/* defines the structure of a double linked list node*/
typedef struct list_node {
   int data;
   struct list_node *next; // pointer to next node
   struct list_node *prev; // pointer to previous node
}node;

/* create new node */
node *getNewNode(int data) {
   node *new_node = new node;
   new_node->data = data;
   new_node->next = NULL;
   new_node->prev = NULL;
   return new_node;
}

/* displays the list elements */
void displayList(node *head) {
   cout << "Displaying List : ";
   node *temp = NULL; // used to display list in reverse direction
   while (head != NULL) {
      cout << head->data << " -> ";
      temp = head;
      head = head->next;
   }
   cout << "NULL " << endl;
   cout << "Displaying List in reverse direction : ";
   while (temp != NULL) {
      cout << temp->data << " -> ";
      temp = temp->prev;
   }
   cout << "NULL " << endl;
}

/* Search the node with element as data
   Return the pointer to the node if found else return NULL */
node *searchNode(node *head, int data) {
   node *ptr = NULL;
   while (head) {
      if (head->data == data) {
         ptr = head;
         break;
      }
      head = head->next;
   }
   return ptr;
}

/* insert a node at the beginning of the list */
node *insertNodeBeg(node *head, int data) {
   node *ptr = getNewNode(data);
   if (head == NULL) { // if list is empty
      head = ptr;
   }
   else {
      ptr->next = head;
      head->prev = ptr;
      head = ptr;
   }
   return head;
}

/* insert a node at the end of the list */
node *insertNodeEnd(node *head, int data) {
   node *ptr = getNewNode(data);
   if (head == NULL) { //if list is empty
      head = ptr;
   }
   else {
      node *temp = head;
      while (temp->next != NULL) { // move to the last node
         temp = temp->next;
      }
      temp->next = ptr; // insert node at the end
      ptr->prev = temp;
   }
   return head;
}

/* insert a node at the after a particular node in the list */
node *insertNodeAfter(node *head, int element, int data) {
   // search the element after which node is to be inserted
   node *temp = searchNode(head, element);
   if (temp == NULL) { // element not found
      cout << "Element not found ... " << endl;
   }
   else {
      node *ptr = getNewNode(data);
      if (temp->next == NULL) { // node has to inserted after the last node
         temp->next = ptr;
         ptr->prev = temp;
      }
      else {  // insert the node after the first or an intermediate node
         ptr->next = temp->next;
         temp->next->prev = ptr;
         ptr->prev = temp;
         temp->next = ptr;
      }
   }
   return head;
}

/* delete a particular node from the list */
node *deleteNode(node *head, int element) {
   node *temp = searchNode(head, element); // search the node to be deleted
   if (temp == NULL) { // element not found
      cout << "Node to be deleted not found ... " << endl;
   }
   else {
      if (temp == head) { // first node is to be deleted
         head = head->next;
         head->prev = NULL;
         delete temp;
      }
      else if (temp->next == NULL) { // node to be deleted is the last node
         temp->prev->next = NULL;
         delete temp;
      }
      else { // node to deleted is an intermediate node
         temp->prev->next = temp->next;
         temp->next->prev = temp->prev;
         delete temp;
      }
   }
   return head;
}

int main() {
   node *head = NULL;
   head = insertNodeBeg(head, 7);       // 7
   head = insertNodeBeg(head, 9);       // 9 -> 7
   head = insertNodeEnd(head, 11);      // 9 -> 7 -> 11
   head = insertNodeAfter(head, 9, 4);  // 9 -> 4 -> 7 -> 11
   head = insertNodeAfter(head, 7, 3);  // 9 -> 4 -> 7 -> 3 -> 11
   head = insertNodeAfter(head, 11, 6); // 9 -> 4 -> 7 -> 3 -> 11 -> 6
   displayList(head);
   head = deleteNode(head, 7);          // 9 -> 4 -> 3 -> 11 -> 6
   head = deleteNode(head, 6);          // 9 -> 4 -> 3 -> 11
   head = deleteNode(head, 9);          // 4 -> 3 -> 11
   displayList(head);
   return 0;
}
