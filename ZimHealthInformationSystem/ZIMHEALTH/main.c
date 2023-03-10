/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.c
 * Author: kundaikwangwari
 *
 * Created on August 11, 2019, 1:23 AM
 */

#include "HEADERS.h"

/*
 * 
 */


int track = 0, ErrorCheck = False;





void RetrieveDataAddress(){
    
    char name[100], surname[100], ID[35];
    printf("Enter patient name: "); scanf("%s",name); 
    if(StringToUpperCase(name) != True){
        ErrorCheck = True; 
        return;
    }
    Encrypt(name);
    //printf("recovered name %s\n",name);
    printf("Enter patient surname: "); scanf("%s", surname);
    if(StringToUpperCase(&surname) != True){
        ErrorCheck = True;
        return;
    }
    Encrypt(surname);
    //printf("recovered name %s\n",surname);
    printf("Enter patient ID: "); scanf("%s",ID);
    if(IsIDCorrect(&ID)!=True){
        ErrorCheck = True;
        return;
    }
    
    printf("Searching...\n");
    int found = False;
    
    for(int i = AlpNum; i >= 0; i--){
     struct node *temp, *Visits;
     printf("%d\n",i);
    temp = L[i].AddressOfFirst;
    
    //if(temp == NULL)printf("There is no data in the database %d.\n\n\n",i);
    
    while(temp != NULL && found == False){
        if((strcmp(temp->patient.name,name) == 0) && (strcmp(temp->patient.surname,surname) == 0) && (strcmp(temp->patient.ID,ID)== 0)){
                    
                    
                     printf("Patient database located \n\n\n");
                     RetrieveAddress = temp;
                     found = True;
                     break;
                }
        temp = temp->prev;
        }
    }
    if(found == False){
        printf("Patient not registered in database\n\n\n");
        RetrieveAddress = NULL;
    }
    
    return;
}

void SearchPatientData(){
 
    printf("Searching...\n");
    RetrieveDataAddress();
    printf("Search completed...\n");
   
     struct node* temp,*Visits;
     int num = 0, Response;
    temp = RetrieveAddress;
    //if(temp == NULL)printf("There is no data in the database %d.\n\n\n",i);
    if(temp == NULL){
        printf("Patient not registered in database\n\n\n");
        RetrieveAddress = NULL;
        return;
    }
    else if(temp != NULL){
                    
                    //RetrieveAddress = temp;
                     printf("Case number: %d\n",++num);
                     printf("Date visited: %d/ %d/ %d\n",temp->patient.Visited.Day, temp->patient.Visited.Month, temp->patient.Visited.Year);
                     printf("Name: %s  \nSurname: %s  \nGender: %s,  \nAge %d   \nProvisional Diagnosis: %s\nDiagnosis: %s\nManagement: %s\nOutcome: %s\n",
                     temp->patient.name,temp->patient.surname,temp->patient.Gender,temp->patient.age, temp->patient.ProvisionalDiagnosis, temp->patient.Diagnosis,
                     temp->patient.Management, temp->patient.Outcome);
                     
                        if(RetrieveAddress->NextVisit_NodeAddress != NULL){
                            Visits = RetrieveAddress->NextVisit_NodeAddress;
                            while(Visits != NULL){
                                printf("\n\n");
                                printf("Case number: %d\n",++num);   
                                printf("Next Visit Date: %d/ %d/ %d \nProvisional Diagnosis: %s\nDiagnosis: %s\nManagement: %s\nOutcome: %s\n",Visits->patient.Visited.Day,
                                Visits->patient.Visited.Month,Visits->patient.Visited.Year, Visits->patient.ProvisionalDiagnosis, Visits->patient.Diagnosis,
                                Visits->patient.Management, Visits->patient.Outcome);   
                                //if(Visits->patient.UniqueCaseID == Visits->NextVisit_NodeAddress->patient.UniqueCaseID)break;
                                Visits = Visits->NextVisit_NodeAddress;
                                
                        
                            }
                        }
                     
                     printf("Do you want to view full patient file (Yes(1) or No(0): ");scanf("%d",&Response);
                     if(Response == True){
                         printf("please enter case number: ");scanf("%d",&Response);Visits = RetrieveAddress;                      
                         for(int i = 1;;i++){
                         if(i == Response){                   
                           printf("Case number: %d\n",Response);
                     printf("Date visited: %d/ %d/ %d\n",Visits->patient.Visited.Day, Visits->patient.Visited.Month, Visits->patient.Visited.Year);
                     printf("Name: %s  \nSurname: %s  \nGender: %s,  \nAge %d\n Symptoms: %s\nExamination Conducted: %s\nExamination Results: %s\n"
                             "Provisional Diagnosis: %s\nDiagnosis: %s\nManagement: %s\nOutcome: %s\n",
                     Visits->patient.name,Visits->patient.surname,Visits->patient.Gender,Visits->patient.age,Visits->patient.FileDetails.symptoms,
                             Visits->patient.FileDetails.ConductedTests,Visits->patient.FileDetails.TestResults,Visits->patient.ProvisionalDiagnosis,
                             Visits->patient.Diagnosis,Visits->patient.Management, Visits->patient.Outcome);
                             return;
                         }
                         if(Visits->NextVisit_NodeAddress == NULL){printf("The case you selected is not available\n");RetrieveAddress = NULL;break;}
                         else Visits = Visits->NextVisit_NodeAddress;
                     }
                         
                     }   
                
        RetrieveAddress = NULL;
        }
    return;
    } 

