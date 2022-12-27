#pragma once
#include<iostream>
using namespace std;

template<class T>
class List{
        T *p;
        int length;
    public:
        List(int = 0);
        ~List();
        T &operator [] (const int& index);
        int getLength();
        int getIndex(const T&);
        bool is_Empty();
        T& search(const string&);
        void push(const T&);
        T pop();
        void delLast();
        void delAt(const int&);
        void show() const;
        friend ostream& operator << (ostream& o, const List<T> v){
            for(int i = 0; i<v.length;i++){
                cout<<v.p[i]<<endl;
            }
            return o;
        }
};

