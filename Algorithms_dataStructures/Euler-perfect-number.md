https://www.nowcoder.com/practice/7299c12e6abb437c87ad3e712383ff84

 **推导公式**
大数学家欧拉曾推算出完全数的获得公式：如果p是质数，且2^p-1也是质数，那么（2^p-1）X2^（p-1）便是一个完全数。
例如p=2，是一个质数，2^p-1=3也是质数，（2^p-1）X2^（p-1）=3X2=6，是完全数。
例如p=3，是一个质数，2^p-1=7也是质数，（2^p-1）X2^（p-1）=7X4=28，是完全数。
例如p=5，是一个质数，2^p-1=31也是质数，（2^p-1）X2^（p-1）=31X16=496是完全数。
当2^p-1是质数的时候，称其为梅森素数。到2013年2月6日为止，人类只发现了48个梅森素数，较小的有3、7、31、127等 

```c
//欧拉完全数公式
//大数学家欧拉曾推算出完全数的获得公式：
//如果p是质数，且2^p-1也是质数，那么（2^p-1）X2^（p-1）便是一个完全数
#include<stdio.h>
#include<math.h>
int is_prime(int num)
{
    for(int i = 2; i <= sqrt(num); i++)
    {
        if(num % i == 0)
            return 0;
    }
    return 1;
}
int main()
{
    int num = 0;
    while(~scanf("%d", &num))
    {
        int count = 0;
        int i = 0;
        //(pow(2, 2 * i -1) - pow(2, i -1)) <= num
        for(i = 2; (pow(2, 2 * i -1) - pow(2, i -1)) <= num; i++)
        {
            long int t = pow(2,i) - 1;
            //如果都是质数，则对应数值为完全数
            if(is_prime(i) && is_prime(t))
            {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
```