/*
void display(){  

    for(int i = AlpNum; i >= 0; i--){
        
    struct node* temp, *Visits;
    temp = L[i].AddressOfFirst; //this gets the head of each alp numeric section
    int num = 0;

    
    //The problem here is the address of the numerical class is same for start and end,
    //printf("\n\n iteration %d is %u\n\n",i,L[i].AddressOfLast);
 //   if(temp == NULL)printf("\n\n\nThere is no data in the database.\n\n\n");
    printf("Searching...\n");

    while(temp != NULL){
     printf("\n\n*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *\n\n");
     //printf("debugging...Name: %s  \n",temp->patient.name);
    printf("Case number: %d\n",++num);
    //printf("Date visited: %d/ %d/ %d\n",temp->patient.Visited.Day, temp->patient.Visited.Month, temp->patient.Visited.Year);
    printf("Name: %s  \nSurname: %s  \nGender: %s  \nAge: %d   \nProvisional Diagnosis: %s\nDiagnosis: %s\nManagement: %s\nOutcome: %s\n",
            temp->patient.name,temp->patient.surname,temp->patient.Gender,temp->patient.age, temp->patient.ProvisionalDiagnosis, temp->patient.Diagnosis,
            temp->patient.Management, temp->patient.Outcome);
    
    if(temp->NextVisit_NodeAddress != NULL){
        Visits = temp->NextVisit_NodeAddress;
        while(Visits != NULL){
            //if(Visits == temp)break;  //??*********
                printf("\n\n Case number: %d UniqueID : %d\n",++num,Visits->patient.UniqueCaseID);   
                printf("Next Visit Date: %d/ %d/ %d \nProvisional Diagnosis: %s\nDiagnosis: %s\n Management: %s\nOutcome: %s\n",Visits->patient.Visited.Day,
                Visits->patient.Visited.Month,Visits->patient.Visited.Year, Visits->patient.ProvisionalDiagnosis, Visits->patient.Diagnosis,
                Visits->patient.Management, Visits->patient.Outcome);  
            //if(((Visits->patient.UniqueCaseID) == (Visits->NextVisit_NodeAddress->patient.UniqueCaseID)))break;
        Visits = Visits->NextVisit_NodeAddress;
        }
    }
    
    
    if(temp == temp->prev)break; //this is the root. Only the root is in the database
    else temp = temp->prev;
    num = 0;
    }
    }
         printf("\n\n*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *\n\n");  

    return;
}
*/

