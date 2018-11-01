#include "rsa.h"
rsa::rsa(){
   /*p=GenPrime_ZZ(a);
    q=GenPrime_ZZ(a);
    n=p*q;
    phi=conv<ZZ>(((p-ZZ(1))*(q-ZZ(1))));
    e=generare(phi,a);
    d=inversa(modulo(phi,n),e);*/
    d=conv<ZZ>("9885");
    n=conv<ZZ>("35611");
    p=conv<ZZ>("239");
    q=conv<ZZ>("149");
}
rsa::rsa(ZZ e1,ZZ n1){
    e=e1;
    n=n1;
}
string rsa::cifrado(string mensaje){
    string result_aux;
    string tmp_1;
    string tmp_2;
    string tmp_3;
    vector <string> aux_1;
    vector <ZZ> aux_2;
    ZZ auxiliar;
    string byne=binario(e);
    tmp_2=ZZ_to_string(n);
     for(int i=0;i<mensaje.size();i++){
        tmp_1+=arreglar_1(alfabeto.find(mensaje[i]));
    }
    while(modulo(ZZ(tmp_1.size()),ZZ(tmp_2.size()-1))!=0){
        tmp_1+=ZZ_to_string(ZZ(alfabeto.find('W')));
    }
    int bloques=tmp_2.size()-1;
    for(int i=0;i<tmp_1.size();i++){
        tmp_3+=tmp_1[i];
        if(tmp_3.size()==bloques){
            aux_1.push_back(tmp_3);
            tmp_3="";
        }
    }
    for(int i=0;i<aux_1.size();i++){
        auxiliar=bynexpo(string_to_ZZ(aux_1[i]),byne,n);
        result_aux+=arreglar_2(auxiliar,n);
    }
    return result_aux;
}
string rsa::descifrado(string mensaje){
    string result_aux;
    string tmp_1;
    string tmp_2;
    string tmp_3;
    vector <string> aux_1;
    vector <ZZ> aux_2;
    ZZ auxiliar;
    string byne=binario(e);
    tmp_2=ZZ_to_string(n);
     for(int i=0;i<mensaje.size();i++){
        tmp_1+=arreglar_1(alfabeto.find(mensaje[i]));
    }
    while(modulo(ZZ(tmp_1.size()),ZZ(tmp_2.size()-1))!=0){
        tmp_1+=ZZ_to_string(ZZ(alfabeto.find('W')));
    }
    int bloques=tmp_2.size()-1;
    for(int i=0;i<tmp_1.size();i++){
        tmp_3+=tmp_1[i];
        if(tmp_3.size()==bloques){
            aux_1.push_back(tmp_3);
            tmp_3="";
        }
    }
    for(int i=0;i<aux_1.size();i++){
        auxiliar=bynexpo(string_to_ZZ(aux_1[i]),byne,n);
        result_aux+=arreglar_2(auxiliar,n);
    }
    return result_aux;
}
ZZ rsa::getd(){
    return d;
}
ZZ rsa::gete(){
    return e;
}
ZZ rsa::getn(){
    return phi;
}
