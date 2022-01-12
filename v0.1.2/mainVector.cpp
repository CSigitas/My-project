#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <time.h> 
using namespace std;
ofstream MyFile("filename.txt");
class student {
    string vardas,pavarde;
    vector<double> nd;
    int egz;
    double gal;
    int sk ,kuris;
    int count;
    public:
     student(){
       vardas = "none";
       pavarde = "none";
       egz = 0;
       count = 0;

   }
    student(string vardas1 , string pavarde1 ,vector<double> nd1 , double egz1 ,int count1 ,int kuris1){
       vardas = vardas1;
       pavarde = pavarde1;
       for(int i = 0 ; i<10 ; i++){
           nd = nd1;
       }
       egz = egz1;
       count = count1;
       kuris = kuris1;
   }
   //Copy constructor
   student(const student& other){
       vardas = other.vardas;
       pavarde = other.pavarde;
        for(int i = 0 ; i<10 ; i++){
           nd = other.nd;
       }
       egz = other.egz;
       count = other.count;
       kuris = other.kuris;
   }
   //copy assignment operator
   student operator = (const student& other){
       return *this;  
   }
   //Destructor
   ~student() { delete[] this; }

    void ivestis(){
        srand(time(NULL));
        cout << "Iveskite varda"<<endl;
        cin >> vardas;
        cout << "Iveskite pavarde"<<endl;
        cin >> pavarde;
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
    double galutinis(){
        return (0.4 * sk + 0.6 * egz);
    }
    double mediana(){

        sort(nd.begin(), nd.end());
            if (nd.size() % 2 != 0){
                return nd.at(nd.size()/2);
            }
            else{
                return (nd.at(nd.size()/2)+nd.at((nd.size()/2)-1))/2.0;
            }

    }
    void kursiokaiPrint(){
           cout<< "Vardas         Pavarde     ";
        for(int i = 0 ; i<nd.size();i++){
            if(i == nd.size()-1){
                cout<<"ND"<<i+1<<"    ";
            }else{
                cout<<"ND"<<i+1<<" ";
            }
        }
        cout<<"Egzaminas"<<endl;
    cout<< "-----------------------------------------------------------"<<endl;
        cout <<left<<setw(15)<<vardas<<left<<setw(12)<<pavarde;
        for(int i = 0 ; i<nd.size();i++){
            if(i == nd.size()-1){
                cout<<left<<setw(7)<<nd.at(i);
            }else{
             cout<<left<<setw(4)<<nd.at(i);
            }
        }
        cout<<setw(4)<<egz<<endl;

    }
    void print(){
        // MyFile <<vardas<<"    "<<pavarde<<"       ";
        // MyFile <<setprecision(2)<<fixed<<galutinis();
        // MyFile << endl;
        cout <<left<<setw(15)<<vardas<<left<<setw(15)<<pavarde<<left<<setw(19)<<setprecision(2)<<fixed<<galutinis();
        cout<<setprecision(2)<<fixed<<left<<setw(15)<<mediana()<<endl;
    }

};
int main(){
    // MyFile << "Vardas    Pavarde       Galutinis (Vid.)"<<endl;
    // MyFile << "-----------------------------------------------------------"<<endl;
    cout<<"Kiek mokiniu noresite ivesti?"<<endl;
    int c;
    cin>>c;
    student st[c];
    for(int i = 0 ; i< c ; i++){
    st[i].ivestis();
    }
     cout<< "Vardas         Pavarde        Galutinis (Vid.) / Galutinis (Med.)"<<endl;
        cout<< "-----------------------------------------------------------"<<endl;
    for(int i = 0 ; i< c ; i++){
    st[i].print();
    }
    return 0;
}