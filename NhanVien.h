#pragma once
#include"person.h"
#include<fstream>
#include<sstream>

class NhanVien : public person{
    private:
        static int id(){
            int id;
            ifstream file("listNhanVien.txt");
            int count = 0;
            while (!file.eof())
            {
                string ss;
                getline(file, ss);
                count++;
            }
            file.seekg(0, ios::beg);
            for(int i = 1;i<count;i++){
                string ss;
                getline(file, ss);
            }
            file>>id;
            file.close();
            static int ID = id;
            return ++ID;
        }
        string manv;
    public:
        NhanVien();
        NhanVien(string, int, bool, string, string);
        NhanVien(string, string, int, bool, string, string);
        ~NhanVien();
        string getMaNV();
        void setMaNV(const string&);
        void Nhap();
        void Xuat();
        friend ostream& operator<< (ostream&, const NhanVien&);
        friend istream& operator>> (istream&, NhanVien&);
        const NhanVien& operator = (const NhanVien&);
        friend bool operator == (const NhanVien&, const NhanVien&);
};

NhanVien::NhanVien(){
}

string intToString(int a){
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str;
}

NhanVien::NhanVien( string ten, int tuoi, bool gt, string sdt, string diaChi)
: person(ten, tuoi, gt, sdt, diaChi){
    this->manv = intToString(id());
}

NhanVien::NhanVien(string manv, string ten, int tuoi, bool gt, string sdt, string diaChi)
: person(ten, tuoi, gt, sdt, diaChi)
{
    this->manv = manv;
}

NhanVien::~NhanVien(){
}

string NhanVien::getMaNV(){
    return this->manv;
}

void NhanVien::setMaNV(const string& mnv){
    this->manv = mnv;
}

void NhanVien::Nhap(){
    cout<<"=====NHAP THONG TIN NHAN VIEN====="<<endl;
    this->manv = intToString(this->id());
    person::Nhap();
}

void NhanVien::Xuat(){
    cout<<"===================="<<endl;
    cout<<"Ma nhan vien: "<<this->manv<<endl;
    person::Xuat();
    cout<<"===================="<<endl;
}

ostream& operator << (ostream& o, const NhanVien& nv){
    o<<nv.manv<<"-"<<nv.ten<<"-"<<nv.tuoi<<"-"<<nv.gt<<"-"<<nv.sdt<<"-"<<nv.diaChi;
    return o;
}

istream& operator >> (istream& i, NhanVien& nv){
    nv.manv = intToString(nv.id());
    nv.Nhap();
    return i;
}

const NhanVien& NhanVien::operator = (const NhanVien& nv){
    this->manv = nv.manv;
    this->ten = nv.ten;
    this->gt = nv.gt;
    this->sdt = nv.sdt;
    this->diaChi = nv.diaChi;
    return *(this);
}

bool operator == (const NhanVien& nv1, const NhanVien& nv2){
    return nv1.manv == nv2.manv;
}