//查询范围内质数
#include <stdio.h>
int main() {
    //输入
    int n=0;
    printf("请输入查询范围最大值");
    fflush(stdout);
    scanf("%d",&n);
    //计算
    for (int i=2;i<n;i++) {
       int isprime=1;
        for (int j=2;j<i;j++) {
            if (i%j==0) {
                isprime=0;
                break;
            }

        }
   if (isprime) {
       printf("%d是质数\n",i);
   } }
    return 0;
}