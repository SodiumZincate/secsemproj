#include "logic.h"

//this file is used to mark those teams who have passed the group stage 

void markQualifiedTeams(League L)
{
    int i;
    for (i = 0; i < L.league_team_number; i++)
    {
        if (L.T[i].team_position <= L.league_qualifiers)
        {
            L.T[i].team_ko_status = 1;
        }
    }
}