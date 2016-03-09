#include "filecch.h"

/**********************************************************
 *                                                        *
 *                 Author: qodbop                         *
 *  Creates all the statistics needed for the prog        *
 *                                                        *
 **********************************************************/

//if the actual char is a space returns with 1, if not returns with 0
int ifspace()
{
    if(actual_char==' ')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//if the actual char is a new line char returns with 1, if not returns with 0
int ifnl()
{
    if(actual_char=='\n')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

//fill an array with how many words are in the text with that number of letters
void lettersumarrayfiller()
{
    for(i=1;i<ARRAYSIZE;i++)
    {
        if(i==wordletternum)
        {
            letternumsum[i]=letternumsum[i]+1;
            return 0;
        }
        if(wordletternum>(ARRAYSIZE-1))
        {
            letternumsum[ARRAYSIZE-1]=letternumsum[ARRAYSIZE-1]+1;
			if(DEBUG)
			{
	            printf("wordletternum=%d; letternumsum[%d]=%d\n",wordletternum,i,letternumsum[i]);
			}
            return 0;
        }
    }
}
/* need:
//
int?void start_of_word()
{

}

//
int?void end_of_word()
{

}*/

//calculate average
float avrcalc()
{
    int j=0,counter=0;
    float avr=0;

    i=0;sum=0;
	if(DEBUG)
	{
	    printf("letternumsum[0]=%d counter=%d\n",letternumsum[0],counter);
	}
    for(j=0;j<50;j++)
    {
        sum+=letternumsum[++i];
        if(letternumsum[i]!=0)
        {
            counter++;
			if(DEBUG)
			{
				printf("counter=%d\n",counter);
			}
        }
    }
    avr=(float)counter/sum;
	if(DEBUG)
	{
	    printf("avr=%f\n",avr);
	}
    return avr;
}