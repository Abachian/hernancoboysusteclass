#include "grafo_funciones.h"
#include "grafo.h"
#include <algorithm>
#include <queue>
#include <pair>
#include <cassert>
#include "iostream"
#include "sets.h"
using namespace std;

void Imprimir_visitados(nodo visitados[],int n){
	for (int i=1 ; i<n ; i++ ){
		cout<< "V: "<<i<<"\n\nI: "<<visitados[i].inicio<<"\nF: "<<visitados[i].fin<<"\n" <<
		"P: "<<visitados[i].padre << "\n\n";
	}
}

void Inicializar_visitados(nodo visitados[],int n){
	for (int i=1 ; i <= n ; i++){
		visitados[i].inicio=-1;
		visitados[i].fin=-1;
		visitados[i].padre=0;
	}
}


template <typename C>
ostream & operator << (ostream & salida, const Grafo<C> & grafo)
{
	list<int> vertices;
	grafo.devolver_vertices(vertices);
	list<int>::iterator v = vertices.begin();
	while (v != vertices.end()) {
		salida << "    " << *v << "\n";
		// Recorremos todos los adyacentes de cada vertice
		list<typename Grafo<C>::Arco> adyacentes;
		grafo.devolver_adyacentes(*v, adyacentes);
		typename list<typename Grafo<C>::Arco>::iterator ady = adyacentes.begin();
		while (ady != adyacentes.end()) {
			salida << "    " << *v << "-> " << ady->devolver_adyacente() << " (" << ady->devolver_costo() << ")\n";
			ady++;
		}
		v++;
	}
	return salida;
}

int main()
{
	Grafo<int> g;
	cout << "Carga grafo" << '\n';
	g.agregar_vertice(1);
	g.agregar_vertice(2);
	g.agregar_vertice(3);
	g.agregar_vertice(4);
	g.agregar_vertice(5);
	g.agregar_vertice(6);
	g.agregar_vertice(7);
	g.agregar_vertice(8);
	g.agregar_vertice(9);
	// // // Luego los arcos
	g.agregar_arco(1, 2, 1);
	g.agregar_arco(1, 3, 1);
	g.agregar_arco(1 ,5, 5);
	g.agregar_arco(1, 9, 5);
	g.agregar_arco(2, 4, 14);
	g.agregar_arco(3, 4, 5);
	g.agregar_arco(4, 6, 2);
	g.agregar_arco(5, 7, 4);
	g.agregar_arco(5, 6, 4);
	g.agregar_arco(6, 7, 3);

	cout << g << "\n\n";

	nodo visitados[g.devolver_longitud()+1];
	Inicializar_visitados(visitados,g.devolver_longitud()+1);
	//comp_fuertemente_conectados(g,visitados);
	list <int> solucion;
	list <int> route;
	ejercicio8(g,1,7,route,solucion,pair <9,7>);
	list <int>::const_iterator it;
	for ( it=caminos.begin() ; it!=caminos.end() ; it++){
		cout << (*it) << " ";
		if ( (*it) == fin ){
			cout << "\n";
	// int color[g.devolver_longitud()+1];
	// for ( int i=1 ; i <= g.devolver_longitud()+1 ; i++ ){
	// 	color[i]=0;
	// }
	//
	// list <int> caminos;
	// list <int> de_ruta;
	// int fin = 7;
	//
	// routes_w_avoid (g,1,fin,0,de_ruta,caminos);
	// list <int>::const_iterator it;
	// cout << "\n\nSoluciones: ";
	// for ( it=caminos.begin() ; it!=caminos.end() ; it++){
	// 	cout << (*it) << " ";
	// 	if ( (*it) == fin ){
	// 		cout << "\n";
	// 	}
	// }
	// cout << "\n\nRuta: ";
	// for ( it=de_ruta.begin() ; it!=de_ruta.end() ; it++){
	// 	cout << (*it) << " ";
	// 	if ( (*it) == fin ){
	// 		cout << "\n";
	// 	}
	// }

	// queue <int> joya;
	// nodo visitados[g.devolver_longitud()+1];
	// int tiempo = 1;
	// Inicializar_visitados(visitados,g.devolver_longitud()+1);
	// BFS_w_cout(g,1,visitados,tiempo,joya);
	// Imprimir_visitados(visitados,g.devolver_longitud()+1);
	// cout << "\n\nSoluciones: ";
	// list <int>::const_iterator it_2;
	// int i = 0;
	// while ( !joya.empty() ){
	// 	cout << "i: "<< i++ << joya.front() << " ";
	// 	joya.pop();
	//
}
