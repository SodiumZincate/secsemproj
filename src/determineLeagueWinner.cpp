#include "logic.h"

//this file determines the winner of a league system

Team determineLeagueWinner(League L)
{
    int i, j;
    //determine team with highest points
    Team winner = L.T[0];
    for (int i = 0; i < L.league_team_number; i++) 
    {
        if (L.T[i].team_points > winner.team_points) 
        {
            winner = L.T[i];
        }
    }

    //check if two teams have highest points
    int c = 0;
    for (int i = 0; i < L.league_team_number; i++) 
    {
        if (L.T[i].team_points == winner.team_points) 
        {
            c++;
        }
    }
    if (c == 1)
    {
        return winner;
    }

    //if two teams are tied with highest points, use tiebreaker gd
    if (c != 1)
    {
        for (int i = 0; i < L.league_team_number; i++) 
        {
            if ((L.T[i].team_points == winner.team_points) && (L.T[i].team_gd > winner.team_gd)) 
            {
                winner = L.T[i];
            }
        }
    }

    //check if two teams have highest points and gd
    int c = 0;
    for (int i = 0; i < L.league_team_number; i++) 
    {
        if ((L.T[i].team_points == winner.team_points) && (L.T[i].team_gd = winner.team_gd)) 
        {
            c++;
        }
    }
    if (c == 1)
    {
        return winner;
    }

    //if two teams are tied with highest points and highest gd use tiebreaker gf
    if (c != 1)
    {
        for (int i = 0; i < L.league_team_number; i++) 
        {
            if ((L.T[i].team_points == winner.team_points) && (L.T[i].team_gd == winner.team_gd)) 
            {
                if (L.T[i].team_gf > winner.team_gf)
                    winner = L.T[i];
            }
        }
    }

    return winner;
}