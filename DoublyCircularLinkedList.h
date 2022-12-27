#pragma once
#include<iostream>
#include"Node.h"
using namespace std;

template<class T>
class DoublyCircularLinkedList{
    public:
        Node<T> *start;
        Node<T> *end;
        int length;
    public:
        DoublyCircularLinkedList();
        ~DoublyCircularLinkedList();
        Node<T>* getStart();
        Node<T>* getEnd();
        int getLength();
        T& operator [] (const int&);
        bool isEmpty() const;

        //Them 
        void AddFirst(const T&);
        void AddLast(const T&);
        void Insert(const T&, int);

        //Xoa
        void DelFirst();
        void DelLast();
        void DelAt(int);

        //Quick Sort
        Node<T>* partition(Node<T>*, Node<T>*, bool(*cmp)(const T&, const T&));
        void QuickSort(Node<T>*, Node<T>*, bool(*cmp)(const T&, const T&));
        //Tim kiem
        int getIndex(T&);

        //Xuat
        friend ostream& operator << (ostream& o, const DoublyCircularLinkedList<T>& list){
            if(list.start == NULL) {
                o<<"List is empty!"<<endl;
            }
            else{
                Node<T> *n = list.start;
                for(int i = 0;i<list.length; i++){
                    o<<n->data<<endl;
                    n = n->next;
                }
            }
            return o;
        }
};

template class DoublyCircularLinkedList<int>;