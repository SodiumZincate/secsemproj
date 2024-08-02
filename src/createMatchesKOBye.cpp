#include "logic.h"

//this file is used to create matches for bye KO matches

void createMatchesKOBye(League L)
{
    //array of teams qualified for first KO round
    Team Q[MAX_TEAMS];
    Match Mko[MAX_MATCHES_KO_BYE];
    int matches;
    int i, j, k;
    j = 0;
    for (i = 0; i < L.league_team_number; i++)
    {
        if (L.T[i].team_position <= L.league_qualifiers)
        {
            L.T[i].team_ko_status = 1;
            Q[j] = L.T[i];
            j++;
        }
    }
    int QualifiedTeams = sizeof(Q) / sizeof(Q[0]);
    int &q = QualifiedTeams;
    if (q >= 17 && q <= 32)
    {
        matches = q - 16;
        j = 0;
        for (i = 0; i < matches; i++)
        {
            Mko[i].T1 = Q[j];
            Mko[i].T2 = Q[j+1];
            j += 2;
        }
    }
    if (q >= 9 && q <= 16)
    {
        matches = q - 8;
        j = 0;
        for (i = 0; i < matches; i++)
        {
            Mko[i].T1 = Q[j];
            Mko[i].T2 = Q[j+1];
            j += 2;
        }
    }
    if (q >= 5 && q <= 8)
    {
        matches = q - 4;
        j = 0;
        for (i = 0; i < matches; i++)
        {
            Mko[i].T1 = Q[j];
            Mko[i].T2 = Q[j+1];
            j += 2;
        }
    }
    if (q >= 3 && q <= 4)
    {
        matches = q - 2;
        j = 0;
        for (i = 0; i < matches; i++)
        {
            Mko[i].T1 = Q[j];
            Mko[i].T2 = Q[j+1];
            j += 2;
        }
    }

    string str;
    for (i = 0; i < matches; i++)
    {
        str = to_string(L.league_user_id) + "\n" + to_string(L.league_id) + "\n" +
        to_string(Mko[i].T1.team_id) + "\n" + to_string(Mko[i].T2.team_id) + "\n" + "0" + "\n" + "0" + "\n" + "0";
        stringstream temp;
        int errorDatabase = updateDatabase(str, "insert_match", temp);
        if (errorDatabase!=0)
        {
            std::cout << "\nError initializing database" << std::endl;
        }
        else
        {
            std::cout << "\nData inserted successfully" << std::endl;
        } 
        str.clear();
    }
}