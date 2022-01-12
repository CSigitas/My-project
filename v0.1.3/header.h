#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <regex>
#include <time.h>
#include <sstream> 
#ifndef _Enrollment_h_
#define _Enrollment_h_
using namespace std;
class student{
    string vardas,pavarde;
    vector<double> nd;
    int egz;
    double gal;
    int sk ,kuris;
    int count;
    public:
    student();
    student(string , string ,vector<double> , double );
    student(const student& other);
    student &operator = (const student& other);
    ~student();
    string getname() const;
    void ivestis();
    double galutinis();
    double mediana();
    void kursiokaiPrint();
    void print();
    void random(int g);
    void read();
    void print1();
}; 
#endif