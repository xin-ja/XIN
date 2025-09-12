#include <stdio.h>
#include "game.h"

void menu() {
    printf("*************************\n");
    printf("*****1. play 0. exit*****\n");
    printf("*************************\n");
}

void game() {
    char mine[T_ROW][T_COL]={0};
    char show[T_ROW][T_COL]={0};
    //初始化数组 mine数组' '  show'*'
    init_board(mine,T_ROW,T_COL,' ');
    init_board(show,T_ROW,T_COL,'*');
    //打印棋盘
    print(show,ROW,COL);
    //设雷
    mine_set(mine,ROW,COL);
    //排雷
    find_mine(mine,show,ROW,COL);

}
int main(void) {
do {
    srand(time(NULL));
    int input = 0;
    setbuf(stdout,NULL);
    menu();
    scanf("%d",&input);
    switch (input) {
        case 1:
        printf("Welcome to Minesweeper!\n");
            game();
            break;
        case 0:
            return 0;
        default:
            printf("Please enter a valid option!\n");
    }

}
    while (1);
}