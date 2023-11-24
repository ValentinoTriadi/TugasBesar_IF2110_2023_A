#include "linkedlist.h"

int main() {
    LinkedList l;
    int choice;
    ElType_LinkedList val;
    int index;
    ElType_LinkedList el;
    CreateList_LinkedList(&l);

    do {
        printf("\nLinked LinkedList Operations\n");
        printf("1. Insert First\n");
        printf("2. Insert Last\n");
        printf("3. Insert At\n");
        printf("4. Delete First\n");
        printf("5. Delete Last\n");
        printf("6. Delete At\n");
        printf("7. Display LinkedList\n");
        printf("8. LinkedList Length\n");
        printf("9. Concatenate Two Lists\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a value to insert at the beginning: ");
                scanf("%d", &val);
                insertFirst_LinkedList (&l, val);
                break;
            case 2:
                printf("Enter a value to insert at the end: ");
                scanf("%d", &val);
                insertLast_LinkedList (&l, val);
                break;
            case 3:
                printf("Enter the index and value to insert: ");
                scanf("%d %d", &index, &val);
                insertAt_LinkedList (&l, val, index);
                break;
            case 4:
                deleteFirst_LinkedList (&l, &el);
                printf("First element deleted: %d\n", el);
                break;
            case 5:
                deleteLast_LinkedList (&l, &el);
                printf("Last element deleted: %d\n", el);
                break;
            case 6:
                printf("Enter the index to delete: ");
                scanf("%d", &index);
                deleteAt_LinkedList (&l, index, &el);
                printf("Element at index %d deleted: %d\n", index, el);
                break;
            case 7:
                printf("Current LinkedList: ");
                displayList_LinkedList (l);
                printf("\n");
                break;
            case 8:
                printf("LinkedList Length: %d\n", length_LinkedList (l));
                break;
            case 9: {
                LinkedList l1, l2, lConcatenated;
                CreateList_LinkedList(&l1);
                insertLast_LinkedList (&l1, 1);
                insertLast_LinkedList (&l1, 2);

                CreateList_LinkedList(&l2);
                insertLast_LinkedList (&l2, 3);
                insertLast_LinkedList (&l2, 4);

                lConcatenated = concat_LinkedList (l1, l2);
                printf("Concatenated LinkedList: ");
                displayList_LinkedList (lConcatenated);
                printf("\n");
                break;
            }
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
                break;
        }
    } while (choice != 10);

    return 0;
}
