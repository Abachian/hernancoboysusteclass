#ifndef GRAFO_H_
#define GRAFO_H_

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
	}; // class Arco

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

	map <int,map<int,C>> map_grafo;

};

template <typename C> Grafo<C>::Arco::Arco()
{

}

template <typename C> Grafo<C>::Arco::Arco(int adyacente, const C & costo)
{
	vertice = adyacente;
	this->costo = costo;
}

template <typename C> int Grafo<C>::Arco::devolver_adyacente() const
{
	return vertice;
}

template <typename C> const C & Grafo<C>::Arco::devolver_costo() const
{
	return costo;
}

//COSOSOSOSOOSOS

template <typename C> Grafo<C>::Grafo()
{
}

template <typename C> Grafo<C>::Grafo(const Grafo & otroGrafo)
{

}

template <typename C> Grafo<C>::~Grafo()
{

}

template <typename C> Grafo<C> & Grafo<C>::operator = (const Grafo & otroGrafo)
{
	this->map_grafo = otroGrafo.map_grafo;
}

template <typename C> bool Grafo<C>::esta_vacio() const
{
	return map_grafo.empty();
}

template <typename C> int Grafo<C>::devolver_longitud() const
{
	return map_grafo.size();
}

template <typename C> bool Grafo<C>::existe_vertice(int vertice) const
{
	typename map<int,map<int,C>>::const_iterator it = map_grafo.find(vertice);
	if (it != map_grafo.end())
		return true;
	return false;
}

template <typename C> bool Grafo<C>::existe_arco(int origen, int destino) const
{
	typename map <int,map<int,C>>::const_iterator it = map_grafo.find(origen);
	if ( it != map_grafo.end() ){
		typename map<int, C>::const_iterator it_ = it->second.find(destino);
		if ( it_ != it->second.end()){
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
	typename map <int,map<int,C>>::const_iterator it = map_grafo.begin();
	while ( it != map_grafo.end() ){
		vertices.push_back(it->first);
		it++;
	}
}

template <typename C> void Grafo<C>::devolver_adyacentes(int origen, list<Arco> & adyacentes) const
{
	typename map <int,map<int,C>>::const_iterator it = map_grafo.find(origen);
	if ( it != map_grafo.end()){
		typename map<int,C>::const_iterator it_2 = it->second.begin();
		while ( it_2 != it->second.end()){
			adyacentes.push_back(Arco(it_2->first,it_2->second));
			it_2++;
		}
	}
}

template <typename C> void Grafo<C>::agregar_vertice(int vertice)
{
	map_grafo[vertice];
}

template <typename C> void Grafo<C>::eliminar_vertice(int vertice)
{
	typename map <int,map<int,C>>::iterator it = map_grafo.begin();
	while ( it != map_grafo.end() ){
		if ( it == vertice ){
			it->map_grafo.erase( it );
		}
		else{
			typename map <int,map<int,C>>::iterator it_2 = it->second.begin();
			while ( it_2 != it->second.end()){
				if ( it_2->vertice == vertice ){
					map_grafo.erase(it_2);
				}
			}
		}
		it++;
	}
}

template <typename C> void Grafo<C>::modificar_costo_arco(int origen, int destino, const C & costo)
{
	typename map <int,map<int,C>>::iterator it = map_grafo.find(origen);
	if ( it != map_grafo.end() ){
		typename map <int,map<int,C>>::iterator it_2 = it->second.find(destino);
		if ( it_2 != it->second.end()){
			map_grafo.erase(it_2);
			it->second.insert(destino,costo);
			return;
		}
		else{
			cout<< "\n\nEl arco no existe";
		}
	}
	else{
		cout<< "\n\nEl arco no existe";
	}
}

template <typename C> void Grafo<C>::agregar_arco(int origen, int destino, const C & costo)
{
	if ( existe_vertice(origen) && existe_vertice(destino) && !existe_arco(origen,destino) ){
		typename map<int,map<int,C>>::iterator it = map_grafo.find(origen);
		it->second[destino] = costo;
	}
}

template <typename C> void Grafo<C>::eliminar_arco(int origen, int destino)
{

}

template <typename C> void Grafo<C>::vaciar()
{

}

#endif /* GRAFO_H_ */
