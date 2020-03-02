#include <bits/stdc++.h> 
using namespace std; 

#define Vertex 5 //define 5 vertex graphs

int hamiltonianPath[5]; // Array to store the path of Hamiltonian path


bool conditionCheck(bool graph[Vertex][Vertex], int hamiltonianPath[], int vertex ,int index) 
{ 
    //To check whether the vertex has an adjacency with the previous added vertex
if (graph [hamiltonianPath[index - 1]][ vertex ] == 0) 
{
return 0; //return false if not
}
for (int i = 0; i < index; i++) 
{
    if (hamiltonianPath[i] == vertex) //to check if the vertex is already included in the Hamiltonian Path
        
    {
     return 0; 
    }
}
     return 1; 
} 

bool hamiltonianHelper(bool graph[Vertex][Vertex], int hamiltonianPath[], int index) 
{ 

for (int i = 1; i < Vertex; i++) 
{ 
 if(conditionCheck(graph , hamiltonianPath ,i ,index))
  {
     hamiltonianPath[index] = i; 

       if(hamiltonianHelper (graph, hamiltonianPath, index + 1)== true)
         {
            return 1;
          }

       else
          {
           hamiltonianPath[index] = -1; 
           }
   }
 }

	if (index == Vertex) //if all vertices are in the Hamiltonian cycle path
	{ 
               //to check if an edge exist between last and first edge
		if (graph[hamiltonianPath[index - 1]][hamiltonianPath[0]] == 1) 
			return 1; 
		else
			return 0; 
	} 

	return 0; 
} 

void hamiltonianCycle(bool graph[Vertex][Vertex]) 
{ 
	int *hamiltonianPath = new int[Vertex];  //Hamiltonian Path array
		hamiltonianPath[0] = 0; //Intial vertex starts from 0
	for (int i = 1; i < Vertex; i++) 
		hamiltonianPath[i] = -1; //All other index values set to -1

	if (hamiltonianHelper(graph, hamiltonianPath, 1) == true ) 
	{ 
            cout << "\nHamiltonian Cycle exists in Graph\n";
            cout << "\nHamiltonian Cycle is -\n";
	for (int i = 0; i < Vertex; i++) 
		cout << hamiltonianPath[i] << " ";//print the hamiltonian path

	cout << hamiltonianPath[0] << " "; //to print the last vertex meets the first vertex
	cout << endl; 
		
                
	} 
        else
        {
	cout << "\nNo Hamiltonian cycle exists for Graph\n"; 
	
        }
} 
int main() 
{ 
    
   /*
    A----B
    |\  /|
    | /\ |
    |/  \| 
    C----D
     \  /
      \/
      E
    A - 0 , B - 1, C -2 , D -3 , E-4 
    
    */
bool graphA[Vertex][Vertex] = {
                     {0, 1, 1, 1, 0}, 
		     {1, 0, 1, 1, 0}, 
		     {1, 1, 0, 1, 1}, 
		     {1, 1, 1, 0, 1}, 
		     {0, 0, 1, 1, 0}
                              }; 

hamiltonianCycle(graphA); 

/*
    A----B
    |\  /|
    | /\ |
    |/  \| 
    C----D
     \  
      \
      E
    A - 0 , B - 1, C -2 , D -3 , E-4 
    
    */

bool graphB[Vertex][Vertex] = {
                     {0, 1, 1, 1, 0}, 
		     {1, 0, 1, 1, 0}, 
		     {1, 1, 0, 1, 1}, 
		     {1, 1, 1, 0, 0}, 
		     {0, 0, 1, 0, 0}
                              }; 
hamiltonianCycle(graphB); 

return 0; 
} 


