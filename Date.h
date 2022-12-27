#pragma once
#include<iostream>
#include<ctime>
using namespace std;

class Date{
    private:
        int day;
        int month;
        int year;
    public:
        Date();
        Date(int, int, int);
        ~Date();
        int getDay();
        void setDay(const int&);
        int getMonth();
        void setMonth(const int&);
        int getYear();
        void setYear(const int&);
        bool isLeapYear(const int&);
        Date localDate();
        int monthDays();
        void nextDay();
        bool operator > (const Date&);
        bool operator >= (const Date&);
        bool operator < (const Date&);
        bool operator <= (const Date&);
        bool operator == (const Date&);
        const Date& operator = (const Date&);
        friend istream& operator>>(istream &i, Date&);
        friend ostream& operator<<(ostream &o, const Date&);
};