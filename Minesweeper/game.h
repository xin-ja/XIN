//
// Created by Xinja on 2025/9/7.
//
#include <time.h>
#include <stdlib.h>
#ifndef MINESWEEPER_GAME_H
#define MINESWEEPER_GAME_H

#endif //MINESWEEPER_GAME_H
#define T_ROW 11
#define T_COL 11

#define ROW 9
#define COL 9
#define COUNT 10

//初始化数组
void init_board(char board[T_ROW][T_COL],int row ,int col,char x);
//打印棋盘
void print(char board[T_ROW][T_COL],int row,int col);
//设雷
void mine_set(char board[T_ROW][T_COL],int row,int col);
//排雷
void find_mine(char mine[T_ROW][T_COL],char show[T_ROW][T_COL],int row,int col);