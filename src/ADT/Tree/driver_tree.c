#include "tree.h"
#include <stdio.h>

int main() {
    Tree myTree;
    CreateTree(&myTree);

    // Alokasi node root
    addressTree root = Alokasi(1);
    Root(myTree) = root;

    // Menambahkan child pada root
    addressTree child1 = Alokasi(2);
    addressTree child2 = Alokasi(3);
    AddChild(&root, child1);
    AddSibling(&child1, child2);

    // Menambahkan child pada child1
    addressTree child1_1 = Alokasi(4);
    addressTree child1_2 = Alokasi(5);
    AddChild(&child1, child1_1);
    AddSibling(&child1_1, child1_2);

    // Menambahkan child pada child2
    addressTree child2_1 = Alokasi(6);
    addressTree child2_2 = Alokasi(7);
    AddChild(&child2, child2_1);
    AddSibling(&child2_1, child2_2);

    // Mencetak Tree
    printf("Tree yang dibangun:\n");
    printTree(Root(myTree), 0);

    // Mencetak child dari root
    printf("\nAnak-anak dari root:\n");
    printChild(root);

    // Mencetak siblings dari child1
    printf("\nSaudara-saudara dari child1:\n");
    printSiblings(NextSibling(child1));

    // Mencari elemen dalam Tree
    int searchElement = 5;
    if(isTreeElmt(Root(myTree), searchElement)) {
        printf("\nElemen %d ditemukan dalam Tree.\n", searchElement);
    } else {
        printf("\nElemen %d tidak ditemukan dalam Tree.\n", searchElement);
    }

    // Mendapatkan alamat dari elemen
    addressTree address = getAddress(Root(myTree), searchElement);
    if(address != NULL) {
        printf("Alamat dari elemen %d adalah %p.\n", searchElement, (void*)address);
    }

    // Mendapatkan parent dari sebuah node
    addressTree parent = getParent(Root(myTree), child2_1);
    if(parent != NULL) {
        printf("Parent dari elemen %d adalah %d.\n", Data(child2_1), Data(parent));
    }

    // Deallocate semua node
    Dealokasi(root);
    Dealokasi(child1);
    Dealokasi(child2);
    Dealokasi(child1_1);
    Dealokasi(child1_2);
    Dealokasi(child2_1);
    Dealokasi(child2_2);

    return 0;
}
