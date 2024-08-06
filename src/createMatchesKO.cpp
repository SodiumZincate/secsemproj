#include "logic.h"

//this file is used to create matches for all knockout stages(bye, 32, 16, 8, 4, final)

void createMatchesKO32(League L)
{
    Match Mko[16];
    Team Tko[32];
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

    int matches = 16;
    
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

void createMatchesKO8(League L)
{
    Match Mko[4];
    Team Tko[8];
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

    int matches = 4;
    
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

void createMatchesKO4(League L)
{
    Match Mko[2];
    Team Tko[4];
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

    int matches = 2;
    
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

void createMatchesFinal(League L)
{
    Match Mko[1];
    Team Tko[2];
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

    int matches = 1;
    
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

void createMatchesKOBye(League L)
{
    Match Mko[MAX_MATCHES_KO_BYE];
    Team Tko[32];
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

    int matches;
    
    int QualifiedTeams = j;
    int &q = QualifiedTeams;
    if (q >= 17 && q <= 32)
    {
        matches = q - 16;
        j = 0;
        for (i = 0; i < matches; i++)
        {
            Mko[i].T1 = Tko[j];
            Mko[i].T2 = Tko[j+1];
            j += 2;
        }
    }
    if (q >= 9 && q <= 16)
    {
        matches = q - 8;
        j = 0;
        for (i = 0; i < matches; i++)
        {
            Mko[i].T1 = Tko[j];
            Mko[i].T2 = Tko[j+1];
            j += 2;
        }
    }
    if (q >= 5 && q <= 8)
    {
        matches = q - 4;
        j = 0;
        for (i = 0; i < matches; i++)
        {
            Mko[i].T1 = Tko[j];
            Mko[i].T2 = Tko[j+1];
            j += 2;
        }
    }
    if (q >= 3 && q <= 4)
    {
        matches = q - 2;
        j = 0;
        for (i = 0; i < matches; i++)
        {
            Mko[i].T1 = Tko[j];
            Mko[i].T2 = Tko[j+1];
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