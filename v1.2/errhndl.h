#ifndef errhandl_H_INCLUDED
#define errhandl_H_INCLUDED

#include "filecch.h"
#include <errno.h>
#define DEBUG_ERR_HNDL 0 //debug only error_hndl.c

int file_open_error(void);
int eerror(void);

#endif
