#ifndef filecch_H_INCLUDED
#define filecch_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <ctype.h>
//#include <errno.h>
//#include <locale.h>
//#include <sys/ioctl.h>
//#include <math.h>

#define ARRAYSIZE 51
//TODO: Check if number needs to change
#define CHARCOUNT 7
#define ERROR -1
#define DEBUG 0 //all debugs

//global variables
int space, word, nl, letter,punct,character,letternumsum[ARRAYSIZE],wordletternum,i,sum,inword_toggle;
char actual_char, previous_char;
float rounded_graph_length[ARRAYSIZE];
FILE *txt;

#endif
