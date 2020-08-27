//
// Created by c0ntr on 2020/08/27.
//

#include<stdio.h>

/*
 * 方針
 * 入力を４回受け取って足していくだけ
 */

int main(void){
    int input,ans = 0;

    for(int i = 0;i < 4;i++){
        int tmp;
        scanf("%d",&tmp);
        ans += tmp;
    }

    printf("%d\n",ans);
    return 0;
}