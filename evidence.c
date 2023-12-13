#include "defs.h"



/* 
  Function: Print the Evidence

  Purpose:  To print the the Evidence ev to the console

  Params:   
            EvidenceType* ev: The evidence to print

    Output: printing to the console    
*/
void printEvidence(EvidenceType* ev){
  

    //Print Room ID
    printf("%3d |", ev->id);
    //Print Room
    printf("%20s|", ev->room);
    //Print the Device
    printf("%11s|", ev->device);
    //Print the Value
    if(ghostRangeValid(ev->value, ev->device) == 1){
        printf("%18.1f (HIGH)|", ev->value);

    } else if(ghostRangeValid(ev->value, ev->device) == 2){
        printf("%18.2f (COLD)|", ev->value);
    } else if(ghostRangeValid(ev->value, ev->device) == 3){
        printf("%16.1f (SCREAM)|", ev->value);
    } else if(ghostRangeValid(ev->value, ev->device) == 4){
        printf("%15.1f (WHISPER)|", ev->value);
    } else if(strcmp(ev->device, "SOUND") == 0 || strcmp(ev->device, "EMF") == 0 ){
        printf("%25.1f|", ev->value);
    } else if(strcmp(ev->device, "THERMAL") == 0){
        printf("%25.2f|", ev->value);   
    }
    
    //Print TimeStamp
    int hours = ev->timestamp / 3600;
    int mins = (ev->timestamp % 3600)/60;
    int secs = (ev->timestamp % 3600) % 60;


    printf("   %02d:%02d:%02d\n", hours, mins, secs);


}


/* 
  Function: Copy Evidence

  Purpose:  To copy the evidence from the source to the dest

  Params:   
            EvidenceType* dest: The destenation evidence 
            EvidenceType* src: The source evidence 

    Output:  EvidenceType* dest: The destenation evidence 
*/
void copyEvidence(EvidenceType* dest, EvidenceType* src){
    initEvidence(src->id, src->room, src->device, src->value, src->timestamp, dest);

}


/* 
  Function: Grow Evidence

  Purpose:  To grow the evidence array to double its capacity
  Params:   
            EvidenceArray* evArr: The evidence array to grow
            

    Output: EvidenceArray* evArr: The evidence array to grow 
*/
void growEvidenceArray(EvidenceArray* evArr){
  EvidenceType *tempArr = (EvidenceType*) calloc(2*evArr->capacity, sizeof(EvidenceType));

 
  for(int i = 0; i< evArr->size; i++){    

    copyEvidence(&tempArr[i], &evArr->elements[i]);
    //printf("Added\n");


    
  }
  
  evArr->capacity = 2*evArr->capacity;
  free(evArr->elements);
  
//   for(int j = 0; j< evArr->size; j++){
//     copyEvidence(&evArr->elements[j],&tempArr[j] );

    
//   }
  evArr->elements = tempArr;
  //free(tempArr);

}


/* 
  Function: Add Evidence

  Purpose:  To add evidence from the source to the dest array 
            the function calls growArray() if needed.
  Params:   
            EvidenceArray* dest: The evidence array to add to
            EvidenceType* src: The evidence type adding

    Output: EvidenceArray* dest: The evidence array to add to

*/
void addEvidence(EvidenceArray* dest, EvidenceType* src) {
   

    if(dest->size == dest->capacity){

        growEvidenceArray(dest);
        int insertPoint = findInsertPoint(dest, src);
        for (int i = dest->size; i > insertPoint; i--) {
            copyEvidence(&dest->elements[i], &dest->elements[i - 1]);
        }
        copyEvidence(&dest->elements[insertPoint],src);
        //dest->elements[insertPoint] = *src;
        dest->size++;

    }else{
        int insertPoint = findInsertPoint(dest, src);
        for (int i = dest->size; i > insertPoint; i--) {
            copyEvidence(&dest->elements[i], &dest->elements[i - 1]);
        }
        copyEvidence(&dest->elements[insertPoint],src);
        //dest->elements[insertPoint] = *src;
        
        dest->size++;
    }
}


