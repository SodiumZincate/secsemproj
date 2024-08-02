#include "logic.h"

//this file is used to check if bye stage exists for the league 

void checkBye(League L)
{
    int byeExists;
    int i, j;
    j = 0;
    for (i = 0; i < L.league_team_number; i++)
    {
        if (L.T[i].team_ko_status == 1)
        {
            j++;
        }
    }

    if (j == 1 || j == 2 || j == 4 || j == 8 || j == 16 || j == 32)
    {
        byeExists = 0;
    }
    else
    {
        byeExists = 1;
    }
}