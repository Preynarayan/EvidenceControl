//Assignment 3 header file By Prayanshu Narayan S#101144277
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define C_OK       0
#define C_NOK     -1

#define MAX_STR       32
#define MAX_CAP       2
#define MAX_TIME_STR  9

//Evidence Struct
typedef struct {	
  int   id;
  char  room[MAX_STR];
  char  device[MAX_STR];
  float value;
  int   timestamp;
} EvidenceType;

//Evidence Struct Array
typedef struct {
  EvidenceType *elements;
  int capacity;
  int size;
} EvidenceArray;

//Forward Declarations
void printMenu(int* choice);
void loadEvidenceData(EvidenceArray* dest);

void initEvidenceArray(EvidenceArray* evArr, int cap);
void initEvidence(int id, char* room, char* device, float value, int timestamp, EvidenceType* dest);

void addEvidence(EvidenceArray* dest, EvidenceType* src);
int  delEvidence(EvidenceArray* src , int id);
void copyEvidence(EvidenceType* dest, EvidenceType* src);
void printEvidence(EvidenceType*);

void printEvidenceArray(EvidenceArray*);
void cleanupEvidenceArray(EvidenceArray*);
 
//helpers
int ghostRangeValid(float value, char* device);
int timeStrToInt(char* timeStr);
int findInsertPoint(EvidenceArray* evArr, EvidenceType*arr);
void cleanupEvidence(EvidenceType*);

//void loadEvidenceData2(EvidenceArray* arr);