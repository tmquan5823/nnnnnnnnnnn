#include"Pair.h"

template<class T, class U>
Pair<T, U>::Pair(){
}

template<class T, class U>
Pair<T, U>::Pair(T& first, U& second){
    this->first = first;
    this->second = second;
}

template<class T, class U>
void Pair<T, U>::setFirst(const T& f){
    this->first = f;
}

template<class T, class U>
T Pair<T, U>::getFirst(){
    return this->first;
}

template<class T, class U>
void Pair<T, U>::setSecond(const U& s){
    this->second = s;
}

template<class T, class U>
U Pair<T, U>::getSecond(){
    return this->second;
}

template<class T, class U>
const Pair<T, U>& Pair<T, U>::operator=(const Pair<T, U>& p){
    this->first = p.first;
    this->second = p.second;
    return *this;
}

template<class T, class U>
bool Pair<T, U>::operator==(const Pair<T, U>& p){
    if(p.first == this->first) return 1;
    return 0;
}

template<class T, class U>
void Pair<T, U>::show(){
    cout<<this->first<<" "<<this->second<<endl;
}