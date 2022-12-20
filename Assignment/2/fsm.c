/*************************************
 * fsm.c : you will read input from the filename provided as the first argument on the comand line. If you can not open it for reading, print a meaningful message, and quit. If no filename is provided, you will read stdin. Then you will print "OK if string is message is valid, "FAIL" othewise.
 * 11/24/2022
 * Khoa Nguyen
 * gcc (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0
 * 5.4.0-125-generic x86_64 GNU/Linux
 * tabstop = 3,columns = 108
 ************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//a_aldo () function is used to check if string is a valid 'aldo message'
bool a_aldo(char* s)    {
    int i = 1;
    int len = strlen(s);
	 //Check if letter is valid number
    while(isdigit(s[i]) && i < len)    {
        i++;
    }
	 //return true if message ends with 'F' and false otherwise
    return (s[i] == 'F') && i == len-1 && i >= 2;
}

//b_bar () function is used to check if string is a valid 'bar' message
bool b_bar(char* s)  {
    int i =1;
	 //return true if string contains only one 'B' letter;
    if(s[i] == '\0')
        return true;
	//check if next two letters are 'H' and 'G', and check if string start with 'X' if length is greater than 3
    while (s[i] != '\0')    {
		 if (s[i] != 'H')	{
            return false;
			}
        i +=1;
        if (s[i] != 'G')	{
            return false;
			}
        i +=1;
		  if (s[i] != '\0' && s[i] != 'X')	{
				return false;
			}
			i+=1;
	 }
    return s[i-1] != 'X';
}

// c_calma() function check if message is a valid calma message
bool c_calma (char* s)  {
    int i = 1;
    int countT =0;
    bool state = false;
    //state 1: true;
    //state 2: false;
    // return true if message contain only 'C' letter
    if (s[i] == '\0')   {
        return true;
    }
    // check if all
    while (s[i] != '\0')   {
        // if letter is R and T is even, state 1(true)
        if ((s[i] == 'R') && (countT %2 == 0))   {
            state = true;
        }
         // if letter is T and T is not even, state 2(false)
        else if (s[i] == 'T' && ((countT+1) % 2 != 0))    {
            countT ++;
            state = false;
        }
        // if letter is R and T is not  even, state 2(false)
        else if ((s[i] == 'R') && (countT % 2 != 0))    {
            state = false;
        }
         // if letter is T and T is even, state 1(true)
         else if ((s[i] == 'T') && ((countT+1) % 2 == 0))    {
            countT++;
            state = true;
        }
        i++;
    }
    return state;
}

//d_dol fuction check message is valid if follow by 2 digit and either aldo or calma message
bool d_dol (char* s)    {
    int i =1;
    //check if letter is digit;
    if (!isdigit(s[i])) {
        return false;
    }
    i +=1;
    //check if letter is digit;
    if (!isdigit(s[i])) {
        return false;
    }
    i +=1;
    //check if letter is either 'A' or 'C'
    if (s[i] == 'A' && a_aldo(s+i)) {
        return true; 
    }
    else if (s[i] == 'C' && c_calma(s+i))   {
        return true;
    }
    return false;
}
//main funtion
int main( int argc, char **argv)  {
    FILE * fp = NULL;
    char* buff = NULL;
    size_t len = 0;
    if ( argc > 1)  {
        fp = fopen(argv[1],"r");

        if( fp == NULL) {
            perror("Cannot open input file for read.\n");
            exit(1);
        }
    }
    else    {
		fp = stdin;
       while (getline(&buff,&len,fp) != -1)
       {
             buff[ strlen(buff)-1 ] = '\0' ; /*overwite the newline*/
             switch (buff[0])
             {
				// check if first letter is A, then check whether messgae is valid
             case 'A':
            if (a_aldo(buff)){
                fprintf(stdout,"%s OK\n", buff);
            }
            else    {
                fprintf(stdout,"%s FAIL\n", buff);
            }
                break;
				// check if first letter is B, then check whether messgae is valid
             case 'B':
				if (b_bar(buff)){
                fprintf(stdout,"%s OK\n",buff);
            }
            else    {
                fprintf(stdout,"%s FAIL\n",buff);
            }
                break;
				// check if first letter is C, then check whether messgae is valid
             case 'C':
				if (c_calma(buff)){
                fprintf(stdout,"%s OK\n",buff);
            }
            else    {
                fprintf(stdout,"%s FAIL\n",buff);
            }
            
                break;
				// check if first letter is D, then check whether messgae is valid
             case 'D':
				 if (d_dol(buff)){
                fprintf(stdout,"%s OK\n",buff);
            }
            else    {
                fprintf(stdout,"%s FAIL\n",buff);
            }
                break;
				default:
					fprintf(stdout,"%s FAIL\n",buff);
					break;
             }
       }
    }
    free(buff); /*Avoid memory leak*/
	 buff = NULL;
    len = 0;
    return 0;
}
