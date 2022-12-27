#pragma once
#include<iostream>
#include"listFoods.h"
#include"listDrinks.h"
#include<sstream>
#include"MyException.h"
#include"Date.h"
#include"listNhanVien.h"
using namespace std;

listNhanVien lNV;
listFoods lf;
listDrinks ld;
Date date;

class Bill {
    protected:
        int static id();
        string mahd;
        DoublyCircularLinkedList<Pair<order, int>> bill;
        bool tt; //true-da thanh toan, flase-chua thanh toan
        NhanVien *nv;
    public:
        Bill();
        virtual ~Bill();
        virtual string getMHD();
        virtual bool getTinhTrang();
        virtual NhanVien* getNhanVien();
        virtual bool isEmpty();
        virtual DoublyCircularLinkedList<Pair<order, int>> getBill();
        virtual void QuanLy();
        virtual void GoiMon();
        virtual void DatThucAn();
        virtual void DatThucUong();
        virtual void CapNhatHoaDon();
        virtual long long TongTienHD();
        virtual void HoaDon();
        virtual void XuatHoaDon();
        virtual void LuuDoanhThu();
        friend ostream& operator << (ostream&, Bill&);
        Bill& operator = (const Bill&);
};

bool File_Is_Empty(ifstream& pFile)
{
    return pFile.peek() == ifstream::traits_type::eof();
}

int Bill::id(){
    int id;
    ifstream checkFile("DoanhThuTrongNgay.txt");
    bool check = File_Is_Empty(checkFile);
    int count = 0;
    Date cd;
    int day, mon, year;
    if(!check){
        checkFile>>day;
        cd.setDay(day);
        checkFile.ignore(1);
        checkFile>>mon;
        cd.setMonth(mon);
        checkFile.ignore(1);
        checkFile>>year;
        cd.setYear(year);
        while(!checkFile.eof()){
        string ss;
        getline(checkFile, ss);
        count++;
        }
    }
    checkFile.close();
    if(!check){
        if(cd == date.localDate()){
            ifstream file("DoanhThuTrongNgay.txt");
            string ss;
            for(int i = 1;i<count;i++){
                getline(file, ss);
            }
            file>>ss;
            stringstream strs(ss.substr(6, 9));
            strs>>id;
            static int ID = id;
            return ++ID;
        }
        else{
            static int ID = 0;
            return ++ID;
        }
    }
    static int ID = 0;
    return ++ID;
}

Bill::Bill(){
    int ID = this->id();
    string ngay = to_string(date.localDate().getDay());
    if(ngay.length() == 1){
        ngay = "0" + ngay;
    }
    string thang = to_string(date.localDate().getMonth());
    if(thang.length() == 1){
        thang = "0" + thang;
    }
    string nam = to_string(date.localDate().getYear()).substr(2, 3);
    this->mahd = ngay + thang + nam + this->mahd.append(4 - to_string(ID).length(), '0') + to_string(ID);
}

Bill::~Bill(){}

string Bill::getMHD(){
    return this->mahd;
}

bool Bill::getTinhTrang(){
    return this->tt;
}

DoublyCircularLinkedList<Pair<order, int>> Bill::getBill(){
    return this->bill;
}

NhanVien* Bill::getNhanVien(){
    return this->nv;
}

bool Bill::isEmpty(){
    return this->bill.isEmpty();
}

