//
// Created by Xinja on 2025/9/5.
//

#include "game.h"


#include <stdio.h>

#include <stdlib.h>
//初始化棋盘
void initial_board(char board[ROW][COL],int row, int col) {

    int i = 0;
    int j = 0;
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            board[i][j]=' ';
        }
    }

}
//打印棋盘
void print_board(char board[ROW][COL],int row,int col) {
    int i = 0;
    int j = 0;
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            printf(" %c ",board[i][j]);
            if (j<col-1) {
                printf("|");
            }
        }
        printf("\n");
        for(j=0;j<col;j++) {
            printf("---");
            if (j<col-1) {
                printf("|");
            }

        }
        printf("\n");
    }
}

//玩家下棋
void player_move(char board[ROW][COL],int row,int col) {
    int i = 0;
    int j = 0;
    while (1) {printf("请输入坐标: \n");
        scanf("%d %d",&i,&j);
        if(i<=row &&i>=1 && j<=col &&j>=1) {
            if(board[i-1][j-1]!=' ') {
                printf("此格已被占据，请重新选择\n");
            }
            else {
               board[i-1][j-1]='*';
               print_board(board,row,col);
               break;
           }




        }
        else {
            printf("坐标非法，请重新输入\n");
        }
    }
}

//电脑下棋
void computer_move(char board[ROW][COL],int row,int col) {
    printf("电脑下棋\n");
    int i = 0;
    int j = 0;
    while (1) {
        i= rand()%row;
        j= rand()%col;
        if(board[i][j]==' ') {
            board[i][j]='#';
            print_board(board,row,col);
            break;
        }


    }

}


int isfull(char board[ROW][COL],int row,int col) {
    int i = 0;
    int j = 0;
    for(i=0;i<ROW;i++) {
        for(j=0;j<COL;j++) {
            if (board[i][j]==' ') {
                return 0;
            }
        }
    }
    return 1;
}

//判断输赢
/*玩家赢 ：*
 * 电脑赢：#
 * 平局：p
 * 继续游戏：c
 */
char juge_winner(char board[ROW][COL],int row,int col) {
    int i = 0;
    int j = 0;
//行
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            if(board[i][j]==board[i][j+1] && board[i][j+1]==board[i][j+2] && board[i][j]!=' ') {
                return board[i][j];
            }
        }
    }
//列
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            if(board[i][j]==board[i+1][j] && board[i+1][j]==board[i+2][j]&& board[i][j]!=' ') {
                return board[i][j];
            }
        }
    }
//对角线
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            if (board[i][j]==board[i+1][j+1] && board[i+1][j+1]==board[i+2][j+2]&& board[i][j]!=' ') {
                return board[i][j];
            }
        }
    }
    for(i=0;i<row;i++) {
        for(j=0;j<col;j++) {
            if (board[i][j]==board[i-1][j-1] && board[i-2][j-2]==board[i-1][j-1]&& board[i][j]!=' ') {
                return board[i][j];
            }
        }
    }
//平局
    int full = isfull(board,row,col);
    if(full) {
        return 'p';
    }

        return'c';


    }