#include "filecch.h"
#include "filecharcount.h"

/***************************************************************************************
 *                                                                                     *
 * Author: qodbop                                                                      *
 * Reads the input of a txt file and reports statistics                                *
 * Statistics reported: letter, punctuation, character, word, space, nl count          *
 * All calls a function that displays a graphical bar chart of the amount of each word *
 * accourding to its letter count                                                      *
 *                                                                                     *
 ***************************************************************************************/

int main()
{
//init global var
	space=0;
	word=0;
	nl=0;
	letter=0;
	wordletternum=0;
	i=0;
	sum=0;
	actual_char='\0';
	previous_char=' ';
	inword_toggle=0;
	character=0;
	punct=0;
   
//FIXME:get ekezet to work
    setlocale(LC_ALL,"hun_HU.UTF-8");

//TODO:make dynamic (argc,argv[])
    txt=fopen("test04.txt","r");

	file_open_error();

    while((actual_char=fgetc(txt))!=EOF)
    {
        if(eerror()==ERROR)
        {
			debug_filecharcount("",1,(char)actual_char);
			if(DEBUG || DEBUG_MAIN)
			{
        		printf("%c",actual_char);
        		printf("\tvalue is=%d\n",actual_char);
			}
            eerror();
            return ERROR;
        }
		
//counts number of punctuation in the file
		if(ispunct(actual_char))
		{
			punct++;
		}
//counts number of letters in the file
        if(isalpha(actual_char))
        {
            letter++;
        }
        else
        {
//counts number of spaces in the file
            if(ifspace()==1)
            {
                space++;
            }
//counts number of enters in the file
            if(ifnl()==1)
            {
                nl++;
            }
        }
		start_of_word();
		end_of_word();
//increments wordletternum if still in word or resets counter if not
        if(inword_toggle==1)
        {
            wordletternum++;
        }
        else
        {
            wordletternum=0;
        }
		if(DEBUG || DEBUG_MAIN)
		{
			printf("%c",actual_char);
		}
        previous_char=actual_char;
    }
	character=punct+letter;
    lettersumarrayfiller();
//TODO: add check for close error of all functions
    fclose(txt);
    avrcalc();
    term_win_size();
    onepercent();
	stat_num();
    make_graph();
	if(DEBUG || DEBUG_MAIN)
	{
		printf("terminal width is:%d\n",term_win_size());
		printf("1 percent is:%f\n",onepercent());
    	printf("display size is %d\n",display_size());
	}
    return 0;
}
