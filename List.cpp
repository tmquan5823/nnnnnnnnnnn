#include"List.h"

template<class T>
List<T>::List(int n){
    this->length = n;
    if(this->length != 0){
        this->p = new T[this->length];
    }
};

template<class T>
List<T>::~List(){
    delete[] this->p;
}

template<class T>
T &List<T>::operator[] (const int& index){
    static T t;
    if(index >= 0 && index < this->length){
        return *(this->p + index);
    }
    return t;
}

template<class T>
int List<T>::getIndex(const T& val){
    for(int i = 0;i<this->length;i++){
        if(p[i] == val) return i;
    }
    return -1;
}

template<class T>
int List<T>::getLength(){
    return this->length;
}

template<class T>
bool List<T>::is_Empty(){
    if(this->length == 0) return true;
    return false;
}

template<class T>
void List<T>::push(const T& value){
    this->length++;
    if(this->length - 1 == 0){
        this->p = new T[this->length];
        this->p[this->length - 1] = value;
    }
    else{
        T *tmp = new T[this->length];
        for(int i = 0;i<this->length - 1;i++){
            tmp[i] = this->p[i];
        }
        delete[] this->p;
        this->p = new T[this->length];
        for(int i = 0;i<this->length;i++){
            this->p[i] = tmp[i];
        }
        this->p[length - 1] = value;
        delete[] tmp;
    }
}

template<class T>
T List<T>::pop(){
    static T t;
    if(this->length == 0) return t;
    T val = *(this->p + length - 1);
    this->length--;
    T *tmp = new T[this->length];
    for(int i = 0;i<this->length;i++){
        tmp[i] = this->p[i];
    }
    delete[] this->p;
    p = new T[this->length];
    for(int i = 0;i<this->length;i++){
        this->p[i] = tmp[i];
    }
    delete[] tmp;
    return val;
}

template<class T>
void List<T>::delLast(){
    T *tmp = new T[this->length];
    for(int i = 0;i<this->length; i++){
        *(tmp + i) = *(this->p + i);
    }
    delete[] this->p;
    this->length--;
    this->p = new T[this->length];
    for(int i = 0;i<this->length; i++){
        *(this->p + i) = *(tmp + i);
    }
    delete[] tmp;
}

template<class T>
void List<T>::delAt(const int& index){
    if(index == length - 1){
        this->delLast();
        return;
    }
    T *tmp = new T[this->length - 1];
    int j = 0;
    for(int i = 0;i<this->length; i++){
        if(index == i && index != length - 1){
            i++;
        }
        tmp[j] = this->p[i];
        j++;
    }
    delete[] this->p;
    this->length--;
    this->p = new T[this->length];
    for(int i = 0;i<this->length; i++){
        *(this->p + i) = *(tmp + i);
    }
    delete[] tmp;
}

template<class T>
void List<T>::show() const{
    if(this->length == 0) {
        cout<<"List is empty!"<<endl;
        return;
    }
    for(int i = 0;i<this->length;i++){
        cout<<this->p[i]<<" ";
    }
}