#include "utmatrix.h"

#include <gtest.h>


#define SIZE 10

TEST(TVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, throws_when_create_vector_with_negative_startindex)
{
  ASSERT_ANY_THROW(TVector<int> v(5, -2));
}

TEST(TVector, can_create_copied_vector)
{
  TVector<int> v(10);

  ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
  TVector <int> v1(SIZE);
	for (int i = 0; i < SIZE; i++)
		v1[i] = i;     
	TVector <int> v2(v1);
	EXPECT_EQ(SIZE, v2.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i, v2[i]);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
  TVector<int> v(5);  
   int k = 10;
   for (int i = 0; i < 5; i++)
   {
 	  v[i] = k;  
 	  k = k + 10;
   }
   // 10 20 30 40 50
   TVector<int> b(v); 
   b[3] = 1;
   //10 20 30 1 50
   EXPECT_NE(b, v);  
}

TEST(TVector, can_get_SIZE)
{
  TVector<int> v(4);

  EXPECT_EQ(4, v.GetSize());
}

TEST(TVector, can_get_start_index)
{
  TVector<int> v(4, 2);

  EXPECT_EQ(2, v.GetStartIndex());
}

TEST(TVector, can_set_and_get_element)
{
  TVector<int> v(4);
  v[0] = 4;

  EXPECT_EQ(4, v[0]);
}

TEST(TVector, throws_when_set_element_with_negative_index)
{
	TVector<int> v(4);


  ASSERT_ANY_THROW(v[-3]);
}

TEST(TVector, throws_when_set_element_with_too_large_index)
{
 TVector<int> v(SIZE);

  ASSERT_ANY_THROW(v[SIZE+1]);
}

TEST(TVector, can_assign_vector_to_itself)
{
  TVector<int> v(4); 
   TVector<int> v1(4); 
   int k = 5;
   for (int i = 0; i < 4; i++)
   {
 	  v[i] = k;  
 	  k = k + 5;
   }
   int m = 5;
   for (int i = 0; i < 4; i++)
   {
 	  v1[i] = m;  
 	  m = m + 5;
   }
   v = v;
   EXPECT_EQ(v, v1); 
}

TEST(TVector, can_assign_vectors_of_equal_SIZE)
{
  TVector<int> v1(SIZE),v2(SIZE);

  v1.GetSize();

  v2=v1;

  EXPECT_EQ(v1.GetSize(),v2.GetSize());

}

TEST(TVector, assign_operator_change_vector_SIZE)
{
 TVector<int> v1(3);
	TVector<int> v2(5);
	for (int i=0; i<3; i++)
	{
		v1[i]=i;
	}

	v2=v1;

	EXPECT_EQ(5, v1.GetSize());

}

TEST(TVector, can_assign_vectors_of_different_SIZE)
{
	TVector<int> v1(3),v2(5);
   for (int i=0; i < 3 ; i++ )
   v1[i]=i;

   for (int i=0; i < 5 ; i++ )
   v2[i]=i+8;

   ASSERT_NO_THROW(v1 = v2);
	EXPECT_EQ(5, v1.GetSize());
	for (int i = 0; i < 3; i++)
		EXPECT_EQ(i+8, v1[i]);
  

}

TEST(TVector, compare_equal_vectors_return_true)
{
 /* TVector<int> v1(SIZE), v2(SIZE);
	for (int i = 0; i < SIZE; i++) {
		v1[i] = i;
		v2[i] = i;
	}
	*/

TVector<int> v1(5), v2(10);
   int k = 5;
   for (int i = 0; i < 10; i++)
   {
 	  v2[i] = k;  
 	  k = k + 5;
   }
   v1 = v2;
   EXPECT_EQ(true, v1 == v2);  
}

TEST(TVector, compare_vector_with_itself_return_true)
{
  TVector<int> v(SIZE);
	for (int i = 0; i < SIZE; i++)
		v[i] = i;
	EXPECT_EQ(true, v == v);
}

