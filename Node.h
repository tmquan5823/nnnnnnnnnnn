#pragma once
#include<iostream>
using namespace std;

template<class T>
class Node{
    public:
        T data;
        Node *next;
        Node *pre;

        Node(){
            this->data = NULL;
            this->next = NULL;
            this->pre = NULL;
        }
        Node(const T& value){
            this->data = value;
            this->next = NULL;
            this->pre = NULL;
        }
        ~Node(){}
};
