/*
NAME:
DATE:
DESCRIPTION:
SAMPLE I/P:
SAMPLE O/P:
*/
#include<stdio.h>
#include"address.h"

int main()
{
    contact con[MAX_CONTACTS];
    int choice;

    load_contacts("address_book.data",con);

    do {
        printf("\n\nMENU\n");
        printf("1. Add contact\n");
        printf("2. List all contacts\n");
	printf("3.Search contact\n");
	printf("4.Edit contact\n");
	printf("5.Delete contact\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add(con);
                break;
            case 2:
                list(con);
                break;
	    case 3:
		search(con);
		break;
	    case 4:
		edit(con);
		break;
	    case 5:
		delete_contacts(con);
		break;
            case 6:
                printf("Exiting...\n");
		save_contacts("address_book.data",con);
		exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
		break;
        }
    } while (choice != 6);

    return 0;
}
