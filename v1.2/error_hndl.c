#include "filecch.h"
#include "fccgvar.h"

/**********************************************************
 *                                                        *
 *                 Author: qodbop                         *
 *                 Error handling                         *
 *                                                        *
 **********************************************************/

//if file cannot be opened display error message why
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
//TO-DO: Write out error message not just error code
//TO-DO: More error handling???
