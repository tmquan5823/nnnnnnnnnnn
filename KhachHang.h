#pragma once
#include"person.h"

class KhachHang : public person{
    private:
    
    public:
        KhachHang();
        KhachHang(string, int, bool, string, string);
        ~KhachHang();
        void Nhap();
};

KhachHang::KhachHang(){
    this->ten = "";
    this->tuoi = 0;
    this->sdt = "";
    this->diaChi = "";
}

KhachHang::KhachHang(string ten, int tuoi, bool gt, string sdt, string diaChi){
    this->ten = ten;
    this->tuoi = tuoi;
    this->gt = gt;
    this->sdt = sdt;
    this->diaChi = diaChi;
}

KhachHang::~KhachHang(){
}

void KhachHang::Nhap(){
    system("cls");
    cout<<"=====NHAP THONG TIN KHACH HANG====="<<endl;
    person::Nhap();
}
