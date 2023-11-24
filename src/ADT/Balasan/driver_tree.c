#include "tree.h"
#include <stdio.h>

int main() {
    Tree myTree;
    ListTreeStatik treeList;
    addressTree node, child, sibling;
    int data, childData, siblingData, nodeData;
    int choice;
    boolean running = true;

    CreateTree(&myTree);
    CreateListTreeStatik(&treeList);

    while (running) {
        printf("\nTree Operations\n");
        printf("1. Create Root\n");
        printf("2. Add Child\n");
        printf("3. Add Sibling\n");
        printf("4. Print Tree\n");
        printf("5. Print All Trees in List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data for root: ");
                scanf("%d", &data);
                myTree.root = Alokasi(data);
                insertLast_ListTreeStatik(&treeList, myTree);
                printf("Root created with data: %d\n", data);
                break;
            case 2:
                printf("Enter data for the new child: ");
                scanf("%d", &childData);
                printf("Enter data of the parent node: ");
                scanf("%d", &nodeData);
                node = getAddress(myTree.root, nodeData);
                if (node != NULL) {
                    child = Alokasi(childData);
                    AddChild(&node, child);
                    printf("Child %d added to parent %d\n", childData, nodeData);
                } else {
                    printf("Parent not found.\n");
                }
                break;
            case 3:
                printf("Enter data for the new sibling: ");
                scanf("%d", &siblingData);
                printf("Enter data of the existing child node: ");
                scanf("%d", &nodeData);
                node = getAddress(myTree.root, nodeData);
                if (node != NULL) {
                    sibling = Alokasi(siblingData);
                    AddSibling(&node, sibling);
                    printf("Sibling %d added to node %d\n", siblingData, nodeData);
                } else {
                    printf("Node not found.\n");
                }
                break;
            case 4:
                printf("Current Tree:\n");
                printTree(myTree.root, 0);
                break;
            case 5:
                printf("All Trees in List:\n");
                printList_ListTreeStatik(treeList);
                break;
            case 6:
                printf("Exiting...\n");
                running = false;
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 6.\n");
        }
    }
    return 0;
}