
#include "SDB.h"
#include "SDBAPP.h"
#include <stdio.h>
#include <stdbool.h>



void SDB_APP()
{
    uint8 choice;

    do
    {
        printf("Choose an option:\n");
        printf("1. Add entry\n");
        printf("2. Get used size in database\n");
        printf("3. Read student data\n");
        printf("4. Get the list of all student IDs\n");
        printf("5. Check if ID exists\n");
        printf("6. Delete student data\n");
        printf("7. Check if database is full\n");
        printf("0. Exit\n");

        printf("\n Enter your choice:     ");
        scanf("%hhu", &choice);

        SDB_action(choice);
    } while (choice != 0);
}

void SDB_action(uint8 choice)
{
    switch (choice)
    {
    case 1:
    {
        bool success = SDB_AddEntry();
        if (success)
        {
            printf("Entry added successfully.\n");
        }
        else
        {
            printf("Failed to add entry. Database is full.\n");
        }
        break;
    }
    case 2:
    {
        uint8 size = SDB_GetUsedSize();
        printf("Used size in the database: %hhu\n", size);
        break;
    }
    case 3:
    {
        uint32 id;
        printf("Enter the student ID: ");
        scanf("%u", &id);
        bool success = SDB_ReadEntry(id);
        if (!success)
        {
            printf("Student data not found.\n");
        }
        break;
    }
    case 4:
    {
        uint8 count;
        uint32 list[MAX_STUDENTS];
        SDB_GetList(&count, list);

        printf("List of all student IDs:\n");
        for (uint8 i = 0; i < count; i++)
        {
            printf("%u\n", list[i]);
        }
        break;
    }
    case 5:
    {
        uint32 id;
        printf("Enter the student ID: ");
        scanf("%u", &id);
        bool exists = SDB_IsIdExist(id);
        if (exists)
        {
            printf("ID exists in the database.\n");
        }
        else
        {
            printf("ID does not exist in the database.\n");
        }
        break;
    }
    case 6:
    {
        uint32 id;
        printf("Enter the student ID: ");
        scanf("%u", &id);
        SDB_DeleteEntry(id);
        break;
    }
    case 7:
    {
        bool isFull = SDB_IsFull();
        if (isFull)
        {
            printf("Database is full.\n");
        }
        else
        {
            printf("Database is not full.\n");
        }
        break;
    }
    case 0:
    {
        printf("Exiting the program.\n");
        break;
    }
    default:
    {
        printf("Invalid choice. Please try again.\n");
        break;
    }
    }
}
