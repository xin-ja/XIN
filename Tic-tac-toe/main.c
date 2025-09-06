#include <stdio.h>

#include "game.h"

#include <stdlib.h>
#include <time.h>

void menu() {
    printf("************************\n");
    printf("******1.play 0.exit*****\n");
    printf("*************************\n");

}

void game() {
    char board[ROW][COL]={0};
    char juge =  0;
    //初始化棋盘数组
    initial_board(board,ROW,COL);
    //打印棋盘
    print_board(board,ROW,COL);
   while(1) {//下棋
       //玩家下棋
       player_move(board,ROW,COL);
       //判断输赢
       juge = juge_winner(board,ROW,COL);
       if(juge != 'c') {
           break;
       }
       //电脑下棋
       computer_move(board,ROW,COL);
       //判断输赢
       juge = juge_winner(board,ROW,COL);
       if(juge != 'c') {
           break;
       }
   }

    if(juge == 'p') {
        printf("NO WINNER\n");
    }

    if(juge == '*') {
        printf("YOU WIN\n");
    }

    if(juge == '#') {
        printf("YOU LOSE\n");
    }

}

int main() {
    srand(time(NULL));
    int input = 0;
    do {
        setbuf(stdout,NULL);
        menu();
        scanf("%d", &input);
        switch (input) {
            case 1:
                printf("游戏开始!\n");
                game();
                break;
            case 0:
                printf("退出程序\n");
                return 0;
        }
    }
    while (1);
}