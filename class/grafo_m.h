#ifndef GRAFO_H_
#define GRAFO_H_

#define inf 99999
#define basura 720

#include <map>
#include <list>
#include <iostream>
using namespace std;

template <typename C> class Grafo
{
public:
	class Arco
	{
	public:
		Arco();
		Arco(int adyacente, const C & costo);
		int devolver_adyacente() const;
		const C & devolver_costo() const;
	private:
		int vertice;
		C costo;
	};

public:
	// NOTA: Dependiendo de la implementación puede ser necesario incluir otras funciones constructuras
	Grafo();
	Grafo(const Grafo & otroGrafo);

	~Grafo();

	Grafo & operator = (const Grafo & otroGrafo);

	// Devuelve true si la cantidad de vértices es cero
	bool esta_vacio() const;

	// Indica la cantidad de vértices del grafo
	int devolver_longitud() const;

	bool existe_vertice(int vertice) const;

	bool existe_arco(int origen, int destino) const;

	// PRE CONDICION: existe_arco(origen, destino)
	const C & costo_arco(int origen, int destino) const;

	void devolver_vertices(list<int> & vertices) const;

	void devolver_adyacentes(int origen, list<Arco> & adyacentes) const;

	void agregar_vertice(int vertice);

	// POST CONDICION: Para todo vértice v != vertice: !existeArco(v, vertice) && !existeArco(vertice, v)
	void eliminar_vertice(int vertice);

	// PRE CONDICION: existeArco(origen, destino)
	void modificar_costo_arco(int origen, int destino, const C & costo);

	// PRE CONDICION: existeVertice(origen) && existeVertice(destino)
	// POST CONDICION: existeArco(origen, destino)
	void agregar_arco(int origen, int destino, const C & costo);

	// POST CONDICION: !existeArco(origen, destino)
	void eliminar_arco(int origen, int destino);

	void vaciar();

private:

	int ** matriz;
	int n;

};

template <typename C> Grafo<C>::Grafo()
{
	n = 0;
}

template <typename C> Grafo<C>::Grafo(const Grafo & otroGrafo)
{

}

template <typename C> Grafo<C>::~Grafo()
{

}

template <typename C> Grafo<C> & Grafo<C>::operator = (const Grafo & otroGrafo)
{
}

template <typename C> bool Grafo<C>::esta_vacio() const
{
	return 0;
}

template <typename C> int Grafo<C>::devolver_longitud() const
{
	return n;
}

template <typename C> bool Grafo<C>::existe_vertice(int vertice) const
{
	return vertice<=n;
}

template <typename C> bool Grafo<C>::existe_arco(int origen, int destino) const
{
	if ( existe_vertice(origen) && existe_vertice(destino) ){
		if (matriz[origen][destino] != basura){
			return true;
		}
	}
	return false;
}

template <typename C> const C & Grafo<C>::costo_arco(int origen, int destino) const
{

}

template <typename C> void Grafo<C>::devolver_vertices(list<int> & vertices) const
{

}

template <typename C> void Grafo<C>::devolver_adyacentes(int origen, list<Arco> & adyacentes) const
{

}

template <typename C> void Grafo<C>::agregar_vertice(int vertice)
{
	matriz = new int*[vertice];
	int p = 0;
	while ( p < n ){
		matriz[p++] = new int [n];
	}
	// matriz[vertice] = new int[n];
	// int p = 0;
	// while ( p <= n ){
	// 	p++;
	// }

	int k = 0;

	while ( k <= n ){
		matriz[k][vertice] = basura;
		k++;
	}

	k=0;

	while ( k <= n ){
		matriz[vertice][k] = basura;
		k++;
	}

	this->n++;
}

template <typename C> void Grafo<C>::eliminar_vertice(int vertice)
{

}

template <typename C> void Grafo<C>::modificar_costo_arco(int origen, int destino, const C & costo)
{

}

template <typename C> void Grafo<C>::agregar_arco(int origen, int destino, const C & costo)
{
	matriz[origen][destino] = costo;
	return;
}

template <typename C> void Grafo<C>::eliminar_arco(int origen, int destino)
{

}

template <typename C> void Grafo<C>::vaciar()
{

}

template <typename C> Grafo<C>::Arco::Arco()
{

}

template <typename C> Grafo<C>::Arco::Arco(int adyacente, const C & costo)
{

}

template <typename C> int Grafo<C>::Arco::devolver_adyacente() const
{
	return this->vertice;
}

template <typename C> const C & Grafo<C>::Arco::devolver_costo() const
{
}

#endif /* GRAFO_H_ */
