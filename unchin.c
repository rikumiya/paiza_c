#include <stdio.h>
#include <stdlib.h>

int main(void){
    int **station;
    int i = 0, n, m, l, k,sum = 0, x,y;
    char str[1000];
    
    fgets(str, sizeof(str), stdin);
    
    n = atoi(str);
    station = (int **)malloc(sizeof(int *)*n);
    //printf("%c\n", str[i]);
    while(str[i] != ' ') i++;
    i++;
    m = atoi(&str[i]);
    for(i = 0; i < n; i++)
        station[i] = (int *)malloc(sizeof(int)*m);
    
    for(i = 0; i < n; i++){
        fgets(str, sizeof(str), stdin);
        k = 0;
        for(int j = 0; j < m; j++){
            if(j == 0)
                station[i][j] = atoi(str);
            else{
                while(str[k] != ' ') k++;
                    k++;
                    station[i][j] = atoi(&str[k]);
            }
            //printf("%d ", station[i][j]);
        }
        //printf("\n");
    }
    
    fgets(str, sizeof(str), stdin);
    l = atoi(str);
    x = 1, y = 1;
    for(i = 0; i < l; i++){
        k = 0;
        fgets(str, sizeof(str), stdin);
        m = atoi(str);
        while(str[k] != ' ') k++;
        k++;
        n = atoi(&str[k]);
        if(x != m)
            x = m;
        if(y > n)
            sum += station[x-1][y-1] - station[m-1][n-1];
        else if(y < n)
            sum += station[m-1][n-1] - station[x-1][y-1];
            
        x = m;
        y = n;
    }
    printf("%d\n", sum);
    
    return 0;
}