/*Duy Nguyen - lab 7 - Manual.c - Fall 2017 - CIS 2107 - Oct 21st 2017*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define SIZE 1000

//functions prototypes
void upperLower(char s[SIZE]);
void convertStrtoInt(char a[SIZE], char b[SIZE], char c[SIZE], char d[SIZE]);
void convertStrtoFloat(char a[SIZE], char b[SIZE], char c[SIZE], char d[SIZE]);
void compareStr(char a[SIZE], char b[SIZE]);
void comparePartialStr(char a[SIZE], char b[SIZE]);
void tokenizeTelNum(char a[SIZE]);
void reverseWords(char s[SIZE]);
void countSubstr(char a[SIZE], char b[SIZE]);
void countChar(char a[SIZE], char b);
void randomize();
void countWords(char a[SIZE]);
void startsWithB(char a[SIZE]);
void endsWithed(char a[SIZE]);
void countAlpha(char a[SIZE], char b);

int main()
{
    //starting the program
    char s[SIZE];
    char x[SIZE], y[SIZE];
    upperLower(s);
    puts("");

    char a[SIZE] = "123abwka";
    char b[SIZE] = "456asdw1";
    char c[SIZE] = "789asd78a9w";
    char d[SIZE] = "1231asd8wd71924";
    convertStrtoInt(a, b, c, d);
    puts("");

    char e[SIZE] = "12.3 awdasd";
    char f[SIZE] = "4.56 asdfst";
    char g[SIZE] = "78.9 ad wawd";
    char h[SIZE] = "12.31 sdfs";
    convertStrtoFloat(e, f, g, h);
    puts("");

    puts("Comparing the 2 strings...");
    compareStr(x, y);
    puts("");

    comparePartialStr(x, y);
    puts("");

    tokenizeTelNum(x);
    puts("");

    char n[SIZE] = "I like to code";
    reverseWords(n);
    puts("");

    char v[SIZE] = "This is a test to count substring. A test is supposed to be hard. A test will evaluate students.";
    char k[SIZE] = "test";
    printf("%s\n", v);
    countSubstr(v, k);
    puts("");
    
    char l[SIZE] = "This will count the occurences of a character. This test is possible.";
    char m = 'i';
    printf("%s\n", l);
    countChar(l, m);
    puts("");
    puts("");

    puts("Counting occurrences of the alpha bet in the string:");
    char z[SIZE] = "The quick brown fox jumped over the lazy dog.";
    printf("%s\n", z);
    char q;
    
    countAlpha(z, q);

    puts("Randomizing sentences.");
    randomize();
    puts("");

    char j[SIZE] = "This is a test to count the words in the string.\nThis is the 2nd line.";
    countWords(j);
    puts("");

    char o[SIZE] = "Diane just had a baby this week. It is a big baby boy.";
    printf("%s\n", o);
    startsWithB(o);
    puts("");

    char i[SIZE] = "This function will print words ended with 'ed'. John is married to Jane. Noted the date. Baked with love.";
    printf("%s\n\n", i);
    endsWithed(i);
    puts("");
}

void upperLower(char s[SIZE])
{
    int c;
    char upper[SIZE];
    char lower[SIZE];
    size_t i = 0;

    //gets input
    puts("Enter a string:");

    while((i < SIZE - 1) && (c = getchar()) != '\n')
    {
        s[i++] = c;
    }

    s[i] = '\0';

    //start interting array
    for(i = 0; i < SIZE; ++i)
    {
        //save strings in uppercase and lowercase
        upper[i] = toupper(s[i]);
        lower[i] = tolower(s[i]);
    }

    //prints results
    printf("The string in lower case is: %s\n", lower);
    printf("The string in upper case is: %s\n", upper);

}

void convertStrtoInt(char a[SIZE], char b[SIZE], char c[SIZE], char d[SIZE])
{
    long sum = 0;
    char *re1, *re2, *re3, *re4;

    //converting str to int
    long x1 = strtol(a, &re1, 0);
    long x2 = strtol(b, &re2, 0);
    long x3 = strtol(c, &re3, 0);
    long x4 = strtol(d, &re4, 0);

    //sum
    sum = x1 + x2 + x3 + x4;

    //results
    printf("Values from the 4 strings are: %ld, %ld, %ld, %ld\n", x1, x2, x3, x4);
    printf("Sum is: %ld\n", sum);
}

void convertStrtoFloat(char a[SIZE], char b[SIZE], char c[SIZE], char d[SIZE])
{
    double sum = 0;
    char *re1, *re2, *re3, *re4;

    //convert str to float
    double x1 = strtof(a, NULL);
    double x2 = strtof(b, NULL);
    double x3 = strtof(c, NULL);
    double x4 = strtof(d, NULL);

    //sum
    sum = x1 + x2 + x3 + x4;

    //results
    printf("Values from the 4 strings are: %.2f, %.2f, %.2f, %.2f\n", x1, x2, x3, x4);
    printf("Sum is: %.2f\n", sum);
}

void compareStr(char a[SIZE], char b[SIZE])
{
    size_t i = 0;
    int c, count1 = 0, count2 = 0;

    //gets the input while increasing the count of characters in both strings 
    puts("Input the first string:");

    while((i < SIZE - 1) && (c = getchar() != '\n'))
    {
        a[i++] = c;
        ++count1;
    }

    a[i] = '\0';

    puts("Input the second string:");

    while((i < SIZE - 1) && (c = getchar()) != '\n')
    {
        b[i++] = c;
        ++count2;
    }

    b[i] = '\0';

    //compare
    if(count1 > count2)
    {
        puts("String 1 is greater than string 2.");
    }

    else if(count1 < count2)
    { 
        puts("String 1 is less than string 2.");
    }

    else if(count1 = count2)
    {
        puts("String 1 is equal to string 2.");
    }
}

void comparePartialStr(char a[SIZE], char b[SIZE])
{
    size_t i = 0;
    int c;
    //gets the inputs
    puts("Input the first string:");

    scanf("%s", a);

    puts("Input the second string:");

    scanf("%s", b);

    //getting only first 4 elements to compare
    int count = strncmp(a, b, 4);
    
    puts("Comparing first 4 characters in the string...");
    //results
    if(count < 0) 
    {
        puts("String 1 is less than string 2.");
    } 
       
    else if(count > 0)
    {
        puts("String 1 is greater than string 2.");
    }

    else 
    {
        puts("String 1 is equal to string 2.");
    }
}

void tokenizeTelNum(char a[SIZE])
{
    char buffer[SIZE];
    char area[4] = {0};
    char number[9] = {0};
    char *p;
    char delimit[] = " ()-";
   
    printf ("Enter a phone number in form of (555)555-5555: \n");
    scanf("%s", buffer);
    
    //starts tokenizing
    p = strtok(buffer, delimit);
   
    //get the are number
    if (p != NULL)
      strncat(area, p, sizeof area - 1);
   
    //tokenizes to get first 3 phone #
    p = strtok(NULL, delimit);
   
    //get the number leaving '\0'
    if (p != NULL)
      strncat (number, p, sizeof number - 1);
   
    //tokenizes 1 more time to get the last 4 digits
    p = strtok (NULL, delimit);
   
    //get the number leaving '\0'
    if (p != NULL)
      strncat(number, p, sizeof number - 1);
   
    //prints out area and number
    printf("Area number: %s\n", area);
    printf("Phone number: %s\n", number);
  }

//this is a generalized funtionc to reverse anything.
void reverse(char *begin, char *end)
{
    char temp;
    while (begin < end)
    {
        //starts reversing.
        temp = *begin;
        *begin++ = *end;
        *end-- = temp;
    }
}
// Function to reverse a string
void reverseWords(char s[SIZE])
{
    char *begin = NULL;
    char *temp = s; //temp is for word boundry
 
    printf("Reversing the string '%s'...\n", s);
    //do this while pointer is in bound
    while(*temp)
    {
        /*This condition is to make sure that the string start with
          valid character (not space) only*/
        if ((begin == NULL ) && (*temp != ' '))
        {
            begin=temp;
        }
        if(begin && ((*(temp + 1) == ' ') || (*(temp + 1) == '\0')))
        {
            //use the reverse function above to do this
            reverse(begin, temp);
            begin = NULL;
        }
        temp++;
    }
 
    /*STEP 2 of the above algorithm */
    reverse(s, temp - 1);
    printf("%s\n", s);
}