/* 
  Function: Print an Evidence Array

  Purpose:  To print an evidence array to the console
            the function calls printEvidence() to print each evidence
  Params:   
            EvidenceArray* evArr: Evidence array to print

    Output: printiing to console

*/
void printEvidenceArray(EvidenceArray* evArr){
    printf("  ID |               Room |    Device |                   Value | Timestamp \n");
    for(int i = 0; i <evArr->size; i++){
        printEvidence(evArr->elements+i);
    }
}



void cleanupEvidenceArray(EvidenceArray* evArr){
    // for(int i = 0; i<evArr->size; i++){
    //     free(&evArr->elements[i]);
    // }
    free(evArr->elements);
    //free(evArr);
}


/* 
  Function: Delete Evidence

  Purpose:  To delete evidence from the source with the given id
  Params:   
            EvidenceArray* src: The evidence type adding
            int             id: The id of the evidence to delete

    Output: return 1: if ID not foudn
            return 0: if deleting was a sucess
            return -1: for invalid arguements

*/
int  delEvidence(EvidenceArray* src , int id){
    if (src == NULL || src->elements == NULL || src->size == 0) {
        // Handle invalid arguments
        return -1; // Error code for invalid arguments
    }

    for (int i = 0; i < src->size; i++) {
        if (src->elements[i].id == id) {
            // Found the ID, now shift elements to fill the gap
            for (int j = i; j < src->size - 1; j++) {
                src->elements[j] = src->elements[j + 1];
            }
            src->size--;
            return 0; // Success
        }
    }

    return 1; //ID not found

}
//Helper Functions

/*
Funtions:ghostRangeValid(float value, char* device)
Return 1 if EMF is above 4.0
Return 2 if THERMAL is <0.0
Return 3 if SOUND is >70.0
Return 4 if SOUND is < 35.0
*/
int ghostRangeValid(float value, char* device){
    if(strcmp(device, "EMF") == 0 && value >4.0){
        return 1;

    } else if(strcmp(device, "THERMAL") == 0 && value < 0.0){
        return 2;
    } else if (strcmp(device, "SOUND") == 0){
        if(value < 35.0){
            return 4;
        } else if (value > 70.0){
            return 3;
        }

    } else{
        return 0;
    }
    return 0;
}

//Test copyEvidence!
void testCopy(EvidenceType* dest, EvidenceType* src){
    
    printf("Printing Dest!\n");
    printEvidence(dest);
    printf("Printing Source!!!\n");
    printEvidence(src);
    copyEvidence(dest, src);
    printf("Printing Dest AFTER COPY!\n");
    printEvidence(dest);
    printf("Printing Source AFTER COPY!!!\n");
    printEvidence(src);


}
// Time as a string to time as an int
int timeStrToInt(char* timeStr){
    int hours;
    int mins;
    int seconds;
    int timeStamp;

    sscanf(timeStr, "%d %d %d", &hours, &mins, &seconds);
    timeStamp = (hours*3600) + (mins*60) + seconds;
    return timeStamp;
    
}

int findInsertPoint(EvidenceArray* evArr, EvidenceType*ev){
    int inPoint = evArr->size;
    while(inPoint > 0){
        EvidenceType* currEv = &evArr->elements[inPoint - 1];
        int compRmName = strcmp(ev->room, currEv->room);

        if(compRmName > 0 || (compRmName == 0 && ev->timestamp >= currEv->timestamp)) { 
            break;
        }
        // if(inPoint==1){
        //     break;
        // }
        

        //evArr->elements[inPoint] = *currEv;
        inPoint--;
        

    }
    return inPoint;




    // if(evArr->size == 0){
    //     return inPoint;
    // }
    //Go through the array and compare 
    //the first leter of ev->room to the first letter of the 
    //evArr->elements->
    // for(int i = 0; i < evArr->size;i++){
    //     if(strcmp(evArr->elements[i].room[i],  ev->room[i])){
    //         inPoint = i;
    //         return inPoint;
    //     }

    // }
    // return 0;

}
