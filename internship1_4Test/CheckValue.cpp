#include "pch.h"
#include"CheckValue.h"

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
