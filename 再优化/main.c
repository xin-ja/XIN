#include <stdio.h>
//鸡兔同笼的再优化
int main(void) {
    //输入
    printf("请输入头的总数和腿的总数：");
    fflush(stdout);
    int footcount=0;
    int headcount=0;
    scanf("%d %d",&headcount,&footcount);//一定不要忘记&！！！！！！！

    //计算
  int chickencount=0;
    int rabbitcount=0;
    while (2*chickencount+4*rabbitcount!=footcount) {
        chickencount++;
        rabbitcount=headcount-chickencount;
        if (chickencount>headcount) {
            printf("无解");
            return 0;
        }
    }
    printf("鸡有%d只 兔有%d只",chickencount,rabbitcount);
return 0;
}