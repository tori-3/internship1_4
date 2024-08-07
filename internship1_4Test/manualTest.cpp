#include "pch.h"
#include"../internship1_4/List.h"
#include"../internship1_4/Grades.h"
#include"manualTest.h"

/**********************************************************************************//**
	@brief		ソート関数に型などが不適切なキー指定が引数で渡された時の挙動
	@details	ID:リスト-7(手動)\n
				ソート関数のテストです。
				有効にしてコンパイルエラーになれば成功です。\n
				TEST_LIST_SORT_INVALID_KEYマクロを定義すると有効になります。\n
*//***********************************************************************************/

TEST(TestListSort, InvalidKey) 
{
#ifdef TEST_LIST_SORT_INVALID_KEY

	List<Grades>list;
	list.sort([](int left, int right) {return left < right; });

#endif
}

/**********************************************************************************//**
	@brief		ソート関数が非constのメソッドであるか
	@details	ID:リスト-8(手動)\n
				ソート関数のテストです。
				有効にしてコンパイルエラーになれば成功です。\n
				TEST_LIST_SORT_IS_NOT_CONSTマクロを定義すると有効になります。\n
*//***********************************************************************************/

TEST(TestListSort, IsNotConst) 
{
#ifdef TEST_LIST_SORT_IS_NOT_CONST

	const List<Grades>list;
	list.sort();

#endif
}
