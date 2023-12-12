#include <iostream>
#include "Graphs.h"
#include "Edge.h"
using namespace std;


int main() {

    Graphs g;
    g.getGraph("Data.txt");
    g.dispGraph();
    g.shPath(0);
    cout<<endl<<endl;
    g.printPath(0,5);
    cout<<endl<<endl;
    g.DFS();
    return 0;
}
