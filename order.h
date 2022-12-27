#pragma once
#include<iostream>
#include<string>
using namespace std;

class order{
    protected:
        string ten;
        int gia;
        bool kt; //true - food | flase - drink
    public:
        virtual void setTenMon(const string&);
        virtual string getTenMon();
        virtual void setGia(const int&);
        virtual int getGia();
        virtual void setKT(bool);
        virtual bool getKT();
        virtual void xuat();
        virtual void CapNhat();
        virtual order& operator = (const order&);
        friend ostream& operator<<(ostream&, const order&);
        virtual bool operator == (const order& o) const;
};