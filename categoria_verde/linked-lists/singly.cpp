#include <iostream>

using namespace std;

class Node {
  public:
  // Valor de nuestro nodo
  int data;

  // Apuntador al siguiente nodo
  Node* next;

  // void imprimir() {
  //   cout<<"NumeroPrivado "<< NumeroPrivado << endl;
  // }
};

// Ej. ListaLigada: 1-2-3, nuevo valor:4  =   ListaLigada: 1-2-3-4
Node* agregarNuevoValorAlFinal(Node* listaLigada, int newData)


void iterarLista(Node* listaLigada) {
  Node* actual = listaLigada;

  while(actual != nullptr) {
    cout<<actual->data<<endl;
    actual = actual->next;
  }
}



int main() {

  // 1 -> 2 -> 3 ->

  Node val3 = Node();
  val3.data = 3;
  val3.next = nullptr;

  Node val2 = Node();
  val2.data = 2;
  val2.next = &val3;

  Node val1 = Node();
  val1.data = 1;
  val1.next = &val2;

  // LA LISTA LIGADA ES VAL1;

  iterarLista(&val1);

  return 0;
}