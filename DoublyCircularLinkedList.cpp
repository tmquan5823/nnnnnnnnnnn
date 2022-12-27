#include"DoublyCircularLinkedList.h"

template<class T>
DoublyCircularLinkedList<T>::DoublyCircularLinkedList(){
    this->length = 0;
    this->start = NULL;
    this->end = NULL;
}

template<class T>
DoublyCircularLinkedList<T>::~DoublyCircularLinkedList(){}

template<class T>
int DoublyCircularLinkedList<T>::getLength(){
    return this->length;
}

template<class T>
Node<T>* DoublyCircularLinkedList<T>::getStart(){
    return this->start;
}

template<class T>
Node<T>* DoublyCircularLinkedList<T>::getEnd(){
    return this->end;
}

template<class T>
T& DoublyCircularLinkedList<T>::operator [] (const int& index){
    static T t;
    if (index < 0 || index >= this->length) return t;
    if (index == this->length - 1) return this->end->data;
    
    Node<T> *tmp = this->start;
    int i = 0;
    while (tmp != end)
    {
        if(i == index) return tmp->data;
        i++;
        tmp = tmp->next;
    }
}

template<class T>
bool DoublyCircularLinkedList<T>::isEmpty() const{
    return (this->start == NULL);
}

template<class T>
void DoublyCircularLinkedList<T>::AddFirst(const T& value){
    Node<T> *n = new Node<T>(value);
    if(this->start == this->end && this->start == NULL){
        this->start = this->end = n;
        this->start->next = this->end->next = NULL;
        this->start->pre = this->end->pre =NULL;
        this->length++;
        return;
    }
    n->next = this->start;
    this->start->pre = n;
    this->start = n;
    this->start->pre = this->end;
    this->end->next = this->start;
    this->length++;
}

template<class T>
void DoublyCircularLinkedList<T>::AddLast(const T& value){
    Node<T>* n = new Node<T>(value);
    if(this->start == this->end && this->start == NULL){
        this->start = this->end = n;
        this->start->next = this->end->next = NULL;
        this->start->pre = this->end->pre =NULL;
        this->length++;
        return;
    }
    this->end->next = n;
    n->pre = this->end;
    this->end = n;
    this->start->pre = this->end;
    this->end->next = this->start;
    this->length++;
}

template<class T>
void DoublyCircularLinkedList<T>::Insert(const T& value, int index){
    Node<T> *n = new Node<T>(value);
    if(this->start == this->end && this->start == NULL){
        this->start = this->end = n;
        this->start->next = this->end->next = NULL;
        this->start->pre = this->end->pre =NULL;
        this->length++;
        return;
    }
    Node<T> *tmp = this->start;
    if(index > this->length) index = this->length;
    if(index == 0){
        this->AddFirst(value);
        return;
    }
    if(index == this->length){
        this->AddLast(value);
        return;
    }
    for(int i = 0;i<this->length; i++){
        if(i == index) break;
        tmp = tmp->next;
    }
    if(tmp != NULL){
        if(tmp->pre != NULL){
            tmp->pre->next = n;
            n->next = tmp;
            n->pre = tmp->pre;
            tmp->pre = n;
            this->length++;
        }
    }
}

template<class T>
void DoublyCircularLinkedList<T>::DelFirst(){
    if(this->start == NULL){
        return;
    }
    if(this->start == this->end){
        this->start = this->end = NULL;
        this->length--;
        return;
    }
    Node<T> *tmp = this->start;
    this->end->next = tmp->next;
    tmp->next->pre = this->end;
    this->start = tmp->next;
    this->length--;
    delete tmp;
}

template<class T>
void DoublyCircularLinkedList<T>::DelLast(){
    if(this->start == NULL){
        return;
    }
    if(this->start == this->end){
        delete this->start;
        this->start = NULL;
        return;
    }
    Node<T> *tmp = this->end;
    this->start->pre = tmp->pre;
    tmp->pre->next = this->start;
    this->end = tmp->pre;
    this->length--;
}

template<class T>
void DoublyCircularLinkedList<T>::DelAt(int index){
    if(this->start == NULL){
        return;
    }
    Node<T> *tmp = this->start;
    if(index > this->length) index = this->length;
    if(index == 0){
        this->DelFirst();
        return;
    }
    if(index == this->length){
        this->DelLast();
        return;
    }
    for(int i = 0;i<this->length;i++){
        if(i == index) break;
        tmp = tmp->next;
    }
    tmp->pre->next = tmp->next;
    tmp->next->pre = tmp->pre;
    this->length--;
    delete tmp;
}

//Quick sort
template<class T>
void Swap(T& a, T& b){
    T tmp = a;
    a = b;
    b = tmp;
}

template<class T>
Node<T>* DoublyCircularLinkedList<T>::partition(Node<T>* l, Node<T>* r, bool(*cmp)(const T&, const T&)){
    T& pivot = r->data;
    Node<T>* L = l;
    for (Node<T>* i = l; i != r; i = i->next) {
        if (cmp(i->data, pivot)) {
            Swap(L->data, i->data);
            L = L->next;
        }
    }
    Swap(L->data, r->data);
    return L;
}

//Tim kiem 
template<class T>
int DoublyCircularLinkedList<T>::getIndex(T& value){
    Node<T> *tmp = this->start;
    for(int i = 0;i<this->length; i++){
        if(value == tmp->data) return i;
        tmp = tmp->next;
    }
    return -1;
}

template<class T>
void DoublyCircularLinkedList<T>::QuickSort(Node<T>* l, Node<T>* r, bool(*cmp)(const T&, const T&)){
    if(this->length == 1 || this->length == 0) return;
    else if(this->length == 2){
        if(!cmp(l->data, r->data)) Swap(l->data, r->data);
    }
    else{
        if(l != r){
            Node<T>* part = this->partition(l, r, cmp);
            Node<T>* tmp = l;
            while (tmp->next != part) tmp = tmp->next;

            if (tmp->next != l)
                this->QuickSort(l, tmp, cmp);
            this->QuickSort(part, r, cmp);
        }
    }
}
