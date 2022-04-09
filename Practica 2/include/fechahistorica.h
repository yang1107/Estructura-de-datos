/**
  * @file fechahistorica.h
  * @brief Fichero cabecera del TDA Fecha_Hostorica
  *
  */

#ifndef __FECHAHISTORICA
#define __FECHAHISTORICA

#include <iostream>
#include <vector>


using namespace std;

class Fecha_Historica {

 private:
/**
  * @page repConjunto Rep del TDA Fecha_Historica
  *
  * @section invConjunto Invariante de la representación
  *
  * El invariante es \e rep.anio>0 && anio <2018
  *
  * @section faConjunto Función de abstracción
  *
  */

  int anio; /**< Fecha */
  vector<string> acts; /**< vector de acontecimientos */

  //friend ostream& operator<< ( ostream& os, const Fecha_Historica& f);

 public:

/**
  * @brief Constructor por defecto de la clase. Crea la fecha historica con anio 1 y ningun acontecimiento asociado.
  */
  Fecha_Historica();

/**
  * @brief Constructor de la clase
  * @param a fecha de la fecha historica a construir
  * @param ac acontecimiento de la fecha historica a construir
  * @return Crea la fecha historica
  * @pre anio debe ser mayor que cero y menor que 2018
  */
  Fecha_Historica(int a, string ac);

/**
  * @brief Constructor de copias de la clase
  * @param c.anio fecha de la fecha historica a construir
  * @param c.acts acontecimientos de la fecha historica a construir
  */
  Fecha_Historica (const Fecha_Historica& c);

/**
  * @brief constructor de clase, construye un objeto de la clase a partir de un string
  * @param s string a partir de la cual se construye el objeto de la clase
  * @return crea un objeto de la fecha historica con datos correspondientes
  * @pre anio debe ser mayor que cero y menor que 2018
  */
  Fecha_Historica &operator=(string  & s);

/**
  * @brief Asignación de una fecha historica
  * @param a fecha de la fecha historica a construir
  * @param acs acontecimientos de la fecha historica a construir
  * @return Asigna al objeto implícito la fecha historica
  * @pre anio debe ser mayor que cero y menor que 2018
  */
  void asignar(int a, vector<string> acs);

/**
  * @brief obtiene el anio de una fecha historica
  * @return Devuelve el anio de una fecha historica
  */
  int getAnio();

  /**
  * @brief obtiene los acontecimientos de una fecha historica
  * @return Devuelve los acontecimientos de una fecha historica
  */
  vector<string> getAcon();

  /**
    * @brief asigna el anio a un objeto de la clase
    * @param a anio que vamos a asignar al objeto de la clase
    * @return devuleve el objeto con el anio asignado
    */
  void setAnio(int a);

  /**
    * @brief asigna los acontecimientos a un objeto de la clase
    * @param a acontecimientos que vamos a asignar al objeto de la clase
    * @return devuleve el objeto con los acontecimientos asignados
    */
  void setActs(vector<string> a);

  /**
    * @brief informa sobre el numero de acontecimientos asociados a un anio
    * @return devuleve el numero de acontecimientos
    */
  int Nacont();

  /**
    *@brief addAcon
    *@param ac acontecimiento de la fecha historica a aniadir en el caso de que el nuevo acontecimiento no se encuentre ya en la lista
    *@return devuelve el objeto aniadiendo el acontecimiento al final de la lista de los acontecimientos
    */
  void addAcon(string ac);

  /**
    *@brief elimina un acontecimiento de una fecha historica
    *@param ac acontecimiento a eliminar
    *@return devuelve la lista de acontecimientos moificado.
    */
  void eliminaAcon(string ac);

  /**
    * @brief dada una fecha historica muestra todos sus acontecimientos
    * @return muestra los acontecimientos asociados a una fecha concreto.
    */
  void mostrarAcontecimientos();

  /**
    * @brief dada una fecha historica muestra sus contenidos
    * @return muestra el anio y los acontecimientos asociados a una fecha historica concreto
    */
  void mostrarFechaHistorica();

  /**
    * @invariante de la representacion
    * @parm a anio del objeto fecha historica
    * @return false si a<0 || a>2018
    */
  bool checkIR(int a);

  /**
    * @brief operador de comparacion <
    * @param f fecha historia al que se compara con el objeto apuntado por this
    * @return true si el anio del objeto apuntaddo por this es menor que de f, falso si es mayor
    */
  bool operator<(Fecha_Historica  & f);

  /**
    * @brief operador de comparacion >
    * @param f fecha historia al que se compara con el objeto apuntado por this
    * @return true si el anio del objeto apuntaddo por this es mayor que de f, falso si es menor
    */
  bool operator>(Fecha_Historica  & f);

  /**
    * @brief operador de comparacion ==
    * @param f fecha historia al que se compara con el objeto apuntado por this
    * @return true si el anio del objeto apuntaddo por this es igual que de f, falso si no es igual
    */
  bool operator==(Fecha_Historica  & f);

  /**
    * @brief union de dos fechas historicas
    * @param f fecha historica a la que se fusiona con el objeto apuntado por this
    * @return fecha historica fusionado
    * @los anios tienen que ser iguales
    */
  void fusionarFechas(Fecha_Historica f);

};

#endif
