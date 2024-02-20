//
// Created by onitn on 11/14/2023.
//

#ifndef TETRISS_TETRISGAMERENDERER_H
#define TETRISS_TETRISGAMERENDERER_H

#include "TetrisLogicController.h"

class TetrisGameRenderer {
protected:
    WINDOW *gridWindow;
    WINDOW *scoreWindow;
    int posX{0}, posY{0};
public:
    TetrisLogicController logicController;
    void gameLoop();
    TetrisGameRenderer(){
        int gameWindowsWidth, gameWindowsHeight,scoreWindowsWidth,scoreWindowsHeight, predictionWindowsHeight, predictionWindowsWidth;
        gameWindowsWidth = GRID_WIDTH * GRAPHICS_BLOCK_WIDTH + GRAPHICS_BORDERS_SIZE;
        gameWindowsHeight = GRID_HEIGHT + GRAPHICS_BORDERS_SIZE;
        scoreWindowsWidth = (TETRAMINO_BLOCKS+2) * GRAPHICS_BLOCK_WIDTH + GRAPHICS_BORDERS_SIZE;;
        scoreWindowsHeight = 5 + GRAPHICS_BORDERS_SIZE;
        gridWindow = newwin(gameWindowsHeight, gameWindowsWidth, posY, posX+scoreWindowsWidth+4);
        scoreWindow = newwin(scoreWindowsHeight, scoreWindowsWidth, posY,posX);
     logicController = TetrisLogicController();
    }



    void renderGrid();
    void renderScore();
    void destroyWindows();

};


#endif //TETRISS_TETRISGAMERENDERER_H
