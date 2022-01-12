#include <iostream>
#include <ios>
#include "header.h"
int main(){
    srand (time(NULL));
    ofstream MyFile("kursiokai.txt");
    ofstream MyFile1("sarasas1.txt");
    ofstream MyFile2("galutiniai.txt");
    int c=100;
    student st[c];
    for(int i = 0 ; i<c;i++){
        if(i==0){
            st[i].print1();
            st[i].random(i+1);
        }else{
        st[i].random(i+1);
        }
    } 
    st[0].read(); 
    // for(int i = 0 ; i< c ; i++){
    // st[i].ivestis();
    // }
    //  cout<< "Vardas         Pavarde        Galutinis (Vid.) / Galutinis (Med.)"<<endl;
    //  cout<< "-----------------------------------------------------------"<<endl;
    // for(int i = 0 ; i< c ; i++){
    // st[i].kursiokaiPrint();
    // st[i].print();
    // }       
    MyFile1.close();
    MyFile.close();
    return 0;
}

