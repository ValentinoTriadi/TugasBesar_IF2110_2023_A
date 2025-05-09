// #include "listdin.h"
// #include <stdio.h>

// int main() {
//     ListDin l;
//     int choice, val;
//     ListDin_ElType el;
//     int capacity;

//     printf("Enter the initial capacity of the dynamic list: ");
//     scanf("%d", &capacity);
//     CreateListDin(&l, capacity);

//     do {
//         printf("\n");
//         printf("Dynamic List Operations\n");
//         printf("1. Create New List\n");
//         printf("2. Read List\n");
//         printf("3. Print List\n");
//         printf("4. Add Last Element\n");
//         printf("5. Delete Last Element\n");
//         printf("6. Check if List is Empty\n");
//         printf("7. Check if List is Full\n");
//         printf("8. Expand List\n");
//         printf("9. Shrink List\n");
//         printf("10. Compress List\n");
//         printf("11. Exit\n");
//         printf("Enter your choice: ");
//         scanf("%d", &choice);

//         switch (choice) {
//             case 1:
//                 dealocateList_ListDin(&l);
//                 printf("Enter the new capacity of the dynamic list: ");
//                 scanf("%d", &capacity);
//                 CreateListDin(&l, capacity);
//                 printf("A new empty dynamic list has been created with capacity %d.\n", capacity);
//                 break;
//             case 2:
//                 readList_ListDin(&l);
//                 break;
//             case 3:
//                 printList_ListDin(l);
//                 printf("\n");
//                 break;
//             case 4:
//                 if (!isFull_ListDin(l)) {
//                     printf("Enter a value to add: ");
//                     scanf("%d", &val);
//                     insertLast_ListDin(&l, val);
//                 } else {
//                     printf("List is full. Cannot add more elements.\n");
//                 }
//                 break;
//             case 5:
//                 if (!isEmpty_ListDin(l)) {
//                     deleteLast_ListDin(&l, &el);
//                     printf("Last element deleted: %d\n", el);
//                 } else {
//                     printf("List is empty. Cannot delete elements.\n");
//                 }
//                 break;
//             case 6:
//                 if (isEmpty_ListDin(l)) {
//                     printf("The list is empty.\n");
//                 } else {
//                     printf("The list is not empty.\n");
//                 }
//                 break;
//             case 7:
//                 if (isFull_ListDin(l)) {
//                     printf("The list is full.\n");
//                 } else {
//                     printf("The list is not full.\n");
//                 }
//                 break;
//             case 8:
//                 printf("Enter how much to expand the list by: ");
//                 scanf("%d", &val);
//                 expandList_ListDin(&l, val);
//                 printf("The list has been expanded by %d.\n", val);
//                 break;
//             case 9:
//                 printf("Enter how much to shrink the list by: ");
//                 scanf("%d", &val);
//                 if (val < LISTDIN_CAPACITY(l)) {
//                     shrinkList_ListDin(&l, val);
//                     printf("The list has been shrunk by %d.\n", val);
//                 } else {
//                     printf("Cannot shrink the list by more than its current capacity.\n");
//                 }
//                 break;
//             case 10:
//                 compressList_ListDin(&l);
//                 printf("The list has been compressed.\n");
//                 break;
//             case 11:
//                 printf("Exiting...\n");
//                 dealocateList_ListDin(&l);
//                 break;
//             default:
//                 printf("Invalid choice. Please enter a number between 1 and 11.\n");
//         }
//     } while (choice != 11);

//     return 0;
// }
