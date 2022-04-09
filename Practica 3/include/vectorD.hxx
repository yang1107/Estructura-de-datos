#include <cassert>
#include <algorithm>
#include <list>

//TO-DO: Completar la implementacion de los metodos de vectorD.h

//////////// constructores //////////////

template <class T>
vectorD<T>::vectorD(const  T  & t){
  n_ele = 0;
  v_nulo = t;
}

template <class T>
vectorD<T>::vectorD(const vectorD<T> & b){

  n_ele=b.n_ele;
  v_nulo=b.v_nulo;
  vd=b.vd;

}




template <class T>
vectorD<T>::vectorD(int numcomp, const  T  & t){

  if(numcomp>=0){
    n_ele=numcomp;
    v_nulo = t;

  }
  else{
    cout<<"numcomp debe ser mayor o igual que 0"<<endl;
  }


}


  ////////////// destructor ////////////

template <class T>
vectorD<T>::~vectorD(){
  vd.~list();
}


/////////// Consultores ////////////

template <class T>
typename vectorD<T>::size_type vectorD<T>::size() const{

  return this->n_ele;
}

template <class T>
T vectorD<T>::default_value( ) const{
     return this->v_nulo;
}

template <class T>
bool vectorD<T>::empty(){
     bool vacio=false;
     if(n_ele==0){
          vacio=true;
     }

     return vacio;
}

////////  MODIFICADORES //////////////////////

template <class T>
void vectorD<T>::set(int p, const T & t){

  typename list< pair<int, T > >::iterator it=vd.begin();
  pair<int,T> tmp(p,t);

  if((*it).first==p){
    (*it).second=t;
  }
  else if((*it).first>p){
    vd.push_front(tmp);
  }
  else if((*it).first<p){
    while((*it).first<p){
      it++;
    }
    vd.insert(it,tmp);
  }
}


//push_back
template <class T>
void vectorD<T>::push_back(const T & t){
  if(t==0){
    n_ele=n_ele+1;
  }
  else{
    pair<int, T> tmp(n_ele,t);
    vd.push_back(tmp);
    n_ele=n_ele+1;
  }
}


//pop_back
template <class T>
void vectorD<T>::pop_back(){
  typename list< pair<int, T > >::iterator it=vd.end();
  it--;
  if((*it).first==n_ele){
    vd.pop_back();
    n_ele=n_ele-1;
  }
  else{
    n_ele=n_ele-1;
  }
}


//clear

template <class T>
void vectorD<T>::clear(){
  vd.clear();
  n_ele=0;
}


template <class T>
void vectorD<T>::resize(int s){
    if(s<n_ele){
        typename list< pair<int, T > >::iterator it;
        for(it=vd.begin();it!=vd.end();it++){
            if((*it).first>s){
                vd.erase(it);
            }
        }
    }

    n_ele=s;
}

/////////////// operadores ///////////////////

//operator=

template <class T>
vectorD<T> & vectorD<T>::operator= (const vectorD<T> & x){
    n_ele=x.n_ele;
    v_nulo=x.v_nulo;
    vd=x.vd;

    return *this;
}


//operator[]
template <class T>
const T & vectorD<T>::operator[](int c) const{

        typename list< pair<int, T > >::const_iterator it;
        static T res;
        bool existe=false;

        for(it=vd.begin();it!=vd.end() && !existe;it++){
            if((*it).first==c){
            existe=true;
            res=(*it).second;
            }
        }

        if(!existe){
            res=v_nulo;
        }

        return res;
}




//operator==
template <class T>
bool vectorD<T>::operator==(const vectorD<T> & x){
  bool iguales=true;
  typename list< pair<int, T > >::const_iterator it;
  typename list< pair<int, T > >::const_iterator itx;

  if(this->n_ele==x.n_ele){
    for(it=vd.begin();it!=vd.end();it++){
      if((*it)!=(*itx)){
        iguales=false;
      }
    }
  }
  else{
    iguales=false;
  }

  return iguales;
}

//operator!=
template <class T>
bool vectorD<T>::operator!=(const vectorD<T> & x){
  return !(*this==x);
}


/////////////// iteradores ///////////////////

//begin

template <class T>
typename vectorD<T>::iterator vectorD<T>::begin(){
     vectorD<T>::iterator salida;
     salida.el_vect=this;
     salida.ite_rep=vd.begin();
     salida.i_vect=0;

     return salida;

}

//end

template <class T>
typename vectorD<T>::iterator vectorD<T>::end(){
     vectorD<T>::iterator salida;
     salida.el_vect=this;
     salida.ite_rep=vd.end();
     salida.i_vect=n_ele;

     return salida;
}



//sbegin
template <class T>
typename vectorD<T>::stored_iterator vectorD<T>::sbegin(){
    vectorD<T>::stored_iterator salida;
    salida.ite=vd.begin();

    return salida;
}


//send
template <class T>
typename vectorD<T>::stored_iterator vectorD<T>::send(){
    vectorD<T>::stored_iterator salida;
    salida.ite=vd.end();

    return salida;
}



template <class T>
vectorD<T>::iterator::iterator(){

}

template <class T>
vectorD<T>::iterator::iterator(const iterator & d){
    i_vect=d.i_vect;
    ite_rep=d.ite_rep;
    el_vect=d.el_vect;
}

template <class T>
const T & vectorD<T>::iterator::operator *(){
    T sal=el_vect->v_nulo;;
    if(i_vect==(*ite_rep).first){
        sal=(*ite_rep).second;
        ite_rep++;
    }

    return sal;
}


template <class T>
typename vectorD<T>::iterator & vectorD<T>::iterator::operator++() {
    ++i_vect;
    return *this;
}


template <class T>
typename vectorD<T>::iterator vectorD<T>::iterator::operator++(int ){
    iterator tmp(*this);
    ++i_vect;
    return tmp;
}



template <class T>
bool vectorD<T>::iterator::operator == (const iterator & d){
    bool igual=true;
    if(i_vect!=d.i_vect || (*ite_rep).first!=(*d.ite_rep).first || el_vect!=d.el_vect){
        igual=false;
    }

    return igual;

}


template <class T>
bool vectorD<T>::iterator::operator != (const iterator & d){

    return !(*this==d);
}

template <class T>
typename vectorD<T>::iterator & vectorD<T>::iterator::operator=(const iterator & d){
    i_vect=d.i_vect;
    ite_rep=d.ite_rep;
    el_vect=d.el_vect;

    return *this;
}




  template <class T>
  int vectorD<T>::checkRepFails(){
    int res=0;

    if(0>vd.size() || vd.size()>n_ele){
        res=1;
    }

    if(res=0){
        for(unsigned int i=0;i<vd.size();i++){
            if(vd[i]==v_nulo){
                res=2;
            }
        }
    }

    if(res=0){
        for(unsigned int i=0;i<vd.size();i++){
            if(vd[i].first<0){
                res=3;
            }
        }
    }

    if(res=0){
        for(unsigned int i=0;i<vd.size();i++){
            for(unsigned int j=i+1;j<vd.siez();j++){
                if(vd[i].first>vd[j].first){
                    res=4;
                }
            }
        }
    }

    return res;
  }
