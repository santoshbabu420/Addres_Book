/*
NAME:santhoshkumar
DATE:7-7-2024
DESCRIPTION:Addres_book
*/
#include"address.h"

int current=0;

void add(contact *con)
{

   if(current < MAX_CONTACTS)
   {
        printf("Enter the contact details:\n");
        con[current].index = current+1;

        printf("ENTER THE NAME: ");
        scanf(" %[^\n]", con[current].name); // Space before %[^\n] is important

        printf("ENTER THE PHONE NUMBER: ");
        scanf(" %[^\n]", con[current].number);

        // Clear input buffer to avoid skipping next input
        while (getchar() != '\n');

        printf("ENTER THE EMAIL: ");
        scanf(" %[^\n]", con[current].mail); // Space before %[^\n] is important

        printf("ENTER THE AGE: ");
        scanf("%d", &con[current].age);

        // Clear input buffer to prepare for the next iteration
        while (getchar() != '\n');

        printf("ENTER THE ADDRESS: ");
        scanf(" %[^\n]", con[current].address);

	current++;
   }
   else
   {
       printf("ADDRESS BOOK IS FULL\n");
       printf("Cannot add more contacts.\n");
   }

}

void list(contact *con) 
{
    if(current == 0)
    {
	printf("No contacts in the address book.\n");
    }
    else
    {
    int j;
    printf("\n==================================================================\n");
    printf("|                        ADDRESS BOOK DETAILS                     |\n");
    printf("==================================================================\n");
    for (j = 0; j < current ; j++)
    {
        printf("Index: %d\n", con[j].index);
        printf("Name: %s\n", con[j].name);
        printf("Phone Number: %s\n", con[j].number);
        printf("Email: %s\n", con[j].mail);
        printf("Age: %d\n", con[j].age);
        printf("Address: %s\n", con[j].address);
        printf("==================================================================\n");
    }

    }
}

void search(contact *con)
{
    int i;
    char search_name[20];

    contact *found = NULL;

    printf("enter the name of contact to search:");
    scanf("%s",search_name);

    for(i=0;i<current;i++)
    {
	if(strcmp(search_name,con[i].name) == 0)
	{
	    found = &con[i];
	    break;
	}
    }

    if(found)
    {
	printf("-----------------------\n");
        printf("Index: %d\n", found->index);
        printf("Name: %s\n", found->name);
        printf("Phone Number: %s\n", found->number);
        printf("Email: %s\n", found->mail);
        printf("Age: %d\n", found->age);
	printf("-----------------------\n");
    }
    else
    {
	printf("Contact not found in the list.\n");
    }
}

void edit(contact *con)
{

    int i;
    char search_name[20];

    contact *found = NULL;

    printf("enter the name of contact to search:");
    scanf("%s",search_name);

    for(i=0;i<current;i++)
    {
	if(strcmp(search_name,con[i].name) == 0)
	{
	    found = &con[i];
	    break;
	}
    }

    if(found)
    {
//	printf("Enter the new contact Information:\n");
	printf("1.name\n2.phone number\n3.email\n4.age\n5.address\n");
	int opt;
	printf("enter the option:");
	scanf("%d",&opt);
	switch(opt)
	{
	    case 1:
        printf("Enter the contact details:\n");
       found->index = con->index;
        printf("ENTER THE NAME: ");
        scanf(" %[^\n]", found->name); // Space before %[^\n] is important
	printf("NAME updated sucessfully.\n");
	break;
	    case 2:
        printf("ENTER THE PHONE NUMBER: ");
        scanf(" %[^\n]", found->number);

        // Clear input buffer to avoid skipping next input
        while (getchar() != '\n');
	printf("NUMBER updated sucessfully.\n");
	break;
	    case 3:
        printf("ENTER THE EMAIL: ");
        scanf(" %[^\n]",found->mail); // Space before %[^\n] is important
	printf("MAIL updated sucessfully.\n");
	break;
	    case 4:
        printf("ENTER THE AGE: ");
        scanf("%d", &found->age);

        // Clear input buffer to prepare for the next iteration
        while (getchar() != '\n');
	printf("AGE updated sucessfully.\n");
	break;
	    case 5:
        printf("ENTER THE ADDRESS: ");
        scanf(" %[^\n]", found->address);
	printf("address updated sucessfully.\n");
	break;
	    default:
	puts("enter the input properly,");
	break;
	}
    }
    else
    {
	printf("contact not found.\n");
    }
}

void delete_contacts(contact *con)
{
    int i,j;

    char search_name[20];

    contact *found = NULL;

    printf("enter the name of contact to search:");
    scanf("%s",search_name);

    for(i=0;i<current;i++)
    {
	if(strcmp(search_name,con[i].name) == 0)
	{
	    found = &con[i];
	    break;
	}
    }
    if(found)
    {
	for(j=i;j<current-1;j++)
	{
	    con[j] = con[j+1];
	}
	current--;
	printf("Contact deleted succesfully.\n");
    }
    else
    {
	printf("Contact not found.\n");
    }
}

void load_contacts(const char *bookname,contact *con)
{
    FILE *fptr = fopen(bookname,"r");

    if(fptr)
    {
	while(current < MAX_CONTACTS && fread(&con[current],sizeof(contact),1,fptr))
	{
		current++;
	}
	fclose(fptr);
    }
   // else
    //{
//	printf("ERROR:THE FILE DOESNOT OPEN TO READ THE CONTACTS.\n");
  //  }
}

void save_contacts(const char *bookname,contact *con)
{
    FILE *fptr = fopen(bookname,"w");
    if(fptr)
    {
	fwrite(con,sizeof(contact),current,fptr);
	fclose(fptr);
    }
    else
    {
	printf("ERROR: THE FILE DOESNOT OPEN TO WRITE THE DATA.");
    }
}


