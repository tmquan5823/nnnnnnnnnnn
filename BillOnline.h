#pragma once
#include"Bill.h"
#include"KhachHang.h"

class BillOnline : public Bill{

        KhachHang kh;
    public:
        BillOnline();
        ~BillOnline();
        void QuanLy();
        long long TongTienHD();
        void HoaDon();
        void XuatHoaDon();
        friend ostream& operator << (ostream&, BillOnline&);
};  

BillOnline::BillOnline(){}

BillOnline::~BillOnline(){}

void BillOnline::QuanLy(){
    system("cls");
    lNV.DanhSachNhanVien();
    cout<<"Nhap ma nhan vien: ";
    string mnv;
    cin>>mnv;
    if(!lNV.KiemTraNV(mnv)){
        throw MyException("Ma nhan vien khong hop le!");
    }
    this->nv = lNV.TimKiemNhanVien(mnv);
    this->tt = false;
    kh.Nhap();
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

long long BillOnline::TongTienHD(){
    long long total = 0;
    Node<Pair<order, int>> *tmp = this->bill.getStart();
    for(int i = 0;i<bill.getLength(); i++){
        total += (tmp->data.getFirst().getGia() * tmp->data.getSecond());
        tmp = tmp->next;
    }
    return total + 15000;
}

void BillOnline::HoaDon(){
    cout<<right<<setw(62)<<date.localDate()<<endl;
    cout<<"Ma hoa Don: "<<this->mahd<<endl;
    cout<<"Ten khach hang: "<<this->kh.getTen()<<endl;
    cout<<"Dia chi giao hang: "<<this->kh.getDiaChi()<<endl;
    cout<<"Ma nhan vien: "<<this->nv->getMaNV()<<left<<setw(10)<<" "<<"Ten Nhan Vien: "<<this->nv->getTen()<<endl;
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
    cout<<left<<setw(52)<<"Tong gia mon an"<<right<<setw(10)<<Bill::TongTienHD()<<endl;
    cout<<left<<setw(52)<<"Phi ship"<<right<<setw(10)<<15000<<endl;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    cout<<left<<setw(52)<<"TONG"<<right<<setw(10)<<this->TongTienHD()<<endl;
}

void BillOnline::XuatHoaDon(){
    ofstream billOut("Bill.txt");
    billOut.clear();
    billOut << "\n\t =====================HOA DON======================" << endl;
    billOut<<right<<setw(62)<<date.localDate()<<endl;
    billOut<<"Ma hoa Don: "<<this->mahd<<endl;
    billOut<<"Ten khach hang: "<<this->kh.getTen()<<endl;
    billOut<<"Dia chi giao hang: "<<this->kh.getDiaChi()<<endl;
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
    billOut<<left<<setw(52)<<"Tong gia mon an"<<right<<setw(10)<<Bill::TongTienHD()<<endl;
    billOut<<left<<setw(52)<<"Phi ship"<<right<<setw(10)<<15000<<endl;
    billOut<<setfill('-')<<setw(62)<<"-"<<endl;
	billOut<<setfill(' ');
    billOut<<left<<setw(52)<<"TONG"<<right<<setw(10)<<this->TongTienHD()<<endl;
    billOut<<"\n\t\t\t\t\t\tCam on quy khach!"<<endl;
    this->tt = true;
    cout<<"Xuat hoa don thanh cong!"<<endl;
    system("pause");
}

ostream& operator << (ostream& o, BillOnline& b){
    cout<<"Ma hoa Don: "<<b.mahd<<endl;
    // cout<<"Nhan vien: "<<b.nv<<endl;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    cout<<left<<setw(7)<<"STT"<<left<<setw(25)<<"Ten mon"<<left<<setw(10)<<"Gia"<<left<<setw(10)<<"So luong"<<left<<setw(10)<<"Thanh tien"<<endl;
    int i = 1;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    Node<Pair<order, int>> *tmp = b.bill.getStart();
    long long total = 0;
    for(int i = 0;i<b.bill.getLength();i++){
        cout<<left<<setw(7)<<i + 1<<left<<setw(25)<<tmp->data.getFirst().getTenMon()<<left<<setw(10)<<tmp->data.getFirst().getGia()<<left<<setw(10)<<tmp->data.getSecond()<<right<<setw(10)<<tmp->data.getFirst().getGia() * tmp->data.getSecond()<<endl;
        total += tmp->data.getFirst().getGia() * tmp->data.getSecond();
        tmp = tmp->next;
    }
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    cout<<left<<setw(52)<<"Tong gia mon an"<<right<<setw(10)<<total<<endl;
    cout<<left<<setw(52)<<"Phi ship"<<right<<setw(10)<<15000<<endl;
    cout<<setfill('-')<<setw(62)<<"-"<<endl;
	cout<<setfill(' ');
    cout<<left<<setw(52)<<"TONG"<<right<<setw(10)<<total + 15000<<endl;
}