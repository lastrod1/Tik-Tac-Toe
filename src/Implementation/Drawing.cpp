#include "../Headers/Drawing.h"
#include "../vendors/GLEW/glew.h"
#include "../vendors/GLFW/glfw3.h"
#include "../Headers/Game_Logic.h"
#include <algorithm>
#include <iostream>

void drawTicTacToeGrid()
{
    // Set line color (white)
    glColor3f(0.92941f, 0.95686f, 0.94902f);

    // Begin drawing lines
    glLineWidth(10.0);
    glBegin(GL_LINES);

    // Vertical lines
    glVertex2f(-0.33f, -1.0f); glVertex2f(-0.33f, 1.0f);
    glVertex2f(0.33f, -1.0f); glVertex2f(0.33f, 1.0f);

    // Horizontal lines
    glVertex2f(-1.0f, -0.33f); glVertex2f(1.0f, -0.33f);
    glVertex2f(-1.0f, 0.33f); glVertex2f(1.0f, 0.33f);

    glEnd();
}

void drawX(int x_pos, int y_pos)
{
    float x_center = -1 + 0.333f + (0.666f * x_pos);
    float y_center = 1 - 0.333f - (0.666f * y_pos);
    glColor3f(0.92941f, 0.95686f, 0.94902f);
    glLineWidth(7.5);
    glBegin(GL_LINES);

    // left to right
    glVertex2f(x_center - 0.222f, y_center + 0.222f);
    glVertex2f(x_center + 0.222f, y_center - 0.222f);

    // right to left
    glVertex2f(x_center + 0.222f, y_center + 0.222f);
    glVertex2f(x_center - 0.222f, y_center - 0.222f);

    glEnd();
}

void drawO(int x_pos, int y_pos)
{
    float x_center = -1 + 0.333f + (0.666f * x_pos);
    float y_center = 1 - 0.333f - (0.666f * y_pos);
    float radius = 0.2664f;
    int line_segz = 400;
    glColor3f(0.92941f, 0.95686f, 0.94902f);
    glLineWidth(10);
    glBegin(GL_LINE_LOOP);
    for(int i = 0; i < line_segz; i++)
    {
        float theta = 2.0f * 3.1415 * (float(i)/float(line_segz));
        float x = radius * cosf(theta);
        float y = radius * sinf(theta);
        glVertex2f(x + x_center, y + y_center);
    }
    glEnd();
}

void drawBoard(int board[4][3])
{
    for(int i = 0; i<3; i++)
    {
        for(int j = 0; j<3; j++)
        {
            if(board[j][i] != 0)
                if(board[j][i] == 1)
                {
                    drawX(i, j);
                }
                else
                {
                    drawO(i, j);
                }
        }
    }
}

void getXandYpos(double x_pos, double y_pos, int width, int height, int &grid_x, int &grid_y)
{
    grid_x = (x_pos/width)*3;
    grid_y = (y_pos/height)*3;

    grid_x = std::clamp(grid_x, 0, 2);
    grid_y = std::clamp(grid_y, 0, 2);
}


void mouseButtonCallBack(GLFWwindow* window, int button, int action, int mods)
{
    if(button == GLFW_MOUSE_BUTTON_1 && action == GLFW_PRESS)
    {
        double x_position;
        double y_position;
        int width;
        int height;
        glfwGetCursorPos(window, &x_position, &y_position);
        glfwGetWindowSize(window, &width, &height);

        int grid_x;
        int grid_y;
        getXandYpos(x_position, y_position, width, height, grid_x, grid_y);
        int (*board)[3] = (int(*)[3])glfwGetWindowUserPointer(window);
        if(board[grid_y][grid_x] == 0)
        {
            if(TurnDecide(board))
            {
                board[grid_y][grid_x] = 2;
            }
            else
            {
                board[grid_y][grid_x] = 1;
            }
        }
    }
}