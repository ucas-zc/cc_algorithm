#include "DevideAndConquer.h"
#include "gtest/gtest.h"

namespace 
{
    class TestDevideAndConquer : public testing::Test
    {
        void SetUp() override
        {};

        void TearDown() override
        {};
    };
}

// 分而治之问题测试用例
TEST_F(TestDevideAndConquer, TEST_DEVIDE_AND_CONQUER)
{
    DevideAndConquer d;
    NS_ALGORITHM::SqList tb;

    // 测试归并排序
    tb.table[0] = 3;
    tb.table[1] = 6;
    tb.table[2] = 2;
    tb.table[3] = 5;
    tb.table[4] = 1;
    tb.length = 5;
    ASSERT_EQ(AL_OK, d.MergeSort(tb, 0, 4));
    ASSERT_EQ(1, tb.table[0]);
    ASSERT_EQ(2, tb.table[1]);
    ASSERT_EQ(3, tb.table[2]);
    ASSERT_EQ(5, tb.table[3]);
    ASSERT_EQ(6, tb.table[4]);

    // 测试最大子数组问题
    tb.table[0] = 13;
    tb.table[1] = -3;
    tb.table[2] = -25;
    tb.table[3] = 20;
    tb.table[4] = -9;
    tb.table[5] = -3;
    tb.table[6] = 3;
    tb.table[7] = -10;
    tb.table[8] = 20;
    tb.table[9] = -7;
    tb.length = 10;
    NS_ALGORITHM::SubArray cross;
    ASSERT_EQ(AL_OK, d.MaximumSubArray(tb, cross, 0, 9));
    ASSERT_EQ(21, cross.sum);
    ASSERT_EQ(3, cross.left);
    ASSERT_EQ(8, cross.right);
}
