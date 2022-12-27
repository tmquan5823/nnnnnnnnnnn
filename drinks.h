#pragma once
#include"order.h"

class drinks : public order {
    private:
    public:
        drinks(string = "", int = 0);
        friend ostream& operator << (ostream& o, const drinks& d){
            o<<d.ten<<": "<<d.gia;
            return o;
        }
        const drinks& operator = (const drinks&);
};

drinks::drinks(string s, int g){
    this->ten = s;
    this->gia = g;
    this->kt = false;
}

const drinks& drinks::operator = (const drinks& d){
    this->ten = d.ten;
    this->gia = d.gia;
    this->kt = d.kt;
    return *(this);
}   
