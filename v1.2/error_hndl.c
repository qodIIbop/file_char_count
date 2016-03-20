#include "filecch.h"
#include "errhndl.h"

 /******************
  *                *
  * Author: qodbop *
  * Error handling *
  * And debugging  *
  *                *
  ******************/

//if file cannot be opened display error code why
//TODO: Write out error message not just error code
int file_open_error()
{
	if(txt==0)
    {
        printf("Error: %d",errno);
        return ERROR;
    }
}

//errorhandling for ekezet
int eerror()
{
    if(actual_char<0)
    {
        printf("ERROR:\nThe input file contains invalid characters!\n");
        return ERROR;
    }
    return 0;
}

//debug function for error_hndl.c
/*debug_note=message to be displayed
value=what type the extention should be
gvar=the global variable to be displayed by the value*/
int debug_errhndl(char debug_note,int value,int gvar)
{
	if(DEBUG || DEBUG_ERR_HNDL)
	{
		switch(value)
		{
			case 1: 
		  	 printf("%s%c",debug_note,gvar);
		 	 break;
			case 2:
		 	 printf("%s%s",debug_note,gvar);
		  	 break;
			case 3:
		 	 printf("%s%f",debug_note,gvar);
		  	 break;
			default:
		  	 printf("%s%d",debug_note,gvar);
		}
	}
	return 0;
}

//debug fuction for filecharcount.c
/*debug_note=message to be displayed
value=what type the extention should be
gvar=the global variable to be displayed by the value*/
int debug_filecharcount(char debug_note,int value,int gvar)
{
	if(DEBUG || DEBUG_MAIN)
	{
		switch(value)
		{
			case 1: 
		  	 printf("%s%c",debug_note,gvar);
		 	 break;
			case 2:
		 	 printf("%s%s",debug_note,gvar);
		  	 break;
			case 3:
		 	 printf("%s%f",debug_note,gvar);
		  	 break;
			default:
		  	 printf("%s%d",debug_note,gvar);
		}
	}
	return 0;
}

//debug function for file_stat.c
/*debug_note=message to be displayed
value=what type the extention should be
gvar=the global variable to be displayed by the value*/
int debug_filestat(char debug_note,int value,int gvar)
{
	if(DEBUG || DEBUG_FILE_STAT)
	{
		switch(value)
		{
			case 1: 
		  	 printf("%s%c",debug_note,gvar);
		 	 break;
			case 2:
		 	 printf("%s%s",debug_note,gvar);
		  	 break;
			case 3:
		 	 printf("%s%f",debug_note,gvar);
		  	 break;
			default:
		  	 printf("%s%d",debug_note,gvar);
		}
	}
	return 0;
}

/*debug function for graph_pr.c
debug_note=message to be displayed
value=what type the extention should be
gvar=the global variable to be displayed by the value*/
int debug_graphpr(char debug_note,int value,int gvar)
{
	if(DEBUG || DEBUG_GRAPH_PR)
	{
		switch(value)
		{
			case 1: 
		  	 printf("%s%c",debug_note,gvar);
		 	 break;
			case 2:
		 	 printf("%s%s",debug_note,gvar);
		  	 break;
			case 3:
		 	 printf("%s%f",debug_note,gvar);
		  	 break;
			default:
		  	 printf("%s%d",debug_note,gvar);
		}
	}
	return 0;
}

//debug function for term_size.c
/*debug_note=message to be displayed
value=what type the extention should be
gvar=the global variable to be displayed by the value*/
int debug_termsize(char debug_note,int value,int gvar)
{
	if(DEBUG || DEBUG_TERM_SIZE)
	{
		switch(value)
		{
			case 1: 
		  	 printf("%s%c",debug_note,gvar);
		 	 break;
			case 2:
		 	 printf("%s%s",debug_note,gvar);
		  	 break;
			case 3:
		 	 printf("%s%f",debug_note,gvar);
		  	 break;
			default:
		  	 printf("%s%d",debug_note,gvar);
		}
	}
	return 0;
}

//TODO: More error handling???
