
#ifndef SDB_H
#define SDB_H

#define MAX_STUDENTS 10
#include "STD.h"
#include <stdint.h>
#include <stdbool.h>

// typedef unsigned char uint8;
// typedef char Int8;
// typedef unsigned short uint16;
// typedef short int16;
// typedef unsigned int uint32;
// typedef int int32;

// typedef enum
// {
//     FALSE = 0,
//     TRUE = 1
// } bool;

typedef struct SimpleDb
{
    uint32 Student_ID;
    uint32 Student_year;
    uint32 Course1_ID;
    uint32 Course1_grade;
    uint32 Course2_ID;
    uint32 Course2_grade;
    uint32 Course3_ID;
    uint32 Course3_grade;
} student;

bool SDB_IsFull();
uint8 SDB_GetUsedSize();
bool SDB_AddEntry();
void SDB_DeleteEntry(uint32 id);
bool SDB_ReadEntry(uint32 id);
void SDB_GetList(uint8 *count, uint32 *list);
bool SDB_IsIdExist(uint32 id);

// bool SDB_IsFull(void);
// uint8_t SDB_GetUsedSize(void);
// bool SDB_AddEntry(void);
// void SDB_DeleteEntry(uint32_t id);
// bool SDB_ReadEntry(uint32_t id);
// void SDB_GetList(uint8_t *count, uint32_t *list);
// bool SDB_IsIdExist(uint32_t id);

#endif



