// FILE: graphs.cpp
// Graph Library Implementation File for Asn 6

#include <fstream>		// For reading file from disk
#include <iostream>
#include <string>		// For file name
#include <iomanip>
#include "Edge.h"// Deinition of an Edge
#include "Graphs.h"
#include <limits>

using namespace std;

// Constructor
Graphs::Graphs()
{
    E = V = order = 0;
}

// Destructor
Graphs::~Graphs()
{
}


// Map vertex number (0,1,2,..) to (A,B,C,..)
char Graphs::Vname(const int s) const
{
    return char(s+65);
}

// Get Graph from text File (file name is stored in string fname)
// Graph is stored in adjacency matrix
void Graphs::getGraph(string fname) {
    // Local data ...
    weightType wi;
    ifstream source;
    string line;
    source.open(fname.c_str());
    string convert;
    int n;
    int row = 0;
   // int i=0;


   // source >> V;    // Read no. of verices (V)

    if (!source.is_open())
        cout << "Error opening the file" << endl;
    else {
        while (getline(source, line))
        {
            istringstream stream(line);
           V++;
            int i=0;
            while (getline(stream, convert, '\t')) {
                n = stoi(convert);
                AdjMatrix[row][i]=n;
               cout<<AdjMatrix[row][i];
                i++;
            }
            row++;

        }
    }
}

// Display Adjacency Matrix
void Graphs::dispGraph() const
{
    int i,j;
    cout<<"Adjacency Matrix\n";
    for(i=0; i<V; i++)
    {
        for(j=0; j<V; j++)
            cout<< setw(3)<< AdjMatrix[i][j] << " ";
        cout<< endl;
    }
}

// Get Non-Zero edges from adjacency matrix
// and store them in array edges[].
void Graphs::getEdges()
{
    int r , c;
    int i = 0;
    weightType weight;

    // Only examine weights above the diagonal
    for (r = 0; r <= V-2; r++)
        for (c = r+1; c <= V-1; c++)
        {
            weight = AdjMatrix[r][c];
            if (weight > 0)
            {
                // save (r,c,weight) in edges[i]
                edges[i].u = r;
                edges[i].v = c;
                edges[i].w = weight;
                i++;
            }
        }

    E = i;		// Number of non-zero edges

}

// Get number of vertices (V)
int Graphs::No_of_Verices() const
{
    return V;
}

// Get Number of Non-zero edges (E)
int Graphs::No_of_Edges() const
{
    return E;
}

// Output an edge (e): Vertex names and weight
void Graphs::printEdge(Edge e) const
{
    cout << Vname(e.u) << " " << Vname(e.v) << " " << e.w << endl;
}

// Display Graph Edges
void Graphs::dispEdges() const
{
    cout<<"Graph Edges\n";
    for (int i = 0; i < E; i++)
        printEdge(edges[i]);
}

// Shortest paths from node s
// uses Dijkstra's Algorithm
void Graphs::shPath(int s)
{

    for (int i = 0; i < V; i++) {
        via[i] = -1;
        distance[i] = INT_MAX;
        processed[i] = 0;
    }

    distance[s] = 0;

    for (int i = 0; i < V - 1; i++) {
        int minIndex;
        int minDist = INT_MAX;

        for (int j = 0; j < V; j++) {
            if (!processed[j] && distance[j] <= minDist) {
                minDist = distance[j];
                minIndex = j;
            }
        }
        processed[i] = true;

        for (int j = 0; j < V; j++) {

            if (!processed[j] && AdjMatrix[i][j] && distance[i] != INT_MAX) {
                if (distance[i]+AdjMatrix[i][j]<distance[j]) {
                    distance[j]=distance[i]+AdjMatrix[i][j];
                    via[j] = i;
                }
            }

        }
    }

    cout << "Shortest Paths from Node " << Vname(s) << endl;
    for (int i = 0; i < V; i++) {
        cout<<"To node "<<Vname(i)<<" Total distance: "<<distance[i]<<endl;
        cout<<"Path: ";
        printPath(s, i);
        cout << endl;
    }

}

// Print path (vertex names) from source (s) to destination (i)
void Graphs::printPath(int s, int i) const
{
    if (via[i]!=-1)
        printPath(s,via[i]);
    cout<<Vname(i)<< " -> ";
}

// Node Visit Function
void Graphs::visit(int i)
{
    val[i] = order++;
    cout<<Vname(i)<< " ";
    for (int j = 0; j < V; j++) {
        if (AdjMatrix[i][j] != 0 && val[j] == -1) {
            visit(j);
        }
    }
}

// Depth First Search Traversal
void Graphs::DFS() {
    for (int i=0;i<V;i++)
        val[i] = -1;

    cout<<endl;
    cout<<"DFS Traversal"
          ": ";

    for (int i=0;i<V;i++) {
        if (val[i] == -1)
            visit(i);
    }


}

