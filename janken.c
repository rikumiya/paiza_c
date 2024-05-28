#include <stdio.h>
#include <stdlib.h>

int main(void){
    char str[1000];
    int head = 0, tail = 0;
    int i, N, max;
    int *count;
    max = 0;
    
    fgets(str, sizeof(str), stdin);
    N = atoi(str);
    count = (int *)malloc(sizeof(int)*N);
    for(i = 0; i < atoi(str); i++){
        count[i] = 1;
    }

    while(fgets(str, sizeof(str), stdin) != NULL){
        i = 0;
        while(str[i] != ' ') i++;
        head = atoi(str);
        //printf("%d\n", head);
        //後半のノードを作成
        tail = atoi(&str[i]);
        //printf("%d\n", tail);
        count[head-1] += count[tail-1];
        count[tail-1] = 0;
    }
    for(i = 0; i < N; i++){
        if(max < count[i])
            max = count[i];
    }
    for(i = 0; i < N; i++){
        if(max == count[i])
            printf("%d\n", i+1);
    }

    return 0;
}