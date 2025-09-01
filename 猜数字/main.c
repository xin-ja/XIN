#include <stdio.h>
//猜数字
/*
 *电脑给出一个随机数用户猜(1-100)
 *反馈猜小了 猜大了
 */
#include <stdlib.h>
#include <time.h>

void menu() {
    printf("1.play  0.end\n");
}
int guess_num() {
    int n=rand()%100+1;
    int guess = 0;
    loop:
    printf("Enter your guess: ");
    fflush(stdout);
    scanf("%d",&guess);
    if(n<guess) {
        printf("猜大了\n");
        goto loop;
    }
    else if(n>guess) {
        printf("猜小了\n");
        goto loop;
    }
    else {
        printf("猜对了！\n");
        return 0;
    }

}

int main(void) {
    int n = 1;
    srand(time(NULL));
    do {    menu();
        fflush(stdout);
        scanf("%d",&n);
       switch (n) {
           case 0:
            break;
           case 1:
             guess_num();
               break;
           default:
               printf("Wrong choice\n");
       }

    }
    while (n != 0);

}