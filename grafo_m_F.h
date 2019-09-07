#ifndef GRAFO_MATRIZ_ADYACENCIA_H_
#define GRAFO_MATRIZ_ADYACENCIA_H_

#include <map>
#include <list>
#include <vector>
#include "iostream"

using namespace std;


  if (a <= b){
    return a;
  }
  return b;
}

void inicMat(vector<vector<int>> & m){
  m[1][2] = 3;
  m[1][3] = 5;
  m[1][4] = 1;
  m[1][5] = 99999;
  m[1][6] = 99999;
  m[2][1] = 3;
  m[2][2] = 0;
  m[2][3] = 99999;
  m[2][4] = 99999;
  m[2][5] = 9;
  m[2][6] = 99999;
  m[3][1] = 5;
  m[3][2] = 99999;
  m[3][3] = 0;
  m[3][4] = 7;
  m[3][5] = 7;
  m[3][6] = 1;
  m[4][1] = 1;
  m[4][2] = 99999;
  m[4][3] = 7;
  m[4][4] = 0;
  m[4][5] = 99999;
  m[4][6] = 4;
  m[5][1] = 99999;
  m[5][2] = 9;
  m[5][3] = 7;
  m[5][4] = 99999;
  m[5][5] = 0;
  m[5][6] = 99999;
  m[6][1] = 99999;
  m[6][2] = 99999;
  m[6][3] = 1;
  m[6][4] = 4;
  m[6][5] = 99999;
  m[6][6] = 0;

}

void Ej11( vector<vector<int> > & m){
  int dim=6;
  for ( int k=1 ; k  <= dim ; k++ ){
    for ( int i=1 ; i <= dim ; i++ ){
      for ( int j=1 ; j<= dim ; j++){
        m[i][j] = min(m[i][j],m[i][k] + m[k][j]);
      }
    }
  }
  //cout
  for ( int i=1 ; i <= dim ; i++ ){
    for ( int j=1 ; j<= dim ; j++){
      cout << m[i][j] << " ";
    }
    std::cout << "\n" << '\n';
  }
}

#endif /* GRAFO_H_ */
