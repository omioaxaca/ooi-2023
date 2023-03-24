// Clase de punteros
#include <stdio.h>
#include <iostream>

using namespace std;

int main (){

  // asignacion de direccion de memoria de la variable al puntero.

  // int numero = 20;
  // int* puntero;
  // puntero = &numero;
  // cout<<"valor en numero:"<<numero<<endl;
  // cout<<"valor del puntero:"<<puntero<<endl;  
  // cout<<"valor en puntero:"<<*puntero<<endl;  


  // int arreglo[5] = { 10, 20, 30, 40, 50 };
  // int* puntero;

  // // al ser un arreglo la asignacion al puntero se puede hacer directamente.
  // puntero = arreglo;

  // for (int i=0; i<5; i++) {

  //   cout<<"valor del puntero:"<<puntero<<endl;  
  //   cout<<"valor en elpuntero:"<<*puntero<<endl;  
  //   cout<<endl;

  //   puntero++;
  // }


  // inicializacion de un puntero C = NULL, CPP = NULLPTR.
  // Esta vacio? Esta apuntando a algo? Tiene un valor asignado?
  int* puntero = nullptr;
  cout<<"valor del puntero:"<<puntero<<endl;  
  cout<<"valor del puntero:"<<*puntero<<endl;  


  return 0;
}