void Bill::QuanLy(){
    system("cls");
    lNV.DanhSachNhanVien();
    cout<<setfill('-')<<setw(10)<<"-"<<endl;
    cout<<setfill(' ');
    cout<<setw(1)<<"|"<<"0. Thoat"<<setw(1)<<"|"<<endl;
    cout<<setfill('-')<<setw(10)<<"-"<<endl;
    cout<<setfill(' ');
    cout<<"Nhap ma nhan vien: ";
    string mnv;
    cin>>mnv;
    if(mnv.compare("0") == 0) return;
    if(!lNV.KiemTraNV(mnv)){
        throw MyException("Ma nhan vien khong hop le!");
    }
    this->nv = lNV.TimKiemNhanVien(mnv);
    this->tt = false;
    do
    {
        try
        {
            int choice;
            system("cls");
            cout << "\t\t ==========GOI MON==========" << endl;
            cout << "1. Goi mon" << endl;
            cout << "2. Cap nhat hoa don" << endl;
            cout << "3. Xem hoa don" << endl;
            cout << "4. Xuat hoa don" << endl;
            cout << "0. Thoat" << endl;
            cout << "Vui long nhap lua chon: ";
            fflush(stdin);
            cin >> choice;
            if(cin.fail()){
                throw MyException("Nhap khong hop le!");
            }
            if(choice ==  1){
                this->GoiMon();
            }
            else if(choice == 2){
                this->CapNhatHoaDon();
            }
            else if(choice == 3){
                system("cls");
                cout<<"\t\t============HOA DON============\n\n";
                this->HoaDon();
                system("pause");
            }
            else if(choice == 4){
                this->XuatHoaDon();
                this->LuuDoanhThu();
                break;
            }
            else if(choice == 0){
                break;
            }
            else {
                cout<<"Nhap khong hop le, vui long nhap lai!"<<endl;
                system("pause");
            }
        }   
        catch(const std::exception& e)
        {
            cout << e.what() << '\n';
        }
    }
    while (true);
}

void Bill::GoiMon(){
    while (true)
    {
        system("cls");
        cout<<"==========GOI MON=========="<<endl;
        cout<<"1. Dat thuc an"<<endl;
        cout<<"2. Dat thuc uong"<<endl;
        cout<<"0. Thoat"<<endl;
        int choice;
        cout<<"Vui long nhap lua chon: ";
        cin>>choice;
        if(choice == 1){
            this->DatThucAn();
        }
        else if(choice == 2){
            this->DatThucUong();
        }
        else if(choice == 0){
            break;
        }
        else {
            cout<<"Nhap khong hop le, vui long nhap lai!"<<endl;
            system("pause");
        }
    }
}

void Bill::DatThucAn(){
    while (true)
    {
        system("cls");
        cout<<"==========DAT THUC AN==========\n"<<endl;
        lf.DanhSach();
        cout<<"0. Thoat"<<endl;
        int goimon;
        Pair<order, int> tmp;
        cout<<"Vui long chon mon: ";
        cin>>goimon;
        if(goimon < 0 || goimon > lf.getSoLuong()){
            cout<<"Nhap khong hop le, vui long nhap lai!"<<endl;
            system("pause");
        }
        else if(goimon == 0) break;
        else{
            do{
                cout<<lf[goimon - 1];
                tmp.setFirst(lf[goimon - 1]);
                int sl;
                cout<<"\nNhap so luong mon: ";
                cin>>sl;
                tmp.setSecond(sl);
                int index = this->bill.getIndex(tmp);
                if(tmp.getSecond() < 0) {
                    bill.DelAt(index);
                    cout<<"Nhap khong hop le, vui long nhap lai!"<<endl;
                }
                if(this->bill.getIndex(tmp) == -1){
                    bill.AddLast(tmp);
                }
                else{                   
                    bill.DelAt(index);
                    bill.Insert(tmp, index);
                }
                if(tmp.getSecond() == 0) bill.DelAt(this->bill.getIndex(tmp));
            } 
            while (tmp.getSecond() < 0);      
            cout<<"Dat thanh cong!"<<endl; 
        }
    }
}

