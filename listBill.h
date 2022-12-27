#pragma once
#include"Sample.h"

class listBill{
    List<Bill*> lBill;
    public:
        listBill();
        ~listBill();
        void QuanLy();
        List<Bill*> getListBill();
        Bill* TimKiemHoaDon(const string&);
        void ThemHoaDon();
        void QuanLyHoaDon();
        void DanhSachHoaDon();
        void DanhSachThongTinHoaDon();
        friend class Bill;
};

listBill::listBill(){}

listBill::~listBill(){}

void listBill:: QuanLy(){
    do
    {
        try
        {
            system("cls");
            cout<<"==========QUAN LY HOA DON=========="<<endl;
            cout<<"1. Them hoa don"<<endl;
            cout<<"2. Quan ly hoa don"<<endl;
            cout<<"3. Xem danh sach hoa don"<<endl;
            cout<<"0. Ket thuc"<<endl;
            int choice;
            cout<<"Vui long nhap lua chon: ";
            fflush(stdin);
            cin>>choice;
            if(cin.fail()){
                throw MyException("Nhap khong hop le!");
            }
            if(choice == 1){
                this->ThemHoaDon();

            }
            else if(choice == 2){
                this->QuanLyHoaDon();
            }
            else if(choice == 3){
                system("cls");
                cout<<"\t\t==========DANH SACH HOA DON==========\n"<<endl;
                this->DanhSachHoaDon();
                system("pause");
            }
            else if(choice == 0){
                break;
            }
            else{
                throw MyException("Nhap khong hop le!");
            }
        }
        catch(const MyException& e)
        {
            cout << e.what() << '\n';
            system("pause");
        }
        
    } while (true);
    
}

List<Bill*> listBill::getListBill(){
    return this->lBill;
}

//Them hoa don
void listBill::ThemHoaDon(){
    while (true)
    {
        system("cls");
        cout<<"=========THEM HOA DON========="<<endl;
        cout<<"1. Them hoa don tai cho"<<endl;
        cout<<"2. Them hoa don Online"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Vui long nhap lua chon: ";
        int choice;
        fflush(stdin);
        cin>>choice;
        if(cin.fail()){
            throw MyException("Nhap khong hop le!");
        }
        if(choice == 1){
            Bill *b = new BillTaiCho();
            b->QuanLy();
            if(b->getTinhTrang() == 0 && b->isEmpty() == 0){
                lBill.push(b);
            }
        }
        else if(choice == 2){
            Bill *b = new BillOnline();
            b->QuanLy();
            if(b->getTinhTrang() == 0 && b->isEmpty() == 0){
                lBill.push(b);
            }
        }
        else if(choice == 0) break;
        else{
            cout<<"Nhap khong hop le!"<<endl;
            system("pause");
        }
    }
}

//Tim kiem hoa don
Bill* listBill::TimKiemHoaDon(const string& str){
    static Bill *b = new Bill();
    for(int i = 0;i<this->lBill.getLength(); i++){
        if(lBill[i]->getMHD() == str) return lBill[i];
    }
    return b;
}

//Cap nhat hoa don
void listBill::QuanLyHoaDon(){
    while (true)
    {
        system("cls");
        cout<<"==========CAP NHAT HOA DON=========="<<endl;
        this->DanhSachThongTinHoaDon();
        cout<<setfill('-')<<setw(10)<<"-"<<endl;
        cout<<setfill(' ');
        cout<<setw(1)<<"|"<<"0. Thoat"<<setw(1)<<"|"<<endl;
        cout<<setfill('-')<<setw(10)<<"-"<<endl;
        cout<<setfill(' ');
        cout<<"Nhap ma hoa don muon cap nhat: ";
        string mhd;
        cin>>mhd;
        if(mhd == "0") return;
        if(this->TimKiemHoaDon(mhd)->isEmpty()){
            throw MyException("Ma hoa don khong hop le!");
        }
        this->TimKiemHoaDon(mhd)->QuanLy();
        if(this->TimKiemHoaDon(mhd)->isEmpty() || this->TimKiemHoaDon(mhd)->getTinhTrang() == 1) this->lBill.delAt(lBill.getIndex(this->TimKiemHoaDon(mhd)));
    }
    
}

//Danh sach hoa don
void listBill::DanhSachHoaDon(){
    if(lBill.is_Empty()){
        cout<<"Hien tai khong co hoa don nao!"<<endl;
        return;
    }
    for(int i = 0; i<lBill.getLength(); i++){
        lBill[i]->HoaDon();
        cout<<endl;
        cout<<setfill('*')<<setw(62)<<"*"<<endl;
	    cout<<setfill(' ');
    }
}

void listBill::DanhSachThongTinHoaDon(){
    if(lBill.is_Empty()){
        cout<<"Hien tai khong co hoa don nao!"<<endl;
        return;
    }
    cout<<left<<setw(5)<<"STT"<<left<<setw(15)<<"Ma hoa don"<<left<<setw(15)<<"Ma nhan vien"<<left<<setw(17)<<"Tong tien hoa don"<<endl;
    cout<<setfill('-')<<setw(52)<<"-"<<endl;
	cout<<setfill(' ');
    for(int i = 0; i<lBill.getLength(); i++){
        cout<<left<<setw(5)<<i + 1<<left<<setw(15)<<lBill[i]->getMHD()<<left<<setw(15)<<lBill[i]->getNhanVien()->getMaNV()<<left<<setw(17)<<lBill[i]->TongTienHD()<<endl;
    }
}