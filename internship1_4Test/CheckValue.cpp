#include "pch.h"
#include"CheckValue.h"

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
