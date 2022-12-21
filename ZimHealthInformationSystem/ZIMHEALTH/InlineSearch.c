/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "HEADERS.h"

void AddNextVisitNode(struct node* newNode){
    
    if(GlobalReferenceAddress->NextVisit_NodeAddress == NULL){
        GlobalReferenceAddress->NextVisit_NodeAddress = newNode;
        //display();
        GlobalReferenceAddress = NULL;
        return;
        }
    else{
        for(;;){
            GlobalReferenceAddress = GlobalReferenceAddress->NextVisit_NodeAddress;
            if(GlobalReferenceAddress->NextVisit_NodeAddress == NULL){
                GlobalReferenceAddress->NextVisit_NodeAddress = newNode;
                //display();
                GlobalReferenceAddress = NULL;
                return;
                }
        }
    }
}



void InlineSearch_InputPositionFront(struct node* newNode){
    
    printf("inline insert front\n");
    //if the newNode name is smaller than the section marker... move t up to the top of the name list
    while((strcmp(GlobalReferenceAddress->patient.name,newNode->patient.name) < 0) && (GlobalReferenceAddress->next != NULL)){
        GlobalReferenceAddress = GlobalReferenceAddress->next;
        if(GlobalReferenceAddress->next == GlobalReferenceAddress)break;// global address is the section global address
        //printf("front ...Address string: %s comes before newNode value %s\n\n",GlobalReferenceAddress->patient.name,newNode->patient.name);
    }

    if((strcmp(GlobalReferenceAddress->patient.name, newNode->patient.name) == 0)
            && (strcmp(GlobalReferenceAddress->patient.surname,newNode->patient.surname)==0)
                    &&(strcmp(GlobalReferenceAddress->patient.ID,newNode->patient.ID) == 0)){
                
     AddNextVisitNode(newNode);
     return;
    }
      printf("inline insert front 2\n");
      //if we reach the top of the namelist
      if(GlobalReferenceAddress->next == NULL){
      printf("inline insert front 3\n");
        newNode->prev = GlobalReferenceAddress;
        GlobalReferenceAddress->next = newNode;
        newNode->next = NULL;
        
        L[alp].AddressOfFirst = newNode;
        GlobalReferenceAddress = NULL;
        return;
    }
}



void InlineSearch_InputPositionBack(struct node* newNode){

    
    printf("inlne insert back\n");
    //if the Global Reference has some leaves previous to it, search until we find the position to input.(to the right) The newNode
    //comes alphabetically after the current GlobalAddress name else stop.
    while((GlobalReferenceAddress->prev != NULL) && (strcmp(GlobalReferenceAddress->patient.name,newNode->patient.name) <= 0)){
        //printf(" Problem ***Address string: %s comes after newNode value %s\n\n",GlobalReferenceAddress->patient.name,newNode->patient.name);
        GlobalReferenceAddress = GlobalReferenceAddress->prev;
        if(GlobalReferenceAddress->next == GlobalReferenceAddress)break;  //The global address is the root of the section

        //printf("The address is %p\n",address);
    }

    //if the root of the section is the same as newNode
    if((strcmp(GlobalReferenceAddress->patient.name, newNode->patient.name) == 0)
            && (strcmp(GlobalReferenceAddress->patient.surname,newNode->patient.surname)==0)
                    &&(strcmp(GlobalReferenceAddress->patient.ID,newNode->patient.ID) == 0)){
                
     AddNextVisitNode(newNode);
     return;
    }
    //if the global reference has no leaves previous to it => the newNode is now the last name on the list.
    printf("inline insert back 2\n");
        newNode->next = GlobalReferenceAddress;
        GlobalReferenceAddress->prev = newNode;
        newNode->prev = NULL;
        L[alp].AddressOfLast = newNode;
                
        //FindTail(L);
        //FindHead(L);
        //display();
        GlobalReferenceAddress = NULL;
        return;
    
}
