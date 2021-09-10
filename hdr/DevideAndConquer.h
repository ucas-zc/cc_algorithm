#ifndef _DEVIDE_AND_CONQUER_H_
#define _DEVIDE_AND_CONQUER_H_

#include "Algorithm.h"

class DevideAndConquer : public Algorithm
{
    public:
        /**
         * @breif 构造函数
         */
        DevideAndConquer();
     
        /**
         * @brief 析构函数
         */
        ~DevideAndConquer();

        /**
         * @brief 归并排序
         *
         * @prame tb 待排列顺序表 && low 低位坐标 && high高位坐标
         *
         * @return AL_OK 成功 && AL_FAIL 失败
         */
        int32_t MergeSort(NS_ALGORITHM::SqList &tb, int32_t low, int32_t high);

        /**
         * @brief 最大子数组问题
         *
         * @prame tb 顺序表 &&cross 最大子数组 && low 低位坐标 && high高位坐标
         *
         * @return AL_OK 成功 && AL_FAIL 失败
         */
        int32_t MaximumSubArray(NS_ALGORITHM::SqList &tb, NS_ALGORITHM::SubArray &cross, 
						int32_t low, int32_t high);

    private:
        /**
         * @brief 合并顺序表
         *
         * @prame tb 待合并列表 && low 最低位坐标 && mid 中间位置坐标 && high 高位坐标
         *
         * @return AL_OK 成功 && AL_FAIL 失败
         */
        int32_t Merge(NS_ALGORITHM::SqList &tb, int32_t low, int32_t mid, int32_t high);

        /**
         * @brief 寻找交叉部分最大子数组
         *
         * @prame tb 顺序表 && cross交叉最大子数组 && low 最低位坐标 
         * @prame mid 中间位置坐标 && high 高位坐标
         *
         * @return AL_OK 成功 && AL_FAIL 失败
         */
        int32_t FindCrossMaxSubArray(NS_ALGORITHM::SqList &tb, NS_ALGORITHM::SubArray &cross, 
						int32_t low, int32_t mid, int32_t high);
};

#endif
