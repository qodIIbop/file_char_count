#ifndef termsize_H_INCLUDED
#define termsize_H_INCLUDED

#include "filecch.h"
#include <sys/ioctl.h>

#define DEBUG_TERM_SIZE 0 //debug only term_size.c

int term_win_size(void);
int display_size(void);

#endif
