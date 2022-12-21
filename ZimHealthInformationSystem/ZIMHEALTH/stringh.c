#include "HEADERS.h"

/*int ScanName(FILE *fin, int i, details *pat)
{
    fscanf(fin,"%s", pat[i].name);
    //printf("%s",pat[i].name);
    return 0;
}*/
//Error Message printer
void MessagePrinter(int x)
{
    switch(x)
    {
        case(1):
        {
            printf("Probably the file is corrupted, error while loading the record.\n");
            break;
        }
        case(2): 
        {
            printf("There is an error with the patient`s name.\n");
            break;
        }
        case(3):
        {
            printf("There is an error in patient ID.\n"); 
            break;
        }
        case(4): 
        {
            printf("There is an error in patient's  Birth Year.\n");
            break;
        }
        case(5): 
        {
            printf("There is an error in patient's Birth Month.\n");
            break;
        }
        case(6):
        {
            printf("There is an error in patient's Birth Day.\n");
            break;
        }
        case(7): 
        {
            printf("There is an missing entry in patient's Birth Date.\n");
            break;
        }
        case(8): 
        {
            printf("Birth Year of patient is illegal.\n");
            break;
        }
        case(9): 
        {
            printf("Birth Month of patient is illegal.\n");
            break;
        }
         case(10): 
        {
            printf("Age calculation error for patient. Check Date.c sourcefile\n");
            break;
        }       
    }
}



//checking if name is alphabet only

//checking if name is correct

int StringToUpperCase(char *name)
{
    int x=1;
    char ch;
    
    for(int i = 0; i < strlen(name); i++)
    {
        
        if(!isalpha(name[i]))
        {
            x=2;
            MessagePrinter(x);
            return x;
        }
        
        ch = toupper(name[i]);
        name[i] = ch;
        //printf("%c ",name[i]);
    }
 
    return x;
}
//checking if ID is correct
int IsIDCorrect(char *ID)
{
    
    int x=1;
    char ch;
    
    for(int i = 0; i < strlen(ID); i++)
    {
        
        if(!isalnum(ID[i]))
        {
            x=3;
            MessagePrinter(x);
            return x;
        }
        
        ch = toupper(ID[i]);
        ID[i] = ch;
        //printf("%c ",name[i]);
    }
 
    return x;
}
