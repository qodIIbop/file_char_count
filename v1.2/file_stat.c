#include "filecch.h"
#include "fccgvar.h"

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
int lettersumarrayfiller()
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
            return 0;
        }
    }
}

//sets inword_toggle to 1 if at start of word
void start_of_word()
{
	if( isalpha(actual_char) && (isspace(previous_char) || ispunct(previous_char)))
    {
		if(DEBUG || DEBUG_FILE_STAT)
		{
			printf("INSIDE");
		}
    	word++;
        inword_toggle=1;
    }
}

//sets inword_toggle to 0 if at the end of a word
void end_of_word()
{
	if((actual_char==' ' || actual_char=='\n' || ispunct(actual_char)) && (inword_toggle==1))
    {
		if(DEBUG || DEBUG_FILE_STAT)
		{
           	printf("OUTSIDE");
		}
        inword_toggle=0;
        lettersumarrayfiller();
     }
}

//calculate average
float avrcalc()
{
    int j=0,counter=0;
    float avr=0;

    i=0;sum=0;
	if(DEBUG || DEBUG_FILE_STAT)
	{
	    printf("letternumsum[0]=%d counter=%d\n",letternumsum[0],counter);
	}
    for(j=0;j<50;j++)
    {
        sum+=letternumsum[++i];
        if(letternumsum[i]!=0)
        {
            counter++;
			if(DEBUG || DEBUG_FILE_STAT)
			{
				printf("counter=%d\n",counter);
			}
        }
    }
    avr=(float)counter/sum;
	if(DEBUG || DEBUG_FILE_STAT)
	{
	    printf("avr=%f\n",avr);
	}
    return avr;
}
//display the statistics in non-graphical form
void stat_num()
{
//	int letter_indent=0,word_indent=0,space_indent=0,nl_indent=0;  //needed for var character indent (if possible)
	//getting the correct number of indents for numbers to be aligned
	if(DEBUG || DEBUG_FILE_STAT)
	{	
		printf("\n");
	}
	if(character>100)
	{
    	printf("The number of characters: %d\n",character);
	}
	else if(character<100 && character>10)
	{
		printf("The number of characters: %d\n",character);
	}
	else
	{
		printf("The number of characters: %d\n",character);
	}

	if(letter>100)
	{
    	printf("The number of letters: %6d\n",letter);
	}
	else if(letter<100 && letter>10)
	{
		printf("The number of letters: %5d\n",letter);
	}
	else
	{
		printf("The number of letters: %4d\n",letter);
	}

	if(word>100)
	{
    	printf("The number of letters: %8d\n",word);
	}
	else if(word<100 && word>10)
	{
		printf("The number of words: %7d\n",word);
	}
	else
	{
		printf("The number of letters: %6d\n",word);
	}

    if(space>100)
	{
    	printf("The number of spaces: %8d\n",space);
	}
	else if(space<100 && space>10)
	{
		printf("The number of spaces: %7d\n",space);
	}
	else
	{
		printf("The number of spaces: %6d\n",space);
	}
    printf("The number of new lines:  %d\n",nl);
    printf("\n\n");
	if(DEBUG || DEBUG_FILE_STAT)
	{
    	for(i=0;i<ARRAYSIZE;i++)
    	{
        	if(letternumsum[i]!='\0')
        	{
            	printf("The number of %d letter words is=%d\n",i,letternumsum[i]);
       		}
    	}
	}
}
