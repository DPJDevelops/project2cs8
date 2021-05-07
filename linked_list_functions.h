#ifndef LINKED_LIST_FUNCTIONS_H
#define LINKED_LIST_FUNCTIONS_H
#include <iostream>
#include <cassert>

using namespace std;

template <typename ITEM_TYPE>
struct node
{
public:
    node(){
        next = NULL;
        _item = ITEM_TYPE();
    }
    node(ITEM_TYPE item){
        next = NULL;
        _item = item;
    }

    ITEM_TYPE _item;        //ATT - item in list
    node<ITEM_TYPE>* next;  //ATT - next item in list


};

template <typename ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head,  //IN - list head
                            ITEM_TYPE key);         //IN - val to search for


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _PreviousNode(node<ITEM_TYPE>* head,       //IN - list head
                              node<ITEM_TYPE>* prevToThis); //IN - prev pointer


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head,     //IN - list head
                            ITEM_TYPE insertThis);       //IN - val to insert


template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertAfter(
                              node<ITEM_TYPE> *afterThis,   //IN - node ptr
                             ITEM_TYPE insertThis);         //IN - val to ins

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertBefore(node<ITEM_TYPE>*& head,      //IN - list head
                              node<ITEM_TYPE>* beforeThis,  //IN - ins before
                              ITEM_TYPE insertThis);        //IN - val to ins

template <typename ITEM_TYPE>
ITEM_TYPE _DeleteNode(node<ITEM_TYPE>*&head,                 //IN - list head
                     node<ITEM_TYPE>* deleteThis);           //IN - ptr to del

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _CopyList(node<ITEM_TYPE>* head);       //IN - list head

template <typename ITEM_TYPE>
void _ClearList(node<ITEM_TYPE>*& head);                 //IN - list head

template <typename ITEM_TYPE>
ITEM_TYPE& At(node<ITEM_TYPE>* head,         //IN - list head
              int pos);                      //IN - position to ret val

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertSorted(node<ITEM_TYPE>* &head,    //IN - list head
                             ITEM_TYPE item,              //IN - val to ins
                             bool ascending=true);        //IN - how to sort

template <typename ITEM_TYPE>
    node<ITEM_TYPE>* InsertSorted_and_add(
                                    node<ITEM_TYPE>* &head,//IN - list head
                                    ITEM_TYPE item,        //IN - val to ins
                                    bool ascending=true);  //IN - how to sort

template <typename ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head,        //IN - list head
                              ITEM_TYPE item,                //IN - val to ins
                               bool unique,                  //IN - if unique
                              bool ascending=true);          //IN - how to sort
template <typename ITEM_TYPE>
node<ITEM_TYPE>* LastNode(node<ITEM_TYPE>* head);          //IN - list head


