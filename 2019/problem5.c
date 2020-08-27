//
// Created by c0ntr on 2020/08/27.
//

#include <stdio.h>
#include <stdlib.h>

/*
 * 方針
 * スタックを使いデータをPush,Popしていく
 * すでに入っているかどうかを配列で判断して、おかしかった場合はそこで
 * 切り上げる。
 * 問題が無ければ"OK"を返す
 *
 * 注意すべき点
 * -がつくとpopだが、フラグの添え字はabsで絶対値をとらないといけない
 */

#define MAX_DATA 1000

struct stack
{
    int arr[MAX_DATA];
    int top;
};

int push(struct stack *stk, int input)
{
    if (stk->top <= MAX_DATA){
        stk->top++;
        stk->arr[stk->top] = input;
        return 0;
    } else {
        return -1;
    }
}

int pop(struct stack *stk)
{
    if (stk->top != 0) {
        int temp = stk->top;
        stk->top--;
        return stk->arr[temp];
    } else {
        return -1;
    }
}

void initStack(struct stack *stk)
{
    int i;
    for (i = 0; i < MAX_DATA; i++){
        stk->arr[i] = 0;
    }
    stk->top = 0;
    return;
}

int main(void){
    int l,wrongPos =-1;
    struct stack stk;
    short flag[1000];
    scanf("%d",&l);

    initStack(&stk);
    for(int i = 0;i < l;i++){
        flag[i] = 0;
    }

    for(int i = 0;i < l;i++){
        int tmp;
        scanf("%d",&tmp);

        if(tmp > 0){

            if(!flag[tmp]){
                push(&stk,tmp);
                flag[tmp] = 1;
            } else {
                wrongPos = i;
                break;
            }

        } else {
            tmp = abs(tmp);

            if(flag[tmp]){
                int popData = pop(&stk);

                if(popData != tmp){
                    wrongPos = i;
                    break;
                } else {
                    flag[tmp] = 0;
                    continue;
                }
            } else {
                wrongPos = i;
                break;
            }

        }
    }

    if(wrongPos + 1){
        printf("%d\n",wrongPos + 1);
    } else {
        printf("OK\n");
    }

    return 0;
}