/**
 *  快速排序
 *  中心思想:
 *  假定以数组第一个元素为中间值
 *  将数组中比中间值小的放在中间值左边,大的放在右边
 *  将分组后的部分作为整体进行递归操作 
 */
#include <stdio.h>

void quicksort(int *arr,int start,int end);
int partation(int *arr,int start,int end);
void show(const int * arr,const int size);

int main()
{
    int arr[5] = {3,1,2,5,4};

    show(arr,5);

    quicksort(arr,0,5);

    show(arr,5);
}

void quicksort(int *arr,int start,int end)
{
    if(end - start < 2)
    {
        return ;
    }
    else
    {
        int midIndex = partation(arr,start,end);
        quicksort(arr,start,midIndex);
        quicksort(arr,midIndex + 1,end);
    }
    
}

/**
 * @param arr   数组指针
 * @param start 当前排序起始下标
 * @param end   当前排序范围结束下边(非超尾)
 * 
 * @return rightIndex   中间值索引
 */
int partation(int *arr,int start,int end)
{
    int leftIndex = start;
    int rightIndex = end - 1;
    int leftValue;
    int rightValue;
    int midValue = arr[start];
    int tmp = 0;

    while(leftIndex < rightIndex)
    {
        leftValue = arr[leftIndex];
        rightValue = arr[rightIndex];

        //找出比中间值小的元素
        while(rightValue >= midValue && rightIndex > leftIndex)
        {
            rightIndex--;
            rightValue = arr[rightIndex];
        }
        //找出比中间值大的元素
        while(leftValue <= midValue && leftIndex < rightIndex)
        {
            leftIndex++;
            leftValue = arr[leftIndex];
        }

        //交换比中间值大的和比中间值小的值
        tmp = arr[leftIndex];
        arr[leftIndex] = arr[rightIndex];
        arr[rightIndex] = tmp;
    }

    //将中间中交换到小值末尾
    tmp = arr[start];
    arr[start] = arr[rightIndex];
    arr[rightIndex] = tmp;

    show(arr,5);

    return rightIndex;
}

void show(const int * arr,const int size)
{
    int i;

    for(i = 0;i < size;i++)
    {
        printf("%d\t",arr[i]);
    }

    printf("\n");
}