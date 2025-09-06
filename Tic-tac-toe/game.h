//
// Created by Xinja on 2025/9/5.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H

#endif //UNTITLED_GAME_H

#define ROW 5
#define COL 5

//初始化棋盘
void initial_board(char board[ROW][COL],int row, int col);
//打印棋盘
void print_board(char board[ROW][COL],int row,int col);
//玩家下棋
void player_move(char board[ROW][COL],int row,int col);
//电脑下棋
void computer_move(char board[ROW][COL],int row,int col);
//判断输赢
char juge_winner(char board[ROW][COL],int row,int col);
/*玩家赢 ：*
 * 电脑赢：#
 * 平局：p
 * 继续游戏：c
 */