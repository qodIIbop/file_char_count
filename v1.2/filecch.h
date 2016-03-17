#ifndef filecch_H_INCLUDED
#define filecch_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
#include <errno.h>
#include <locale.h>
#include <sys/ioctl.h>
#include <math.h>

#define ARRAYSIZE 51
#define CHARCOUNT 7
#define ERROR -1
#define DEBUG 0
#define DEBUG_ERR_HNDL 0
#define DEBUG_MAIN 0
#define DEBUG_FILE_STAT 0
#define DEBUG_GRAPH_PR 0
#define DEBUG_TERM_SIZE 0


//file_stat.c
int ifspace(void);
int ifnl(void);
int lettersumarrayfiller(void);
void stat_num(void);
void start_of_word(void);
void end_of_word(void);

//?????
float avrcalc(void);
//error_handl.c
int file_open_error(void);
int eerror(void);
//term_size.c
int term_win_size(void);
int display_size(void);
//graph_pr.c
float onepercent(void);
void make_graph(void);

#endif
