#include "class/grafo.h"
#include "grafo_funciones.h"
#include "iostream"

using namespace std;

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

int main() {
  Grafo <int> g;
  // m.agregar_vertice(1);
  // m.agregar_vertice(2);
  // m.agregar_arco(1,2,10);
  // cout << "\n\nExiste vertice?: "<< m.existe_vertice(1);
  // cout << "\n\nExiste Arco?: "<< m.existe_arco(1,2);
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
	g.agregar_arco(1, 2, 3);
	g.agregar_arco(1, 3, 9);
	g.agregar_arco(1 ,5, 5);
	g.agregar_arco(1, 9, 5);
  g.agregar_arco(1, 8, 10);
	g.agregar_arco(2, 1, 6);
	g.agregar_arco(2, 4, 2);
	g.agregar_arco(2, 7, 4);
	g.agregar_arco(3, 4, 5);
	g.agregar_arco(4, 6, 2);
	g.agregar_arco(4, 1, 2);
  g.agregar_arco(5, 7, 4);
	g.agregar_arco(5, 6, 4);
  g.agregar_arco(6, 7, 3);
  g.agregar_arco(8, 7, 1);

	nodo visitados[g.devolver_longitud()];
	comp_fuertemente_conectados(g,visitados);

  // Prim(g,1);
  // Dijkstra (g,1);
  // Pink_Floyd(g,1,7);
  // Kruskal(g);

  return 0;
}
