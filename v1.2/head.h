#ifndef filecch_H_
#define filecch_H_

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
#define DEBUG 1

//file_stat.c
int ifspace();
int ifnl();
void lettersumarrayfiller();
/*need:
start_of_word();
end_of_word();
*/
//?????
float avrcalc();
//error_handl.c
int file_open_error();
int eerror();
//term_size.c
int term_win_size();
int display_size();
//graph_pr.c
float onepercent();
int make_graph();

#endif
