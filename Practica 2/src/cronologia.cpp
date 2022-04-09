#include<iostream>
#include "../include/cronologia.h"
#include <string>

using namespace std;

//constructor por defecto
Cronologia::Cronologia(){
    vector<Fecha_Historica> fech;
}

Cronologia::Cronologia(Fecha_Historica f){
    fech.push_back(f);
}

Cronologia::Cronologia(const Cronologia& c){
    fech=c.fech;
}

vector<Fecha_Historica> Cronologia::getAllFechas(){
    return fech;
}

void Cronologia::setFech(vector<Fecha_Historica> f){
  fech=f;
}

int Cronologia::Nfechas(){
  int n=fech.size();
  return n;
}

void Cronologia::addFechaHistorica(Fecha_Historica f){
    int aniof=f.getAnio();
    bool existe=false;
    int pos;
    vector<Fecha_Historica> vf=this->getAllFechas();
    for(unsigned int i=0;i<vf.size();i++){
        if(vf[i].getAnio()==aniof && !existe){
            existe=true;
            pos=i;
        }
    }
    if(!existe){
        fech.push_back(f);
    }
    else{
        vector<string> tmp=f.getAcon();
        for(unsigned int j=0;j<tmp.size();j++){
            fech[pos].addAcon(tmp[j]);
        }
    }

    this->ordenarFechas();
}

void Cronologia::eliminaFechaHistorica(int a){
  int pos;
  bool existe=false;
  vector<Fecha_Historica> vf=this->getAllFechas();

  for(unsigned int i=0;i<vf.size();i++){
    if(a==vf[i].getAnio()){
      existe=true;
      pos=i;
    }
  }

  if(existe){
    fech.erase(fech.begin()+pos);
  }
  else{
    cout<<"no existe fecha historica con el anio "<<a<<endl;
  }

}

void Cronologia::mostrarCronologia(){
    vector<Fecha_Historica> vf=this->getAllFechas();
    for(unsigned int j=0;j<vf.size();j++){
        cout<<"Anio: "<<vf[j].getAnio()<<": ";
        vf[j].mostrarAcontecimientos();
    }
}



vector<string> Cronologia::getAcontecimiento(int anio){
    vector<Fecha_Historica> vf=this->getAllFechas();
    vector<string> ac;
    int pos=-1;
    for(unsigned int i=0;i<vf.size();i++){
        if(vf[i].getAnio()==anio){
            pos=i;
        }
    }
    if(pos!=-1){
        ac=vf[pos].getAcon();
    }

    return ac;
}

void Cronologia::ordenarFechas(){

    for(unsigned int i=1;i<fech.size();i++){
        for(unsigned int j=0;j<fech.size()-1;j++){
            if(fech[j].getAnio()>fech[j+1].getAnio()){
                Fecha_Historica tmp=fech[j];
                fech[j]=fech[j+1];
                fech[j+1]=tmp;
            }
        }
    }
}

Cronologia Cronologia::obtenerAcontecimientos(int aini, int afin){
    this->ordenarFechas();
    vector<Fecha_Historica> vf=this->getAllFechas();
    Cronologia tmp;
    for(unsigned int i=0;i<vf.size();i++){
        if(vf[i].getAnio()>=aini && vf[i].getAnio()<=afin){
            tmp.addFechaHistorica(vf[i]);
        }
    }

    return tmp;
}

Cronologia Cronologia::buscarAcontecimientos(string s){
    this->ordenarFechas();
    vector<Fecha_Historica> vf=this->getAllFechas();
    Cronologia tmp;
    vector<string> listaAcon;

    for(unsigned int i=0;i<vf.size();i++){
        for(unsigned int j=0;j<vf[i].getAcon().size();j++){
            if(vf[i].getAcon()[j].find(s)!= std::string::npos){ //vf[i].getAcon()[j].find(s) iterar sobre el acontecimientos de cada anio
                tmp.addFechaHistorica(vf[i]);
            }
        }
    }

    if(tmp.fech.size()==0){
        cout<<"no existe ningun acontecimiento relacionado con ("<< s <<")"<< endl;
    }

    return tmp;

}

void Cronologia::unirCronologia(Cronologia c){
    vector<Fecha_Historica> tmpc=c.getAllFechas();

    for(unsigned int i=0;i<tmpc.size();i++){
        this->addFechaHistorica(tmpc[i]);
    }

    this->ordenarFechas();
}