template <typename ITEM_TYPE>
node<ITEM_TYPE>* SearchList(node<ITEM_TYPE>* head,  //IN - list head
                            ITEM_TYPE key){         //IN - val to search for
    assert(head != NULL);
    node<ITEM_TYPE> * walker = head;                //CALC - temp pointer
    if (head->_item == key)
        return head;
    // loop through the entire list
    while (walker != NULL){
        if (key == walker->_item)
            return walker;
        walker = walker->next;
    }
    return NULL;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertHead(node<ITEM_TYPE> *&head,     //IN - list head
                             ITEM_TYPE insertThis){      //IN - val to insert
    node<ITEM_TYPE>* temp = new node<ITEM_TYPE>(insertThis);//CALC - new node
     temp->next = head;
     head= temp;
     return head;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertAfter(                              node<ITEM_TYPE> *afterThis,  //IN - ptr
ITEM_TYPE insertThis){       //IN - ins after ptr
// calls insert head and use afterthis-> next as the head
return _InsertHead(afterThis->next, insertThis);
}
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertBefore(node<ITEM_TYPE>*& head,       //IN - list head
                               node<ITEM_TYPE>* beforeThis,  //IN - ptr
                              ITEM_TYPE insertThis){         //IN - ins be4 ptr
    node<ITEM_TYPE> *prev = _PreviousNode(head, beforeThis);
    if (prev == nullptr){
        return _InsertHead(head, insertThis);
    }
    return _InsertHead(prev->next, insertThis);
}
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _PreviousNode(node<ITEM_TYPE>* head,        // IN - list head
                               node<ITEM_TYPE>* prevToThis){ // IN - ptr
    // use a walker to compare if the node that the current node is pointing to
    // is equal to prevToThis. walker stops at that point and return that point
    node<ITEM_TYPE> *walker = head;         // CALC - to traverse
    assert(walker != NULL);
    while (walker!= NULL){
        if (head == prevToThis){
            return NULL;
        }
        if (walker ->next == prevToThis){
            return walker;
        }
        walker = walker ->next;
    }
    assert(walker != NULL);
    return NULL;
}

template <typename ITEM_TYPE>
ITEM_TYPE _DeleteNode(node<ITEM_TYPE>*&head,            // IN - list head
                      node<ITEM_TYPE>* deleteThis){     // IN - ptr to delete
    //first find the previous node to the node that will be deleted, make that
    // node point to the next node of the deleting node, delete the node.
    assert(head != NULL);
    assert(deleteThis!=NULL);
    ITEM_TYPE temp = deleteThis->_item;                 // CALC - object deleted
    node <ITEM_TYPE> *prev
            = _PreviousNode(head,deleteThis);           // CALC - left shift
    if (prev == nullptr){
        head= deleteThis->next;
        delete deleteThis;
        return temp;
    }
    prev->next = deleteThis->next;
    delete deleteThis;
    return temp;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _CopyList(node<ITEM_TYPE>* head){ // IN - list head

    // set a walker walking through the old list, set a walker to the new list,
    // walker through each element in the old list and append it to the new list
    node<ITEM_TYPE> *result = NULL;     // CALC - result pointer
    node<ITEM_TYPE> *result_walker;     // IN - to traverse
    node<ITEM_TYPE> *walker = head;     // IN - ptr to head
    while (walker != NULL){

        if (result == NULL){
            result_walker = _InsertHead(result, walker->_item);
        }else{
            result_walker = _InsertAfter(result_walker, walker->_item);
        }
        walker = walker->next;
    }
    return result;
}

template <typename ITEM_TYPE>
void _ClearList(node<ITEM_TYPE>*& head){ // IN - list head
    // call the function to delete a single node, while list is not empty, keep
    // deleting the head node, at the end, set head to node pointer
    while (head != NULL){
        _DeleteNode(head,head);
    }
    head = NULL;
}

template <typename ITEM_TYPE>
ITEM_TYPE& At(node<ITEM_TYPE>* head,        // IN - list head
              int pos){                     // IN - list position
    // use a counter to counter to the particular position
    int counter = 0;
    node <ITEM_TYPE> * w=head;              // CALC - to traverse
    while (w != NULL && counter != pos){
        w = w->next;
        counter++;
    }
    return w->_item;
}
template <typename ITEM_TYPE>
node<ITEM_TYPE>* InsertSorted_and_add(node<ITEM_TYPE>* &head, // IN - list head
                                      ITEM_TYPE item,         // IN - val ins
                                      bool ascending){        // IN - sort type
    node<ITEM_TYPE>*ptr
            = WhereThisGoes(head,item,true,ascending);  // CALC - helper
    if (ptr == nullptr || head == NULL){
        return _InsertHead(head,item);
    }
    if (ptr->_item == item){
        ptr->_item = ptr->_item + item;
        return ptr;
    }
        return _InsertAfter(ptr, item);
}
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _InsertSorted(node<ITEM_TYPE>* &head,  // IN - list head
                               ITEM_TYPE target,        // IN - val to ins
                               bool ascending){         // IN - sort type
    node<ITEM_TYPE>* ptr
            =WhereThisGoes(head,target,false,ascending); //CALC - helper
    if (ptr == NULL || head == NULL){
        return _InsertHead(head,target);
    }
        return _InsertAfter(ptr, target);
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* WhereThisGoes(node<ITEM_TYPE>* head, // IN - list head
                               ITEM_TYPE item,        // IN - val to ins
                               bool unique,           // IN - if unique
                               bool ascending){       // IN - sort type
    node<ITEM_TYPE>* w = head;                  // CALC - head traverse
      node<ITEM_TYPE> * nextItem = head ->next;   // CALC - check ahead
      if (ascending == true){
          if (item > LastNode(head)->_item){
              return LastNode(head);
          }
          if (item == head->_item && unique == true){
              return head;
          }
          if (item < head->_item){
              return nullptr;
          }
          while (item > nextItem->_item && w != NULL){
              nextItem = nextItem->next;
              w = w->next;
          }
      }

      if (ascending == false) {
          if (item < LastNode(head)->_item){
              return LastNode(head);
          }
          if (item == head->_item && unique == true){
              return head;
          }
          if (item > head->_item){
              return nullptr;
          }
          while (item <= nextItem->_item && w != NULL){
              nextItem = nextItem->next;
              w = w->next;
          }
      }
      return w;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* LastNode(node<ITEM_TYPE>* head){ // IN - list head
    node<ITEM_TYPE>* w = head;                    // IN - to traverse
    if (head == NULL){
        return head;
    }
    while (w->next != NULL){
        w = w->next;
    }
    return w;
}

#endif // LINKED_LIST_FUNCTIONS_H
