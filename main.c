#include <stdio.h>
#include <string.h>

#include "defs.h"


//Main Function
int main()
{
  //Main Evidence Array and initialization
  EvidenceArray mainArr;
  initEvidenceArray(&mainArr, MAX_CAP);


  //Adding Evidence type
  EvidenceType addEv;
  //EvidenceType dest;

  //For user input
  int choice = -1;
  int evType =0;
  char time[MAX_TIME_STR];

  int   id;
  char  room[MAX_STR];
  char  device[MAX_STR];
  float value;
  int   timestamp;

  loadEvidenceData(&mainArr);
  
  //Uncomment if you want more Data
  // loadEvidenceData2(&mainArr);

  //starting the program
  while(choice != 0){
    printMenu(&choice);
    switch(choice){

      //add Evidence
      case 1:
        printf("Please add the evidence:\n");
        //get ID
        printf("Enter the evidence ID:");
        scanf("%d", &id);
        while(getchar() != '\n');

        //get room name
        printf("Enter the room name:");
        fgets(room, MAX_STR, stdin);
        room[strlen(room)] = 0;
        
        //get the device code
        printf("Enter the device code [EMF: 1, THERMAL: 2, SOUND: 3]:");
        scanf("%d", &evType);
        while(getchar() != '\n');
        if(evType == 1){
          strcpy(device, "EMF");
          
        } else if(evType == 2){
          strcpy(device, "THERMAL");
        } else if(evType == 3){
          strcpy(device, "SOUND");
        } else {
          //if a valid id device code isnt enter
          printf("Please Enter a valid device code try again!");
        }
        

        //get value
        printf("Enter the evidence value:");
        scanf("%f", &value);
        while(getchar() != '\n');

        //get timestamp
        printf("Enter time stamp (Hours, minutes, seconds, space seperated):");
        fgets(time, MAX_TIME_STR, stdin);
        time[strlen(time)-1] = 0;
        timestamp = timeStrToInt(time);
        room[strlen(room)-1] = 0;
        initEvidence(id, room, device, value, timestamp, &addEv);
        printf(" \n");

        //Evidence was added!
        addEvidence(&mainArr, &addEv);
        printf("Evidence was ADDED!\n");

        break;

      //delete Evidence
      case 2:
        int id;
        printf("Enter the ID of the room you want to delete\n");
        scanf("%d", &id);
        if(delEvidence(&mainArr, id) == 0){
          printf("Evidence was Deleted!\n");
        } else if(delEvidence(&mainArr, id) == -1 ){
          printf("Array is empty or unintialized!\n");
        }else{
          printf("404: Evidence Not FOUND!!!!\n");
        }
      
        break;

      //print Evidence
      case 3:
        printf("Printing Array!\n");
        printEvidenceArray(&mainArr);
        break;
      // Exit the program
      case 0:
        cleanupEvidenceArray(&mainArr);
        printf("Exiting the Program!\n");
        break;
      //invalid selection
      default:
        printf("Please enter a valid selection and try again\n");


    }
  }
  
  //To test copying evidence
  //testCopy(&dest, &addEv);

  return(0);
}

/* 
  Function: Print Menu
  Purpose:  Print the main menu and get the user's choice via user input
  Params:   
    Output: int* choice - the choice typed by the user
*/
void printMenu(int* choice)
{
  // NOTE: Do not make _any_ modifications to this function.
  int c = -1;
  int numOptions = 3;

  printf("\nMAIN MENU\n");
  printf("  (1) Add evidence\n");
  printf("  (2) Delete evidence\n");
  printf("  (3) Print evidence\n");
  printf("  (0) Exit\n\n");

  printf("Please enter your selection: ");
  scanf("%d", &c);

  if (c == 0) {
    *choice = c;
    return;
  }

  while (c < 0 || c > numOptions) {
    printf("Please enter your selection: ");
    scanf("%d", &c);
  }

  *choice = c;
}

