/**
  * @file Cronologia.h
  * @brief Fichero cabecera del TDA Cronologia
  *
  */

#ifndef __CRONOLOGIA
#define __CRONOLOGIA

#include <iostream>
#include <vector>
#include "fechahistorica.h"
#include <string>


using namespace std;

class Cronologia {

 private:
/**
  * @page repConjunto Rep del TDA Cronologia
  *
  * @section un objeto de la clase cronologia esta formado por un vector de Fecha_Historica
  *
  *  @section faConjunto Función de abstracción
  */

  vector<Fecha_Historica> fech; /**< vector de fecha historica */

 public:

/**
  * @brief Constructor por defecto de la clase.
  */
  Cronologia();

/**
  * @brief Constructor de la clase
  * @param f fecha historica de la cronologia que queremos construir
  * @return Crea el objeto cronologia
  */
  Cronologia(Fecha_Historica f);

/**
  * @brief Constructor de copias de la clase
  * @param c.fechas fecha historica de la cronologia a construir
  * @return devuelve una copia del objeto
  */
  Cronologia (const Cronologia& c);


/**
  * @brief obtiene todas las fechas de una cronologia con su acontecimientos
  * @return Devuelve las fechas de un objeto cronologia
  */
  vector<Fecha_Historica> getAllFechas();

  /**
    * @brief asigna las fechas historicas a una cronologia
    * @param f las fechas historicas a asignar
    * @return devuleve el objeto apuntado por this con las fechas asignadas
    */
  void setFech(vector<Fecha_Historica> f);

  /**
    * @brief obtiene los acontecimientos ocurrido en un anio concreto
    * @param anio anio de los acontecimientos que queremos buscar
    * @return devuelve un vector de string con los acontecimientos correspondientes
    */
  vector<string> getAcontecimiento(int anio);

  /**
    * @brief informa sobre numero de fechas historicas de una cronologia
    * @retun devuleve el numero de fechas historicas de una cronologia
    */
  int Nfechas();

  /**
    * @brief aniade una Fecha_Historica a un objeto de la clase cronologia
    * @param f la fecha historica que queremos aniadir al objeto cronologia
    * @return devuelve el objeto cronologia con la fecha historica aniadida
    * @post las fechas deben estar ordenadas
    */
  void addFechaHistorica(Fecha_Historica f);

  /**
    * @brief elimina una Fecha_Historica a un objeto de la clase
    * @param a el anio de la fecha historica que se va a eliminar
    * @return devuelve la cronologia con la fecha historica eliminada
    */
  void eliminaFechaHistorica(int a);


  /**
    * @brief dada una cronologia, muestra sus contenidos
    * @return muestra el contenido de un objeto cronologia con formato anio#acontecimientos
    */
  void mostrarCronologia();

  /**
    * @brief Obtener la (sub)cronologia de eventos historicos acaecidos en [anioDesde, anioHasta]
    * @param aini el inicio del periodo de anios que queremos buscar
    * @param afin el fin del periodo de anios que queremos buscar
    * @return devuelve un objeto cronologia con el resultado de la busquedad
    */
  Cronologia obtenerAcontecimientos(int aini, int afin);

  /**
    * @brief ordena las fechas historicas de un objeto cronologia
    * @return devuelve el objeto cronologia con las fechas ordenadas
    */
  void ordenarFechas();

  /**
    * @brief Obtener la (sub)cronologia de eventos historicos asociados a una palabra clave
    * @param s palabra clave que queremos buscar
    * @return devuelve un objeto cronologia con el resultado de la busquedad
    */
  Cronologia buscarAcontecimientos(string s);

  /**
    * @brief une dos objetos cronologia
    * @param c el objeto cronologia que queremos unir con el objeto apuntado por this
    * @return devuelve el objeto apuntado por this con los acontecimientos de la cronologia c
    */
  void unirCronologia(Cronologia c);



};

#endif
