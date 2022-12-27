#include"order.h"

void order::setTenMon(const string& ten){
    this->ten = ten;
}

string order::getTenMon(){
    return this->ten;
}

void order::setGia(const int &gia){
    this->gia = gia;
}

int order::getGia(){
    return this->gia;
}

void order::xuat(){
    cout<<this->ten<<": "<<this->gia;
}

void order::setKT(bool kt){
    this->kt = kt;
}

bool order::getKT(){
    return this->kt;
}

void order::CapNhat(){
    this->xuat();
    cout<<endl;
    cout<<"Nhap gia ban moi: ";
    int gia;
    cin>>gia;
    this->setGia(gia);
    cout<<"Cap nhat thanh cong!"<<endl;
    system("pause");
}

order& order::operator = (const order& o){
    this->ten = o.ten;
    this->gia = o.gia;
    this->kt = o.kt;
    return *(this);
}

ostream& operator<<(ostream& o, const order& n){
    o<<n.ten<<" "<<n.gia;
    return o;
}

bool order::operator == (const order& o) const{
    if(this->ten == o.ten) return 1;
    return 0;
}