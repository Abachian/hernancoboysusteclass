#include "grafo_funciones.h"
#include "class/grafo.h"
#include <algorithm>
#include <queue>
#include "iostream"
#include "class/sets.h"
using namespace std;

void Imprimir_visitados (list<int> n){
	list<int>::const_iterator it = n.begin();
	for ( it=n.begin() ; it!=n.end() ; it++){
		cout << (*it) << " ";
	}
}

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

	int visitados[g.devolver_longitud()+1];
	list < int > route;
	list < list < int > > solucion;

	int n = 0;
	while ( n <= g.devolver_longitud()+1 ){
		visitados[n++] = 0;
	}

	routes_from_to(g,visitados,1,7,route,solucion);

	list < list < int > >::const_iterator it;
	cout << solucion.size() << "\n\n";
	for ( it=solucion.begin() ; it!=solucion.end() ; it++){
		Imprimir_visitados((*it));
		cout << "\n";
	}

}
