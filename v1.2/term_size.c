#include "filecch.h"
#include "termsize.h"

/**************************************************************************************************
 *                                                                                                *
 * Author: qodbop                                                                                 *
 * Checks the size of the terminal and calculates to usable area for graphical graph presentation *
 * Usable area: size of terminal - length of labeling for the bar chart rows                      *
 *                                                                                                *
 **************************************************************************************************/

//get terminal parametres
int term_win_size()
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);
	if(DEBUG || DEBUG_TERM_SIZE)
	{
	    printf ("lines %d\n", w.ws_row);
	    printf ("columns %d\n", w.ws_col);
	}
    return w.ws_col;
}

//give back the display size for graphical graph presentation
int display_size()
{
    int display_size=0;
//calculates usable area via terminal size and number of characters needed for labeling graph (charcount)
    display_size=term_win_size()-CHARCOUNT;
    return display_size;
}

