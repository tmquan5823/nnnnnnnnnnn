#include"Date.h"
#include<string>
#include"MyException.h"

time_t now = time('\0');
tm *t = localtime(&now);
char *ch = asctime(t);

Date::Date(int d, int m, int y){
    this->day = d;
    this->month = m;
    this->year = y;
}

Date::Date(){
    this->day = 0;
    this->month = 0;
    this->year = 0;
}

Date::~Date(){}

Date Date::localDate(){
    Date d;
    d.day = t->tm_mday;
    d.month = t->tm_mon + 1;
    d.year = t->tm_year + 1900;
    return d;
}

int Date::getDay(){
    return this->day;
}

void Date::setDay(const int& ngay){
    this->day = ngay;
}

int Date::getMonth(){
    return this->month;
}

void Date::setMonth(const int& thang){
    this->month = thang;
}

int Date::getYear(){
    return this->year;
}

void Date::setYear(const int& nam){
    this->year = nam;
}

bool Date::isLeapYear(const int& y){
    if((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) 
        return true;
    else 
        return false;
}

int Date::monthDays(){
    switch (this->month)
    {
    case 1:
        return 31;
    case 2:
        if(this->isLeapYear(this->year))
            return 29;
        else return 28; 
    case 3:
        return 31;
    case 4:
        return 30;
    case 5:
        return 31;
    case 6:
        return 30;
    case 7:
        return 31;
    case 8:
        return 31;
    case 9:
        return 30;
    case 10:
        return 31;
    case 11:
        return 30;
    case 12:
        return 31;
    default:
        cout<<"Nhap thang khong hop le!"<<endl;
        break;
    }
}

void Date::nextDay(){
    if(month == 12){
        if(this->day != this->monthDays()){
            this->day ++;
        }
        else{
            this->day = 1;
            this->month = 1;
            this->year ++;
        }
    }
    else {
        if(this->day != this->monthDays()){
            this->day ++;
        }
        else {
            this->day = 1;
            this->month ++;
        }
    }
}

bool Date::operator> (const Date& date){
    if(this->day > date.day && this->month == date.month && this->year == date.year) return true;
    if(this->month > date.month && this->year == date.year) return true;
    if(this->year > date.year) return true;
    return false;
}

bool Date::operator>= (const Date& date){
    if(this->day >= date.day && this->month == date.month && this->year == date.year) return true;
    if(this->month > date.month && this->year == date.year) return true;
    if(this->year > date.year) return true;
    return false;
}

bool Date::operator< (const Date& date){
    if(this->day < date.day && this->month == date.month && this->year == date.year) return true;
    if(this->month < date.month && this->year == date.year) return true;
    if(this->year < date.year) return true;
    return false;
}

bool Date::operator<= (const Date& date){
    if(this->day <= date.day && this->month == date.month && this->year == date.year) return true;
    if(this->month < date.month && this->year == date.year) return true;
    if(this->year < date.year) return true;
    return false;
}

bool Date::operator == (const Date& date){
    if(this->day == date.day && this->month == date.month && this->year == date.year) return true;
    return false;
}

const Date& Date::operator = (const Date& date){
    this->day = date.day;
    this->month = date.month;
    this->year = date.year;
    return *(this);
}

istream& operator>>(istream &i, Date &date){
    i>>date.day>>date.month>>date.year;
    if(cin.fail() || date.day <= 0 || date.day > date.monthDays() || date.month <= 0 || date.month > 12 || date.year <= 0){
        throw MyException("Nhap ngay khong hop le!");
    }
    return i;
}

ostream& operator<<(ostream &o, const Date &date){
    string d = to_string(date.day) + "/" + to_string(date.month) + "/" + to_string(date.year);
    o<<d;
    return o;
}
