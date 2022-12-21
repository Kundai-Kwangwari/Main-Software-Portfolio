#include "HEADERS.h"

//checking if Year of birth is legal
int IsYearOfBirthLegal(int Year)
{
    int x=1;
    if((Year < 1900) || (Year > c_YR)) 
        {
            x = 8;
            MessagePrinter(x);  
            return x;
        }
    return x;
}
//checking id Month of birth is legal
int IsMonthOfBirthLegal(int Month)
{
    int x = 1;
    if ((Month > December) || (Month < January))
        {
            int x = 9;
            MessagePrinter(x);  
            return x;
        }
    return x;
}

int IsDayOfBirthLegal(int Year ,int Month, int Day)
{
    int x = 1;
    
    
     if(Day > MONTH_WITH_31_DAYS)
         {
             x = 10;
            MessagePrinter(x);  
            return x;
         }
     if ((Month == April ) ||(Month == June) || (Month == September) || (Month == November))
        {
           if(Day > 30)
           {
            int x = 10;
            MessagePrinter(x);  
            return x;
           }
           return x;
        }
       if (Month == February)
        {
            if (((Year % 4) == 0 && (Year %100) != 0 )|| (Year %400) == 0) //is leap year
            {
                if(Day > MONTH_WITH_29_DAYS)
                {
                    int x = 10;
                    MessagePrinter(x);  
                    return x;
                }
            }
            
            else//is not a leap year
            {
                if(Day > MONTH_WITH_28_DAYS)
                {
                    int x = 6;
                    MessagePrinter(x);  
                    return x;
                }
               
            }
        }

     
     return x;
}

//AGe calculation
int AgeCalculation(int Year, int Month, int Day)
{
    int age;
    if ((Month<c_MM) || ((Month == c_MM) && (Day<c_DD)))
    {
       return age = ((c_YR)-(Year));
    }
    if ((Month>c_MM) || ((Month == c_MM) && (Day>c_DD)))
    {
        return age = ((c_YR)-(Year)-1);
    }
}
