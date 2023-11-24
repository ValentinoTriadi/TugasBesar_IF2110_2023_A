#include <stdio.h>
#include "teman.h"
#include "teman.c"
#include "..\PrioQueue\prioqueueReq.c"
#include "..\Graf\graf.c"
#include "..\Matrix\matrix.c"
#include "..\Mesin-Kata\wordmachine.c"
#include "..\Mesin-Char\charmachine.c"



void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Inisialisasi\n");
    printf("2. Add vertex\n");
    printf("3. Add edge\n");
    printf("4. Remove edge\n");
    printf("5. Count edge\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main(){
    

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Initialize
                Word currentUser = {"asep", 4};
                Word friend1 = {"ujang", 5};
                Word friend2 = {"marcelo", 7};
                Word friend3 = {"joko", 4};
                Word friend4 = {"alex", 4};

                Graf g;
                createGraf(&g);
                break;
            case 2:
                // Add vertex
                addVertex(&g, currentUser);
                addVertex(&g, friend1);
                addVertex(&g, friend2);
                addVertex(&g, friend3);
                addVertex(&g, friend4);
                break;
            case 3:
                // Add edge
                //Menambahkan edge 2 kali akan menampilkan pesan sudah terhubung
                addEdge(&g, currentUser, friend1);
                addEdge(&g, currentUser, friend1);
                
                break;
            case 4:
                // Remove edge
                
                //hapus edge yang tidak ada
                removeEdge(&g, currentUser, friend3);

                //hapus edge yang ada
                removeEdge(&g, currentUser, friend1);
                break;
            case 5:
                // Count edge
                printf("Jumlah edge: %d\n", countEdge(g));
                break;
            case 7:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while(choice != 7);




    return 0;

}