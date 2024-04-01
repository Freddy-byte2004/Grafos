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
 string origen;
 public:

 string getorigen(){
 return origen;
 }

 grafo(int numero_nodos){

 matriz_adyacencia= vector<vector<int>>(numero_nodos, vector<int>(numero_nodos,0));
 contador=numero_nodos;

 }
 void insertar_nombres(){
 string nombre;
 int i;
 cout<< "Ingrese el nombre de los nodos"<<endl;
 cin>> origen;
 nodos.insert(make_pair(origen,0));
 i=1;
 for(int i=1; i<contador;i++){

 cin>> nombre;
 nodos.insert(make_pair(nombre,i));
 }



 }
 void  Agregar_arista(){

int pos1,pos2;
for(int i=0;i<contador;i++){
string a,b;
int peso;
cout<< "Ingrese los nodos a conectar"<<endl;
cout<< "Nodo 1 ->"; cin>> a;
cout<<"Nodo 2 -> ";cin>> b;
cout<< "Arista "<< a<< " -> "<< b<< " Creada correctamente"<<endl;
cout<< "Ingrese el peso de la arista"<<endl;
cin>> peso;
pos1= nodos[a];
pos2= nodos[b];
 matriz_adyacencia[pos1][pos2]=peso;
 matriz_adyacencia[pos2][pos1]=peso;
 }

 }
 void DFS(string Nombre, vector<int> visita,int c_recursividad){


 int pos;
 string nombre;
 pos= nodos[Nombre];
 visita[pos]=1;
 cout<<Nombre<< " ";





 for(int i=0;i<contador;i++){
 if((matriz_adyacencia[pos][i]>0)&&(visita[i]==0)){
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

 while(visita[contador-1]==0){
 if((matriz_adyacencia[pos][i]>0)&&(visita[i]==0)){

visita[i]=1;
 for(auto ite=nodos.begin();ite!=nodos.end();ite++){
 if(ite->second==i){
 nombre=ite->first;
 break;
 }
 }
 cout<<nombre<<" ";
 }
 i++;

 if(i==contador){
 i=0;
 pos++;
 }






 }






 }

 void Dikjstra(){
 vector<int>distancia(contador, 214748364);
vector<bool> visita(contador, false);
string Nodo, nombre_nodos[contador];
int origen,u;
cout<< "Ingrese el nodo de partida"<<endl;
cin>> Nodo;
origen= nodos[Nodo];
distancia[origen] = 0;

for (int i = 0; i< contador ; i++) {
u=-1;
for (int j = 0; j< contador; j++) {
if ((visita[j]!=true) && ((u == -1) || (distancia[j] < distancia[u]))) {
u = j;
}
}
// Marca el vértice seleccionado como procesado
visita[u] = true;
// Actualiza la distancia de los vértices adyacentes del vértice seleccionado
// se va actualizando las distancias con los vértices adyacentes al origen
for (int v = 0; v<contador; v++) {
if ((visita[v]!=true) && (matriz_adyacencia[u][v]!=0) && (distancia[u] + matriz_adyacencia[u][v]<distancia[v])) {
distancia[v] = distancia[u] + matriz_adyacencia[u][v];
}
}
}
int i=0;
for( auto ite= nodos.begin(); ite!=nodos.end();ite++){

nombre_nodos[i]=ite->first;
i++;


}
// Imprime las distancias más cortas desde el origen
for (int i = 0; i < contador; ++i) {
cout<< "Distancia del nodo "<< Nodo<< " al nodo "<< nombre_nodos[i]<< " es: "<<distancia[i]<<endl;


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



