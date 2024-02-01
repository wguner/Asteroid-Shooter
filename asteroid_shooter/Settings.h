#pragma once

#define WIN_W 1000 // Everything but menus are calculated off of these
#define WIN_H 600
#define WIN_FRAMERATE 60

#define SHIP_YPOS (WIN_H - 35.0)
#define SHIP_SPEED 10
#define SHIP_SIZE 32
#define SHIP_PTCOUNT 4 // Have to hardcode Ship point positions, don't change this
#define SHIP_FIRE_CD 0.15

#define PLY_LIVES 3

#define BLT_SPEED 7
#define BLT_W 3
#define BLT_H 10

#define AST_SIZE_BIG 15
#define AST_SIZE_SML 10
#define AST_SPEED 1.5
#define AST_SPAWN_TIME 6
#define AST_DECREASE_SPAWN_TIME 2