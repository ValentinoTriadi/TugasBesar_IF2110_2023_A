#include "liststatik.h"
#include <stdio.h>

int main() {
    ListStatik l, l2, lConcatenated;
    int choice, val, index;
    ElTypeLISTSTATIK el;
    CreateListStatik(&l); 

    do {
        printf("\n");
        printf("List Statik Operation\n");
        printf("1. Create New List\n");
        printf("2. Read List\n");
        printf("3. Print List\n");
        printf("4. Add First Element\n");
        printf("5. Add Last Element\n");
        printf("6. Add Element at Index\n");
        printf("7. Delete First Element\n");
        printf("8. Delete Last Element\n");
        printf("9. Delete Element at Index\n");
        printf("10. Check if List is Empty\n");
        printf("11. Check if List is Full\n");
        printf("12. Concatenate Another List to Current List\n");
        printf("13. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                CreateListStatik(&l);
                printf("A new empty list has been created.\n");
                break;
            case 2:
                readListStatik(&l);
                break;
            case 3:
                printListStatik(l);
                printf("\n");
                break;
            case 4:
                printf("Enter a value to add: ");
                scanf("%d", &val);
                insertFirstLISTSTATIK(&l, val);
                break;
            case 5:
                printf("Enter a value to add: ");
                scanf("%d", &val);
                insertLastLISTSTATIK(&l, val);
                break;
            case 6:
                printf("Enter the index and a value to add: ");
                scanf("%d %d", &index, &val);
                insertAtLISTSTATIK(&l, val, index);
                break;
            case 7:
                deleteFirstLISTSTATIK(&l, &el);
                printf("First element deleted: %d\n", el);
                break;
            case 8:
                deleteLastLISTSTATIK(&l, &el);
                printf("Last element deleted: %d\n", el);
                break;
            case 9:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                deleteAtLISTSTATIK(&l, &el, index);
                printf("Element at index %d deleted: %d\n", index, el);
                break;
            case 10:
                if (isEmptyLISTSTATIK(l)) {
                    printf("The list is empty.\n");
                } else {
                    printf("The list is not empty.\n");
                }
                break;
            case 11:
                if (isFullLISTSTATIK(l)) {
                    printf("The list is full.\n");
                } else {
                    printf("The list is not full.\n");
                }
                break;
            case 12:
                CreateListStatik(&l2); 

                printf("You will now enter another list to concatenate with the current list.\n");
                readListStatik(&l2); 

                if ((listStatikLength(l) + listStatikLength(l2)) <= CAPACITY) {
                    lConcatenated = concat_ListStatik(l, l2); 
                    l = lConcatenated; 

                    printf("The lists have been concatenated. The new list is:\n");
                    printListStatik(l); 
                    printf("\n");
                } else {
                    printf("Cannot concatenate the lists. The combined length exceeds the capacity.\n");
                }
                break;
            case 13:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please enter a number between 1 and 13.\n");
        }
    } while (choice != 13);

    return 0;
}