TEST(TVector, vectors_with_different_SIZE_are_not_equal)
{
 TVector<int> v1(3);
	TVector<int> v2(5);
	for (int i = 0; i < 3; i++)
		v1[i] = i;
	for (int i = 0; i < 5; i++)
		v2[i] = i;
	EXPECT_TRUE(v2 != v1);
}

TEST(TVector, can_add_scalar_to_vector)
{
  
TVector<int> v1(SIZE);
	for (int i = 0; i < SIZE; i++)
		v1[i] = i;
	TVector<int> v2(v1);
	ASSERT_NO_THROW(v1 + 8);
	v2 = v1 + 42;
	EXPECT_EQ(SIZE, v2.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i + 8, v2[i]);

}

TEST(TVector, can_subtract_scalar_from_vector)
{
  TVector<int> v1(SIZE);
	for (int i = 0; i < SIZE; i++)
		v1[i] = i;
	TVector<int> v2(v1);
	ASSERT_NO_THROW(v1 - 8);
	v2 = v1 - 42;
	EXPECT_EQ(SIZE, v2.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i - 8, v2[i]);
}

TEST(TVector, can_multiply_scalar_by_vector)
{
 TVector<int> v1(SIZE);
	for (int i = 0; i < SIZE; i++)
		v1[i] = i;
	TVector<int> v2(v1);
	ASSERT_NO_THROW(v1 * 8);
	v2 = v1 * 42;
	EXPECT_EQ(SIZE, v2.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i * 8, v2[i]);
}

TEST(TVector, can_add_vectors_with_equal_SIZE)
{
  TVector<int> v1(SIZE), v2(SIZE), v3(SIZE);
	for (int i = 0; i < SIZE; i++)
		v1[i] = i;
	for (int i = 0; i < SIZE; i++)
		v2[i] = 8 * i;
	ASSERT_NO_THROW(v1 + v2);
	v3 = v1 + v2;
	EXPECT_EQ(SIZE, v3.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(8 * i + i, v3[i]);
}

TEST(TVector, cant_add_vectors_with_not_equal_SIZE)
{
  TVector<int> v1(3), v2(5);
	for (int i = 0; i < 3; i++)
		v1[i] = i;
	for (int i = 0; i < 5; i++)
		v2[i] = i;
	ASSERT_ANY_THROW(v1 + v2);
}

TEST(TVector, can_subtract_vectors_with_equal_SIZE)
{
	TVector<int> v1(SIZE), v2(SIZE), v3(SIZE);
	for (int i = 0; i < SIZE; i++)
		v1[i] = i;
	for (int i = 0; i < SIZE; i++)
		v2[i] = 8 * i;
	ASSERT_NO_THROW(v1 - v2);
	v3 = v1 - v2;
	EXPECT_EQ(SIZE, v3.GetSize());
	for (int i = 0; i < SIZE; i++)
		EXPECT_EQ(i - 8 * i, v3[i]);
}

TEST(TVector, cant_subtract_vectors_with_not_equal_SIZE)
{
	TVector<int> v1(3), v2(5);
	for (int i = 0; i < 3; i++)
		v1[i] = i;
	for (int i = 0; i < 5; i++)
		v2[i] = i;
	ASSERT_ANY_THROW(v1 - v2);
}

TEST(TVector, can_multiply_vectors_with_equal_SIZE)
{
	TVector<int> v1(SIZE), v2(SIZE);
	int k = 0;
	int Sum = 0;
	for (int i = 0; i < SIZE; i++) { 
		v1[i] = i;
		v2[i] = i;
		Sum += i * i;
	}
	ASSERT_NO_THROW(v1 * v2);
	k = v1 * v2;
	EXPECT_EQ(Sum, k);
}

TEST(TVector, cant_multiply_vectors_with_not_equal_SIZE)
{
	TVector<int> v1(3), v2(5);
	for (int i = 0; i < 3; i++)
		v1[i] = i;
	for (int i = 0; i < 5; i++)
		v2[i] = i;
	ASSERT_ANY_THROW(v1 * v2);
}
