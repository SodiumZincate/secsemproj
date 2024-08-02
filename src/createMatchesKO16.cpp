#include "logic.h"

//this file is used to create matches for 16 teams KO matches

void createMatchesKO16(League L)
{
    Match Mko[8];
    Team Tko[16];
    int i, j;
    j = 0;
    for (i = 0; i < L.league_team_number; i++)
    {
        if (L.T[i].team_ko_status == 1)
        {
            Tko[j] = L.T[i];
            j++;
        }
    }

    int matches = 8;
    
    j = 0;
    for (i = 0; i < matches; i++)
    {
        Mko[i].T1 = Tko[j];
        Mko[i].T2 = Tko[j+1];
        j += 2;
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