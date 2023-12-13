#include "defs.h"



/* 
  Function: Intialize an evidence

  Purpose:  intializes the paramter to the correct part of the evidence type dest

  Params:   int id:             room ID
            char* room:         Room Name
            char* device:       Measuring Device
            float value:        Value from the input array
            int timestamp:      The measured
            EvidenceType* dest: The evidence to intialize those parameters to

    Output: EvidenceType* dest: The evidence to intialize those parameters to
*/
void initEvidence(int id, char* room, char* device, float value, int timestamp, EvidenceType* dest){
  dest->id = id;
  strcpy(dest->room, room);
  strcpy(dest->device, device);
  dest->value = value;
  dest->timestamp = timestamp;
  
}

/* 
  Function: Intialize an evidence Array

  Purpose:  intializes an evidence Array with the capacity of cap

  Params:   int cap:             Capacity of the array
            EvidenceArray* evArry: The evidence array to intialize

    Output: EvidenceArray* evArry: The evidence array to intialize      
*/
void initEvidenceArray(EvidenceArray* evArr, int cap){
  

  evArr->size = 0;
  evArr->capacity = cap;
  //evArr = (EvidenceArray*) calloc (1,sizeof(EvidenceArray));
  evArr->elements = (EvidenceType*) calloc(cap, sizeof(EvidenceType));
}




void loadEvidenceData(EvidenceArray* arr)
{
  EvidenceType a;
  // Add sample evidence data
  // Evidence has an ID, room location, type (EMF/THERMAL/SOUND), value, and timestamp in seconds
  initEvidence(1000, "Living Room", "EMF", 4.869, 19554, &a);
  addEvidence(arr, &a);
  initEvidence(1001, "Nursery", "EMF", 2.08, 4260, &a);
  addEvidence(arr, &a);
  initEvidence(1002, "Nursery", "SOUND", 88.8, 4120, &a);
  addEvidence(arr, &a);
  initEvidence(1003, "Living Room", "EMF", 4.9, 17157, &a);
  addEvidence(arr, &a);
  initEvidence(1004, "Living Room", "SOUND", 35.154, 20970, &a);
  addEvidence(arr, &a);
  initEvidence(1005, "Bathroom", "THERMAL", 16.22806, 15936, &a);
  addEvidence(arr, &a);
  initEvidence(1006, "Kitchen", "EMF", 0.439, 609, &a);
  addEvidence(arr, &a);
  initEvidence(1007, "Kitchen", "THERMAL", 9.3643, 11797, &a);
  addEvidence(arr, &a);
  initEvidence(1008, "Bathroom", "EMF", 2.1254, 20166, &a);
  addEvidence(arr, &a);
  initEvidence(1009, "Living Room", "SOUND", 44.8, 12701, &a);
  addEvidence(arr, &a);
  initEvidence(1010, "Dining Room", "EMF", 3.871087, 17593, &a);
  addEvidence(arr, &a);
  initEvidence(1011, "Main Bedroom", "SOUND", 79.0739, 2862, &a);
  addEvidence(arr, &a);
  initEvidence(1012, "Bathroom", "THERMAL", 10.649717, 9292, &a);
  addEvidence(arr, &a);
  initEvidence(1013, "Living Room", "EMF", 4.142, 8384, &a);
  addEvidence(arr, &a);
  initEvidence(1014, "Nursery", "THERMAL", -8.2, 328, &a);
  addEvidence(arr, &a);
  initEvidence(1015, "Dining Room", "SOUND", 49.9, 20757, &a);
  addEvidence(arr, &a);
  initEvidence(1016, "Living Room", "THERMAL", 3.4364, 16043, &a);
  addEvidence(arr, &a);
  initEvidence(1017, "Dining Room", "THERMAL", -1.462089, 14241, &a);
  addEvidence(arr, &a);
  initEvidence(1018, "Living Room", "EMF", 3.484842, 6222, &a);
  addEvidence(arr, &a);
  initEvidence(1019, "Living Room", "EMF", 2.87804, 15926, &a);
  addEvidence(arr, &a);
  initEvidence(1020, "Living Room", "EMF", 4.782, 19880, &a);
  addEvidence(arr, &a);
  initEvidence(1021, "Nursery", "THERMAL", -6.9681, 2905, &a);
  addEvidence(arr, &a);

}

//Test Function made to tess the program.

void loadEvidenceData2(EvidenceArray* arr){
  EvidenceType a;

  // Add sample evidence data with entirely different values, including different IDs
  initEvidence(2000, "Living Room", "EMF", 4.123, 9876, &a);
  addEvidence(arr, &a);

  initEvidence(2001, "Bedroom", "SOUND", 12.345, 5432, &a);
  addEvidence(arr, &a);

  initEvidence(2002, "Kitchen", "THERMAL", 67.89, 1234, &a);
  addEvidence(arr, &a);

  initEvidence(2003, "Bathroom", "EMF", 1.234, 5678, &a);
  addEvidence(arr, &a);

  initEvidence(2004, "Garage", "SOUND", 56.789, 4321, &a);
  addEvidence(arr, &a);

  initEvidence(2005, "Office", "THERMAL", 12.345, 9876, &a);
  addEvidence(arr, &a);

  initEvidence(2006, "Library", "EMF", 1.234, 5678, &a);
  addEvidence(arr, &a);

  initEvidence(2007, "Pantry", "SOUND", 67.89, 1234, &a);
  addEvidence(arr, &a);

  initEvidence(2008, "Dining Room", "THERMAL", 12.345, 4321, &a);
  addEvidence(arr, &a);

  initEvidence(2009, "Guest Bedroom", "EMF", 56.789, 9876, &a);
  addEvidence(arr, &a);

  initEvidence(2010, "Basement", "SOUND", 1.234, 5678, &a);
  addEvidence(arr, &a);

  initEvidence(2011, "Attic", "THERMAL", 67.89, 1234, &a);
  addEvidence(arr, &a);

  initEvidence(2012, "Laundry Room", "EMF", 12.345, 4321, &a);
  addEvidence(arr, &a);

  initEvidence(2013, "Gym", "SOUND", 1.234, 9876, &a);
  addEvidence(arr, &a);

  initEvidence(2014, "Sunroom", "THERMAL", 56.789, 5678, &a);
  addEvidence(arr, &a);

  initEvidence(2015, "Closet", "EMF", 12.345, 1234, &a);
  addEvidence(arr, &a);

  initEvidence(2016, "Master Bedroom", "SOUND", 67.89, 4321, &a);
  addEvidence(arr, &a);

  initEvidence(2017, "Child's Room", "THERMAL", 1.234, 9876, &a);
  addEvidence(arr, &a);

  initEvidence(2018, "Guest Bathroom", "EMF", 56.789, 5678, &a);
  addEvidence(arr, &a);

  initEvidence(2019, "Playroom", "SOUND", 12.345, 1234, &a);
  addEvidence(arr, &a);

  initEvidence(2020, "Study", "THERMAL", 67.89, 4321, &a);
  addEvidence(arr, &a);

  initEvidence(2021, "Home Theater", "EMF", 1.234, 9876, &a);
  addEvidence(arr, &a);
}

