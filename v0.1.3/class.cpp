#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <regex>
#include <time.h> 
#include "header.h"
ofstream MyFile("kursiokai.txt");
ofstream MyFile1("sarasas1.txt");
ofstream MyFile2("galutiniai.txt");

string student::getname() const{
    return vardas;
}
     student::student(){
       vardas = "none";
       pavarde = "none";
       egz = 0;
       count = 0;

   }
    student::student(string vardas1 , string pavarde1 ,vector<double> nd1 , double egz1 ){
        vardas = vardas1;
        pavarde = pavarde1;
        nd = nd1;
        egz = egz1;
   }
   //Copy constructor
   student::student(const student& other){
        vardas = other.vardas;
        pavarde = other.pavarde;
        nd = other.nd;
        egz = other.egz;
   }
   //copy assignment operator
   student& student::operator = (const student& other){
       return *this;  
   }

   //Destructor
   student::~student() { delete[] this; }
    void student::ivestis(){
        bool a= false;
        bool b= false;
        srand((unsigned)time(0));
        cout << "Iveskite varda"<<endl;
        cin >> vardas;
        try{
            a =regex_match(vardas, regex("^[A-Za-z]+$"));
            if(a ==0){
                throw 10;
            }
        }catch(int x){
            cout<<"Pavardeje negali buti skaiciu ar kitokiu simboliu"<<endl;
            cout << "Iveskite varda"<<endl;
            cin >> vardas;
        }
        cout << "Iveskite pavarde"<<endl;
        cin >> pavarde;
        try{
            b =regex_match(pavarde, regex("^[A-Za-z]+$"));
            if(b ==0){
                throw 11;
            }
        }catch(int y){
            cout<<"Varde negali buti skaiciu ar kitokiu simboliu"<<endl;
            cout << "Iveskite pavarde"<<endl;
        cin >> pavarde;
        }
       for(int i = 0 ;i<10;i++){
            cout<<"Kiek turite namu darbu pazimiu (nuo 2 iki 10)?"<<endl;
            cin>>count;
            if(count>=2 && count<=10)break;
            else{
                cout<<"Klaida!"<<endl;
            }
        }
        cout<<"Atsitiktiniu budu - 0 , Rankiniu budu surinkti balus - 1"<<endl;
            cin>>kuris;
        while(kuris!=0 && kuris!=1){
            cout<<"Klaida!"<<endl;
            cout<<"Atsitiktiniu budu - 0 , Rankiniu budu surinkti balus - 1"<<endl;
            cin>>kuris;
        }
        if(kuris == 0 ){
            if(nd.size()!=(count-1)){
                for(int i = 0 ;i<10;i++){
                    sk = rand()%10+1;
                if(sk<1 || sk>10){
                    nd.push_back(sk);
                cout<<"Klaida"<<endl;
                nd.pop_back();
                cout<<"iveskite skaicius is naujo"<<endl; 
            }
            else if(nd.size()==(count-1)){
                nd.push_back(sk);
                break;  
            }
            else{
                nd.push_back(sk);
            }
                }
            }
            egz = rand()%10+1;
        }
        else{
        cout<<"Iveskite pazimius!"<<endl;
            if(nd.size()!=(count-1)){
                for(int i = 0 ;i<10;i++){
                    cin>>sk;
                if(sk<1 || sk>10){
                    nd.push_back(sk);
                cout<<"Klaida"<<endl;
                nd.pop_back();
                cout<<"iveskite skaicius is naujo"<<endl; 
            }
            else if(nd.size()==(count-1)){
                nd.push_back(sk);
                break;  
            }
            else{
                nd.push_back(sk);
            }
                }
            }
            cout<<"Iveskite egzamino bala!"<<endl;
            cin>>egz;
        if(egz<1 || egz>10){
        while(egz<1 || egz>10){
            cout<<"iveskite skaicius is naujo"<<endl; 
            cin>>egz;
        }

        }
    }
        
    }
    void student::random(int g){
        vardas = "vardas"+to_string(g);
        pavarde = "pavarde"+to_string(g); 
        egz =rand()%10+1;
        for(int i = 0; i< 10; i++){
            sk = rand()%10+1;
            nd.push_back(sk);
        }
            MyFile <<left<<setw(15)<<vardas<<left<<setw(15)<<pavarde<<setw(11)<<egz;
                for(int i = 0 ; i<nd.size();i++){
            if(i == nd.size()-1){
                MyFile <<left<<setw(4)<<nd.at(i)<<endl;
            }else{
             MyFile <<left<<setw(4)<<nd.at(i);
            }
        }
    }
    double student::galutinis(){
        double sum=0;
        int a = 0;
        for(int i = 0 ; i< nd.size();i++){
            sum+=nd.at(i);
            a++;
        }
        return (0.4 * (sum/a)) +( 0.6 * egz);
    }
    double student::mediana(){

        sort(nd.begin(), nd.end());
            if (nd.size() % 2 != 0){
                return nd.at(nd.size()/2);
            }
            else{
                return (nd.at(nd.size()/2)+nd.at((nd.size()/2)-1))/2.0;
            }

    }
    void student::kursiokaiPrint(){
        MyFile <<left<<setw(15)<<vardas<<left<<setw(15)<<pavarde<<setw(11)<<egz;
        for(int i = 0 ; i<nd.size();i++){
            if(i == nd.size()-1){
                MyFile <<left<<setw(4)<<nd.at(i)<<endl;
            }else{
             MyFile <<left<<setw(4)<<nd.at(i);
            }
        }

    }
    void student::read(){
        fstream file;
        file.open("kursiokai.txt");
        string feilute,fzodziai;
        vector<string>text;
        int c = 0;
        if(!file){
            cout<<"Failas nesukurtas"<<endl;
        }
        if(file.is_open()){
            while(getline(file,feilute)){
                c++;
                if(c == 1){}
                else{
                    stringstream ss(feilute);
                    while(ss>>fzodziai){
                        text.push_back(fzodziai);
                    }
                    vardas=text.at(0);
                    pavarde=text.at(1);
                    for(int i = 2 ;i<13;i++){
                        nd.push_back(stoi(text.at(i)));
                    }
                        
                        MyFile1<<vardas<<" ";
                        MyFile1<<pavarde<<" ";
                            for(int j = 0 ;j<11;j++){
                      MyFile1<<nd.at(j)<<" ";
                      MyFile1<<endl;
                  }
                double sum=0;
                int a = 0;
                for(int i = 0 ; i< 11;i++){
                sum+=nd.at(i);
                a++;
                }
                MyFile2<<left<<setw(15)<<vardas<<left<<setw(15)<<pavarde<<left<<setw(19)<<setprecision(2)<<fixed<<(0.4 * (sum/a)) +( 0.6 * nd.at(10))<<endl;
                     text.clear();
                     nd.clear();
                }
            }
        }
              

    }
    void student::print(){
        cout <<left<<setw(15)<<vardas<<left<<setw(15)<<pavarde<<left<<setw(19)<<setprecision(2)<<fixed<<galutinis();
        cout<<setprecision(2)<<fixed<<left<<setw(15)<<mediana()<<endl;
    }
    void student::print1(){
        MyFile << "Vardas         Pavarde        Egzaminas  ";
        for(int i = 0 ; i<10;i++){
            if(i == 9)
            MyFile <<"ND"<<i+1<<endl;
            else{
                MyFile <<"ND"<<i+1<<" ";
            }
        }
        MyFile2<< "Vardas         Pavarde        Galutinis (Vid.)"<<endl;
    }