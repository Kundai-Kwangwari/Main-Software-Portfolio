/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "HEADERS.h"




void FindHead(Letter *L){
    for(int i = 0; i < AlpNum; i++){
        if(L[i].AddressOfFirst != NULL){head = L[i].AddressOfFirst;break;}
    }
}

void FindTail(Letter *L){
    for(int i = AlpNum; i >= 0; i--){
        if(L[i].AddressOfLast != NULL){tail = L[i].AddressOfLast;break;}
    }
    //if(marker == 0)printf("The database is empty.\n");
    
}

void AllocateAlphabeticAddress(char *name, data *CurrentInputAddress, Letter *L){
    printf("name %c newNode %p\n", name[0],CurrentInputAddress);
    
    for(;;){
      if(name[0] == ('A' | 'a')){alp = 0; break;}
      else if(name[0] == ('B' | 'b')){alp = 1;break;}    
      else if(name[0] == ('C' | 'c')){alp = 2;break;}      
      else if(name[0] == ('D' | 'd')){alp = 3;break;}   
      else if(name[0] == ('E' | 'e')){alp = 4;break;}
      else if(name[0] == ('F' | 'f')){alp = 5;break;}
      else if(name[0] == ('G' | 'g')){alp = 6;break;}
      else if(name[0] == ('H' | 'h')){alp = 7;break;}
      else if(name[0] == ('I' | 'i')){alp = 8;break;}
      else if(name[0] == ('J' | 'j')){alp = 9;break;} 
      else if(name[0] == ('K' | 'k')){alp = 10;break;} 
      else if(name[0] == ('L' | 'l')){alp = 11;break;}    
      else if(name[0] == ('M' | 'm')){alp = 12;break;}
      else if(name[0] == ('N' | 'n')){alp = 13;break;}
      else if(name[0] == ('O' | 'o')){alp = 14;break;}
      else if(name[0] == ('P' | 'p')){alp = 15;break;}
      else if(name[0] == ('Q' | 'q')){alp = 16;break;}
      else if(name[0] == ('R' | 'r')){alp = 17;break;}
      else if(name[0] == ('S' | 's')){alp = 18;break;}
      else if(name[0] == ('T' | 't')){alp = 19;break;}
      else if(name[0] == ('U' | 'u')){alp = 20;break;}
      else if(name[0] == ('V' | 'v')){alp = 21;break;}
      else if(name[0] == ('W' | 'w')){alp = 22;break;}
      else if(name[0] == ('X' | 'x')){alp = 23;break;}
      else if(name[0] == ('Y' | 'y')){alp = 24;break;}
      else if(name[0] == ('Z' | 'z')){alp = 25;break;}
      else if(name[0] == '0'){alp = 26;break;}
      else if(name[0] == '1'){alp = 27;break;}
      else if(name[0] == '2'){alp = 28;break;}
      else if(name[0] == '3'){alp = 29;break;}
      else if(name[0] == '4'){alp = 30;break;}
      else if(name[0] == '5'){alp = 31;break;}
      else if(name[0] == '6'){alp = 32;break;}
      else if(name[0] == '7'){alp = 33;break;}
      else if(name[0] == '8'){alp = 34;break;}
      else if(name[0] == '9'){alp = 35;break;}

    }  
    
   if(L[alp].AddressOfFirst == NULL){
       L[alp].AddressOfFirst = L[alp].AddressOfLast = GlobalReferenceAddress = CurrentInputAddress;
       return;}
   else GlobalReferenceAddress = L[alp].AddressOfFirst;//printf("returning address of first %p\n",L[alp].AddressOfFirst);
       return;
    
    }