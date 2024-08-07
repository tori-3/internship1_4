#include "pch.h"
#include"../internship1_4/List.h"
#include"../internship1_4/Grades.h"

///@brief List�̓��e�������Ɠ��������m�F���܂�
///@param ans ������vector�Ƃ��ēn���܂�
///@param list ���e�������������ׂ���List��n���܂�
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
	@brief		�v�f�������Ȃ����X�g�Ƀ\�[�g�����s�������̋���
	@details	ID:���X�g-0\n
				�\�[�g�֐��̃e�X�g�ł��B
				�G���[�܂߂āA�����N����Ȃ�����ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestListSort, Empty)
{
	//score�ŏ���
	{
		List<Grades>list;
		list.sort([](const Grades& left, const Grades& right) {return left.score < right.score; });
		CheckValue({},list);
	}

	//score�ō~��
	{
		List<Grades>list;
		list.sort([](const Grades& left, const Grades& right) {return left.score > right.score; });
		CheckValue({}, list);
	}

	//name�ŏ���
	{
		List<Grades>list;
		list.sort([](const Grades& left, const Grades& right) {return left.name < right.name; });
		CheckValue({}, list);
	}

	//name�ō~��
	{
		List<Grades>list;
		list.sort([](const Grades& left, const Grades& right) {return left.name > right.name; });
		CheckValue({}, list);
	}

}

/**********************************************************************************//**
	@brief		�v�f��1���������X�g�Ƀ\�[�g�����s�������̋���
	@details	ID:���X�g-1\n
				�\�[�g�֐��̃e�X�g�ł��B
				�G���[�܂߂āA�����N����Ȃ�����ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestListSort, OneElement)
{
	//score�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort([](const Grades& left, const Grades& right) {return left.score < right.score; });
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//score�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort([](const Grades& left, const Grades& right) {return left.score > right.score; });
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//name�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort([](const Grades& left, const Grades& right) {return left.name < right.name; });
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}

	//name�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.sort([](const Grades& left, const Grades& right) {return left.name > right.name; });
		CheckValue({ Grades{ 0,"hoge" } }, list);
	}
}

/**********************************************************************************//**
	@brief		2�ȏ�v�f�������X�g�Ƀ\�[�g�����s�������̋���
	@details	ID:���X�g-2\n
				�\�[�g�֐��̃e�X�g�ł��B
				�v�f���w�肵���L�[�ɏ����Ďw�肵�����ɕ��ׂΐ����ł��B\n
*//***********************************************************************************/

TEST(TestListSort, MultipleElements)
{	
	//score�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.score < right.score; });
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//score�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.score > right.score; });
		CheckValue({ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//name�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.name < right.name; });
		CheckValue({ Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//name�ō~��
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
	@brief		�����L�[�����v�f�����郊�X�g�ŁA���̃L�[���w�肵�\�[�g�����s�������̋���
	@details	ID:���X�g-3\n
				�\�[�g�֐��̃e�X�g�ł��B
				�v�f���\�[�g����ĕ��ׂΐ����ł��B(�����v�f�̏����͕ۏ؂���Ȃ��B)\n
*//***********************************************************************************/

TEST(TestListSort, ContainsSameKey)
{
	//score�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.score < right.score; });
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//score�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.score > right.score; });
		CheckValue({ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//name�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.sort([](const Grades& left, const Grades& right) {return left.name < right.name; });
		CheckValue({ Grades{ 1,"fuga" },Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//name�ō~��
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
	@brief		����ς݃��X�g�Ƀ\�[�g�����s�������̋���
	@details	ID:���X�g-4\n
				�\�[�g�֐��̃e�X�g�ł��B
				�����L�[�̗v�f�̊ԈȊO�̏��Ԃ��ϓ����Ȃ���ΐ����ł��B\n
*//***********************************************************************************/

TEST(TestListSort, AlignedList)
{
	//score�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 2,"piyo" });
		list.sort([](const Grades& left, const Grades& right) {return left.score < right.score; });
		CheckValue({ Grades{ 0,"hoge" },Grades{ 1,"fuga" },Grades{ 2,"piyo" } }, list);
	}

	//score�ō~��
	{
		List<Grades>list;
		list.add(Grades{ 2,"piyo" });
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 0,"hoge" });
		list.sort([](const Grades& left, const Grades& right) {return left.score > right.score; });
		CheckValue({ Grades{ 2,"piyo" },Grades{ 1,"fuga" },Grades{ 0,"hoge" } }, list);
	}

	//name�ŏ���
	{
		List<Grades>list;
		list.add(Grades{ 1,"fuga" });
		list.add(Grades{ 0,"hoge" });
		list.add(Grades{ 2,"piyo" });
		list.sort([](const Grades& left, const Grades& right) {return left.name < right.name; });
		CheckValue({ Grades{ 1,"fuga" },Grades{ 0,"hoge" }, Grades{ 2,"piyo" } }, list);
	}

	//name�ō~��
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
	@brief		��x���񂵂����X�g�̊e���ɑ}�����A�ēx�\�[�g�����s�������̋���
	@details	ID:���X�g-5\n
				�\�[�g�֐��̃e�X�g�ł��B
				�v�f���\�[�g����ĕ��ׂΐ����ł��B\n
*//***********************************************************************************/

TEST(TestListSort, SortedList)
{
	//score�ŏ���
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

	//score�ō~��
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

	//name�ŏ���
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

	//name�ō~��
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
	@brief		�L�[�w������Ȃ�����(nullptr��n����)���̋���
	@details	ID:���X�g-6\n
				�\�[�g�֐��̃e�X�g�ł��B
				�G���[�܂߂āA�����N����Ȃ���ΐ����ł��B\n
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
