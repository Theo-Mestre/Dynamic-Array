#include "pch.h"
#include "DynamicArray.h"

TEST(DynamicArrayTest, DefaultConstructorTest) {
	DynamicArray<int> arr;
	EXPECT_EQ(arr.Size(), 0);
}

TEST(DynamicArrayTest, ConstructorWithInitialCapacityTest) {
	DynamicArray<int> arr(10);
	EXPECT_EQ(arr.Size(), 0);
	EXPECT_EQ(arr.Capacity(), 10);
}

TEST(DynamicArrayTest, CopyConstructorTest) {
	DynamicArray<int> arr;
	arr.PushBack(1);
	arr.PushBack(2);
	arr.PushBack(3);
	DynamicArray<int> arr2(arr);
	EXPECT_EQ(arr2.Size(), 3);
	EXPECT_EQ(arr2[0], 1);
	EXPECT_EQ(arr2[1], 2);
	EXPECT_EQ(arr2[2], 3);
}

TEST(DynamicArrayTest, PushBackTest) {
    DynamicArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}

TEST(DynamicArrayTest, PopBackTest) {
    DynamicArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    arr.PopBack();
    EXPECT_EQ(arr.Size(), 2);
}

TEST(DynamicArrayTest, ClearTest) {
    DynamicArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    arr.Clear();
    EXPECT_EQ(arr.Size(), 0);
}

TEST(DynamicArrayTest, ReserveTest) {
    DynamicArray<int> arr;
    arr.Reserve(100);
    EXPECT_GE(arr.Size(), 100);
}

TEST(DynamicArrayTest, RemoveAtTest) {
    DynamicArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    arr.RemoveAt(1);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 3);
}

TEST(DynamicArrayTest, ShrinkToFitTest) {
    DynamicArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    arr.ShrinkToFit();
    EXPECT_EQ(arr.Size(), 3);
}

TEST(DynamicArrayTest, OperatorTest) {
    DynamicArray<int> arr;
    arr.PushBack(1);
    arr.PushBack(2);
    arr.PushBack(3);
    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
}

#include "VectorTest.h"

TEST(DynamicArrayTest, PushBackVecTest) {
    DynamicArray<Vector2> arr;
    arr.PushBack(Vector2(1.0f, 2.0f));
    arr.PushBack(Vector2(3.0f, 4.0f));
    arr.PushBack(Vector2(5.0f, 6.0f));
    EXPECT_EQ(arr[0], Vector2(1.0f, 2.0f));
    EXPECT_EQ(arr[1], Vector2(3.0f, 4.0f));
    EXPECT_EQ(arr[2], Vector2(5.0f, 6.0f));
}

TEST(DynamicArrayTest, PopBackVecTest) {
    DynamicArray<Vector2> arr;
    arr.PushBack(Vector2(1.0f, 2.0f));
    arr.PushBack(Vector2(3.0f, 4.0f));
    arr.PushBack(Vector2(5.0f, 6.0f));
    arr.PopBack();
    EXPECT_EQ(arr.Size(), 2);
}

TEST(DynamicArrayTest, ClearVecTest) {
    DynamicArray<Vector2> arr;
    arr.PushBack(Vector2(1.0f, 2.0f));
    arr.PushBack(Vector2(3.0f, 4.0f));
    arr.PushBack(Vector2(5.0f, 6.0f));
    arr.Clear();
    EXPECT_EQ(arr.Size(), 0);
}

TEST(DynamicArrayTest, ReserveVecTest) {
    DynamicArray<Vector2> arr;
    arr.Reserve(100);
    EXPECT_GE(arr.Capacity(), 100);
}

TEST(DynamicArrayTest, RemoveAtVecTest) {
    DynamicArray<Vector2> arr;
    arr.PushBack(Vector2(1.0f, 2.0f));
    arr.PushBack(Vector2(3.0f, 4.0f));
    arr.PushBack(Vector2(5.0f, 6.0f));
    arr.RemoveAt(1);
    EXPECT_EQ(arr[0], Vector2(1.0f, 2.0f));
    EXPECT_EQ(arr[1], Vector2(5.0f, 6.0f));
}

TEST(DynamicArrayTest, ShrinkToFitVecTest) {
    DynamicArray<Vector2> arr;
    arr.PushBack(Vector2(1.0f, 2.0f));
    arr.PushBack(Vector2(3.0f, 4.0f));
    arr.PushBack(Vector2(5.0f, 6.0f));
    arr.ShrinkToFit();
    EXPECT_EQ(arr.Capacity(), 3);
}

TEST(DynamicArrayTest, OperatorVecTest) {
    DynamicArray<Vector2> arr;
    arr.PushBack(Vector2(1.0f, 2.0f));
    arr.PushBack(Vector2(3.0f, 4.0f));
    arr.PushBack(Vector2(5.0f, 6.0f));
    EXPECT_EQ(arr[0], Vector2(1.0f, 2.0f));
    EXPECT_EQ(arr[1], Vector2(3.0f, 4.0f));
    EXPECT_EQ(arr[2], Vector2(5.0f, 6.0f));
}