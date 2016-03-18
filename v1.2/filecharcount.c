#include "filecch.h"
#include "fccgvar.h"

/**********************************************************
 *                                                        *
 *                 Author: qodbop                         *
 *  Reads the input of a txt file and reports statistics  *
 *                                                        *
 **********************************************************/

int main()
{
//init global var
	space=0; word=0; nl=0; letter=0;wordletternum=0;i=0;sum=0;actual_char='\0',previous_char=' ',inword_toggle=0,character=0,punct=0;
   
    setlocale(LC_ALL,"hun_HU.UTF-8");  //doesn't work check why

    txt=fopen("test04.txt","r");      //try to make this dymanic not burned in

	file_open_error();

    while((actual_char=fgetc(txt))!=EOF)
    {
        if(eerror()==ERROR)
        {
			if(DEBUG || DEBUG_MAIN)
			{
        		printf("%c",actual_char);
        		printf("\tvalue is=%d\n",actual_char);
			}
            eerror();
            return ERROR;
        }
		
//count punctuation
		if(ispunct(actual_char))
		{
			punct++;
		}
//count letters
        if(isalpha(actual_char))
        {
            letter++;
        }
        else
        {
//count white spaces
            if(ifspace()==1)
            {
                space++;
            }
//count newlines
            if(ifnl()==1)
            {
                nl++;
            }
        }
		start_of_word();
		end_of_word();
//adds one to wordletternum value if still in word or resets counter if not
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
    fclose(txt); //add close error
    avrcalc();
    term_win_size();
    onepercent();
	stat_num();
    make_graph();
	if(DEBUG || DEBUG_MAIN)
	{
		printf("terminal width is:%d",term_win_size());
		printf("1 percent is:%.3f\n",onepercent());
    	printf("display size is %d\n",display_size());
	}
    return 0;
}
