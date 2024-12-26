#include "../Headers/Game_Logic.h"
#include <iostream>

bool TurnDecide(int board[4][3])
{
    if(board[3][0]==0)
    {
        board[3][0]=1;
        return false;
    }
    else
    {
        board[3][0]=0;
        return true;
    }
}
/*
returns true if O turn
returns false if X turn
*/

void DetermineWinner(int board[4][3], int check)
{
    if(check == 3)
    {
        board[3][1] = 1;
    }
    else
    {
        board[3][2] = 1;
    }
}

void HorizontalCheck(int board[4][3])
{
    int check = 0;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(board[i][j]==0)
                check = check + 2814;
            else
                check = check + board[i][j];
        }
        if(check == 3 || check == 6)
        {
            DetermineWinner(board, check);
            break;
        }
        check = 0;
    }
}

void VerticalCheck(int board[4][3])
{
    int check = 0;
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(board[i][j]==0)
                check = check + 10;
            else
                check = check + board[j][i];
        }
        if(check == 3 || check == 6)
        {
            DetermineWinner(board, check);
            break;
        }
        check = 0;
    }
}

void DiagonalCheck(int board[4][3])
{
    int check = board[0][0] + board[1][1] + board[2][2];
    if(check == 3 || check == 6)
    {
        DetermineWinner(board, check);
    }
    check = board[0][2] + board[1][1] + board[2][0];
    if(check == 3 || check == 6)
    {
        DetermineWinner(board, check);
    }
}

bool FullBoardCheck(int board[4][3])
{
    HorizontalCheck(board);
    VerticalCheck(board);
    DiagonalCheck(board);
    if(board[3][0] == 1 || board[3][1] == 1){
        return true;
    }
    return false;
}