void countSubstr(char a[SIZE], char b[SIZE])
{
    size_t i, j;
    //this to count the times substring appears
    int count = 0;

    //create a pointer poiting to the string
    const char *charPtr = a;
    
    //do this while substring is found
    while ((charPtr = strstr(charPtr, b)) != NULL ) 
    {
        //skip the substring in the main string to continue comparing the next char
        charPtr += strlen(b);
        count++;//increase the count.
    }
    

    printf("The substring '%s' occurs %d times.\n", b, count);
}

void countChar(char a[SIZE], char b)
{
    size_t i;
    int count = 0;

    char *charPtr = a;
  
    while((charPtr = strchr(charPtr, b)) != NULL) 
    {                                                                                                                       
        count++;                                                                                                             
        charPtr++;
    }

    printf("The character '%c' occurs %d times.", b, count);
}

void countAlpha(char a[SIZE], char b)
{
    int i, j;
    int count[26] = { 0 };//initialize array of count to count occurrences to all 0
    b = 'a';//initialize b to be a

    //convert the string to all lowercase so we can compare easier
    for(i = 0; a[i] != '\0'; ++i)
    {
        a[i] = tolower(a[i]);
    }

    //iterate starting with count[0]
    for(j = 0; j < 26; ++j)
    {
        //iterate to compare b to array of string
        for(i = 0; a[i] != '\0'; ++i)
        {
            //increase the count for alphabet when found b in the string
            if(b == a[i])
            {
                count[j]++;
            }
        }
        b += 1;//increase b to the next alphabet
    }

    //prints result
    for(j = 0; j < 26; ++j)
    {
        if(count[j] != 0)
        {
            printf("'%c' = %d\n", (j + 97), count[j]);//layout
        }
    }
    puts("");
    
}