void Bill::DatThucUong(){
    while (true)
    {
        system("cls");
        cout<<"==========DAT THUC UONG==========\n"<<endl;
        ld.DanhSach();
        cout<<"0. Thoat"<<endl;
        int goimon;
        Pair<order, int> tmp;
        cout<<"Vui long chon mon: ";
        cin>>goimon;
        if(goimon < 0 || goimon > ld.getSoLuong()){
            cout<<"Nhap khong hop le, vui long nhap lai!"<<endl;
            system("pause");
        }
        else if(goimon == 0) break;
        else{
            do{
                cout<<ld[goimon - 1];
                tmp.setFirst(ld[goimon - 1]);
                int sl;
                cout<<"\nNhap so luong mon: ";
                cin>>sl;
                if(sl < 0){
                    throw MyException("Nhap so luong khong hop le!");
                }
                tmp.setSecond(sl);
                int index = this->bill.getIndex(tmp);
                if(index == -1){
                    bill.AddLast(tmp);
                }
                else{
                    bill.DelAt(index);
                    bill.Insert(tmp, index);
                }
                if(tmp.getSecond() == 0) bill.DelAt(this->bill.getIndex(tmp));
            } 
            while (tmp.getSecond() < 0);      
            cout<<"Dat thanh cong!"<<endl; 
        }
    }
}

void Bill::CapNhatHoaDon(){
    system("cls");
    cout<<"\t\t==========CAP NHAT HOA DON=========\n\n";
    this->HoaDon();
    cout<<setfill('-')<<setw(10)<<"-"<<endl;
    cout<<setfill(' ');
    cout<<setw(1)<<"|"<<"0. Thoat"<<setw(1)<<"|"<<endl;
    cout<<setfill('-')<<setw(10)<<"-"<<endl;
    cout<<setfill(' ');
    int choice;
    cout<<"Vui long chon mon muon cap nhat: ";
    cin>>choice;
    choice--;
    if(choice >= 0 && choice < bill.getLength()){
        cout<<bill[choice].getFirst()<<endl;
        cout<<"Nhap so luong mon muon chon: ";
        int sl;
        cin>>sl;
        if(sl<0){
            cout<<"Nhap khong hop le!"<<endl;
        }
        else{
            if(sl == 0){
                bill.DelAt(choice);
            }
            else{
                Pair<order, int> tmp;
                tmp.setFirst(bill[choice].getFirst());
                tmp.setSecond(sl);
                bill.DelAt(choice);
                bill.AddLast(tmp);
            }
        }
        cout<<"Cap nhat thanh cong!"<<endl;
        system("pause"); 
    }
}

void Bill::HoaDon(){
    cout<<right<<setw(62)<<date.localDate()<<endl;
    cout<<"Ma hoa Don: "<<this->mahd<<endl;
    cout<<left<<setw(14)<<"Ma nhan vien: "<<left<<setw(16)<<this->nv->getMaNV()<<right<<setw(18)<<"Ten Nhan Vien: "<<this->nv->getTen()<<endl;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    cout<<left<<setw(7)<<"STT"<<left<<setw(25)<<"Ten mon"<<left<<setw(10)<<"Gia"<<left<<setw(10)<<"So luong"<<left<<setw(10)<<"Thanh tien"<<endl;
    int i = 1;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    Node<Pair<order, int>> *tmp = this->bill.getStart();
    for(int i = 0; i<bill.getLength(); i++){
        cout<<left<<setw(7)<<i + 1<<left<<setw(25)<<tmp->data.getFirst().getTenMon()<<left<<setw(10)<<tmp->data.getFirst().getGia()<<left<<setw(10)<<tmp->data.getSecond()<<right<<setw(10)<<tmp->data.getFirst().getGia() * tmp->data.getSecond()<<endl;
        tmp = tmp->next;
    }
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    cout<<left<<setw(52)<<"TONG"<<right<<setw(10)<<this->TongTienHD()<<endl;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
}

long long Bill::TongTienHD(){
    long long total = 0;
    Node<Pair<order, int>> *tmp = this->bill.getStart();
    for(int i = 0;i<bill.getLength(); i++){
        total += (tmp->data.getFirst().getGia() * tmp->data.getSecond());
        tmp = tmp->next;
    }
    return total;
}

