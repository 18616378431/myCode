//有序序列进行二分搜索
#include <stdio.h>

int *bsearch(int *t,int n,int item);
int *bsearch_index(int *t,int n,int item);

int main()
{
    int queue[10] = {1,2,3,4,5,6,7,8,9,10};

    int *tmp = bsearch(queue,10,22);

    printf("%p,%d\n",tmp,tmp == NULL?0:*tmp);

    int *tmp_index = bsearch_index(queue,10,3);

    printf("%p,%d\n",tmp_index,tmp_index == NULL?0:*tmp_index);

    //test
    printf("%lu\n",sizeof(queue));

    return 0;
}

/**
 * @brief   二分搜索
 * @note    二分搜索,地址范围查找
 * 
 * @param   t:序列起始地址
 *          n:序列大小
 *          item:待查找元素
 * 
 * @return  目标元素的地址,查找失败返回NULL
 * 
 * @author  jiankang.wang
 * @date    2019-09-29 
 */
int *bsearch(int *t,int n,int item)
{
    int *lo = t,*hi = t + n,*mid;

    while(lo < hi)
    {
        mid = lo + ((hi - lo) >> 1);
        if(item < *mid)
        {
            hi = mid;
        }
        else if(item > *mid)
        {
            lo = mid + 1;
        }
        else
        {
            return mid;
        }
    }

    return NULL;
}

/**
 * @brief   二分搜索
 * @note    二分搜索,下标范围查找
 * 
 * @param   t:序列起始地址
 *          n:序列大小
 *          item:待查找元素
 * 
 * @return  目标元素的地址,查找失败返回NULL
 * 
 * @author  jiankang.wang
 * @date    2019-09-29 
 */
int *bsearch_index(int *t,int n,int item)
{
    int lo = 0,hi = n - 1,mid;

    while(lo <= hi)
    {
        mid = (hi + lo) / 2;
        if(item < t[mid])
        {
            hi = mid - 1;
        }
        else if(item > t[mid])
        {
            lo = mid + 1;
        }
        else
        {
            return t + mid;
        }
    }

    return NULL;
}