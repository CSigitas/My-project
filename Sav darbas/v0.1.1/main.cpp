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
    int nd[10];
    int egz;
    double gal;
    int k;
    //galutinis = 0.4 * vidurkis + 0.6 * egzaminas
   public:
   student(){
       vardas = "none";
       pavarde = "none";
       for(int i = 0 ;i<10;i++){
           nd[i] = 0;
       }
       egz = 0;

   }
   student(string vardas1 , string pavarde1 ,int nd1[10] , double egz1 , int k1 ){
       vardas = vardas1;
       pavarde = pavarde1;
       for(int i = 0 ; i<10 ; i++){
           nd[i] = nd1[i];
       }
       egz = egz1;
       k = k1;
   }
   //Copy constructor
   student(const student& other){
       vardas = other.vardas;
       pavarde = other.pavarde;
        for(int i = 0 ; i<10 ; i++){
           nd[i] = other.nd[i];
       }
       egz = other.egz;
       k = other.k;
   }
   //copy assignment operator
   student operator = (const student& other){
       return *this;  
   }
   //Destructor
   ~student() { delete[] this; }

    void ivestis(){
        int pazimys , kiekis = 0;
        cout<<"Iveskite varda"<<endl;
        cin>> vardas;
        cout<<"Iveskite pavarde"<<endl;
        cin>>pavarde;
        cout<<"Kiek turite namu darbu pazimiu (nuo 2 iki 10)?"<<endl;
        cin>>k;
        cout<<"Iveskite pazimius"<<endl;
        for(int i =0 ; i<11;i++){
            if(k == kiekis )break;
            else{
            cin>>pazimys;
            if(pazimys >=1 && pazimys <=10){
                nd[i] = pazimys;
                kiekis++;
            }else{
                cout<<"Klaida! Pazimys nuo 1 iki 10"<<endl;
            }
            }
        }
        cout<<"Egzamino balas" <<endl;
        cin>>egz;
    }
    double galutinisVid(){
        double gal=0;
        int count = 0;
        for(int i = 0 ; i<k ; i++){
            gal += nd[i];
            count++;
        }
        return  (0.4*(gal/count)) + (egz * 0.6);
    }
   double galutinisMed(){
       sort(nd, nd + k);
        if (k % 2 != 0)
        return (double)nd[k / 2];
 else{
    return (double)(nd[(k - 1) / 2] + nd[k / 2]) / 2.0;
 }
   }
   void print() {
        cout <<left<<setw(15)<<vardas<<left<<setw(15)<<pavarde<<left<<setw(19);
        cout<<setprecision(2)<<fixed<<galutinisVid();
        cout<<endl;
        }
};
int main(){
    cout<<"Kiek mokiniu noresite ivesti?"<<endl;
    int c;
    cin>>c;
    student st[c];
    for(int i = 0 ; i< c ; i++){
    st[i].ivestis();
    }
     cout<< "Vardas         Pavarde        Galutinis (Vid.)"<<endl;
        cout<< "-----------------------------------------------------------"<<endl;
    for(int i = 0 ; i< c ; i++){
    st[i].print();
    }
    return 0;
}