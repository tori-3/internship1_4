#include "pch.h"
#include"../internship1_4/List.h"
#include"../internship1_4/Grades.h"

///@brief Listの内容が正解と等しいか確認します
///@param ans 正解をvectorとして渡します
///@param list 内容が正しいか調べたいListを渡します
void CheckValue(const std::vector<Grades>& ans, const List<Grades>& list)
{
	EXPECT_TRUE(ans.size() == list.size());

	size_t i = 0;
	for (const auto& grades : list)
	{

		EXPECT_EQ(grades, ans[i]);

		++i;
	}
}

/**********************************************************************************//**
	@brief		要素を持たないリストにソートを実行した時の挙動
	@details	ID:リスト-0\n
				ソート関数のテストです。
				エラー含めて、何も起こらないければ成功です。\n
*//***********************************************************************************/

TEST(TestListSort, Empty)
{
	//scoreで昇順
	{
		List<Grades>list;
		list.sort([](const Grades& left, const Grades& right) {return left.score < right.score; });
		CheckValue({},list);
	}

	//scoreで降順
	{
		List<Grades>list;
		list.sort([](const Grades& left, const Grades& right) {return left.score > right.score; });
		CheckValue({}, list);
	}

	//nameで昇順
	{
		List<Grades>list;
		list.sort([](const Grades& left, const Grades& right) {return left.name < right.name; });
		CheckValue({}, list);
	}

	//nameで降順
	{
		List<Grades>list;
		list.sort([](const Grades& left, const Grades& right) {return left.name > right.name; });
		CheckValue({}, list);
	}

}

/**********************************************************************************//**
	@brief		要素を1つだけ持つリストにソートを実行した時の挙動
	@details	ID:リスト-1\n
				ソート関数のテストです。
				エラー含めて、何も起こらないければ成功です。\n
*//***********************************************************************************/

TEST(TestListSort, OneElement)
{
	//scoreで昇順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort([](const Grades& left, const Grades& right) {return left.score < right.score; });
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//scoreで降順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort([](const Grades& left, const Grades& right) {return left.score > right.score; });
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//nameで昇順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort([](const Grades& left, const Grades& right) {return left.name < right.name; });
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//nameで降順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort([](const Grades& left, const Grades& right) {return left.name > right.name; });
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}
}

/**********************************************************************************//**
	@brief		2つ以上要素を持つリストにソートを実行した時の挙動
	@details	ID:リスト-2\n
				ソート関数のテストです。
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
		list.sort([](const Grades& left, const Grades& right) {return left.score < right.score; });
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//scoreで降順
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.score > right.score; });
		CheckValue({ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//nameで昇順
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.name < right.name; });
		CheckValue({ Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//nameで降順
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.name > right.name; });
		CheckValue({ Grades{ 2,"piyo" } ,Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}
}

/**********************************************************************************//**
	@brief		同じキーを持つ要素があるリストで、そのキーを指定しソートを実行した時の挙動
	@details	ID:リスト-3\n
				ソート関数のテストです。
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
		list.sort([](const Grades& left, const Grades& right) {return left.score < right.score; });
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//scoreで降順
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.score > right.score; });
		CheckValue({ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//nameで昇順
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.name < right.name; });
		CheckValue({ Grades{ 1,"fuga" },Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//nameで降順
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.name > right.name; });
		CheckValue({ Grades{ 2,"piyo" } ,Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 1,"fuga" } }, list);
	}
}

/**********************************************************************************//**
	@brief		整列済みリストにソートを実行した時の挙動
	@details	ID:リスト-4\n
				ソート関数のテストです。
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
		list.sort([](const Grades& left, const Grades& right) {return left.score < right.score; });
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//scoreで降順
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 0,"hoge" });
		list.sort([](const Grades& left, const Grades& right) {return left.score > right.score; });
		CheckValue({ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//nameで昇順
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.sort([](const Grades& left, const Grades& right) {return left.name < right.name; });
		CheckValue({ Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//nameで降順
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.name > right.name; });
		CheckValue({ Grades{ 2,"piyo" } ,Grades{ 0,"hoge" },Grades{ 1,"fuga" } }, list);
	}
}

/**********************************************************************************//**
	@brief		一度整列したリストの各所に挿入し、再度ソートを実行した時の挙動
	@details	ID:リスト-5\n
				ソート関数のテストです。
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
		list.sort([](const Grades& left, const Grades& right) {return left.score < right.score; });

		list.insert(list.begin(), Grades{ 4,"aaaa" });
		auto it = list.begin();++it;++it;
		list.insert(it, Grades{ 5,"cccc" });	
		list.insert(list.end(), Grades{ 3,"bbbb" });

		list.sort([](const Grades& left, const Grades& right) {return left.score < right.score; });
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" },Grades{ 3,"bbbb" },Grades{ 4,"aaaa" },Grades{ 5,"cccc" } }, list);
	}

	//scoreで降順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.score > right.score; });

		list.insert(list.begin(), Grades{ 4,"aaaa" });
		auto it = list.begin(); ++it; ++it;
		list.insert(it, Grades{ 5,"cccc" });
		list.insert(list.end(), Grades{ 3,"bbbb" });

		list.sort([](const Grades& left, const Grades& right) {return left.score > right.score; });
		CheckValue({ Grades{ 5,"cccc" },Grades{ 4,"aaaa" },Grades{ 3,"bbbb" }, Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//nameで昇順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.name < right.name; });

		list.insert(list.begin(), Grades{ 4,"aaaa" });
		auto it = list.begin(); ++it; ++it;
		list.insert(it, Grades{ 5,"cccc" });
		list.insert(list.end(), Grades{ 3,"bbbb" });

		list.sort([](const Grades& left, const Grades& right) {return left.name < right.name; });
		CheckValue({ Grades{ 4,"aaaa" },Grades{ 3,"bbbb" },Grades{ 5,"cccc" },Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//nameで降順
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.name > right.name; });
		list.insert(list.begin(), Grades{ 4,"aaaa" });
		auto it = list.begin(); ++it; ++it;
		list.insert(it, Grades{ 5,"cccc" });
		list.insert(list.end(), Grades{ 3,"bbbb" });
		list.sort([](const Grades& left, const Grades& right) {return left.name > right.name; });
		CheckValue({ Grades{ 2,"piyo" } ,Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 5,"cccc" },Grades{ 3,"bbbb" },Grades{ 4,"aaaa" } }, list);
	}
}


/**********************************************************************************//**
	@brief		キー指定をしなかった(nullptrを渡した)時の挙動
	@details	ID:リスト-6\n
				ソート関数のテストです。
				エラー含めて、何も起こらなければ成功です。\n
*//***********************************************************************************/

TEST(TestListSort, NotSpecifyKey)
{
	List<Grades>list;
	list.add(Grades{ 0,"hoge" });
	list.add(Grades{ 2,"piyo" });
	list.add(Grades{ 1,"fuga" });
	list.sort(nullptr);
	CheckValue({ Grades{ 0,"hoge" },Grades{ 2,"piyo" },Grades{ 1,"fuga" } },list);
}
