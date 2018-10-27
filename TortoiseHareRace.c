
/*Duy Nguyen - Lab 6 - CIS 2107 - Fall 2017 - Oct 12th 2017
This program will simulate the race between the tortoise and the hare.
*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
 
#define FINISH 70

//functions prototypes
void moveT(int *tPtr);
void moveH(int *hPtr);
void printPosition(const int const *tPtr, const int const *hPtr);

int main(void)
{
   //initialize tortoise and hare
   int t = 1, h = 1;
    
   //this to manipulate the pointers moving functions
   srand(time(NULL));
    
   //interface
   printf("%s", "ON YOUR MARK, GET SET\n");
   printf("%s", "BANG !!!!!\nAND THEY'RE OFF !!!!\n");
    
   //move until either tortoise or hare finishes the race
   while(t != FINISH && h != FINISH)
   {
      //move the tortoise
      moveT(&t);
      //move the hare
      moveH(&h);
      //print current position
      printPosition(&t, &h); 

      //slow down the program
      sleep();    
   }
    
   //if tortoise and hare finish at the same time
   if(t == h)
   {
      printf("IT'S A TIE!!!\n"); 
   }

   //if hare wins
   else if(t < h)
   {
      printf("Hare wins. Yuch.\n");      
   }

   //if tortoise wins
   else if(t > h)
   {
      printf("TORTOISE WINS!!! YAY!!!\n"); 
   }
  
}
 
//this functions moves the pointer of tortoise
void moveT(int *tPtr)
{
   int i;
    
   //random numbers from 1 to 10
   i = 1 + rand() % 10;
    
   //tortoise has 50% to do this
   if(i >= 1 && i <= 5)
   {
      //1 - 5 : Fast plod  
      *tPtr += 3; //move 3 square to the right  
   }

   //20%
   else if(i >= 6 && i <= 7)
   {
      //6 - 7 : Slip      
      *tPtr -= 6; //move 6 square to the left
   }
   else

   //30%
   {
      //8 - 10 : Slow plod      
      *tPtr += 1; //move 1 square to the right
   }
    
   //if somehow the pointer is moved to 0 or negative, reset it to 1
   if(*tPtr < 1)
      *tPtr = 1;

   //if pointers goes more than FINISH, set it to FINISH
   else if(*tPtr > FINISH)
      *tPtr = FINISH;
}
 
//this funcitons moves the hare
void moveH(int *hPtr)
{
   int i;
    
   //random numbers from 1 to 10
   i = 1 + rand() % 10;
    
   //20% to do this
   if(i >= 1 && i <= 2)
   {
      //1 - 2 : Sleep   
      *hPtr = *hPtr;  
   }

   //20% to do this
   else if(i >= 3 && i <= 4)
   {
      //3 - 4 : Big hop   
      *hPtr += 9;
   }

   //10% to do this
   else if(i == 5)
   {
      //5 : Big slip
      *hPtr -= 12;
   }

   //30% to do this
   else if(i >= 6 && i<= 8)
   {
      //6 - 8 : Small hop
      *hPtr += 1;
   }

   //20% to do this
   else
   {
      //9 - 10 : Small slip
      *hPtr -= 2;      
   }
    
   //if somehow the pointer is moved to 0 or negative, reset it to 1
   if(*hPtr < 1)
      *hPtr = 1;

   //if pointers goes more than FINISH, set it to FINISH
   else if(*hPtr > FINISH)
      *hPtr = FINISH;
}
 
//this functions print out the position
void printPosition(const int const *tPtr, const int const *hPtr)
{
   int i;
    
   //if the 2 pointers are in the same place, the tortoise bites the hare
   if(*tPtr == *hPtr)
   {
      //prints blank until reaches the tortoise pointer
      for(i = 1; i < *tPtr; i++)
      {
         printf("%s", " ");
      }

      //then print OUCH!!!
      printf("%s", "OUCH!!!");                
   }
   
   //if hare is leading
   else if(*tPtr < *hPtr)
   {
      //prints blank until reaches tPtr
      for(i = 1; i < *tPtr; i++)
      {
         printf("%s", " ");
      }   
      //prints T
      printf("%s", "T");
       
      //then get the position of the hare by taking distance of tortoise away from hare
      for(i = 1; i < (*hPtr - *tPtr); i++)
      {
         printf("%s", " ");
      }
      printf("%s", "H");
   }

   //if tortoise is leading
   else
   {
      //prints blank until reaches hPtr
      for(i = 1; i < *hPtr; i++)
      {
         printf("%s", " ");      
      }     
      //then prints H
      printf("%s", "H");
       
      //then get the position of the tortoise by taking distance of hare away from tortoise
      for( i = 0; i < (*tPtr - *hPtr); i++)
      {
         printf("%s", " ");     
      }
      //then prints T
      printf("%s", "T");
   }
    
   puts("");
}