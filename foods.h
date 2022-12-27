#pragma once
#include"order.h"

class foods : public order {
    private:
    public:
        foods(string = "", int = 0);
        friend ostream& operator << (ostream& o, const foods& f){
            o<<f.ten<<": "<<f.gia;
            return o;
        }
        const foods& operator = (const foods&);
};

foods::foods(string s, int g){
    this->ten = s;
    this->gia = g;
    this->kt = true;
}

const foods& foods::operator = (const foods& f){
    this->ten = f.ten;
    this->gia = f.gia;
    this->kt = f.kt;
    return *(this);
}