#include <stdio.h>

int main()
{
    int kolvo = 0;
    scanf("%d", &kolvo);
    int count = 0;
    int sum = 0;
    int ostatkiranshe[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int ostatkipozhe[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < kolvo; i++){
        int num = 0;
        scanf("%d", &num);
        sum += num;
        if (num % 2 == 0){
            count++;
        }
        int d = count % 10;
        if (ostatkiranshe[d] == 0){ 
            ostatkiranshe[d] = sum;
        }
        ostatkipozhe[d] = sum;
    }
    int maxsum = 0;
    if (count % 10 == 0){
        printf("%d\n", sum);
    }else{
        for (int i = 1; i < (count % 10 + 1); i++){                     
            if ((ostatkipozhe[i] - ostatkiranshe[i]) > maxsum){
                maxsum = ostatkipozhe[i] - ostatkiranshe[i];
            }
        }
    }
    if (ostatkipozhe[0] > maxsum){
        maxsum = ostatkipozhe[0];
    }
    printf("%d\n", maxsum);
}