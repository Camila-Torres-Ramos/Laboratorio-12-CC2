#include <iostream>
#include <cstdlib>
#include "nodo.h"
using namespace std;
struct cola
{
    nodo *delante;
    nodo *atras  ;
};
void encolar( struct cola &q, int valor )
{
     struct nodo *aux = new(struct nodo);
     
     aux->nro = valor;
     aux->sgte = NULL;
     
     if( q.delante == NULL)
         q.delante = aux;  
     else
         (q.atras)->sgte = aux;
         
     q.atras = aux;           
}
int desencolar( struct cola &q )
{
     int num ;
     struct nodo *aux ;
     
     aux = q.delante;    
     num = aux->nro;
     q.delante = (q.delante)->sgte;
     delete(aux);          
     
     return num;
}
void muestraCola( struct cola q )
{
     struct nodo *aux;
     
     aux = q.delante;
         
     while( aux != NULL )
     {
            cout<<"   "<< aux->nro ;
            aux = aux->sgte;
     }    
}
void vaciaCola( struct cola &q)
{
     struct nodo *aux;
     
     while( q.delante != NULL)
     {
            aux = q.delante;
            q.delante = aux->sgte;
            delete(aux);
     }
     q.delante = NULL;
     q.atras   = NULL;
     
}
void menu(){
    cout<<"\n\t IMPLEMENTACION DE COLAS n\n";
    cout<<"1. ENCOLAR "<<endl;
    cout<<"2. DESENCOLAR "<<endl;
    cout<<"3. MOSTRAR COLA "<<endl;
    cout<<"4. VACIAR COLA"<<endl;
    cout<<"5. SALIR"<<endl;

    cout<<"\n INGRESE OPCION: ";
}