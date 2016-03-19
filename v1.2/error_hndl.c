#include "filecch.h"
#include "fccgvar.h"
#include "errhndl.h"

 /******************
  *                *
  * Author: qodbop *
  * Error handling *
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

//TODO: More error handling???
