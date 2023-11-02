#include <stdio.h>
#include "..\..\ADT\PriorityQueue\prioqueueReq.c"
#include "..\..\ADT\Graf\graf.c"
#include "..\..\ADT\Matrix\matrix.c"
#include "..\..\ADT\WordMachine\wordmachine.c"

int main()
{
    Graf graph;

    CreateGraph(&graph);

    Word friend1 = {"asep", 4};    
    Word friend2 = {"ujang", 5};   
    Word friend3 = {"marcelo", 7}; 

    addVertex(&graph, friend1);
    addVertex(&graph, friend2);
    addVertex(&graph, friend3);

    addEdge(&graph, friend1, friend2);
    addEdge(&graph, friend2, friend3);

    return 0;
}
