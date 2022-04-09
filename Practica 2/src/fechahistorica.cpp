#include<iostream>
#include "../include/fechahistorica.h"
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <sstream>

using namespace std;

//constructor por defecto
Fecha_Historica::Fecha_Historica(){
	anio=1;
	vector<string> acts;
}

//constructor
Fecha_Historica::Fecha_Historica(int a, string ac){
	if(checkIR(a)){
        anio=a;
        acts.push_back(ac);
	}
	else{
        cout<<"anio invalido, se le asignara el anio por defecto"<<endl;
	}
}

Fecha_Historica &Fecha_Historica::operator=(string  & s){
    int pos, ini, tam;
    string aux;

    pos=s.find("#");
		int a=std::stoi(s.substr(0,pos));
		if(checkIR(a)){
			anio=a;
		}
		else{
			cout<<"anio invalido, se le asignara el anio por defecto"<<endl;
		}

    while(s.find("#",pos+1)!= std::string::npos)
    {
        ini=pos;
        pos=s.find("#",pos+1);
        tam=pos-ini-1;
        aux=s.substr(ini+1,tam);
        this->addAcon(aux);

    };

        ini=pos;
        pos=s.find("#",pos+1);
        tam=pos-ini-1;
        aux=s.substr(ini+1,tam);
        this->addAcon(aux);

    return *this;


}

//constructor de copia
Fecha_Historica::Fecha_Historica(const Fecha_Historica &c){
	anio=c.anio;
	acts=c.acts;
}

//Asignacion
void Fecha_Historica::asignar(int a, vector<string> acs){
	if(checkIR(a)){
        anio=a;
        acts=acs;
	}
	else{
        cout<<"anio invalido, se le asignara el anio por defecto"<<endl;
	}
}

int Fecha_Historica::getAnio(){
	return anio;
}

vector<string> Fecha_Historica::getAcon(){
	return acts;
}

void Fecha_Historica::setAnio(int a){
	if(checkIR(a)){
		anio=a;
	}
	else{
		cout<<"anio invalido, se le asignara el anio por defecto"<<endl;
	}
}

void Fecha_Historica::setActs(vector<string> a){
	acts=a;
}

int Fecha_Historica::Nacont(){
		unsigned int n=acts.size();
    return n;
  }

void Fecha_Historica::addAcon(string ac){
    bool existe=false;
    for(unsigned int i=0;i<acts.size();i++){
        if(acts[i]==ac){
            existe=true;
        }
    }
    if(!existe){
        acts.push_back(ac);
    }
}

void Fecha_Historica::eliminaAcon(string ac){
    bool encontrado=false;
    unsigned int pos=0;
    while(pos<acts.size()&&!encontrado){
        if(acts[pos]==ac){
            encontrado=true;
        }
        else{
            pos++;
        }
    }
    acts.erase(acts.begin()+pos);
}

void Fecha_Historica::mostrarAcontecimientos(){
		vector<string> ac = this->getAcon();
    if(ac.size()>0){
        for(unsigned int i=0;i<ac.size();i++){
            cout<<"#"<<acts[i];
        }
        cout<<endl;
    }
    else{
        cout<<"no hay acontecimientos en este anio"<<endl;
    }
}

void Fecha_Historica::mostrarFechaHistorica(){
	cout<<"Anio: "<< this->getAnio()<<": ";
	this->mostrarAcontecimientos();
}

bool Fecha_Historica::checkIR(int a){
    bool valido=false;
    if(a>=0 && a<2018){
        valido=true;
    }
    return valido;
}

bool Fecha_Historica::operator<(Fecha_Historica  & f){
	/*bool res;
	if(this->getAnio() < f.getAnio()){
		res=true;
	}
	else{
		res=alse;
	}
	return res;*/
	return (this->getAnio()<f.getAnio());
}

bool Fecha_Historica::operator>(Fecha_Historica  & f){
	/*bool res;
	if(this->getAnio() > f.getAnio()){
		res=true;
	}
	else{
		res=false;
	}
	return res;*/
	return (this->getAnio()>f.getAnio());
}

bool Fecha_Historica::operator==(Fecha_Historica  & f){
	/*bool res;
	if(this->getAnio() == f.getAnio()){
		res=true;
	}
	else{
		res=false;
	}
	return res;*/
	return (this->getAnio()==f.getAnio());
}

void Fecha_Historica::fusionarFechas(Fecha_Historica f){
	if(this->getAnio() == f.getAnio()){
		for(unsigned int i=0;i<f.getAcon().size();i++){
			this->addAcon(f.getAcon()[i]);
		}
	}
	else{
		cout<<"los anios son distintos, no se puede fusionar."<<endl;
	}
}
