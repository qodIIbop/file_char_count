#include "filecch.h"

/**********************************************************
 *                                                        *
 *                 Author: qodbop                         *
 *  Reads the input of a txt file and reports statistics  *
 *                                                        *
 **********************************************************/

int space=0, word=0, nl=0, letter=0,letternumsum[ARRAYSIZE],wordletternum=0,i=0,sum=0;
char actual_char=' ';
float rounded_graph_length[ARRAYSIZE];
FILE *txt;

int main()
{
    int inword_toggle=0;
    char previous_char='\0';

    setlocale(LC_ALL,"hun_HU.iso88592");  //doesn't work check why

    txt=fopen("test04.txt","r");      //try to make this dymanic not burned in

	file_open_error();

    while((actual_char=fgetc(txt))!=EOF)
    {
        if(eerror()==ERROR)
        {
            qerror();
            return ERROR;
        }
		if(DEBUG)
		{
        	printf("%c",actual_char);
        	printf("\tvalue is=%d\n",actual_char);
		}
// TO-DO: Try to add non-letters seperatly
        if(isalpha(actual_char))
        {
            letter++;
        }
        else
        {
            if(ifspace()==1)
            {
                space++;
            }
            if(ifnl()==1)
            {
                nl++;
            }
        }
        //sets inword_toggle to 1 if at start of word (move to file_stat.c)
        if((actual_char!=' ' && actual_char!='\n') && isspace(previous_char))
        {
            word++;
            inword_toggle=1;
        }
        //sets inword_toggle to 0 if at the end of a word (move to file_stat.c)
        if((actual_char==' ' || actual_char=='\n') && isalnum(previous_char))
        {
            inword_toggle=0;
			if(DEBUG)
			{
            	printf("%d\n",wordletternum);
			}
            lettersumarrayfiller();
			if(DEBUG)
			{
            	printf("%d=%d\n",i,letternumsum[i]);
			}

        }
        //adds one to wordletternum value if still in word or resets counter if not
        if(inword_toggle==1)
        {
            wordletternum++;
        }
        else
        {
            wordletternum=0;
        }
        previous_char=actual_char;
    }
    lettersumarrayfiller();
    fclose(txt);
    avrcalc();
    term_win_size();
    onepercent();

//TBD: move to file_stat.c or totally new .c file ?????????

    printf("The number of letters: %5d\n",letter);
    printf("The number of words: %6d\n",word);
    printf("The number of spaces: %5d\n",space);
    printf("The number of new lines: %d\n",nl);
    printf("\n\n");
	if(DEBUG)
	{
    	for(i=0;i<ARRAYSIZE;i++)
    	{
        	if(letternumsum[i]!='\0')
        	{
            	printf("The number of %d letter words is=%d\n",i,letternumsum[i]);
       		}
    	}
	}

    make_graph();
	if(DEBUG)
	{
		printf("terminal width is:%d",term_win_size());     
		printf("1 percent is:%.3f\n",onepercent()); 
    	printf("display size is %d\n",display_size());
	}
    return 0;
}
