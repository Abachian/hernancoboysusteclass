#ifndef GRAFO_FUNCIONES_H_
#define GRAFO_FUNCIONES_H_

#include "grafo.h"
#include "sets.h"
#include <list>
#include <queue>
#include <iostream>
using namespace std;

struct nodo{
	int inicio;
	int fin;
	int padre;
};

struct par{
	int a;
	int b;
};

template <typename C> void comp_fuertemente_conectados (const Grafo<C> & g,nodo visitados[]){
	int tiempo = 0;
	list<int> vertices;
	g.devolver_vertices(vertices);
	list<int>::iterator v = vertices.begin();
	Sets componentes(9);
	while ( v!=vertices.end()){
		if (visitados[(*v)].inicio == -1 ){
			calcular_sets(g,(*v),visitados,tiempo,componentes);
		}
		v++;
	}
	componentes.Mostrar();
}

template <typename C> void calcular_sets(const Grafo<C> & Grafo_, int vertice, nodo visitados[],int & tiempo, Sets & answer){
	tiempo++;
	visitados[vertice].inicio = tiempo;
	list<typename Grafo<C>::Arco> adyacentes;
	Grafo_.devolver_adyacentes(vertice,adyacentes);
	typename list<typename Grafo<C>::Arco>::iterator it = adyacentes.begin();
	while (it!=adyacentes.end()){
		int rep_a = answer.Find(vertice) , rep_b = answer.Find((*it).devolver_adyacente());
		if ( rep_a != rep_b ) {
			answer.Union(rep_a,rep_b);
		}
		calcular_sets(Grafo_,(*it).devolver_adyacente(),visitados,tiempo,answer);
		it++;
	}
	tiempo++;
	visitados[vertice].fin = tiempo;
}

template <typename C> void DFS(const Grafo<C> & Grafo_, int vertice, nodo visitados[],int & tiempo,bool & ciclico,list <int> & toposort){
	tiempo++;
	visitados[vertice].inicio = tiempo;
	list<typename Grafo<C>::Arco> adyacentes;
	Grafo_.devolver_adyacentes(vertice,adyacentes);
	typename list<typename Grafo<C>::Arco>::iterator it = adyacentes.begin();
	toposort.push_front(vertice);
	while (it!=adyacentes.end()){
		int destino = (*it).devolver_adyacente();
		if (visitados[destino].inicio == -1 ){
			visitados[destino].padre = vertice;
			DFS(Grafo_,(*it).devolver_adyacente(),visitados,tiempo,ciclico,toposort);
		}
		if (visitados[destino].fin == -1){
			ciclico = true;
		}
		it++;
	}
	cout <<"v:" << vertice << "\n";
	tiempo++;
	visitados[vertice].fin = tiempo;
}



template<typename C>void ejercicio8(const Grafo<C>& g,int vertice,int destino,list<int> & route,list<int> & solucion, par evadir){
	if ( vertice == destino ){
		route.push_back(vertice);
		solucion.insert(solucion.end(),route.begin(),route.end());
		route.pop_back();
	}
	else{
		list<typename Grafo<C>::Arco> adyacentes;
		g.devolver_adyacentes(vertice,adyacentes);
		typename list<typename Grafo<C>::Arco>::iterator it = adyacentes.begin();
		while( it != adyacentes.end() ){
			route.push_back(vertice);
			if ( vertice!=evadir.a && vertice!=evadir.b ){
				ejercicio8(g,(*it).devolver_adyacente(),destino,route,solucion,evadir);
			}
			route.pop_back();
			it++;
		}
	}
}




template<typename C>void routes_from_to(const Grafo<C>& g,int vertice,int destino,list<int> & route,list<int> & solucion){
	if ( vertice == destino ){
		route.push_back(vertice);
		solucion.insert(solucion.end(),route.begin(),route.end());
		route.pop_back();
	}
	else{
		list<typename Grafo<C>::Arco> adyacentes;
		g.devolver_adyacentes(vertice,adyacentes);
		typename list<typename Grafo<C>::Arco>::iterator it = adyacentes.begin();
		while( it != adyacentes.end() ){
			route.push_back(vertice);
			routes_from_to (g,(*it).devolver_adyacente(),destino,route,solucion);
			route.pop_back();
			it++;
		}
	}
}

template<typename C>void routes_w_avoid(const Grafo<C>& g,int vertice,int destino,int avoid,list<int> & route,list<int> & solucion){
	if ( vertice == destino ){
		route.push_back(vertice);
		solucion.insert(solucion.end(),route.begin(),route.end());
		route.pop_back();
	}
	else{
		list<typename Grafo<C>::Arco> adyacentes;
		g.devolver_adyacentes(vertice,adyacentes);
		typename list<typename Grafo<C>::Arco>::iterator it = adyacentes.begin();
		while( it != adyacentes.end() ){
			route.push_back(vertice);
			if ( (*it).devolver_adyacente() != avoid ){
				routes_w_avoid (g,(*it).devolver_adyacente(),destino,avoid,route,solucion);
			}
			route.pop_back();
			it++;
		}
	}
}

template <typename C> void DFS_Forest(const Grafo<C> & Grafo_,nodo visitados[],bool & ciclico,list <int> & toposort){
	int tiempo = 0;
	list<int> vertices;
	Grafo_.devolver_vertices(vertices);
	list<int>::iterator v = vertices.begin();
	while ( v!=vertices.end()){
		if (visitados[(*v)].inicio==-1 ){
			ciclico = false;
			DFS(Grafo_,(*v),visitados,tiempo,ciclico,toposort);
		}
		v++;
	}
}


#endif /* GRAFO_FUNCIONES_H_ */
