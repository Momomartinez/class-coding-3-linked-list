//04_simple linked list
//!!!SOLUTION!!

#include <iostream>
//#include <bits/valarray_before.h>
//#include <bits/valarray_before.h>

using namespace std;

struct Node {
    int data;
    Node *next;
};

/**
 * This is only for the 1st Node
 * @param head - pointer to the head of the list
 * @param n - data that the first element should hold
 */
void initNode(struct Node *head, int n) {
    //TODO: Initiliaze the node data to n and the next pointer to..?
    head->data = n;
    head->next = nullptr;
}

/**
 * This funtion addes a node to the end of the list.
 * @param head - pointer to the head of the list
 * @param n - data that the new node should hold
 */
void addNode(struct Node *head, int n) {
    //TODO - Implement this function.
    Node *t_head = head;
    //1) find end of list
    while (t_head->next != nullptr) {
        t_head = t_head->next;
    }
    //2) create new node
    Node *newNode = new Node;
    newNode->next = nullptr;
    newNode->data = n;
    //3) add new node to end of list
    t_head->next = newNode;
}

/**
 * This funtion addes a node to the front of the list.
 * @param head - pointer to the head of the list
 * @param n - data that the new node should hold
 */
void insertFront(struct Node **head, int n) {
    //TODO
    Node *newhead = new Node;
    newhead->data = n;
    newhead->next = *head;
    *head = newhead;

}

/**
 * This function displayes the nodes in the list
 * @param head  - pointer to the head of the list
 */
void display(struct Node *head) {
    Node *list = head;
    while (list != nullptr) {
        cout << list->data << " ";
        list = list->next;


    }

}

/**
 * This function searches for a node holding n and returns a pointer to it.
 * @param head - pointer to the head of the list
 * @param n - data to search nodes for
 * @return - pointer to the node found.
 */
struct Node *searchNode(struct Node *head, int n) {
    //TODO
    Node *tmp = head;
    while (tmp != nullptr) {
        if (tmp->data == n) {
            return tmp;
        }
        tmp = tmp->next;

    }
    return nullptr;
}

/**
 * This function deletes a node
 * @param head - pointer to the head of the list
 * @param ptrDel - pointer to the node that is to be deleted
 * @return - boolean that indicates if the deletion was successful
 */
bool deleteNode(struct Node **head, Node *ptrDel) {

    Node *tmp = *head;
    /**
     * Delete first node if needed
     */
    if (ptrDel->data == tmp->data) {
        *head = tmp->next;
        return true;
    }
    while (tmp->next != nullptr) {
        if (tmp->next->data == ptrDel->data) {
            tmp->next = ptrDel->next;
            return true;
        }
        tmp = tmp->next;
    }
    return false;
}

/* reverse the list */
struct Node *reverse(struct Node **head) {
    Node *parent = *head;
    Node *me = parent->next;
    Node *child = me->next;

    /* make parent as tail */
    parent->next = NULL;
    while (child) {
        me->next = parent;
        parent = me;
        me = child;
        child = child->next;
    }
    me->next = parent;
    *head = me;
    return *head;
}

/* Creating a copy of a linked list */
void copyLinkedList(struct Node *node, struct Node **pNew) {
    if (node != NULL) {
        *pNew = new Node;
        (*pNew)->data = node->data;
        (*pNew)->next = NULL;
        copyLinkedList(node->next, &((*pNew)->next));
    }
}

/* Compare two linked list */
/* return value: same(1), different(0) */
int compareLinkedList(struct Node *node1, struct Node *node2) {
    static int flag;

    /* both lists are NULL */
    if (node1 == NULL && node2 == NULL) {
        flag = 1;
    } else {
        if (node1 == NULL || node2 == NULL)
            flag = 0;
        else if (node1->data != node2->data)
            flag = 0;
        else
            compareLinkedList(node1->next, node2->next);
    }

    return flag;
}

void deleteLinkedList(struct Node **node) {
    struct Node *tmpNode;
    while (*node) {
        tmpNode = *node;
        *node = tmpNode->next;
        delete tmpNode;
    }
}

int main() {
    struct Node *newHead;
    struct Node *head = new Node;
    initNode(head, 7);
    //display(head);

    addNode(head, 20);
    //display(head);

    addNode(head, 30);
    //display(head);
    //cout<<endl;
    insertFront(&head, 5);
    //display(head);

    addNode(head, 35);
    //display(head);

    addNode(head, 40);
    //display(head);
    display(head);
    int numDel = 40;
    Node *ptrDelete = searchNode(head, numDel);
    if (deleteNode(&head, ptrDelete))
        cout << "Node " << numDel << " deleted!\n";
    display(head);
/*
  cout << "The list is reversed\n";
  reverse(&head);
  display(head);

  cout << "The list is copied\n";
  copyLinkedList(head,&newHead);
  display(newHead);

  cout << "Comparing the two lists...\n";
  cout << "Are the two lists same?\n";
  if(compareLinkedList(head,newHead))
      cout << "Yes, they are same!\n";
  else
      cout << "No, they are different!\n";
  cout << endl;

  numDel = 35;
  ptrDelete = searchNode(newHead,numDel);
  if(deleteNode(&newHead,ptrDelete)) {
      cout << "Node "<< numDel << " deleted!\n";
      cout << "The new list after the delete is\n";
      display(newHead);
  }
  cout << "Comparing the two lists again...\n";
  cout << "Are the two lists same?\n";
  if(compareLinkedList(head,newHead))
      cout << "Yes, they are same!\n";
  else
      cout << "No, they are different!\n";

  cout << endl;
  cout << "Deleting the copied list\n";
  deleteLinkedList(&newHead);
  display(newHead);
*/
    return 0;
}