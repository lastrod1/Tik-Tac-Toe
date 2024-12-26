#pragma once

//functions that use GLFW
#include "../vendors/GLEW/glew.h"
#include "../vendors/GLFW/glfw3.h"

void drawTicTacToeGrid();
void drawX(int x_pos, int y_pos);
void drawO(int x_pos, int y_pos);
void drawBoard(int board[4][3]);
void getXandYpos(double x_pos, double y_pos, int width, int height, int &grid_x, int &grid_y);
void mouseButtonCallBack(GLFWwindow* window, int button, int action, int mods);
