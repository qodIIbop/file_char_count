#ifndef filestat_H_INCLUDED
#define filestat_H_INCLUDED

#include "filecch.h"
#include "fccgvar.h"
#include <ctype.h>

#define DEBUG_FILE_STAT 0 //debug only file_stat.c

int ifspace(void);
int ifnl(void);
int lettersumarrayfiller(void);
void stat_num(void);
void start_of_word(void);
void end_of_word(void);
float avrcalc(void);

#endif
