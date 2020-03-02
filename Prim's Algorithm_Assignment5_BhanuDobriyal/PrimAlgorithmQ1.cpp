#include <cstring>
#include <iostream>
using namespace std;
#define V 8
#define INF 999

int G[V][V] = {
  {0, 1, 0, 0, 4 , 8, 0 ,0},
  {1, 0, 2, 0, 0 , 6, 6 ,0},
  {0, 2, 0, 1, 0 , 0, 2 ,0},
  {0, 1, 0, 0, 0 , 0, 1 ,4},
  {4, 0, 0, 0, 0 , 5, 0 ,0},
  {8, 6, 0, 0, 5 , 0, 1 ,0},
  {0, 6, 2, 1, 0 , 1, 0 ,1},
  {0, 0, 0, 4, 0 , 0, 1 ,0}
};
 
int main () {
     int x , y;
  int number_of_edge = 0;           
  int selectedVertex[V];
  
  memset (selectedVertex, false, sizeof (selectedVertex));
  selectedVertex[0] = true;
  cout << "Edges of the MST" << " : " << "Weight" <<endl;
  while (number_of_edge < V - 1) { //condition of MST in PRim's algorithm
 int minimum = INF;
      for (int i = 0; i < V; i++) 
      {if (selectedVertex[i]) {
            for (int j = 0; j < V; j++) {
              if (G[i][j]&& !selectedVertex[j] ) {
                  if (minimum > G[i][j]) {
                      minimum = G[i][j];
                      x = i;
                      y = j;
                  }}}}}
      cout << x <<  " - " << y << " :  " << G[x][y]<< endl;
      selectedVertex[y] = true;
      number_of_edge++;
    }
 
  return 0;
}