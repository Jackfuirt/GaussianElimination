#include <stdio.h>
#include <math.h>
int n=3; //未知数个数

int main(void)
{
   double a[n][n+1];
   int f=1;
   int bj=0;
   double count;
   int f1=1;
   double bs;
   double x[n];
   //输入矩阵元素
   for (int i = 0; i < n; i++)
   {
     printf("请输入第 %d 行",i+1);
     for (int j = 0; j < n+1; j++)
     {
        scanf("%lf",&a[i][j]);
     }
   }
   //转换为上三角矩阵
   for (int i = 0; i < n; i++)
   {
    f=1;
    //保证对角线非0
    if(a[i][i]==0)
    {
        f=0;
        for (int k = i+1; k < n; k++)
        {
        
            if(a[k][i] != 0) 
            {            
                bj=k;
                f=1;
            }   
        }
    if (f==1)
    {
       //交换行
       for (int q = 0; q < n+1; q++)
        {
            count=a[bj][q];
            a[bj][q]=a[i][q];
            a[i][q]=count;
        }
    }
    else printf("erro");
    }
    //消元
    for (int k = i+1; k < n; k++)
    {
        bs=a[k][i]/a[i][i];
        for (int j = 0; j < n+1; j++)
        {
            a[k][j]=a[k][j]-bs*a[i][j];
        }
        
    }
    
    
   }
   //输出上三角矩阵
   printf("上三角矩阵为：\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n+1; j++)
        {
            printf("%.3lf ",a[i][j]);
        }
        printf("\n");
    } 
   //求解
   for (int i = n-1; i >+0; i--)
   {
    count=a[i][n];
    for (int j= i+1; j<n ;j++)
    {
        count-=a[i][j]*x[j];  
    }
    x[i]=count/a[i][i];
   }
   //输出解
   printf("解为：\n");
   for (int i = 0; i < n; i++)
   {
    printf("x[%d]=%.3lf\n",i+1,x[i]);
   }
      
}
