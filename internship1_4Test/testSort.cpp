#include "pch.h"
#include"CheckValue.h"
#include"../internship1_4/List.h"
#include"../internship1_4/Grades.h"

///@brief scoreで昇順に並べるための比較関数です。
///@param left 左側のデータ
///@param right 右側のデータ
bool AscendingOrderScore(const Grades& left, const Grades& right)
{
	return left.score < right.score;
};

///@brief scoreで降順に並べるための比較関数です。
///@param left 左側のデータ
///@param right 右側のデータ
bool DescendingOrderScore(const Grades& left, const Grades& right)
{
	return left.score > right.score;
};

///@brief nameで昇順に並べるための比較関数です。
///@param left 左側のデータ
///@param right 右側のデータ
bool AscendingOrderName(const Grades& left, const Grades& right)
{
	return left.name < right.name;
};

///@brief nameで降順に並べるための比較関数です。
///@param left 左側のデータ
///@param right 右側のデータ
bool DescendingOrderName(const Grades& left, const Grades& right)
{
	return left.name > right.name;
};

/**********************************************************************************//**
	@brief		クイックソート 要素を持たないリストにソートを実行した時の挙動
	@details	ID:リスト-0\n
				クイックソートのテストです。
				エラー含めて、何も起こらないければ成功です。\n
*//***********************************************************************************/

TEST(TestListSort, Empty)
{
	//scoreで昇順
	{
		List<Grades>list;
		list.sort(AscendingOrderScore);
		CheckValue({}, list);
	}

	//scoreで降順
	{
		List<Grades>list;
		list.sort(DescendingOrderScore);
		CheckValue({}, list);
	}

	//nameで昇順
	{
		List<Grades>list;
		list.sort(AscendingOrderName);
		CheckValue({}, list);
	}

	//nameで降順
	{
		List<Grades>list;
		list.sort(DescendingOrderName);
		CheckValue({}, list);
	}

}

/**********************************************************************************//**
	@brief		クイックソート 要素を1つだけ持つリストにソートを実行した時の挙動
	@details	ID:リスト-1\n
				クイックソートのテストです。
				エラー含めて、何も起こらないければ成功です。\n
*//***********************************************************************************/

TEST(TestListSort, OneElement)
{
	//scoreで昇順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort(AscendingOrderScore);
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//scoreで降順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort(DescendingOrderScore);
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//nameで昇順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort(AscendingOrderName);
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//nameで降順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort(DescendingOrderName);
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}
}

/**********************************************************************************//**
	@brief		クイックソート 2つ以上要素を持つリストにソートを実行した時の挙動
	@details	ID:リスト-2\n
				クイックソートのテストです。
				要素が指定したキーに準じて指定した順に並べば成功です。\n
*//***********************************************************************************/

TEST(TestListSort, MultipleElements)
{
	//scoreで昇順
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(AscendingOrderScore);
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//scoreで降順
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderScore);
		CheckValue({ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//nameで昇順
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(AscendingOrderName);
		CheckValue({ Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//nameで降順
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderName);
		CheckValue({ Grades{ 2,"piyo" } ,Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}
}

/**********************************************************************************//**
	@brief		クイックソート 同じキーを持つ要素があるリストで、そのキーを指定しソートを実行した時の挙動
	@details	ID:リスト-3\n
				クイックソートのテストです。
				要素がソートされて並べば成功です。(同じ要素の順序は保証されない。)\n
*//***********************************************************************************/

TEST(TestListSort, ContainsSameKey)
{
	//scoreで昇順
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(AscendingOrderScore);
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//scoreで降順
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderScore);
		CheckValue({ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//nameで昇順
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(AscendingOrderName);
		CheckValue({ Grades{ 1,"fuga" },Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//nameで降順
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderName);
		CheckValue({ Grades{ 2,"piyo" } ,Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 1,"fuga" } }, list);
	}
}

/**********************************************************************************//**
	@brief		クイックソート 整列済みリストにソートを実行した時の挙動
	@details	ID:リスト-4\n
				クイックソートのテストです。
				同じキーの要素の間以外の順番が変動しなければ成功です。\n
*//***********************************************************************************/

TEST(TestListSort, AlignedList)
{
	//scoreで昇順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.sort(AscendingOrderScore);
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//scoreで降順
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 0,"hoge" });
		list.sort(DescendingOrderScore);
		CheckValue({ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//nameで昇順
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.sort(AscendingOrderName);
		CheckValue({ Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//nameで降順
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderName);
		CheckValue({ Grades{ 2,"piyo" } ,Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}
}

/**********************************************************************************//**
	@brief		クイックソート 一度整列したリストの各所に挿入し、再度ソートを実行した時の挙動
	@details	ID:リスト-5\n
				クイックソートのテストです。
				要素がソートされて並べば成功です。\n
*//***********************************************************************************/

TEST(TestListSort, SortedList)
{
	//scoreで昇順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.sort(AscendingOrderScore);

		list.insert(list.begin(), Grades{ 4,"aaaa" });
		auto it = list.begin(); ++it; ++it;
		list.insert(it, Grades{ 5,"cccc" });
		list.insert(list.end(), Grades{ 3,"bbbb" });

		list.sort(AscendingOrderScore);
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" },Grades{ 3,"bbbb" },Grades{ 4,"aaaa" },Grades{ 5,"cccc" } }, list);
	}

	//scoreで降順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderScore);

		list.insert(list.begin(), Grades{ 4,"aaaa" });
		auto it = list.begin(); ++it; ++it;
		list.insert(it, Grades{ 5,"cccc" });
		list.insert(list.end(), Grades{ 3,"bbbb" });

		list.sort(DescendingOrderScore);
		CheckValue({ Grades{ 5,"cccc" },Grades{ 4,"aaaa" },Grades{ 3,"bbbb" }, Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//nameで昇順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.sort(AscendingOrderName);

		list.insert(list.begin(), Grades{ 4,"aaaa" });
		auto it = list.begin(); ++it; ++it;
		list.insert(it, Grades{ 5,"cccc" });
		list.insert(list.end(), Grades{ 3,"bbbb" });

		list.sort(AscendingOrderName);
		CheckValue({ Grades{ 4,"aaaa" },Grades{ 3,"bbbb" },Grades{ 5,"cccc" },Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//nameで降順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.sort(DescendingOrderName);
		list.insert(list.begin(), Grades{ 4,"aaaa" });
		auto it = list.begin(); ++it; ++it;
		list.insert(it, Grades{ 5,"cccc" });
		list.insert(list.end(), Grades{ 3,"bbbb" });
		list.sort(DescendingOrderName);
		CheckValue({ Grades{ 2,"piyo" } ,Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 5,"cccc" },Grades{ 3,"bbbb" },Grades{ 4,"aaaa" } }, list);
	}
}


/**********************************************************************************//**
	@brief		クイックソート キー指定をしなかった(nullptrを渡した)時の挙動
	@details	ID:リスト-6\n
				クイックソートのテストです。
				エラー含めて、何も起こらなければ成功です。\n
*//***********************************************************************************/

TEST(TestListSort, NotSpecifyKey)
{
	List<Grades>list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 2,"piyo" });
	list.add(Grades{ 1,"fuga" });
	list.sort(nullptr);
	CheckValue({ Grades{ 0,"hoge" },Grades{ 2,"piyo" },Grades{ 1,"fuga" } }, list);
}
