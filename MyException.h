#pragma once
#include<iostream>
#include<exception>
using namespace std;

class MyException : public exception {
    string msg;
    public:
        MyException(){
            this->msg = "ERROR!";
        }
        MyException(string msg){
            this->msg = msg;
        }
        const char* what() const throw() {
            return msg.c_str();
        }
};