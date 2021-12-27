#include <iostream>
#include <string>
#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

#define lenth(array) sizeof(array) / sizeof(array[0])

void BubbleSort(int bubble_arr[]);
void CountSort(int count_arr[]);
void QuickSort(int quick_arr[]);

//待排序的数组
int array_to_sort[] = {1, 9, 4, 2, 8, 23, 44, 11, 16, 34, 34, 77, 84, 38, 94, 57, 68, 32, 3, 7, 86, 12, 33, 64, 23, 87, 52, 100, 0, -1};
//数组长度
int arr_lenth = lenth(array_to_sort);

int main()
{

    int bubble_array[30];
    int count_array[30];
    int quick_array[30];

    //拷贝三组待排序的数列，用于做三个排序的输入
    memcpy(bubble_array, array_to_sort, sizeof(array_to_sort));
    memcpy(count_array, array_to_sort, sizeof(array_to_sort));
    memcpy(quick_array, array_to_sort, sizeof(array_to_sort));

    //先输出待排序的数列，即数组array_to_sort[]
    cout << "待排序的数列："
         << " ";
    for (int i = 0; i < 30; i++)
    {
        cout << array_to_sort[i] << " "; //TODO
    }
    cout << endl
         << endl;

    //输出三种排序的结果
    BubbleSort(bubble_array);
    CountSort(count_array);
    QuickSort(quick_array);

    return 0;
}

//*************************************************************
//冒泡排序，时间复杂度为n^2

void BubbleSort(int bubble_arr[])
{
    int tmp;
    int bub_lenth = arr_lenth;
    for (int i = 0; i < bub_lenth - 1; i++)
    {
        for (int j = 0; j < bub_lenth - 1 - i; j++)
        {
            if (bubble_arr[j] > bubble_arr[j + 1])
            {
                tmp = bubble_arr[j + 1];
                bubble_arr[j + 1] = bubble_arr[j];
                bubble_arr[j] = tmp;
            }
        }
    }

    //输出排序完毕的数组
    cout << "冒泡排序："
         << " ";
    for (int k = 0; k < bub_lenth; k++)
    {
        cout << bubble_arr[k] << " "; //TODO
    }
    cout << endl
         << endl;
}

//*************************************************************
//计数排序,时间复杂度为n
void CountSort(int count_arr[])
{

    int max_value = count_arr[0];
    int count_lenth = arr_lenth;

    //找寻数组中最大的元素，以最大的元素作为下标
    for (int i = 0; i < count_lenth; i++)
    {
        if (count_arr[i] > max_value)
        {
            max_value = count_arr[i];
        }
    }

    //创建一个长度为max_value+1的数组存储计数，并初始化为0
    int *count = (int *)malloc(sizeof(int) * (max_value + 1));
    memset(count, 0, sizeof(int) * (max_value + 1));

    //对待排序的数列进行计数
    for (int j = 0; j < count_lenth; j++)
    {
        count[count_arr[j]]++;
    }

    //统计计数的累计值
    for (int k = 0; k < max_value + 1; k++)
    {
        count[k] += count[k - 1];
    }

    //设立一个输出的数组
    int cnt[count_lenth];

    //将计数完毕元素放到正确的位置上
    for (int n = 0; n < count_lenth; n++)
    {
        cnt[count[count_arr[n]] - 1] = count_arr[n];
        count[count_arr[n]]--;
    }

    //输出排序完毕的数组
    cout << "计数排序："
         << " ";
    for (int m = 0; m < count_lenth; m++)
    {
        cout << cnt[m] << " "; //TODO
    }
    cout << endl
         << endl;
}

//***************************************************************
//快速排序，时间复杂度为nlogn

// 用于交换数组的值
void swap(int *x1, int *x2)
{
    int tmp;
    tmp = *x1;
    *x1 = *x2;
    *x2 = tmp;
}

int PointJudge(int arr[], int left, int right)
{
    int flag_point = arr[right];
    int i = left;

    for (int j = left; j < right; j++)
    {
        // 比flag_point小的，全部换到前面去
        if (arr[j] < flag_point)
            swap(&arr[j], &arr[i++]);
    }
    // 此时，i指向的元素一定大于等于flag_point
    swap(&arr[right], &arr[i]);
    return i;
}

//分冶治之，递归划分
void QSort(int quick_arr[], int left, int right)
{
    if (left < right)
    {
        int mid = PointJudge(quick_arr, left, right);
        QSort(quick_arr, left, mid - 1);
        QSort(quick_arr, mid + 1, right);
    }
}

void QuickSort(int quick_arr[])
{
    QSort(quick_arr, 0, arr_lenth - 1);

    //输出排序完毕的数组
    cout << "快速排序："
         << " ";
    for (int i = 0; i < arr_lenth; i++)
    {
        cout << quick_arr[i] << " "; //TODO
    }
    cout << endl
         << endl;
}