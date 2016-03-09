#include "filecch.h"

/**********************************************************
 *                                                        *
 *                 Author: qodbop                         *
 *  Creates all the statistics needed for the prog        *
 *                                                        *
 **********************************************************/

//get terminal parametres
int term_win_size()
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
	if(DEBUG)
	{
	    printf ("lines %d\n", w.ws_row);
	    printf ("columns %d\n", w.ws_col);
	}
    return w.ws_col;
}

//give back the display size
int display_size()
{
    int display_size=0;

    display_size=term_win_size()-CHARCOUNT;
    return display_size;
}

