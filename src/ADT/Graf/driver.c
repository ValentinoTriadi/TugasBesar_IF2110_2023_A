#include <stdio.h>
#include "graf.h"
#include "../WordMachine/wordmachine.c"

int main() {
    Teman graph;


    CreateGraph(&graph);

 
    Word friend1 = {"Alice", 5};
    Word friend2 = {"Bob", 3};
    Word friend3 = {"Charlie", 7};
    addName(&graph, friend1);
    addName(&graph, friend2);
    addName(&graph, friend3);


    addFriendship(&graph, friend1, friend2);
    addFriendship(&graph, friend2, friend3);

  
    showFriends(&graph, friend1);
    showFriends(&graph, friend2);
    showFriends(&graph, friend3);

    
    printf("%s punya %d teman.\n", friend1.TabWord, countFriends(&graph, friend1));
    printf("%s punya %d teman.\n", friend2.TabWord, countFriends(&graph, friend2));
    printf("%s punya %d teman.\n", friend3.TabWord, countFriends(&graph, friend3));


    removeFriendship(&graph, friend1, friend2);


    showFriends(&graph, friend1);
    showFriends(&graph, friend2);
    showFriends(&graph, friend3);

    return 0;
}
