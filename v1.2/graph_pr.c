#include "filecch.h"
#include "graphpr.h"

/*************************************************************************************
 *                                                                                   *
 * Author: qodbop                                                                    *
 * Creates the graph from the statistics in a terminal                               *
 * Responsive resizing                                                               *
 * Statistics shown in graphical form: how many of each length word is in input file *
 * lenght=letter count                                                               *
 *                                                                                   *
 *************************************************************************************/

//FIXME: Make longest line=100% of displaysize
//calculate 1% of the sum
float onepercent()
{
    float percent=0.0;

    percent=(float)display_size()/100;
    return percent;
}

//tells you how long each element of the graph should be
void make_graph()
{
    int j,k,total=0,graph_string_toggle=0;
    float graph_i_length[ARRAYSIZE],a=0;

    i=0;
//FIXME: //should be a seperate function
    a=(float)display_size()/sum;
	if(DEBUG)
	{
	    printf("a=%.3f\n",a);
	}
    for(j=0;j<ARRAYSIZE;j++)
    {
        if(letternumsum[i]!=0)
        {
			if(DEBUG || DEBUG_GRAPH_PR)
			{
	            printf("letternumsum[%d]\n",i);
			}
            graph_i_length[j]=a*letternumsum[i]*onepercent();
            rounded_graph_length[j]=roundf(graph_i_length[j]);
			if(DEBUG || DEBUG_GRAPH_PR)
			{
	            printf("The number of \"=\" in %d letter words is %.2f\n",i,rounded_graph_length[j]);
			}
            total+=rounded_graph_length[j];
//graphical part
            do
            {
//indents words is smaller than 10 by 2 so all : in one line
                if(i<10)
                {
                    printf("Word #%3d: ",i);
                    graph_string_toggle=1;
                }
//for words larger than ARRAYSIZE-1 letters long
                else if(i==(ARRAYSIZE-1))
                {
                    printf("Word #%d+: ",i);
                }
//indents words between 10 and ARRAYSIZE by 2 so all: in one line
                else
                {
                    printf("Word #%3d: ",i);
                    graph_string_toggle=1;
                }
            }while(graph_string_toggle==0);
//prints the amount of = to indicate ratio between letter length accurance
            for(k=0;k<=rounded_graph_length[j];k++)
            {
                printf("=");
                if(k==rounded_graph_length[j])
                {
                    printf("\n");
                }
            }
        }
//increment the index of letternumsum
        i++;
    }
	if(DEBUG || DEBUG_GRAPH_PR)
	{
	    printf("total=%d\n",total);
	}
}
