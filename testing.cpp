#include "class/grafo.h"
#include "grafo_funciones.h"
#include "iostream"

using namespace std;

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

  cout << "Inicio: " << '\n\n';

  // Prim(g,1);
  // Dijkstra (g,1);
  // Pink_Floyd(g,1,7);
  // Kruskal(g);

  return 0;
}
