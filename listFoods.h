#pragma once
#include"Sample.h"
#include<fstream>
#include<iomanip>
#include"MyException.h"

class listFoods{
    private:
        List<foods> list;       
        int soLuong;
    public:
        listFoods();
        ~listFoods();
        int getSoLuong() const;
        void CapNhatGiaBan();
        void ThemMonAn();
        void XoaMonAn();
        List<foods> getList();
        order operator[](const int&);
        void DanhSach();
};

listFoods::listFoods(){
    this->soLuong = 0;
    //Doc file foods
    ifstream fileFoods;
    fileFoods.open("foods.txt", ios::in);
    // fileFoods.seekg(0, ios::beg);
    while(!fileFoods.eof()){
        foods f;
        string food;
        getline(fileFoods, food);
        f.setTenMon(food);
        int price;
        fileFoods >> price;
        string s;
        getline(fileFoods, s);
        f.setGia(price);
        f.setKT(true);
        this->soLuong++;
        this->list.push(f);
    }
    fileFoods.close();
}

listFoods::~listFoods(){}

int listFoods::getSoLuong() const{
    return this->soLuong;
}

void listFoods::CapNhatGiaBan(){
    system("cls");
    cout<<"=====CAP NHAT GIA BAN THUC AN======"<<endl;
    this->DanhSach();
    cout<<"Nhap so thu tu mon an muon cap nhat: ";
    int choice;
    cin>>choice;
    this->list[choice - 1].CapNhat();
    ofstream file("foods.txt", ios::trunc);
    for(int i = 0;i<this->list.getLength() - 1;i++){
        file<<list[i].getTenMon()<<"\n"<<list[i].getGia()<<endl;
    }
    file<<list[list.getLength() - 1].getTenMon()<<"\n"<<list[list.getLength() - 1].getGia();
    file.close();
    cout<<"Cap nhat thanh cong!"<<endl;
};

void listFoods::ThemMonAn(){
    system("cls");
    cout<<"=======THEM MON AN========="<<endl;
    this->DanhSach();
    cout<<"Nhap ten mon an: ";
    string name;
    fflush(stdin);
    getline(cin, name);
    cout<<"Nhap gia mon an: ";
    int price;
    cin>>price;
    foods d(name, price);
    this->list.push(d);
    ofstream file("foods.txt", ios::app);
    file<<"\n"<<d.getTenMon()<<"\n"<<d.getGia();
    file.close();
    system("cls");
    this->DanhSach();
    cout<<"Them thanh cong!"<<endl;
    system("pause");
};

void listFoods::XoaMonAn(){
    system("cls");
    cout<<"======XOA MON AN====="<<endl;
    this->DanhSach();
    cout<<"Nhap so thu tu mon an muon xoa: ";
    int choice;
    cin>>choice;
    if(choice > list.getLength() || choice <= 0){
        throw MyException("Nhap khong hop le!");
    }
    else{
        cout<<list[choice - 1];
        cout<<"\nBan co muon xoa mon nay(Y-Xoa, N-Huy): ";
        char c;
        cin>>c;
        if(c == 'n' || c == 'N') return;
        else if(c == 'Y' || c == 'y'){
            int index = choice - 1;
            this->list.delAt(index);
            ofstream file("foods.txt", ios::trunc);
            for(int i = 0;i<this->list.getLength() - 1;i++){
                file<<list[i].getTenMon()<<"\n"<<list[i].getGia()<<endl;
            }
            file<<list[list.getLength() - 1].getTenMon()<<"\n"<<list[list.getLength() - 1].getGia();
            file.close();
            cout<<"Xoa thanh cong!"<<endl;
            system("pause");
        }
        else{
            throw MyException("Nhap khong hop le!");
        }
    }
};

List<foods> listFoods::getList(){
    return this->list;
}

order listFoods::operator[](const int& index){
    foods f;
    if(index >= 0 && index < this->soLuong){
        return list[index];
    }
    return f;
}

void listFoods::DanhSach(){
    cout<<setfill('-')<<setw(56)<<"-"<<endl;
    cout<<setfill(' ');
    cout<<setw(2)<<"||"<<left<<setw(5)<<" STT"<<setw(2)<<"|"<<left<<setw(30)<<" Ten mon"<<setw(5)<<"|"<<left<<setw(10)<<" Gia"<<setw(2)<<"||"<<endl;
    cout<<setfill('-')<<setw(56)<<"-"<<endl;
    cout<<setfill(' ');
    for(int i = 0;i<this->list.getLength();i++){
        cout<<setw(2)<<"||"<<left<<setw(2)<<" "<<setw(3)<<i + 1<<setw(2)<<"|"<<left<<setw(30)<<list[i].getTenMon()<<setw(5)<<"|"<<left<<setw(10)<<list[i].getGia()<<setw(2)<<"||"<<endl;
    }
    cout<<setfill('-')<<setw(56)<<"-"<<endl;
    cout<<setfill(' ');
}