void Bill::XuatHoaDon(){
    ofstream billOut("Bill.txt");
    billOut.clear();
    billOut << "\n\t =====================HOA DON======================" << endl;
    billOut<<right<<setw(62)<<date.localDate()<<endl;
    billOut<<"Ma hoa Don: "<<this->mahd<<endl;
    billOut<<"Ma nhan vien: "<<this->nv->getMaNV()<<left<<setw(10)<<" "<<"Ten Nhan Vien: "<<this->nv->getTen()<<endl;
    billOut<<setfill('-')<<setw(62)<<"-"<<endl;
	billOut<<setfill(' ');
    billOut<<left<<setw(7)<<"STT"<<left<<setw(25)<<"Ten mon"<<left<<setw(10)<<"Gia"<<left<<setw(10)<<"So luong"<<left<<setw(10)<<"Thanh tien"<<endl;
    int i = 1;
    billOut<<setfill('-')<<setw(62)<<"-"<<endl;
	billOut<<setfill(' ');
    Node<Pair<order, int>> *tmp = this->bill.getStart();
    for(int i = 0;i < bill.getLength(); i++){
        billOut<<left<<setw(7)<<i + 1<<left<<setw(25)<<tmp->data.getFirst().getTenMon()<<left<<setw(10)<<tmp->data.getFirst().getGia()<<left<<setw(10)<<tmp->data.getSecond()<<right<<setw(10)<<tmp->data.getFirst().getGia() * tmp->data.getSecond()<<endl;
        tmp = tmp->next;
    }
    billOut<<setfill('-')<<setw(62)<<"-"<<endl;
	billOut<<setfill(' ');
    billOut<<left<<setw(52)<<"TONG"<<right<<setw(10)<<this->TongTienHD()<<endl;
    billOut<<"\n\t\t\t\t\t\tCam on quy khach!"<<endl;
    this->tt = true;
    cout<<"Xuat hoa don thanh cong!"<<endl;
    system("pause");
}

void Bill::LuuDoanhThu(){
    ifstream checkFile("DoanhThuTrongNgay.txt");
    bool check = File_Is_Empty(checkFile);
    int day, mon, year;
    checkFile>>day;
    checkFile.ignore(1);
    checkFile>>mon;
    checkFile.ignore(1);
    checkFile>>year;
    Date check_Date(day, mon, year);
    checkFile.close();
    ofstream file;
    if(check){
        file.open("DoanhThuTrongNgay.txt", ios::app);
        file<<date.localDate()<<endl;
        file<<this->mahd<<" "<<this->nv->getMaNV()<<" "<<this->TongTienHD();
    }
    else{
        cout<<check_Date<<endl;
        if(date.localDate() > check_Date){
            file.open("DoanhThuTrongNgay.txt", ios::trunc);
            file<<date.localDate()<<endl;
            file<<this->mahd<<" "<<this->nv->getMaNV()<<" "<<this->TongTienHD();
        }
        else{
            file.open("DoanhThuTrongNgay.txt", ios::app);
            file<<"\n"<<this->mahd<<" "<<this->nv->getMaNV()<<" "<<this->TongTienHD();
        }
    }
    file.close();
}


ostream& operator << (ostream& o, Bill& b){
    cout<<"Ma hoa Don: "<<b.mahd<<endl;
    // cout<<"Nhan vien: "<<b.nv<<endl;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    cout<<left<<setw(7)<<"STT"<<left<<setw(25)<<"Ten mon"<<left<<setw(10)<<"Gia"<<left<<setw(10)<<"So luong"<<left<<setw(10)<<"Thanh tien"<<endl;
    int i = 1;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    Node<Pair<order, int>> *tmp = b.bill.getStart();
    for(int i = 0;i<b.bill.getLength();i++){
        cout<<left<<setw(7)<<i + 1<<left<<setw(25)<<tmp->data.getFirst().getTenMon()<<left<<setw(10)<<tmp->data.getFirst().getGia()<<left<<setw(10)<<tmp->data.getSecond()<<right<<setw(10)<<tmp->data.getFirst().getGia() * tmp->data.getSecond()<<endl;
        tmp = tmp->next;
    }
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    cout<<left<<setw(52)<<"TONG"<<right<<setw(10)<<b.TongTienHD()<<endl;
}

Bill& Bill::operator = (const Bill& b){
    this->mahd = b.mahd;
    this->bill = b.bill;
    this->tt = b.tt;
    // this->nv = b.nv;
    return *(this);
}