void InputPatientDetails(){
    
    //printf("inserting %d\n",Value);
    newNode = (struct node*)malloc(sizeof(struct node));
    newNode->prev = NULL;
    newNode->next = NULL;
    newNode->NextVisit_NodeAddress = NULL;
    
    if(newNode == NULL){
        printf("memory allocation failed. Run terminated...\n");
        return;
    }
    //printf("memory allocation successful\n");
    
    printf("Enter patient name: "); scanf("%s",newNode->patient.name);
    if(StringToUpperCase(newNode->patient.name) != True){
        ErrorCheck = True;
        return;
    }
    Encrypt(newNode->patient.name);
    AllocateAlphabeticAddress(newNode->patient.name,newNode,L);
    //printf("received address %p\n",GlobalReferenceAddress);
    printf("Enter patient surname: "); scanf("%s", newNode->patient.surname);
    if(StringToUpperCase(newNode->patient.surname)!= True){
        ErrorCheck = True;
        return;
    }
    Encrypt(newNode->patient.surname);
    printf("Enter patient ID: "); scanf("%s", newNode->patient.ID);
    if(IsIDCorrect(newNode->patient.ID)!= True){
        ErrorCheck = True;
        return;
    }
    printf("Enter patient Gender: ");scanf("%s", newNode->patient.Gender);
    printf("Enter Date of Birth and Patient symptoms(i.e 30 01 1998 Headache and cough) DD MM YY : ");
    scanf("%d %d %d",&newNode->patient.BDay.Day,&newNode->patient.BDay.Month,&newNode->patient.BDay.Year);
    if(IsYearOfBirthLegal(newNode->patient.BDay.Year) != True){
        ErrorCheck = True;
        return;}
    if(IsMonthOfBirthLegal(newNode->patient.BDay.Month) != True){
        ErrorCheck = True;
        return;
    }
    if(IsDayOfBirthLegal(newNode->patient.BDay.Year,newNode->patient.BDay.Month,newNode->patient.BDay.Day)!=True){
        ErrorCheck = True;
        return;
    }
    newNode->patient.UniqueCaseID = rand();
    newNode->patient.age = AgeCalculation(newNode->patient.BDay.Year,newNode->patient.BDay.Month,newNode->patient.BDay.Day);
    
    newNode->patient.Visited.Day = c_DD;
    newNode->patient.Visited.Month = c_MM;
    newNode->patient.Visited.Year = c_YR; 
    
    fgets(newNode->patient.FileDetails.symptoms,1000,stdin);
    printf("Patient Examination: ");fgets(newNode->patient.FileDetails.ConductedTests,300,stdin);
    printf("Examination Results: ");fgets(newNode->patient.FileDetails.TestResults,250,stdin);
    printf("Provisional Diagnosis: ");fgets(newNode->patient.ProvisionalDiagnosis,100,stdin);
    printf("Diagnosis: ");fgets(newNode->patient.Diagnosis,100,stdin);
    printf("Patient Management: ");fgets(newNode->patient.Management,1000,stdin);
    printf("Outcomes: ");fgets(newNode->patient.Outcome,500,stdin);
    fflush(stdin);
    
    
        
   
    if(root == NULL){
 // there is some track flag i removed from the original code
        root = head = tail = GlobalReferenceAddress;
        //tail = head;
        //root = head;
        printf("Root created.address %p",GlobalReferenceAddress);
        GlobalReferenceAddress = NULL;
        //display();
        return;
    }
    
    //printf("%s address\n\n",address->patient.name);
    //is it to the left or the right of the global reference of the section
       if(strcmp(GlobalReferenceAddress->patient.name,newNode->patient.name) < 0)InlineSearch_InputPositionFront(newNode);
       else InlineSearch_InputPositionBack(newNode); 
    

    }
    
