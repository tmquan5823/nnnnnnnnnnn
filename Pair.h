#pragma once
#include<iostream>
using namespace std;

template<class T, class U>
class Pair{
        T first;
        U second;
    public:
        Pair();
        Pair( T&,  U&);
        void setFirst(const T&);
        T getFirst();
        void setSecond(const U&);
        U getSecond();
        const Pair<T, U>& operator=(const Pair<T, U>&);
        bool operator == (const Pair<T, U>&);
        friend ostream& operator<<(ostream& o, const Pair<T, U> p){
            o<<p.first<<" "<<p.second;
            return o;
        }
        void show();
};