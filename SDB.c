#include "SDB.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_STUDENTS 10

student database[MAX_STUDENTS];
uint8 usedSize = 0;

bool SDB_IsFull()
{
    return usedSize == MAX_STUDENTS;
}

uint8 SDB_GetUsedSize()
{
    return usedSize;
}

bool SDB_AddEntry()
{
    if (usedSize >= MAX_STUDENTS)
    {
        return false; // Database is full, cannot add more entries
    }

    // Ask user for data
    printf("Enter Student ID: ");
    scanf("%u", &database[usedSize].Student_ID);

    printf("Enter Student Year: ");
    scanf("%u", &database[usedSize].Student_year);

    printf("Enter Course 1 ID: ");
    scanf("%u", &database[usedSize].Course1_ID);

    printf("Enter Course 1 Grade: ");
    scanf("%u", &database[usedSize].Course1_grade);

    printf("Enter Course 2 ID: ");
    scanf("%u", &database[usedSize].Course2_ID);

    printf("Enter Course 2 Grade: ");
    scanf("%u", &database[usedSize].Course2_grade);

    printf("Enter Course 3 ID: ");
    scanf("%u", &database[usedSize].Course3_ID);

    printf("Enter Course 3 Grade: ");
    scanf("%u", &database[usedSize].Course3_grade);

    usedSize++;  // Increment used size after adding an entry
    return true; // Entry added successfully
}

void SDB_DeleteEntry(uint32 id)
{
    for (uint8 i = 0; i < usedSize; i++)
    {
        if (database[i].Student_ID == id)
        {
            // Shift entries to remove the deleted one
            for (uint8 j = i; j < usedSize - 1; j++)
            {
                database[j] = database[j + 1];
            }

            usedSize--; // Decrement used size after deletion
            printf("Entry with ID %u deleted.\n", id);
            return;
        }
    }

    printf("Entry with ID %u not found.\n", id);
}

bool SDB_ReadEntry(uint32 id)
{
    for (uint8 i = 0; i < usedSize; i++)
    {
        if (database[i].Student_ID == id)
        {
            printf("Student ID: %u\n", database[i].Student_ID);
            // Print other fields...
            return true; // Entry found
        }
    }

    printf("Entry with ID %u not found.\n", id);
    return false; // Entry not found
}

void SDB_GetList(uint8 *count, uint32 *list)
{
    *count = usedSize;

    for (uint8 i = 0; i < usedSize; i++)
    {
        list[i] = database[i].Student_ID;
    }
}

bool SDB_IsIdExist(uint32 id)
{
    for (uint8 i = 0; i < usedSize; i++)
    {
        if (database[i].Student_ID == id)
        {
            return true; // ID exists
        }
    }

    return false; // ID not found
}
