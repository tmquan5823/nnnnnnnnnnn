#pragma once
#include<fstream>
#include<string>
#include"NhanVien.h"
#include"Sample.h"

class listNhanVien{
    private:
        List<NhanVien*> listNV;
    public:
        listNhanVien();
        ~listNhanVien();
        void QuanLy();
        bool KiemTraNV(const string&);
        void CapNhatFileNV();
        void ThemNhanVien();
        NhanVien* TimKiemNhanVien(const string&);
        void XoaNhanVien();
        void CapNhatThongTin();
        void DanhSachNhanVien();
};

listNhanVien::listNhanVien(){
    ifstream fileNV("listNhanVien.txt");
    while (!fileNV.eof()){
        string manv;
        getline(fileNV, manv, '-');
        string ten;
        getline(fileNV, ten, '-');
        int tuoi;
        fileNV>>tuoi;
        fileNV.ignore();
        bool gt;
        fileNV>>gt;
        fileNV.ignore();
        string sdt;
        getline(fileNV, sdt, '-');
        string dc;
        getline(fileNV, dc);
        NhanVien *nv = new NhanVien(manv, ten, tuoi, gt, sdt, dc);
        listNV.push(nv);
    }
    fileNV.close();
}

listNhanVien::~listNhanVien(){
}

void listNhanVien::QuanLy(){
    system("cls");
    do
    {
        try
        {
            system("cls");
            cout<<"==========QUAN LY NHAN VIEN=========="<<endl;
            cout<<"1. Them nhan vien"<<endl;
            cout<<"2. Xoa Nhan Vien"<<endl;
            cout<<"3. Cap nhat thong tin nhan vien"<<endl;
            cout<<"4. Danh sach nhan vien"<<endl;
            cout<<"0. Thoat"<<endl;
            int choice;
            cout<<"Vui long nhap lua chon: ";
            cin>>choice;
            if(cin.fail()){
                throw MyException("Nhap khong hop le!");
            }
            if(choice == 1){
                this->ThemNhanVien();
            }
            else if(choice == 2){
                this->XoaNhanVien();
            }
            else if(choice == 3){
                this->CapNhatThongTin();
            }
            else if(choice == 4){
                system("cls");
                cout<<"\t\t\t=====DANH SACH NHAN VIEN=====\n"<<endl;
                this->DanhSachNhanVien();
                system("pause");
            }
            else if(choice == 0){
                break;
            }
            else throw MyException("Nhap khong hop le!");
        }
        catch(MyException& e)
        {
            cout << e.what() << '\n';
            system("pause");
        }
        
    } while (true); 
}

bool listNhanVien::KiemTraNV(const string& mnv){
    if(this->listNV.is_Empty()) return 0;
    for(int i = 0;i<this->listNV.getLength();i++){
        if(mnv == listNV[i]->getMaNV()) return 1;
    }
    return 0;
}

NhanVien* listNhanVien::TimKiemNhanVien(const string& mnv){
    static NhanVien *nv = new NhanVien;
    for(int i = 0;i<this->listNV.getLength();i++){
        if(mnv == listNV[i]->getMaNV()) return listNV[i];
    }
    return nv;
}

void listNhanVien::CapNhatFileNV(){
    ofstream file("listNhanVien.txt", ios::trunc);
    for(int i = 0;i<this->listNV.getLength() - 1; i++){
        file<<listNV[i]->getMaNV()<<"-"<<listNV[i]->getTen()<<"-"<<listNV[i]->getTuoi()<<"-"<<listNV[i]->getGT()<<"-"<<listNV[i]->getSDT()<<"-"<<listNV[i]->getDiaChi()<<endl;
    }
    file<<listNV[listNV.getLength() - 1]->getMaNV()<<"-"<<listNV[listNV.getLength() - 1]->getTen()<<"-"<<listNV[listNV.getLength() - 1]->getTuoi()<<"-"<<listNV[listNV.getLength() - 1]->getGT()<<"-"<<listNV[listNV.getLength() - 1]->getSDT()<<"-"<<listNV[listNV.getLength() - 1]->getDiaChi();
    file.close();
}

void listNhanVien::ThemNhanVien(){
    system("cls");
    cout<<"\t=====THEM NHAN VIEN======\n"<<endl;
    NhanVien *nv = new NhanVien;
    nv->Nhap();
    if(cin.fail()){
        throw MyException("Nhap khong hop le!");
    }
    else{
        ofstream file("listNhanVien.txt", ios::app);
        file<<"\n"<<nv->getMaNV()<<"-"<<nv->getTen()<<"-"<<nv->getTuoi()<<"-"<<nv->getGT()<<"-"<<nv->getSDT()<<"-"<<nv->getDiaChi();
        this->listNV.push(nv);
        cout<<"Them thanh cong!"<<endl;
        file.close();
        system("pause");
    }
}

void listNhanVien::XoaNhanVien(){
    system("cls");
    cout<<"=======XOA NHAN VIEN========"<<endl;
    this->DanhSachNhanVien();
    cout<<"Nhap ma nhan vien muon xoa: ";
    string mnv;
    cin>>mnv;
    if(!this->KiemTraNV(mnv)){
        throw MyException("Ma nhan vien khong hop le!");
    }
    else{
        this->TimKiemNhanVien(mnv)->Xuat();
        cout<<endl;
        cout<<"Dong y xoa nhan vien nay? (Y-Xoa, N-Huy): ";
        char c;
        cin>>c;
        if(c == 'n' || c=='N') return;
        else if(c=='Y' || c == 'y'){
            this->listNV.delAt(this->listNV.getIndex(this->TimKiemNhanVien(mnv)));
            this->CapNhatFileNV();
            cout<<"Xoa thanh cong!"<<endl;
            system("pause");
        }
        else{
            throw MyException("Nhap khong hop le!");
        }
    }
}

void listNhanVien::CapNhatThongTin(){
    system("cls");
    cout<<"=======CAP NHAT THONG TIN NHAN VIEN=========="<<endl;
    this->DanhSachNhanVien();
    cout<<"Nhap ma nhan vien muon cap nhat: ";
    string mnv;
    cin>>mnv;
    this->TimKiemNhanVien(mnv)->CapNhat();
    this->CapNhatFileNV();
    cout<<"Cap nhat thanh cong!";
    system("pause");
}

void listNhanVien::DanhSachNhanVien(){
    cout<<left<<setw(5)<<"STT"<<left<<setw(7)<<"MaNV"<<left<<setw(30)<<"Ho ten nhan vien"<<left<<setw(7)<<"Tuoi"<<left<<setw(15)<<"Gioi tinh"<<left<<setw(15)<<"So dien thoai"<<left<<setw(40)<<"Dia chi"<<endl;
    for(int i = 0;i<this->listNV.getLength();i++){
        cout<<left<<setw(5)<<i + 1;
        cout<<left<<setw(7)<<listNV[i]->getMaNV();
        cout<<left<<setw(30)<<listNV[i]->getTen();
        cout<<left<<setw(7)<<listNV[i]->getTuoi();
        if(listNV[i]->getGT()){
            cout<<left<<setw(15)<<"Nu";
        }
        else{
            cout<<left<<setw(15)<<"Nam";
        }
        cout<<left<<setw(15)<<listNV[i]->getSDT();
        cout<<left<<setw(40)<<listNV[i]->getDiaChi()<<endl;
    }
}