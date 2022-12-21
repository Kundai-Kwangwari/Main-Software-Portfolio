#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

 /* File:   Date.h
 * Author: s1262007
 *
 * Created on May 6, 2019, 12:53 PM
 */
#define MAX_MONTH_IN_YEAR 12
#define MIN_MONTH_IN_YEAR 1
#define MIN_DAY_IN_MONTH 1
#define MIN_DAY_IN_MONTH 1
#define MONTH_WITH_31_DAYS 31
#define MONTH_WITH_30_DAYS 30
#define MONTH_WITH_29_DAYS 29
#define MONTH_WITH_28_DAYS 28



#define January 1
#define February 2
#define March 3
#define April 4
#define May 5
#define June 6
#define July 7
#define August 8
#define September 9
#define October 10
#define November 11
#define December 12

typedef struct 
{
    int Year;
    int Month;
    int Day;
}Date;


typedef struct{

    char symptoms[500];
    char ConductedTests[100];
    char TestResults[250];
    
}PatientFile;

typedef struct
{
    
    char name[100];
    char surname[100];
    char ID[35];
    int age;
    int UniqueCaseID;
    char Gender[7];
    char ProvisionalDiagnosis[100];
    char Diagnosis[100];
    char Management[500];
    char Outcome[500];
    Date BDay;
    Date Visited;
    PatientFile FileDetails;
}details;


typedef struct node {
    
    int Value;
    details patient;
    struct node *next;
    struct node *prev;
    struct node *NextVisit_NodeAddress;
}data;

typedef struct{
    struct node *AddressOfFirst;
    struct node *AddressOfLast;
}Letter;

struct node *GlobalReferenceAddress;
struct node *root, *head, *newNode, *tail, *RetrieveAddress;
int alp, c_YR, c_MM, c_DD; //the c_ represent current****


typedef struct
{
    int Inline;
    int Outline;
    int Errorfound;
    int IsSpace;
    //char name[100];
}CheckResult;

CheckResult SearchBy;

int IsYearOfBirthLegal(int Year);
int IsMonthOfBirthLegal(int Month);
int IsDayOfBirthLegal(int Year,int Month, int Day);



int AgeCalculation(int , int, int);
void MessagePrinter(int);
int GetColor(FILE *, int, details*, int i);

