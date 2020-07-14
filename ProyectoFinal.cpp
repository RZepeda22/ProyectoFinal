#include <iostream>
#include <string>

using namespace std;
const int longCad = 20;

struct costoPorArticulo{
  char nombreArticul[longCad + 1];
  int cantidad;
  float precio;
  float CostPorArticulo;
};

void ingresarDatos(costoPorArticulo Articulos[], int Articulo);
void imprimirPantalla(costoPorArticulo Articulos[], int Articulo);
void costoArticulo(costoPorArticulo Articulos[], int Articulo);
float costoTotal(costoPorArticulo Articulos[], int Entrada);
void listaCompraFinal(costoPorArticulo Articulos[], int Entrada);

int main(){
  int Entrada,Opcion,NumArticulo;
  float Total;
  cout << "Cantidad de articulos a comprar" << endl;
  cin >> Entrada;
  cout << "\n";
  costoPorArticulo Articulos[Entrada];
  cin.ignore();
  do{
    cout << "1.Ingresar datos de un articulo" << endl;
    cout << "2.Costo total por articulo" << endl;
    cout << "3.Mostrando informacion de un articulo" << endl;
    cout << "4.Salir"<< endl;
    cin >> Opcion;
    cout << "\n";
    switch(Opcion){
      case 1:
        cout << "Ingresa el numero del articulo que deseas editar" << endl;
        cin >> NumArticulo;
        ingresarDatos(Articulos,NumArticulo);
        costoArticulo(Articulos,NumArticulo);
        cout << "\n";
      break;
      case 2:
        cout << "Ingresa el numero del articulo que deseas calcular" << endl;
        cin >> NumArticulo;
        costoArticulo(Articulos,NumArticulo);
        cout << "\n";
      break;
      case 3:
        cout << "Ingresa el numero del articulo que deseas desplegar" << endl;
        cin >> NumArticulo;
        imprimirPantalla(Articulos,NumArticulo);
        cout << "\n";
      break;
      case 4:
        Opcion = 4;
      break;
    }
  }while(Opcion!=4);
    listaCompraFinal(Articulos,Entrada);
    Total = costoTotal(Articulos,Entrada);
    cout << "El costo total de la compra es: $" << Total <<  endl;
  return 0;
}

//Rellena la estructura
void ingresarDatos(costoPorArticulo Articulos[], int Articulo){
  cout << "Nombre del articulo: " << Articulo << endl;
  cin >> Articulos[Articulo-1].nombreArticul;
  cout << "Cantidad de unidades: " << endl;
  cin >> Articulos[Articulo-1].cantidad;
  cout << "Precio de la unidad: " << endl;
  cin >> Articulos[Articulo-1].precio;
}

//Calcula el costo de un articulo
void costoArticulo(costoPorArticulo Articulos[], int Articulo){
  Articulos[Articulo-1].CostPorArticulo=Articulos[Articulo-1].precio*Articulos[Articulo-1].cantidad;
  cout << "Costo de articulo: $" << Articulos[Articulo-1].CostPorArticulo <<  endl;

}

//Imprime los valores de un articulo
void imprimirPantalla(costoPorArticulo Articulos[], int Articulo){
      cout << "Articulo" << Articulo << endl;
      cout << "Nombre del articulo: " << Articulos[Articulo-1].nombreArticul << endl;
      cout << "Cantidad de unidades: " << Articulos[Articulo-1].cantidad << endl;
      cout << "Precio de la unidad: $" << Articulos[Articulo-1].precio << endl;
      cout << "Costo por articulo: $" << Articulos[Articulo-1].CostPorArticulo << endl;
    
}

//Imprime los valores de la compra final
void listaCompraFinal(costoPorArticulo Articulos[], int Entrada){
      for(int i=0;i<Entrada;i++){
      cout <<  Articulos[i].nombreArticul << " : " << Articulos[i].CostPorArticulo << endl;
    }
}

//Devuelve el costo total de la compra
float costoTotal(costoPorArticulo Articulos[], int Entrada){
    float Total;
    for(int i=0;i<Entrada;i++){
      Total = Total+Articulos[i].CostPorArticulo;
    }
    return Total;
}