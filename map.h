#pragma once

#include"scene.h"

#define CELL_WIDTH 40
#define CELL_HEIGHT 40
#define CELL_NUM_X 16
#define CELL_NUM_Y 12
#define WINDOW_Y 480
#define WINDOW_X 640
#define GAME_MAP ".\\image\\BaseChip.png"
struct Cell {
    int gh;
};

class Map {
public:
    Cell cell[CELL_NUM_X][CELL_NUM_Y];
    int chipgh[(128 / 16) * (1248 / 16)];

    Map() {
        LoadDivGraph(GAME_MAP, (128 / 16) * (1248 / 16), 128 / 16, 1248 / 16, 16, 16, chipgh);
        for (int i = 0; i < CELL_NUM_X; i++) {
            for (int j = 0; j < CELL_NUM_Y; j++) {
                cell[i][j].gh = chipgh[i * CELL_NUM_X + j];
            }
        }
    }

    void View() {
        for (int i = 0; i < CELL_NUM_X; i++) {
            for (int j = 0; j < CELL_NUM_Y; j++) {
                DrawExtendGraph(i * CELL_WIDTH, j * CELL_HEIGHT, (i + 1) * CELL_WIDTH, (j + 1) * CELL_HEIGHT, cell[i][j].gh, TRUE);
            }
        }
    }

    void All() {
        View();
    }
};

