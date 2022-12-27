#pragma once
#include"listBill.h"
#include<string.h>

class QuanLy{
    private:
        string tenNhaHang;
        listNhanVien listNV;
        listBill list;
        listFoods lf;
        listDrinks ld;
    public:
        QuanLy();
        ~QuanLy();
        void Run();
        void DatHoaDon();
        void CapNhatNhaHang();
        void CapNhatTenNhaHang();
        //Cap nhat menu
        void CapNhatMenu();
        void CapNhatGia();
        void ThemMon();
        void XoaMon();
        //Quan ly nhan vien
        void QuanLyNhanVien();
        //Quan ly doanh thu
        long long TongDtTrongNgay();
        void DoanhThuTrongNgay();
        void LuuTongDoanhThu();
        void TongDoanhThu();
};

QuanLy::QuanLy(){
    ifstream file("TenNhaHang.txt");
    getline(file, this->tenNhaHang);
    file.close();
}

QuanLy::~QuanLy(){}

void QuanLy::Run(){
    do
    {
        try
        {
            system("cls");
            cout<<"\t======"<<strupr((char*)this->tenNhaHang.c_str())<<"========"<<endl;
            cout<<"1. Dat hoa don"<<endl;
            cout<<"2. Cap nhat nha hang"<<endl;
            cout<<"3. Quan ly nhan vien"<<endl;
            cout<<"4. Doanh thu trong ngay"<<endl;
            cout<<"5. Tong doanh thu"<<endl;
            cout<<"0. Thoat"<<endl;
            cout<<"Vui long nhap lua chon: ";
            int choice; fflush(stdin); cin>>choice;
            if(cin.fail()){
                throw MyException("Nhap khong hop le!");
            }
            if(choice == 1){
                this->DatHoaDon();
            }
            else if(choice == 2){
                this->CapNhatNhaHang();
            }
            else if(choice == 3){
                this->QuanLyNhanVien();
            }
            else if(choice == 4){
                this->DoanhThuTrongNgay();
            }
            else if(choice == 5){
                this->TongDoanhThu();
            }
            else if(choice == 0){
                this->LuuTongDoanhThu();
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

void QuanLy::DatHoaDon(){
    this->list.QuanLy();
}

void QuanLy::CapNhatNhaHang(){
    do
    {
        system("cls");
        cout<<"======CAP NHAT NHA HANG======="<<endl;
        cout<<"1. Cap nhat ten nha hang"<<endl;
        cout<<"2. Cap nhat Menu"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Vui long nhap lua chon: ";
        int choice;
        cin>>choice;
        if(choice == 1){
            this->CapNhatTenNhaHang();
        }
        else if(choice == 2){
            this->CapNhatMenu();
        }
        else if(choice == 0){
            break;
        }
        else{
            throw MyException("Nhap khong hop le!");
        }
    } while (true);
    
}

//Cap Nhat ten nha hang
void QuanLy::CapNhatTenNhaHang(){
    system("cls");
    cout<<"=====Cap nhat ten nha hang=====\n"<<endl;
    cout<<"Nhap ten nha hang: ";
    fflush(stdin);
    getline(cin, this->tenNhaHang);
    ofstream file("TenNhaHang.txt", ios::trunc);
    file<<this->tenNhaHang;
    file.close();
    cout<<"Cap nhat thanh cong!"<<endl;
    system("pause");
}

//Cap nhat gia ban
void QuanLy::CapNhatGia(){
    do
    {
        system("cls");
        cout<<"======CAP NHAT GIA BAN======"<<endl;
        cout<<"1. Cap nhat gia mon an"<<endl;
        cout<<"2. Cap nhat gia thuc uong"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Vui long nhap lua chon: ";
        int choice;
        cin>>choice;
        if(choice == 1){
            lf.CapNhatGiaBan();
        }
        else if(choice == 2){
            ld.CapNhatGiaBan();
        }
        else if(choice == 0){
            break;
        }
        else{
            throw MyException("Nhap khong hop le!");
        }
    } while (true);
    
}

//Them mon vao menu
void QuanLy::ThemMon(){
    do
    {
        system("cls");
        cout<<"======THEM MON======"<<endl;
        cout<<"1. Them thuc an"<<endl;
        cout<<"2. Them thuc uong"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Vui long nhap lua chon: ";
        int choice;
        cin>>choice;
        if(choice == 1){
            lf.ThemMonAn();
        }   
        else if(choice == 2){
            this->ld.ThemThucUong();
        }
        else if(choice == 0){
            break;
        }
        else{
            throw MyException("Nhap khong hop le!");
        }
    } while (true);
}

//Xoa mon khoi menu
void QuanLy::XoaMon(){
    do
    {
        system("cls");
        cout<<"======THEM MON======"<<endl;
        cout<<"1. Xoa thuc an"<<endl;
        cout<<"2. Xoa thuc uong"<<endl;
        cout<<"0. Thoat"<<endl;
        cout<<"Vui long nhap lua chon: ";
        int choice;
        cin>>choice;
        if(choice == 1){
            lf.XoaMonAn();
        }
        else if(choice == 2){
            ld.XoaThucUong();
        }
        else if(choice == 0){
            break;
        }
        else{
            throw MyException("Nhap khong hop le!");
        }
    } while (true);
}


//Cap nhat menu
void QuanLy::CapNhatMenu(){
    do
    {
        system("cls");
        cout<<"=====CAP NHAT MENU======"<<endl;
        cout<<"1. Cap nhat gia ban"<<endl;
        cout<<"2. Xoa mon khoi menu"<<endl;
        cout<<"3. Them mon vao menu"<<endl;
        cout<<"Vui long nhap lua chon: ";
        int choice;
        cin>>choice;
        if(choice == 1){
            this->CapNhatGia();
        }
        else if(choice == 2){
            this->XoaMon();
        }
        else if(choice == 3){
            this->ThemMon();
        }
        else if(choice == 0){
            break;
        }   
        else {
            throw MyException("Nhap khong hop le!");
        }
    } while (true);
    
}

//Quan ly nhan vien
void QuanLy::QuanLyNhanVien(){
    lNV.QuanLy();
}

//Doanh thu trong ngay
void QuanLy::DoanhThuTrongNgay(){
    system("cls");
    long long total = 0;
    cout<<"=======DOANH THU TRONG NGAY=======\n"<<endl;
    ifstream file("DoanhThuTrongNgay.txt");
    bool check = File_Is_Empty(file);
    if(check){
        cout<<date.localDate()<<endl;
        file.close();
        system("pause");
        return;
    }
    else{
        int day, mon, year;
        file>>day;
        file.ignore();
        file>>mon;
        file.ignore();
        file>>year;
        Date cd(day, mon, year);
        if(cd == date.localDate() == 0){
            file.clear();
            cout<<date.localDate()<<endl;
            system("pause");
            file.close();
            return;
        }
        else{
            cout<<setfill('-')<<setw(47)<<"-"<<endl;
            cout<<setfill(' ');
            cout<<left<<setw(15)<<"Ma hoa don"<<left<<setw(15)<<"Ma nhan vien"<<right<<setw(17)<<"Tong gia hoa don"<<endl;
            while (!file.eof())
            {
                string ss;
                file>>ss;
                cout<<left<<setw(15)<<ss;
                file>>ss;
                cout<<left<<setw(15)<<ss;
                int tien;
                file>>tien;
                total += tien;
                cout<<right<<setw(17)<<tien<<endl;
            }
            cout<<setfill('-')<<setw(47)<<"-"<<endl;
            cout<<setfill(' ');
            cout<<left<<setw(15)<<"TONG"<<right<<setw(32)<<total<<endl;
            file.close();
            system("pause");
        }
    }
}

long long QuanLy::TongDtTrongNgay(){
    ifstream file("DoanhThuTrongNgay.txt");
    long long total = 0;
    bool check = File_Is_Empty(file);
    if(check){
        return 0;
    }
    else{
        int day, mon, year;
        file>>day;
        file.ignore();
        file>>mon;
        file.ignore();
        file>>year;
        file.ignore();
        Date cd(day, mon, year);
        if(date.localDate() == cd){
            string ss;
            int dt;
            while (!file.eof())
            {
                file>>ss;
                file>>ss;
                file>>dt;
                total += dt;
            }
            return total;
        }
        else{
            return 0;
        }
    }
}

//Tong doanh thu

void QuanLy::LuuTongDoanhThu(){
    ifstream checkFile("DoanhThu.txt");
    bool check = File_Is_Empty(checkFile);
    Date cd;
    if(!check){
        int day, mon, year;
        checkFile>>day;
        cd.setDay(day);
        checkFile.ignore();
        checkFile>>mon;
        cd.setMonth(mon);
        checkFile.ignore();
        checkFile>>year;
        cd.setYear(year);
    }
    checkFile.close();
    fstream fileDT("DoanhThu.txt", ios::in | ios::out);
    if(check){
        fileDT<<date.localDate()<<" "<<this->TongDtTrongNgay();
        fileDT.close();
    }
    else{
        List<string> lines;
        string ss;
        if(cd == date.localDate()){
            getline(fileDT, ss);
            while (!fileDT.eof())
            {
                getline(fileDT, ss);
                lines.push(ss);
            }
            ofstream tmp("tmp.txt");
            tmp<<date.localDate()<<" "<<this->TongDtTrongNgay();
            for(int i = 0; i<lines.getLength(); i++){
                tmp<<"\n"<<lines[i];
            }
            fileDT.close();
            tmp.close();
            remove("DoanhThu.txt");
            rename("tmp.txt", "DoanhThu.txt");
        }
        else{
            while (!fileDT.eof())
            {
                getline(fileDT, ss);
                lines.push(ss);
            }
            ofstream tmp("tmp.txt");
            tmp<<date.localDate()<<" "<<this->TongDtTrongNgay();
            for(int i = 0; i<lines.getLength(); i++){
                tmp<<"\n"<<lines[i];
            }
            fileDT.close();
            tmp.close();
            remove("DoanhThu.txt");
            rename("tmp.txt", "DoanhThu.txt");
        }
    }
}

void QuanLy::TongDoanhThu(){
    this->LuuTongDoanhThu();
    system("cls");
    cout<<"========TONG DOANH THU==========\n"<<endl;
    ifstream file("DoanhThu.txt");
    long long total = 0;
    cout<<setfill('-')<<setw(40)<<"-"<<endl;
    cout<<setfill(' ');
    cout<<left<<setw(20)<<"Ngay"<<left<<setw(20)<<"Doanh thu trong ngay"<<endl;
    cout<<setfill('-')<<setw(40)<<"-"<<endl;
    cout<<setfill(' ');
    while (!file.eof())
    {
        string ngay;
        long long dt;
        file>>ngay;
        file>>dt;
        total += dt;
        cout<<left<<setw(20)<<ngay<<right<<setw(20)<<dt<<endl;
    }
    cout<<setfill('-')<<setw(40)<<"-"<<endl;
    cout<<setfill(' ');
    cout<<left<<setw(20)<<"TONG DOANH THU"<<right<<setw(20)<<total<<endl;
    file.close();
    system("pause");
}
