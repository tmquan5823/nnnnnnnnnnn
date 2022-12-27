#pragma once
#include<iostream>
#include<string>
using namespace std;

class person{
    protected:
        string ten;
        int tuoi;
        bool gt; // 0-nam, 1-nu
        string sdt;
        string diaChi;
    public:
        person();
        person(string, int, bool, string, string);
        virtual ~person();
        string getTen();
        void setTen(const string&);
        int getTuoi();
        void setTuoi(const int&);
        bool getGT();
        void setGT(bool);
        string getSDT();
        void setSDT(const string&);
        string getDiaChi();
        void setDiaChi(const string&);
        void CapNhat();
        void Nhap();
        void Xuat();
};

person::person(){
    this->ten = "";
    this->tuoi = 0;
    this->sdt = "";
    this->diaChi = "";
}

person::person(string ten, int tuoi, bool gt, string sdt, string diaChi){
    this->ten = ten;
    this->tuoi = tuoi;
    this->gt = gt;
    this->sdt = sdt;
    this->diaChi = diaChi;
}

person::~person(){}

string person::getTen(){
    return this->ten;
}

void person::setTen(const string& ten){
    this->ten = ten;
}

int person::getTuoi(){
    return this->tuoi;
}

void person::setTuoi(const int& tuoi){
    this->tuoi = tuoi;
}

bool person::getGT(){
    return this->gt;
}

void person::setGT(bool gt){
    this->gt = gt;
}

string person::getSDT(){
    return this->sdt;
}

void person::setSDT(const string& sdt){
    this->sdt = sdt;
}

string person::getDiaChi(){
    return this->diaChi;
}

void person::setDiaChi(const string& dc){
    this->diaChi = dc;
}

void person::CapNhat(){
    cout<<"Nhap ten: ";
    fflush(stdin);
    getline(cin, this->ten);
    cout<<"Nhap tuoi ";
    cin>>this->tuoi;
    cout<<"Nhap gioi tinh (0. Nam, 1.Nu): ";
    cin>>this->gt;
    cout<<"Nhap SDT: ";
    cin>>this->sdt;
    cout<<"Nhap dia chi: ";
    fflush(stdin);
    getline(cin, this->diaChi);
}

void person::Nhap(){
    cout<<"Nhap ten: ";
    fflush(stdin);
    getline(cin, this->ten);
    cout<<"Nhap tuoi ";
    cin>>this->tuoi;
    cout<<"Nhap gioi tinh (0. Nam, 1.Nu): ";
    cin>>this->gt;
    cout<<"Nhap SDT: ";
    cin>>this->sdt;
    cout<<"Nhap dia chi: ";
    fflush(stdin);
    getline(cin, this->diaChi);
}

void person::Xuat(){
    cout<<"Ten: "<<this->ten<<endl;
    cout<<"Tuoi: "<<this->tuoi<<endl;
    cout<<"Gioi tinh: ";
    if(this->gt){
        cout<<"Nu"<<endl;
    }
    else cout<<"Nam"<<endl;
    cout<<"SDT: "<<this->sdt<<endl;
    cout<<"Dia chi: "<<this->diaChi<<endl;
}