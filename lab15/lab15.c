#include <stdio.h>
#include <assert.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    assert(n > 0);
    int matrix[n][n];
    int diag_summ[2*n-3];
    for(int i = 0; i < 2*n-3; i++)diag_summ[i]=0;
    
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
            printf("%8d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    //делаем магию
    int diag_counter = 0;
    
    for (int k = n-2; k >= -n+2; k--)
    {
      for (int j = 0; j < n - k; j++)
      {
        int i = k + j;
        if (i < n && j < n && i >= 0 && j >= 0)
        {
          diag_summ[diag_counter]+=matrix[i][j];
        }
        
      }
      diag_counter++;
    }
    
    
    //подставляем суммы нужных элементов 
    int pointer = 0;
    for(int i = 0; i < diag_counter; i++){
        if (i % 2 != 0){
            pointer++;
            matrix[pointer][n-1-pointer]+=diag_summ[diag_counter-1-i]-2*matrix[pointer][n-1-pointer];
        }
        
    }
    
    //выводи итог
    printf("\nВаша новая матрица\n");
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            printf("%8d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    return 0;
}
