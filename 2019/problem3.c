//
// Created by c0ntr on 2020/08/27.
//

#include<stdio.h>

/*
 * 方針
 * 最上位の'1'ビットを探す
 * それ以外のビットを'0'にする
 */

int main(void) {
    int input,bit = 0;
    scanf("%d",&input);

    while(input >> 1){
            input >>= 1;
            bit++;
    }

    printf("%d\n",1 << bit);
    return 0;
}
