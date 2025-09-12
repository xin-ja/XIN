//
// Created by Xinja on 2025/9/7.
//
#include "game.h"

#include <stdio.h>

//初始化棋盘
void init_board(char board[T_ROW][T_COL],int row ,int col,char x) {
        int i = 0;
        int j = 0;
        for (i = 0;i<row;i++) {
                for (j = 0;j<col;j++) {
                        board[i][j]=x;
                }
        }

}
//打印棋盘
void print(char board[T_ROW][T_COL],int row,int col) {
        int i = 0;
        int j = 0;
        for (i = 1;i<=row;i++) {
                printf("  %d ",i);
        }
        printf("\n");
        for (i = 1;i<=row;i++) {
                printf("%d",i);
                for (j = 1;j<=col;j++) {
                        printf(" %c ",board[i][j]);
                        if (j<=col-1) {
                                printf("|");
                        }
                }
                printf("\n");
                printf(" ");
                for(j=1;j<=row;j++) {
                        printf("---");
                        if(i<=col-1) {
                                printf("|");
                        }
                }
                printf("\n");
        }

}

//设雷
void mine_set(char board[T_ROW][T_COL],int row,int col) {
        int i = 0;
        int j = 0;
        int count = 0;
        while (count<COUNT) {
                i = rand()%row+1;
                j = rand()%col+1;
                if(board[i][j]==' ') {
                        board[i][j]='1';
                        count++;
                }

        }
}

//排雷

int count_mine_around(char board[T_ROW][T_COL],int x,int y) {
        int i = 0;
        int j = 0;
        int count = 0;
        for (i = x-1;  i<=x+1; i++) {
                for (j = y-1;  j<=y+1; j++) {
                        if(board[i][j]=='1') {
                                count++;
                        }
                }
        }
        return count;

}

//标记
void lable(char show[T_ROW][T_COL],int row ,int col) {


        while(1) {
                char input = 0;
                int x = 0;
                int y = 0;
                printf("是否要进行标记(y/n)？\n");
                fflush(stdin);
                scanf("%c",&input);
                if(input=='y') {
                        printf("请输入要标记的坐标\n");
                        scanf("%d %d",&x,&y);
                        show[x][y]='#';
                        print(show,row,col);
                        fflush(stdin);
                }
                else {
                        break;
                }
        }


}

//判断赢
int count_all(char show[T_ROW][T_COL],int row,int col) {
        int i = 0;
        int j = 0;
        int count = 0;
        for (i = 1;i<=row;i++) {
                for (j = 1;j<=col;j++) {
                        if(show[i][j]=='*'||show[i][j]=='#') {
                                count++;
                        }
                }
        }
        return count;
}

//递归解决点一个出一片
void clean(char mine[T_ROW][T_COL],char show[T_ROW][T_COL],int x ,int y) {

        if(show[x][y]=='*') {
                if(count_mine_around(mine,x,y)==0) {
                        show[x][y]=' ';
                        clean(mine,show,x+1,y);
                        clean(mine,show,x-1,y);
                        clean(mine,show,x,y+1);
                        clean(mine,show,x,y-1);
                        clean(mine,show,x+1,y-1);
                        clean(mine,show,x+1,y+1);
                        clean(mine,show,x-1,y-1);
                        clean(mine,show,x-1,y+1);

                }

                else {
                        show[x][y]=count_mine_around(mine,x,y)+'0';
                }
        }


}
void find_mine(char mine[T_ROW][T_COL],char show[T_ROW][T_COL],int row,int col) {
        int judge_win = 0;
        int x = 0;
        int y = 0;

    while (1) {

            printf("请输入排查坐标\n");
            fflush(stdin);
            scanf("%d %d",&x,&y);

             if (x>=1 && x<=row && y>=1 && y<=col) {
                    if (show[x][y]=='*') {
                            if (mine[x][y]=='1') {
                                    printf("boom！！！\n");
                                    print(mine,row,col);
                                    break;
                            }
                            else {
                                    clean(mine,show,x,y);
                            }
                                        judge_win = count_all(show,row,col);
                            if (judge_win==COUNT) {
                                    break;
                            }
                                    print(show,row,col);
                                    lable(show,row,col);}

                    }
             else {
                     printf("坐标非法请重新输入\n");
             }

            }
        if(judge_win==COUNT) {
                printf("YOU WIN！！！\n");
                print(mine,row,col);
        }


    }