void DeletePatientDetails(Letter *L){
    
    RetrieveDataAddress();  
    if(RetrieveAddress == NULL)return; 
    
    struct node *temp, *toDelete, *DeleteNext;

    if(RetrieveAddress == head){
        printf("Data found head\n");
        if(head->next != NULL){
        toDelete = head;
        head = head->next;
        //head->prev = NULL;
        while(toDelete->NextVisit_NodeAddress != NULL){
            DeleteNext = toDelete->NextVisit_NodeAddress;
            free(toDelete);
            toDelete = DeleteNext;
            if(toDelete->NextVisit_NodeAddress == NULL)return;
        }
        free(toDelete);
        //display();
        return;
        }
        else free(head);
        for(int i = AlpNum - 1; i >= 0; i--){
                if(RetrieveAddress == L[i].AddressOfLast){
                        temp = RetrieveAddress;
                        printf("Data found tail %s\n ",temp->patient.name);
                if(temp->NextVisit_NodeAddress != NULL){
                    DeleteNext = temp->NextVisit_NodeAddress;
                }
                else DeleteNext = NULL;
                        
                if((temp->prev != NULL) && (temp != temp->prev)){
                    L[i].AddressOfLast = temp->prev;
                    temp->prev->next = NULL;
                }
                else {
                    temp = NULL;
                free(temp);
                L[i].AddressOfFirst = L[i].AddressOfLast = NULL;
                }
        RetrieveAddress = NULL;
        }
   }
        printf("Data deleted\n");
        return;
    }
    
     for(int i = AlpNum - 1; i >= 0; i--){
         //printf("I did not delete anything  %d\n",i);
    if(RetrieveAddress == L[i].AddressOfLast){
        temp = RetrieveAddress;
        printf("Data found tail %s\n ",temp->patient.name);
        if(temp->NextVisit_NodeAddress != NULL){
            DeleteNext = temp->NextVisit_NodeAddress;
        }
        else DeleteNext = NULL;
        
        
        if((temp->prev != NULL) && (temp != temp->prev)){
            L[i].AddressOfLast = temp->prev;
            temp->prev->next = NULL;
        }
        else {
            temp = NULL;
            free(temp);
        L[i].AddressOfFirst = L[i].AddressOfLast = NULL;
        }
        RetrieveAddress = NULL;

        printf("Data deleted\n");
        return;
    }
    
        //display();
    
     }
    
    //The only other case
    temp = RetrieveAddress;
    free(RetrieveAddress);
        //printf("found %d\n",temp->Value);
            printf("Data found body\n");
            if(temp == head){
                toDelete = head;
                head = head->next;
                head->prev = NULL;
                while(toDelete->NextVisit_NodeAddress != NULL){
                    DeleteNext = toDelete->NextVisit_NodeAddress;
                    free(toDelete);
                    toDelete = DeleteNext;
                    if(toDelete->NextVisit_NodeAddress == NULL)return;
        }
                free(toDelete);
                //display();
                printf("Data deleted\n");
                return;
            }
         toDelete = temp;
         temp->prev->next = toDelete->next;
         temp->next->prev = toDelete->prev;
         
         while(toDelete->NextVisit_NodeAddress != NULL){
            DeleteNext = toDelete->NextVisit_NodeAddress;
            free(toDelete);
            toDelete = DeleteNext;
            if(toDelete->NextVisit_NodeAddress == NULL)return;
        }
         free(toDelete);
         //display();
         printf("Data deleted\n");
         return;
}

void EditPatientData(){
    
    RetrieveDataAddress();
    if(RetrieveAddress == NULL){
        printf("Patient not registered in database\n\n\n");
        RetrieveAddress = NULL;
        return;
    }
    
    else printf("What information do you want to edit\n");
    int Response = 0;
    
    while(Response != 5){
    
     printf("Please enter the number representing the data to be amended:\n1). Name.\n2). Surname.\n3). ID.\n4). Date of Birth.\n5). End operation\n");
                scanf("%d",&Response);   
    
    if(Response == 1) {
        printf("Enter  new patient name:"); scanf("%s",RetrieveAddress->patient.name); 
             if(StringToUpperCase(RetrieveAddress->patient.name)!=True){
                 ErrorCheck = True;
                 return;
             }
        Encrypt(RetrieveAddress->patient.name);
        printf("Name update Successful...\n");
    }
    else if(Response == 2) {
        printf("Enter patient surname:"); scanf("%s",RetrieveAddress->patient.surname);
            if(StringToUpperCase(RetrieveAddress->patient.surname)!=True){
                ErrorCheck = True;
                return;
            }
        Encrypt(RetrieveAddress->patient.surname);
        printf("Surname update Successful...\n");
    }
    else if(Response == 3) {printf("Enter patient ID:"); scanf("%s",RetrieveAddress->patient.ID); printf("Successfully Edited...\n");;}
    else if(Response == 4) {printf("Enter Date of Birth in this format (include space between day, month and year) DD MM YY: ");
    scanf("%d %d %d",&RetrieveAddress->patient.BDay.Day,&RetrieveAddress->patient.BDay.Month,&RetrieveAddress->patient.BDay.Year);}
    else if(Response == 5)return;
    else {printf("Invalid input. Run terminated..."); return;}
    }
}

