#include <iostream>
#include <vector>
#include <map>
#include<stdlib.h>

using namespace std;
class grafo{

private:

 vector< vector<int>> matriz_adyacencia;
 map< string,int> nodos;
 int contador;
 public:

 grafo(int numero_nodos){

 matriz_adyacencia= vector<vector<int>>(numero_nodos, vector<int>(numero_nodos,0));
 contador=numero_nodos;

 }
 void insertar_nombres(){
 string nombre;
 for(int i=0; i<contador;i++){
 cout<< "Ingrese el nombre del nodo"<<endl;
 cin>> nombre;
 nodos.insert(make_pair(nombre,i));
 }



 }
 void DFS(string Nombre, vector<int> visita,int c_recursividad){


 int pos;
 string nombre;
 pos= nodos[Nombre];
 visita[pos]=1;
 cout<<Nombre<< " ";





 for(int i=0;i<contador;i++){
 if((matriz_adyacencia[pos][i]==1)&&(visita[i]==0)){

 for(auto ite=nodos.begin();ite!=nodos.end();ite++){

 if(ite->second==i){

 nombre=ite->first;

break;
 }

 }
 }

 }

 if(c_recursividad<contador){
 c_recursividad++;
 DFS(nombre,visita,c_recursividad);
 }






 }

 void BFS(string Nodo){
 vector<int> visita(contador,0);
 int pos,i=0;
 string nombre;
 pos= nodos[Nodo];
 visita[pos]=1;
 cout<<Nodo<<" ";
 while(i<=contador){
 if((matriz_adyacencia[pos][i]==1)&&(visita[i]==0)){

visita[i]=1;
 for(auto ite=nodos.begin();ite!=nodos.end();ite++){
 if(ite->second==i){
 nombre=ite->first;
 i++;
 break;
 }
 }
 cout<<nombre<<" ";
 }

 else{
 i++;
 }
 if(i==contador){
 i=0;
 pos++;
 }
 if(pos==contador-1){

 i=contador+1;
 }





 }






 }



void  Agregar_arista(){

int pos1,pos2;
for(int i=0;i<contador;i++){
string a,b;
cout<< "Ingrese el nodo a conectar"<<endl;
cin>> a;
cout<<"Ingrese el no que conectara con "<< a<<endl;
cin>> b;
pos1= nodos[a];
pos2= nodos[b];
 matriz_adyacencia[pos1][pos2]=1;
 matriz_adyacencia[pos2][pos1]=1;
 }

 }

void mostrar_matriz(){
int i=0,j=0;
system("clear");
    cout<< "La matriz de adyacencia es: "<<endl;
for( i=0;i<matriz_adyacencia.size();i++){
for (j=0; j<matriz_adyacencia[i].size();j++){

cout<< matriz_adyacencia[i][j]<<" ";

}
cout<<endl;


}





}




};