void randomize()
{     
    //Declarations
     //Int for looping
        int r1,r2,r3,i,index = 0;
        //For 6 
        //Char arrays initialized
        char *article[5] = {"the","a","one","some","any"} ;
        char *noun[5] = {"boy","girl","dog","town","car"}; 
        char *verb[5] = {"drove", "jumped", "ran", "walked","skipped"};
        char *preposition[5] = {"to","from","over","under","on"};
        //Temp char arrays
        char temp[SIZE]=""; // temporary strings initilized to be 0
        char temp_noun[SIZE] = ".";//this to add dot at the end of sentence
        char sentence[SIZE] = "";
    //Function
       
     srand(time(NULL));
     while(r1 < 20)
     {
       r1++;
       strcat(temp, article[rand() % 5]);// Copy content to temp
       //Article
        
        //add noun
        strcat(temp," ");
        strcat(temp, noun[rand() % 5]); 
        //add verb
        strcat(temp," ");
        strcat(temp, verb[rand() % 5]); 
        //add preposition
        strcat(temp," ");
        strcat(temp, preposition[rand() % 5]);   
        //add Article
        strcat(temp," ");
        strcat(temp, article[rand() % 5]);
        //add noun
        strcat(temp," ");
        strcat(temp, noun[rand() % 5]);
        
      for(i = 0; i < (sizeof(temp)); ++i)
        {  
            sentence[i] = temp[i];
            index++;
        }
        sentence[0] = toupper(temp[0]);//capitalize the first character of the sentence

        //add dot to the end of the sentence
        strcat(sentence, temp_noun);

        //Clear temps  
        memset(temp, 0, sizeof(temp));
        puts(sentence);
     }
    
}

void countWords(char a[SIZE])
{
    //declares variables to control the array
    size_t i;
    int count = 0;//this to count the number of words
    char delimit[] = " \n";//set the delimiters of strtok to blank and newline

    //starts tokenizing
    char *tokenPtr = strtok(a, delimit);
    printf("%s '%s ", "The string", tokenPtr);//layout

    //keeps tokenizing and prints the words in the strings on screen
    while (tokenPtr != NULL)
    {
        ++count;
        tokenPtr = strtok(NULL, delimit);
        if(tokenPtr != NULL)
            printf("%s ", tokenPtr);
    }

    //print results
    printf("' has %d words.\n", count);
}

void startsWithB(char a[SIZE])
{
    //variables to control iteration
    size_t i, j, t;
    puts("The words that begin with 'b' are:");

    //start iterating
    for(t = 0, i = 0; a[i] != '\0'; ++i)
    {
        //if the word at i is b and i - 1 is a blank
        if(a[i] == 'b' && a[i - 1] == ' ')
        {
            //set j = t print the word starting with b
            for(j = t; j < SIZE; ++j)
            {
                //print char at j position
                printf("%c", a[j]);
                //increase t
                t = i + 1;

                //if a[j] is a blank set j to SIZE to break out of loop
                if (a[j] == ' ')
                {
                    j = SIZE;
                }
            }
            puts("");
        }
        else
            {
                //if can't find word starting with b, set t to be the word next to the blank in String
                if(a[i] == ' ')
                {
                    t = i + 1;
                }
            }
        }
        puts("");
}

void endsWithed(char a[SIZE])
{
    //variables to control iterations
    size_t i, j, t;

    puts("The words that end with 'ed' are:");
    //starts iterating
    for(t = 0, i = 0; a[i] != '\0'; ++i)
    {
        //if a[i] is e and the next element is d
        if(a[i] == 'e' && a[i + 1] == 'd')
        {
            //set j = t then print the word ended with ed
            for(j = t; j < SIZE; ++j) 
            {
                printf("%c", a[j]);
                t = i + 1;
                if (a[j] == ' ')
                {
                    //if element is a blank set j to SIZE to break out of loop
                    j = SIZE;
                }
            }
            puts("");
        }
        else
            {
                if(a[i] == ' ')
                {
                    //if element is blank, set t to the next word to continue comparing.
                    t = i + 1;
                }
            }
        }
        puts("");
}