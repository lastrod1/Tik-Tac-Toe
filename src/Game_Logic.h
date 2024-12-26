#pragma once

bool TurnDecide(int board[4][3]);

void DetermineWinner(int board[4][3], int check);
void HorizontalCheck(int board[4][3]);
void VerticalCheck(int board[4][3]);
void DiagonalCheck(int board[4][3]);
bool FullBoardCheck(int board[4][3]);