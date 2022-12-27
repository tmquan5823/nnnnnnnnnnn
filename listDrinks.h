#pragma once
#include"Sample.h"
#include<fstream>
#include<iomanip>
#include"MyException.h"

class listDrinks{
    private:
        List<drinks> list;    
        int soLuong;
    public:
        listDrinks();
        ~listDrinks();
        int getSoLuong() const;
        void CapNhatGiaBan();
        void ThemThucUong();
        void XoaThucUong();
        List<drinks> getList();
        order operator[](const int&);
        void DanhSach();
};

listDrinks::listDrinks(){
    this->soLuong = 0;
    //Doc file drinks
    ifstream fileDrinks;
    fileDrinks.open("drinks.txt", ios::in);
    fileDrinks.seekg(0, ios::beg);
    while(!fileDrinks.eof()){
        drinks d;
        string drink;
        getline(fileDrinks, drink);
        d.setTenMon(drink);
        int price;
        fileDrinks >> price;
        string s;
        getline(fileDrinks, s);
        d.setGia(price);
        d.setKT(true);
        this->soLuong++;
        this->list.push(d);
    }
    fileDrinks.close();
}

listDrinks::~listDrinks(){}

int listDrinks::getSoLuong() const{
    return this->soLuong;
}

void listDrinks::CapNhatGiaBan(){
    system("cls");
    cout<<"=====CAP NHAT GIA BAN THUC UONG======"<<endl;
    this->DanhSach();
    cout<<"Nhap so thu tu thuc uong muon cap nhat: ";
    int choice;
    cin>>choice;
    this->list[choice - 1].CapNhat();
    ofstream file("drinks.txt", ios::trunc);
    for(int i = 0;i<this->list.getLength() - 1;i++){
        file<<list[i].getTenMon()<<"\n"<<list[i].getGia()<<endl;
    }
    file<<list[list.getLength() - 1].getTenMon()<<"\n"<<list[list.getLength() - 1].getGia();
    file.close();
    cout<<"Cap nhat thanh cong!"<<endl;
}

void listDrinks::ThemThucUong(){
    system("cls");
    cout<<"=======THEM THUC UONG========="<<endl;
    this->DanhSach();
    cout<<"Nhap ten thuc uong: ";
    string name;
    fflush(stdin);
    getline(cin, name);
    cout<<"Nhap gia thuc uong: ";
    int price;
    cin>>price;
    drinks d(name, price);
    this->list.push(d);
    ofstream file("drinks.txt", ios::app);
    file<<"\n"<<d.getTenMon()<<"\n"<<d.getGia();
    file.close();
    system("cls");
    this->DanhSach();
    cout<<"Them thanh cong!"<<endl;
    system("pause");
}   

void listDrinks::XoaThucUong(){
    system("cls");
    cout<<"======XOA THUC UONG====="<<endl;
    this->DanhSach();
    cout<<"Nhap so thu tu thuc uong muon xoa: ";
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
            cout<<"!";
            ofstream file("drinks.txt", ios::trunc);
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
}


List<drinks> listDrinks::getList(){
    return this->list;
}

order listDrinks::operator[](const int& index){
    foods f;
    if(index >= 0 && index < this->soLuong){
        return list[index];
    }
    return f;
}

void listDrinks::DanhSach(){
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