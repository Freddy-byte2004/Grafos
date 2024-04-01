#include <iostream>
#include "grafos.h"
#include<stdlib.h>
#include<vector>

using namespace std;
void menu();

int main()
{
menu();
}

void menu(){
int n,opcion=0;
string nodo;

cout<< "***************************CONSTRUCCION DEL GRAFO*****************************"<<endl;
cout<<endl;
cout<< "Ingrese la cantidad de nodos del grafo"<<endl;
cin>> n;
grafo g(n);
vector<int> visita (n,0);
g.insertar_nombres();
g.Agregar_arista();
cout<< "*************Grafo creado correctamente***************"<<endl;
cout<< "Presione enter para continuar"<<endl;
cin.get();

while(opcion!=5){
cin.get();
system("clear");


cout<< "                                   Menu"<<endl;

cout<<"1)Busquedad DFS"<<endl;
cout<< "2) Busquedad BFS"<<endl;
cout<< "3) Algoritmo de Dikjtra"<<endl;
cout<< "4) Mostrar matriz"<<endl;
cout<< "5) Salir"<<endl;
cout<< "Ingrese una opcion>> ";cin>>opcion;

switch(opcion){

case 1:
system("clear");
cout<< "Busqueda DFS: "<<endl;
g.DFS(g.getorigen(),visita,0);
cout<<endl;
cout<<"presione enter para continuar..."<<endl;
cin.get();
break;

case 2:
system("clear");
cout<< "Busqueda BFS: "<<endl;

g.BFS(g.getorigen());
cout<<endl;
cout<<"presione enter para continuar..."<<endl;
cin.get();
break;
case 3:
g.Dikjstra();
cout<<endl;
cout<<"presione enter para continuar..."<<endl;
cin.get();
break;


case 4:
g.mostrar_matriz();
cout<<endl;
cout<<"presione enter para continuar..."<<endl;
cin.get();
break;


}




}





}
