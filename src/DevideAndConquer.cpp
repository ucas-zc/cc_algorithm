#include "DevideAndConquer.h"

/** 构造函数 **/
DevideAndConquer::DevideAndConquer()
{}

/** 析构函数 **/
DevideAndConquer::~DevideAndConquer()
{}

/** 归并排序 **/
int32_t DevideAndConquer::MergeSort(NS_ALGORITHM::SqList &tb, 
				int32_t low, int32_t high)
{
    // 低位坐标低于高位坐标，返回失败 
    if (low >= high)
    {
        return AL_FAIL;
    }

    // 计算中间位置坐标
    int32_t mid = (low + high) / 2;
    // 归并前半部分
    MergeSort(tb, low, mid);
    // 归并后半部分
    MergeSort(tb, mid + 1, high);
    // 合并顺序表
    Merge(tb, low, mid, high);

    return AL_OK;
}

int32_t DevideAndConquer::Merge(NS_ALGORITHM::SqList &tb,
				int32_t low, int32_t mid, int32_t high)
{
    // 低位坐标低于高位坐标，返回失败 
    if (low > high || low > mid || mid > high)
    {
        return AL_FAIL;
    }

    // 设置前向指针与后向指针
    int32_t prev = low;
    int32_t back = mid + 1;
    // 临时表
    int32_t index = 0;
    int32_t tmp[MAX_SIZE];

    // 合并
    while (prev <= mid && back <= high && index < MAX_SIZE)
    {
        if (tb.table[prev] < tb.table[back])
        {
            tmp[index++] = tb.table[prev++];
        }
        else
        {
            tmp[index++] = tb.table[back++];
        }
    }

    // 合并前半部分剩余数据
    while (prev <= mid && index < MAX_SIZE)
    {
        tmp[index++] = tb.table[prev++];
    }

    // 合并后半部分剩余数据
    while (back <= high && index < MAX_SIZE)
    {
        tmp[index++] = tb.table[back++];
    }

    // 将临时表内数据拷贝到目标顺序表内
    index = low;
    while (index <= high)
    {
        tb.table[index] = tmp[index - low];
        ++index;
    }

    return AL_OK;
}

/** 最大子数组问题 **/
int32_t DevideAndConquer::MaximumSubArray(NS_ALGORITHM::SqList &tb,
				NS_ALGORITHM::SubArray &cross, int32_t low, int32_t high)
{
    // 高低位坐标异常，返回失败
    if (low > high)
    {
        return AL_FAIL;
    }
    else if (low == high)
    {
        cross.left = low;
        cross.right = high;
        cross.sum = tb.table[low];
        return AL_OK;
    }

    // 定义局部变量（左半部分最大子数组、右半部分最大子数组）
    NS_ALGORITHM::SubArray LeftMax;
    NS_ALGORITHM::SubArray RightMax;
    // 计算中点坐标
    int32_t mid = (low + high) / 2;

    // 寻找左半部分最大子数组
    MaximumSubArray(tb, LeftMax, low, mid);
    // 寻找右半部分最大子数组
    MaximumSubArray(tb, RightMax, mid + 1, high);
    // 寻找交叉部分最大子数组
    FindCrossMaxSubArray(tb, cross, low, mid, high);

    // 左半部分最大子数组最大，更新为全局最大子数组
    if (LeftMax.sum >= cross.sum && RightMax.sum >= cross.sum)
    {
        cross.sum = LeftMax.sum;
        cross.left = LeftMax.left;
        cross.right = LeftMax.right;
    }
    // 右半部分最大子数组最大，更新为全局最大子数组
    else if (RightMax.sum >= LeftMax.sum && RightMax.sum >= cross.sum)
    {
        cross.sum = RightMax.sum;
        cross.left = RightMax.left;
        cross.right = RightMax.right;
    }

    return AL_OK;
}

/** 寻求局部最大子数组 **/
int32_t DevideAndConquer::FindCrossMaxSubArray(NS_ALGORITHM::SqList &tb,
				NS_ALGORITHM::SubArray &cross, int32_t low, 
				int32_t mid, int32_t high)
{
    // 坐标异常判断
    if (low > mid || low > high || mid > high)
    {
        return AL_FAIL;
    }

    // 定义局部变量（求和变量、左半部分最大和）
    // 定义局部变量（右半部分最大和、数组访问游标）
    int32_t sum = 0;
    int32_t LeftSum = INT32_MIN;
    int32_t RightSum = INT32_MIN;
    int32_t index = mid;

    // 求左半部分最大子数组信息
    for (; index >= low; --index)
    {
        sum += tb.table[index];
        if (sum > LeftSum)
        {
            LeftSum = sum;
            cross.left = index;
        }
    }

    // 更新局部变量
    sum = 0;
    index = mid + 1;

    // 求右半部分最大子数组信息
    for (; index <= high; ++index)
    {
        sum += tb.table[index];
        if (sum > RightSum)
        {
            RightSum = sum;
            cross.right = index;
        }
    }

    // 更新交叉部分最大子数组和
    cross.sum = LeftSum + RightSum;

    return AL_OK;
}
