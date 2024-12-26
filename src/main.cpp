#include "vendors/GLEW/glew.h"
#include "vendors/GLFW/glfw3.h"
#include <iostream>
#include "Headers/Drawing.h"
#include "Headers/Game_Logic.h"


//X always goes first

int main(void)
{
    int board[4][3] = {0,0,0,0,0,0,0,0,0,0,0,0};
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 800, "Tic-Tac-Toe", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSetWindowUserPointer(window, &board);

    glfwSetMouseButtonCallback(window, mouseButtonCallBack);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Set the clear color and clear the screen
        glClearColor(0.19215, 0.27843f, 0.22745f, 0.8f);  // Background color
        glClear(GL_COLOR_BUFFER_BIT);

        //check for winner
        if(FullBoardCheck(board))
        {
            if(board[3][1]==1)
            {
                std::cout<<"X WIN!";
            }
            else if(board[3][2]==1)
            {
                std::cout<<"O WIN!";
            }
        }

        // Draw the Tic-Tac-Toe board
        drawTicTacToeGrid();
        drawBoard(board);

        // Swap front and back buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Terminate GLFW
    glfwTerminate();
    return 0;
}