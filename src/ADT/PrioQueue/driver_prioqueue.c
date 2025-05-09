// #include <stdio.h>
// #include "..\PrioQueue\prioqueueReq.c"
// #include "..\Graf\graf.c"
// #include "..\Matrix\matrix.c"
// #include "..\Mesin-Kata\wordmachine.c"
// #include "..\Mesin-Char\charmachine.c"
// #include "prioqueueReq.h"




// int main() {
//     Word friend1 = {"ujang", 5};
//     Word friend2 = {"marcelo", 7};
//     Word friend3 = {"joko", 4};
//     Word friend4 = {"Kil", 3};
//     PrioQueueReq Q;
//     MakeEmptyPrio(&Q, 5);

//     infotype Friend1;
//     Friend1.nama = friend1;
//     Friend1.jumlahTeman = 5;

//     infotype Friend2;
//     Friend2.nama = friend2;
//     Friend2.jumlahTeman = 7;

//     infotype Friend3;
//     Friend3.nama = friend3;
//     Friend3.jumlahTeman = 4;

//     infotype Friend4;
//     Friend4.nama = friend4;
//     Friend4.jumlahTeman = 4;


//     infotype removedFriend;
//     int choice = 0;
//    do {
//         printf("\nMenu:\n");
//         printf("1. Enqueue Friend\n");
//         printf("2. Dequeue Friend\n");
//         printf("3. Print Friends\n");
//         printf("4. Exit\n");
//         printf("Enter your choice: ");

        
//         scanf("%d", &choice);
    
//         switch (choice) {
//             case 1:
//                 printf("Adding friends to the priority queue...\n");
//                 EnqueuePrio(&Q, Friend1);
//                 EnqueuePrio(&Q, Friend2);
//                 EnqueuePrio(&Q, Friend3);
//                 EnqueuePrio(&Q, Friend4);
//                 printf("Friends added.\n");
//                 break;
//             case 2:
//                 printf("Removing friends from the priority queue\n");
//                 if (!IsEmptyPrio(Q)) {
//                     DequeuePrio(&Q, &removedFriend);
//                     PrintPrioQueueTeman(Q);
//                 } else {
//                     printf("Queue is empty. No friend to dequeue.\n");
//                 }
//                 break;
//             case 3:
//                 printf("Printing the contents of the priority queue:\n");
//                 PrintPrioQueueTeman(Q);
//                 break;
//             case 4:
//                 printf("Exiting program.\n");
//                 break;
//             default:
//                 printf("Invalid choice.\n");
//                 break;
//         }
//     } while (choice != 4);


//     DeAlokasiPrio(&Q);

//     return 0;
// }
