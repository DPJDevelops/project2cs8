#ifndef LIST_H
#define LIST_H
#include "linked_list_functions.h"

template <class T>
class List
{
public:
    List();

    ~List();

    List(const List<T> &copyThis); //IN - list to copy

    List& operator =(const List& RHS){  //IN - list to copy
        head = _CopyList(RHS.head);
        return *this;
    }

    bool operator ==(const List& rhs){  //IN - list to compare
        node<T>* w = this->head;        // CALC - to traverse
        node<T>* w2 = rhs.head;         // CALC - to traverse rhs

        while(w || w2){
            if (!(w->_item == w2->_item)){
                return false;
            }
            w = w->next;
            w2 = w2->next;
        }
        return true;
    }


    bool isEmpty() const;
    node<T>* InsertHead(T i);       //IN - value to insert

    node<T>* InsertAfter(T i,       //IN - value to insert
                 node<T>* iMarker); //IN - insert aftert this marker


    node<T>* InsertBefore(T i,          //IN - value to insert
                node<T>* iMarker);      //IN - insert before this marker


    node<T>* InsertSorted(T i);         // IN - insert i. Assume sorted list


    T Delete(node<T>* iMarker);         // IN - delete node pointed by iMarker


    void Print() const;


    node<T>* Search(const T &key);      //IN - search for this value


    node<T>* Prev(node<T>* iMarker);    //IN - find node previous to this


    T& operator[](int index);           //IN - index to access

    node<T>* Begin() const;


    node<T>* End() const;



private:
    node<T>* head;      //ATT - front of list

};

template<class T>
bool List<T>::isEmpty() const{
    return (this->head == nullptr);
}

template <class T>
List<T>::List(){
    head = NULL;
}

template<class T>
List<T>::~List(){
    _ClearList(head);
}
template<class T>
List<T>::List(const List<T> &copyThis){     //IN - list to copy
    this->head= _CopyList(copyThis.head);
}
template<class T>
void List<T>::Print() const{
    PrintList(head);
}

template<class T>
node<T>* List<T>::InsertHead(T i){  //IN - value to insert
    return _InsertHead(head, i);
}
template<class T>
node<T>* List<T>::InsertAfter(T i,      //IN - value to insert
             node<T>* iMarker){         //IN - insert after this
    if (head == NULL){
        return InsertHead(i);
    }
    return _InsertAfter(iMarker, i);
}
template<class T>
node<T>* List<T>::InsertBefore(T i, node<T>* iMarker){  // IN - before ptr
    if (head == NULL){
        return InsertHead(i);
    }
    return _InsertBefore(head, iMarker, i);
}
template<class T>
node<T>* List<T>::InsertSorted(T i){        // IN - insert this
    return _InsertSorted(head, i, true);
}
template<class T>
T List<T>::Delete(node<T>* iMarker){        //IN - delete this
    return _DeleteNode(head, iMarker);
}
template<class T>
node<T>* List<T>::Search(const T &key){     //IN - search for this
    return SearchList(head, key);
}
template<class T>
node<T>* List<T>::Prev(node<T>* iMarker){   //IN - ptr prev to this
    return _PreviousNode(head, iMarker);
}
template<class T>
T& List<T>::operator[](int index){  //IN - position of element
    return At(head, index);
}
template<class T>
node<T>* List<T>::Begin() const{
    return head;
}
template<class T>
node<T>* List<T>::End() const{
    return LastNode(head);
}


#endif // LIST_H
