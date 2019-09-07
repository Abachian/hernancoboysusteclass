#ifndef GRAFO_FUNCIONES_H_
#define GRAFO_FUNCIONES_H_

#include "class/grafo.h"
#include "class/sets.h"
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

struct arcoplus{
	int origen;
	int destino;
	int costo;
};

template <typename C> void Kruskal ( const Grafo<C> & g ){
	int Sum = 0;
	list <arcoplus> solucion;
	list <arcoplus> Arcos;
	list <typename Grafo<C>::Arco> Arcos_aux;
	int k = 1;
	while ( k <= (g.devolver_longitud()+1) ){ //Ver los adyacentes de todos los vertices
		g.devolver_adyacentes(k,Arcos_aux);
		typename list <typename Grafo<C>::Arco>::iterator it = Arcos_aux.begin();
		while (it != Arcos_aux.end() ){
			arcoplus arco;
			arco.costo= (*it).devolver_costo();
			arco.destino = (*it).devolver_adyacente();
			arco.origen = k;
			Arcos.push_back(arco); ///Agrega todos ndeah
			it++;
		}
		k++;
	}

	Sets Componentes (g.devolver_longitud()); //Crea (longitud de grafo) compopnentes
	list <arcoplus>::iterator it ;

	int MinCos;
	while ( !Arcos.empty() ){
		MinCos= 999;
		list <arcoplus>::iterator it_2;
		list <arcoplus>::iterator MinPos;
		for ( it_2 = Arcos.begin() ; it_2 != Arcos.end() ; it_2++ ){
			if ( (*it_2).costo < MinCos ){
				MinCos = (*it_2).costo;
				MinPos = it_2;
			}
		}
		if (Componentes.Find((*MinPos).origen) != Componentes.Find ((*MinPos).destino)){
			Componentes.Union(Componentes.Find((*MinPos).origen),Componentes.Find((*MinPos).destino));
			solucion.push_back((*MinPos));
		}
		Arcos.erase(MinPos);
	} //Mientras no queden componentes por eliminar
	list <arcoplus>::iterator it_2;
	cout << endl;
	for ( it_2 = solucion.begin() ; it_2 != solucion.end() ; it_2++ ){
		cout << (*it_2).origen << " ";
		cout << (*it_2).destino << " ",
		cout << "costo: "<<(*it_2).costo << " ",
		cout << endl;
		Sum += (*it_2).costo;
	}
	cout << endl;
	cout << endl;
	cout << Sum;
}

template <typename C> void Dijkstra ( const Grafo<C> & g , int vertice){

	int n = g.devolver_longitud();
	int calculado[n];
	int distancia[n];
	int padre[n];
	int min= 999;
	int PosMin;
	list <typename Grafo<C>::Arco> lista;

	calculado[vertice] = 1;
	distancia[vertice] = 0;
	distancia[0] = min;

	for ( int i=1;i<=n;i++){
		calculado[i]=0; //S
		padre[i]=vertice; //P
		distancia[i]=999;
	}

	for ( int i=1;i<=n;i++){
		distancia[i] = g.costo_arco(vertice,i);
	}

	distancia[vertice] = 0;

	for ( int k=1 ; k <= n ; k++ ){

		min = 999;

		for ( int j=1;j<=n;j++){
			if ( (distancia[j] < min) && (calculado[j] == 0) ){
				min = distancia[j];
				PosMin = j;
			}
		}

		calculado[PosMin] = 1; //Agregamos Posmin a S conjunto solucion

		g.devolver_adyacentes(PosMin,lista);
		typename list<typename Grafo<C>::Arco>::iterator it = lista.begin();
		for ( it=lista.begin() ; it!=lista.end() ; it++ ){
			if ( calculado[(*it).devolver_adyacente()] == 0 ){ //Si no fue procesado
				if ( distancia[(*it).devolver_adyacente()] > (distancia[PosMin] + g.costo_arco(PosMin,(*it).devolver_adyacente()))){
					distancia[(*it).devolver_adyacente()] = distancia[PosMin] + g.costo_arco(PosMin,(*it).devolver_adyacente());
					padre[(*it).devolver_adyacente()] = PosMin;
				}
			}
		}
	}
	for (int i = 2; i <= n; i++) {
		cout << "\nEl camino minimo desde " << vertice << " a " << i << ": ";
		int sum = 0;
		int sig = padre[i];
		while ( sig != vertice ){
			cout << padre[i] << " ";
			sum += distancia[i];
			sig  =  padre[sig];
		}
		cout << endl;
		cout << sum;
	}
}

template <typename C> void Pink_Floyd (const Grafo<C> & g,int origen,int destino){
	int u = g.devolver_longitud() + 1;
	int m[u][u];
	int p[u][u];

	for ( int j = 1 ; j <= u ; j++ ){
		for ( int i = 1 ; i <= u ; i++ ){
			p[j][i] = 0;
			m[j][i] = g.costo_arco(j,i);
		}
	}

	for ( int j = 1 ; j <= u ; j++ ){
		for ( int i = 1 ; i <= u ; i++ ){
			cout << m[j][i] << " ";
		}
		cout << endl;
	}


	for ( int k = 1 ; k <= u ; k++ ){
		for ( int i = 1 ; i <= u ; i++ ){
			for ( int j = 1 ; j <= u ; j++ ){
				cout << p[i][j] << " ";
				int a = g.costo_arco(i,k) + g.costo_arco(k,j);
				int b = m[i][j];
				if ( a < b ){
					m[i][j] = a;
					p[i][j] = k;
					cout << p[i][j] << " ";
				}
			}
			cout << endl;
		}
	}

	for ( int i = 1 ; i <= u ; i++ ){
		for ( int j = 1 ; j <= u ; j++ ){
			cout << p[i][j] << " ";
			}
		cout << "\n";
	}
	// int n = p[origen][destino];
	// while ( n != 0 ){
	// 	cout << n;
	// 	n = p[origen][n];
	// }
	return;
}

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

template<typename C>void routes_from_to(const Grafo<C>& g,int visitados[],int vertice,int destino,list<int> & route,list<list<int>> & solucion){
	if ( vertice == destino ){
		route.push_back(vertice);
		solucion.push_back(route);
		route.pop_back();
	}
	else{
		visitados[vertice] = 1;
		list<typename Grafo<C>::Arco> adyacentes;
		g.devolver_adyacentes(vertice,adyacentes);
		typename list<typename Grafo<C>::Arco>::iterator it = adyacentes.begin();
		while ( it != adyacentes.end() ){
			if ( visitados[(*it).devolver_adyacente()] == 0 ){
				route.push_back(vertice);
				routes_from_to (g,visitados,(*it).devolver_adyacente(),destino,route,solucion);
				route.pop_back();
			}
			it++;
		}
		visitados[vertice] = 0;
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
