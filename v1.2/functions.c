//if the actual char is a space returns with 1, if not returns with 0
int ifspace()
{
    if(actual_char==' ')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//if the actual char is a new line char returns with 1, if not returns with 0
int ifnl()
{
    if(actual_char=='\n')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
//fill an array with how many words are in the text with that number of letters
void lettersumarrayfiller()
{
    for(i=1;i<ARRAYSIZE;i++)
    {
        if(i==wordletternum)
        {
            letternumsum[i]=letternumsum[i]+1;
            return 0;
        }
        if(wordletternum>(ARRAYSIZE-1))
        {
            letternumsum[ARRAYSIZE-1]=letternumsum[ARRAYSIZE-1]+1;
//            printf("wordletternum=%d; letternumsum[%d]=%d\n",wordletternum,i,letternumsum[i]);
            return 0;
        }
    }
}
//errorhandling for ekezet
int qerror()
{
    if(actual_char<0)
    {
        printf("ERROR:\nThe input file contains invalid characters!\n");
        return -2;
    }
    else
    {
        return 0;
    }
}
//calculate average
float avrcalc()
{
    int j=0,counter=0;
    float avr=0;

    i=0;sum=0;
//    printf("letternumsum[0]=%d counter=%d\n",letternumsum[0],counter);
    for(j=0;j<50;j++)
    {
        sum+=letternumsum[++i];
        if(letternumsum[i]!=0)
        {
            counter++;
//            printf("counter=%d\n",counter);
        }
    }
    avr=(float)counter/sum;
//    printf("avr=%f\n",avr);
    return avr;
}
//get terminal param
int term_win_size()
{
    struct winsize w;
    ioctl(0, TIOCGWINSZ, &w);

//    printf ("lines %d\n", w.ws_row);
//    printf ("columns %d\n", w.ws_col);
    return w.ws_col;
}
//give back the display size
int display_size()
{
    int display_size=0;

    display_size=term_win_size()-CHARCOUNT;
    return display_size;
}
//calculate 1% of the sum
float onepercent()
{
    float percent=0;

    percent=(float)display_size()/100;
    return percent;
}
//tells you how long each element of the graph should be
int make_graph()
{
    int j,k,total=0,graph_string_toggle=0;
    float graph_i_length[ARRAYSIZE],a=0;

    i=0;
    a=(float)display_size()/sum;
//    printf("a=%.3f\n",a);
    for(j=0;j<ARRAYSIZE;j++)
    {
        if(letternumsum[i]!=0)
        {
//            printf("letternumsum[%d]\n",i);
            graph_i_length[j]=a*letternumsum[i]*onepercent();
            rounded_graph_length[j]=roundf(graph_i_length[j]);
//            printf("The number of \"=\" in %d letter words is %.2f\n",i,rounded_graph_length[j]);
            total+=rounded_graph_length[j];
            //graphical part
            do
            {
                if(i<10)
                {
                    printf("Word #%3d: ",i);
                    graph_string_toggle=1;
                }
                else if(i==(ARRAYSIZE-1))
                {
                    printf("Word #%d+: ",i);
                }
                else
                {
                    printf("Word #%3d: ",i);
                    graph_string_toggle=1;
                }
            }while(graph_string_toggle==0);
            for(k=0;k<=rounded_graph_length[j];k++)
            {
                printf("=");
                if(k==rounded_graph_length[j])
                {
                    printf("\n");
                }
            }
        }
        i++;
    }
//    printf("total=%d\n",total);

}
