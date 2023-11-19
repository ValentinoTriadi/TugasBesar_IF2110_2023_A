#include <stdio.h>
#include "teman.h"
#include "teman.c"
#include "..\PrioQueue\prioqueueReq.c"
#include "..\Graf\graf.c"
#include "..\Matrix\matrix.c"
#include "..\Mesin-Kata\wordmachine.c"
#include "..\Mesin-Char\charmachine.c"

Teman teman;

Word currentUser = {"asep", 4};
Word friend1 = {"ujang", 5};
Word friend2 = {"marcelo", 7};
Word friend3 = {"joko", 4};
Word friend4 = {"zaki", 4};



void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Inisialisasi\n");
    printf("2. Daftar teman asep\n");
    printf("3. Kondisi asep tidak punya pending req\n");
    printf("4. zaki mencoba sent req ke Asep\n");
    printf("5. Kondisi asep punya pending req, & ingin sent req\n");
    printf("6. Remove Friend\n");
    printf("7. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice = 0;
    int x = 0;

    

    do {
        displayMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createTeman(&teman);
                addVertex(&Graph(teman), currentUser);
                addVertex(&Graph(teman), friend1);
                addVertex(&Graph(teman), friend2);
                addVertex(&Graph(teman), friend3);
                addVertex(&Graph(teman), friend4);

                printf("\nKondisi Asep sudah berteman dengan ujang & marcelo:\n");
                addEdge(&Graph(teman), currentUser, friend1);
                addEdge(&Graph(teman), currentUser, friend2);
                break;
            case 2:
                printf("Friends of %s:\n", currentUser.TabWord);
                daftarTeman(teman, currentUser);
                break;
            case 3:
                printf("\nKondisi asep tidak punya pending req:\n");
                sentReq(currentUser, &teman);
                printf("Friend request sent.\n");
                break;
            case 4:
                printf("\nzaki mencoba sent req ke Asep:\n");
                sentReq(friend4, &teman);
                printf("\nFriend requests for %s:\n", currentUser.TabWord);
                printRequest(teman.dataTeman.vertex[0].friendReq, currentUser);
                break;
            case 5:
                printf("\nKondisi asep punya pending req:\n");
                sentReq(currentUser, &teman);
                acceptRequest(&teman, currentUser);
                daftarTeman(teman, currentUser);
                break;
            case 6:
                printf("\nAsep mencoba menghapus teman:\n");
                hapusTeman(&teman, currentUser);
                daftarTeman(teman, currentUser);
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("input salah.\n");
                break;
        }
    } while (choice != 7);

    return 0;
}