void SaveToFile(){
    FILE *myFile = fopen("MedicalRecords.txt","wt");
    if (myFile == NULL){
        printf("error opening file MedicalRecords.txt.\n");
        return;
    }
    
    for(int i = AlpNum; i >= 0; i--){
        
        struct node* temp, *Visits, *Check;
        temp = L[i].AddressOfFirst; //this gets the tail of each alp numeric section
        int num = 0;

        while(temp != NULL){
            printf("printing to output file...\n");
            fprintf(myFile,"\n\n*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *\n\n");
            fprintf(myFile,"Case number: %d, UniqueCaseID: %d\n",++num,temp->patient.UniqueCaseID);
            fprintf(myFile,"Date visited: %d/ %d/ %d\n",temp->patient.Visited.Day, temp->patient.Visited.Month, temp->patient.Visited.Year);
            fprintf(myFile,"Name: %s  \nSurname: %s  \nGender: %s  \nAge: %d   \nProvisional Diagnosis: %s\nDiagnosis: %s\nManagement: %s\nOutcome: %s\n",
            temp->patient.name,temp->patient.surname,temp->patient.Gender,temp->patient.age, temp->patient.ProvisionalDiagnosis, temp->patient.Diagnosis,
            temp->patient.Management, temp->patient.Outcome);
    
            if(temp->NextVisit_NodeAddress != NULL){
                    Visits = temp->NextVisit_NodeAddress;
                    while(Visits != NULL){
                            if(Visits == temp)break;
                             fprintf(myFile,"\n\n ");
                             fprintf(myFile,"Case number: %d UniqueID : %d\n",++num,Visits->patient.UniqueCaseID);   
                             fprintf(myFile,"Next Visit Date: %d/ %d/ %d \nProvisional Diagnosis: %s\nDiagnosis: %s\n Management: %s\nOutcome: %s\n",Visits->patient.Visited.Day,
                             Visits->patient.Visited.Month,Visits->patient.Visited.Year, Visits->patient.ProvisionalDiagnosis, Visits->patient.Diagnosis,
                             Visits->patient.Management, Visits->patient.Outcome); 
                            if(Visits -> NextVisit_NodeAddress == NULL)break;
                             else Visits = Visits->NextVisit_NodeAddress;
                    }
        
          }
    
    
            if(temp == temp->prev){
                printf("Unit has one entry. Breaking and moving to next unit...\n");
                temp = NULL;
            }
            else {
                temp = temp->prev;
                num = 0;
            }
            }
    }
         fprintf(myFile,"\n\n*  *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *\n\n");  
         fclose(myFile);
    return;
}

int main(int argc, char** argv) {
    
/*
    char instruction1[9] = "register";
    char instruction2[7] = "delete";
    char instruction3[7] ="search";
    char instruction4[10]= "edit_info";
    char instruction5[4] = "end";
*/
    int action = 0;
    
    char operation[50];
    int lim = 0, numlim=0, num;
    int complete = 1;
    char number[15];
    for(int i = 0; i <= AlpNum; i++){
        L[i].AddressOfFirst = L[i].AddressOfLast = NULL; //INITIALISING THE ADDRESS OF FIRST & LAST LETTER
    }
    
   
    while(action != End_Process){

    time_t now;
    time(&now);
    struct tm *local = localtime(&now);
    //***to use in case current date is required
    c_YR = local -> tm_year + 1900; //current year
    c_MM = local -> tm_mon + 1; // current month
    c_DD = local -> tm_mday; //current day
    
        
        
    printf("Please enter number representing the desired operation:\n1). Register patient data.\n2). Delete patient data.\n3). Retrieve patient info.\n4). Edit patient info.\n5). End process.\n");
    scanf("%d",&action);

    if(action == Input_Details)InputPatientDetails(); 
    else if(action == Delete_Details)DeletePatientDetails(L);
    else if(action == Search_Details)SearchPatientData();
    else if(action == Edit_Details)EditPatientData();
    else if(action == End_Process){SaveToFile();
    if(ErrorCheck!=False){
        printf("Run terminated ...\n");
        return(EXIT_FAILURE);
    }
    printf("File Saved Successfully.\nThank you for using our system.\nRun terminated...\n");return 0;}
    else {
          printf("Invalid input. Run terminated..."); 
           return 0;
            }
    if(ErrorCheck!=False)
        {printf("Run terminated ...\n");
        free(newNode);
        return(EXIT_FAILURE);}       
    }
            

   printf("exited first loop");   
 //display();
    return (0);
     
}



