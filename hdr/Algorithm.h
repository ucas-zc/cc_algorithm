#ifndef _ALGORITHM_H_
#define _ALGORITHM_H_

#include <iostream>
#include <cstdint>

// 顺序表大小
#define MAX_SIZE 128

// 函数返回值
#define AL_OK 0
#define AL_FAIL -1

namespace NS_ALGORITHM
{
    // 子数组结构
    class SubArray
    {
        public:
            /**
             * @brief 构造函数
             */
            SubArray() 
            {
                left = 0;
                right = 0;
                sum = 0;
            }
  
            /**
             * @brief 析构函数
             */
            ~SubArray() 
            {
                left = 0;
                right = 0;
                sum = 0;
            }

        public:
			/**
			 * @brief 左坐标
			 */
            int32_t left;

			/**
			 * @brief 右坐标
			 */
            int32_t right;

			/**
			 * @brief 和
			 */
            int32_t sum;
    };

    // 顺序表结构
    class SqList
    {
        public:
            /**
             * @brief 构造函数
             */
            SqList() 
            {
                int32_t index = 0;
                for (; index < MAX_SIZE; ++index)
                {
                    table[index] = 0;
                }

                length = 0;
            }
  
            /**
             * @brief 析构函数
             */
            ~SqList() 
            {
                int32_t index = 0;
                for (; index < MAX_SIZE; ++index)
                {
                    table[index] = 0;
                }

                length = 0;
            }

        public:
            /**
             * @brief 顺序表
             */
            int32_t table[MAX_SIZE];

            /**
             * @brief 表长度
             */
            int32_t length;
    };
}


/* 该类为算法结构的基类 */
class Algorithm
{
    public:
        /**
         * @brief 构造函数
         */
        Algorithm() {}
  
        /**
         * @brief 析构函数
         */
        virtual ~Algorithm() {}
};

#endif 
