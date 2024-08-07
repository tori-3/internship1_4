#include "pch.h"
#include"../internship1_4/List.h"
#include"../internship1_4/Grades.h"
#include"manualTest.h"

/**********************************************************************************//**
	@brief		�\�[�g�֐��Ɍ^�Ȃǂ��s�K�؂ȃL�[�w�肪�����œn���ꂽ���̋���
	@details	ID:���X�g-7(�蓮)\n
				�\�[�g�֐��̃e�X�g�ł��B
				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
				TEST_LIST_SORT_INVALID_KEY�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/

TEST(TestListSort, InvalidKey) 
{
#ifdef TEST_LIST_SORT_INVALID_KEY

	List<Grades>list;
	list.sort([](int left, int right) {return left < right; });

#endif
}

/**********************************************************************************//**
	@brief		�\�[�g�֐�����const�̃��\�b�h�ł��邩
	@details	ID:���X�g-8(�蓮)\n
				�\�[�g�֐��̃e�X�g�ł��B
				�L���ɂ��ăR���p�C���G���[�ɂȂ�ΐ����ł��B\n
				TEST_LIST_SORT_IS_NOT_CONST�}�N�����`����ƗL���ɂȂ�܂��B\n
*//***********************************************************************************/

TEST(TestListSort, IsNotConst) 
{
#ifdef TEST_LIST_SORT_IS_NOT_CONST

	const List<Grades>list;
	list.sort();

#endif
}
