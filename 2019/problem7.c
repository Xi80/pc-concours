//
// Created by c0ntr on 2020/08/27.
//

#include <stdio.h>

/*
 * 方針
 * bit全探索をする
 *
 * 注意すべき点
 * 変数の最大値に気を付ける
 * 配列を引数にとるときはconstをつけて読み取り専用にする
 *
 * 感想
 * 初めてbit全探索をした、脳死でできた。
 */

unsigned long gcd(unsigned long a, unsigned long b)
{
    if (a == 0)return b;

    return gcd(b % a, a);
}

unsigned long lcm(unsigned long a, unsigned long b)
{
    return (a*b)/gcd(a, b);
}

unsigned long lcm_arr(const unsigned long a[], unsigned long n){
    unsigned long k[20];

    for(long i = 0;i < n;i++){
        k[i] = a[i];
    }

    for(long i=n-2; i>=0; i--){
        k[i] = lcm(k[i], k[i+1]);
    }

    return k[0];
}

int main(void){
    unsigned long n,ans = 0;
    unsigned long p[20];
    scanf("%ld",&n);

    for(long i = 0;i < n;i++){
        scanf("%ld",&p[i]);
    }

    unsigned long bit = 0x0001;
    unsigned long dest = 0x0000;

    for(long i = 0;i < n;i++){
        dest |= 1 << i;
    }

    while(bit != dest + 1){

        unsigned long pos = 0;
        unsigned long negPos = 0;
        unsigned long array[n];
        unsigned long negArray[n];

        for(long i = 0;i < n;i++){
            array[i] = 0;
        }

        for(long i = 0;i < n;i++){
            if(bit & 1 << i){
                array[pos++] = p[i];
            }  else {
                negArray[negPos++] = p[i];
            }
        }

        unsigned long l = lcm_arr(array,pos);
        long flag= 1;
        for(long i = 0;i < negPos;i++){
            if(l % negArray[i] == 0){
                flag = 0;
            }
        }
        if(flag){
            ans++;
        }
        bit++;
    }

    printf("%d\n",ans);
    return 0;
}