###### 169. 多数元素

 [169. 多数元素 - 力扣（LeetCode） (leetcode-cn.com)](https://leetcode-cn.com/problems/majority-element/) （官解）

```c
int majorityElement(int* nums, int numsSize){
    int maj = nums[0];
    int count = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] == maj)
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count <= 0)
        {
            maj = nums[i+1];
        }
    }
    return maj;
}
```

