#include <stdio.h>
#include <string.h>
int main()
{
    char num[10000];
    int len,i,sum,temp;
    
    while(scanf("%s",num)!=EOF)
    {
        len=strlen(num);
        
        if(len==1&&num[0]=='0')
        break;
        
        sum=0;
        for(i=0;i<len;i++)
        sum+=num[i]-'0';
        
        if(sum<10)
        printf("%d\n",sum);
        
        else
        {
          temp=sum;
          while(sum>=10)
          {   
            sum=0;
            while(temp)
            {
               sum+=temp%10;
               temp/=10;
            }
            temp=sum;
          
           }
         printf("%d\n",sum);  
        }               
                              
                              
    }
    
    
    
    return 0;
}
