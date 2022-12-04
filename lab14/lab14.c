#include <stdio.h>
#include <assert.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    assert(n > 0);
    int matrix[n][n];
    
    //инициилизируем матрицу nxn
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            scanf("%d", &matrix[i][j]);
        }
    }
    
    //выводим матрицу nxn
    printf("Ваша матрица\n");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    int upb = 0,
        lob = n - 1,
        leb = 0,
        rib = n - 1,
        state = 1,
        iter = 1;
    
    //выполняем условие задачи
    while (iter <= n*n){ 
        switch (state){
            case 1:
                for(int y = upb; y <= lob; ++y){
                    printf("%d ", matrix[y][rib]);
                }
                rib--;
                state = 2;
                break;
            case 2:
                for(int x = rib; x >= leb; --x){
                    printf("%d ", matrix[lob][x]);
                }
                lob--;
                state = 3;
                break;
            case 3:
                for(int y = lob; y >= upb; --y){
                    printf("%d ", matrix[y][leb]);
                }
                leb++;
                state = 4;
                break;
            case 4:
                for(int x = leb; x <= rib; ++x){
                    printf("%d ", matrix[upb][x]);
                }
                upb++;
                state = 1;
                break;
        }
        iter++;
    }  
    return 0;
}
