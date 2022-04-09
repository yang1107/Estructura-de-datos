#include "fechahistorica.cpp"
#include "cronologia.cpp"
#include <fstream>
#include <iostream>

using namespace std;


bool load(Cronologia&  C, const string & s) {
 ifstream fe;
 string cadena;

 fe.open(s.c_str(), ifstream::in);

 if (fe.fail())
 {
   cerr << "Error al abrir el fichero " << s << endl;
 } else {
    while ( !fe.eof() )
      { getline(fe,cadena,'\n');
       	if (!fe.eof()) {
	  //cout << "leo:: "<< cadena << endl;
	  Fecha_Historica a;
	  a=cadena;

           C.addFechaHistorica(a);

         }

     }

    fe.close();
    return true;
    } // else
  fe.close();
  return false;
 }

 int main(){

   Cronologia algorithms,movies,science,worldhistory,prueba;
   load(algorithms,"./datos/timeline_algorithms.txt");
   load(movies,"./datos/timeline_movies.txt");
   load(science,"./datos/timeline_science.txt");
   load(worldhistory,"./datos/timeline_worldhistory.txt");
/*
   cout<<"mostrar la cronologia algorithms : "<<endl;
   algorithms.mostrarCronologia();
   cout<<endl;

   cout<<"mostrar la cronologia movies : "<<endl;
   movies.mostrarCronologia();
   cout<<endl;

   cout<<"mostrar la cronologia science : "<<endl;
   science.mostrarCronologia();
   cout<<endl;

   cout<<"mostrar la cronologia worldhistory : "<<endl;
   worldhistory.mostrarCronologia();
   cout<<endl;
*/

    //Funcionalidades de TDA FechaHistorica
    cout<<"============================================================================"<<endl;
    cout<<"Prueba de funcionalidades de TDA FechaHistorica"<<endl;
    Fecha_Historica fa;
    Fecha_Historica fb(2016,"prueba");
    string fprueba=("1994#prueba1#prueba2#prueba3#prueba4");
    Fecha_Historica fc;
    fc=fprueba;
    Fecha_Historica fcopia(fc);

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de los constructores"<<endl;
    cout<<endl;
    cout<<"fa------>";
    fa.mostrarFechaHistorica();
    cout<<"fb------>";
    fb.mostrarFechaHistorica();
    cout<<"fc------>";
    fc.mostrarFechaHistorica();
    cout<<"fcopia-->";
    fcopia.mostrarFechaHistorica();

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de la funcion aniadir un acontecimiento a una fecha historica"<<endl;
    cout<<endl;
    string addacon=("probando la funcion addAcon");

    fb.addAcon(addacon);
    fb.mostrarFechaHistorica();

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de la funcion eliminar un acontecimiento a una fecha historica"<<endl;
    cout<<endl;

    string acaeliminar=("prueba2");
    cout<<"fc antes de la eliminacion-->"<<endl;
    fc.mostrarFechaHistorica();
    cout<<endl;
    cout<<"fc despues de la eliminacion-->"<<endl;
    fc.eliminaAcon(acaeliminar);
    fc.mostrarFechaHistorica();

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de los operadores de comparacion"<<endl;
    cout<<endl;

    if(fb<fc){
      cout<<"fb es menor que fc"<<endl;
    }
    else{
      cout<<"fb no es menor que fc"<<endl;
    }

    if(fb>fc){
      cout<<"fb es mayor que fc"<<endl;
    }
    else{
      cout<<"fb no es mayor que fc"<<endl;
    }

    if(fc==fcopia){
      cout<<"fc es igual que fcopia"<<endl;
    }
    else{
      cout<<"fc no es igual que fcopia"<<endl;
    }

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de la funcion fusionar dos fechas historica"<<endl;
    cout<<endl;
    fcopia.addAcon("prueba fusion");
    fcopia.eliminaAcon("prueba4");
    cout<<"fusion de :"<<endl;
    fc.mostrarFechaHistorica();
    fcopia.mostrarFechaHistorica();
    cout<<endl;
    fc.fusionarFechas(fcopia);
    fc.mostrarFechaHistorica();
    cout<<endl;
    cout<<"fusion de :"<<endl;
    fc.mostrarFechaHistorica();
    fb.mostrarFechaHistorica();
    fc.fusionarFechas(fb);

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de la funciones de asignacion"<<endl;
    cout<<endl;
    vector<string> sasig=fc.getAcon();
    Fecha_Historica fasig;
    fasig.setAnio(2000);
    fasig.setActs(sasig);
    fasig.mostrarFechaHistorica();

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de la funciones de mostrar numero de acontecimientos"<<endl;
    cout<<endl;
    int numAcont=fasig.Nacont();
    cout<<"hay "<<numAcont<<" acontecimientos en el anio "<<fasig.getAnio()<<endl;



    //Funcionalidades de TDA Cronologia
    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"Prueba de funcionalidades de TDA Cronologia"<<endl;
    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de la funcion aniadir una fecha historica a una cronologia"<<endl;
    cout<<endl;
    cout<<"cronologia prueba antes de aniadir Fecha historica-->"<<endl;
    prueba.mostrarCronologia();
    prueba.addFechaHistorica(fb);
    prueba.addFechaHistorica(fc);
    Fecha_Historica fp(1994,"prueba1");
    fp.addAcon("prueba5");
    prueba.addFechaHistorica(fp);
    cout<<"fecha historica fc a aniadir--->"<<endl;
    fc.mostrarFechaHistorica();
    cout<<"fecha historica fp a aniadir--->"<<endl;
    fp.mostrarFechaHistorica();
    cout<<"despues de aniadir fecha historica-->"<<endl;
    prueba.mostrarCronologia();

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de la funcion obtener acontecimientos ocurridos entre dos fechas"<<endl;
    cout<<endl;
    cout<<"mostrar la subcronologia de movies(peliculas desde 2000 hasta 2006) : "<<endl;
    Cronologia obtenermovies=movies.obtenerAcontecimientos(2000,2006);
    obtenermovies.mostrarCronologia();

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de la funcion buscar acontecimientos mediante palabra clave"<<endl;
    cout<<endl;
    Cronologia buscarmovies=movies.buscarAcontecimientos("Star");
    buscarmovies.mostrarCronologia();

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de la funcion unir dos cronologias (buscarmovies con obtenermovies)"<<endl;
    cout<<endl;
    buscarmovies.unirCronologia(obtenermovies);
    buscarmovies.mostrarCronologia();

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de la funcion obtener acontecimientos ocurridos en un anio concreto"<<endl;
    cout<<endl;
    vector<string> acont=movies.getAcontecimiento(2015);
    for(unsigned int i=0;i<acont.size();i++){
      cout<<acont[i]<<endl;
    }

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de la funcion de asignacion de fechas historicas a una cronologia"<<endl;
    cout<<endl;
    vector<Fecha_Historica> vectorf;
    Cronologia croAsig;
    vectorf.push_back(fa);
    vectorf.push_back(fb);
    vectorf.push_back(fc);
    croAsig.setFech(vectorf);
    croAsig.mostrarCronologia();

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de la funciones de mostrar numero de fechas historicas"<<endl;
    cout<<endl;
    int nFechas=croAsig.Nfechas();
    cout<<"hay "<<nFechas<<" fechas historicas en la cronologia croAsig"<<endl;

    cout<<"============================================================================"<<endl;
    cout<<endl;
    cout<<"prueba de la funciones eliminar una fecha historica"<<endl;
    cout<<endl;
    croAsig.eliminaFechaHistorica(2016);
    cout<<"croAsig despues de eliminar los acontecimientos el anio 2016"<<endl;
    croAsig.mostrarCronologia();
    cout<<"============================================================================"<<endl;

 }
