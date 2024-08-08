#include "pch.h"
#include"../internship1_4/List.h"
#include"../internship1_4/Grades.h"
#include"manualTest.h"


//ID:8 �f�[�^���̎擾 const�̃��\�b�h�ł��邩
TEST(TestListSize, IsConst)
{
#ifdef TEST_LIST_SIZE_IS_CONST
	const List<Grades> list;
	list.size();
#endif
}

//ID:15 �f�[�^�̑}�� ��const�̃��\�b�h�ł��邩
TEST(TestListInsert, IsNotConst)
{
#ifdef TEST_LIST_IMSERT_IS_NOT_CONST
	const List<Grades> list;
	list.insert(list.begin(), Grades{ 0,"hoge" });
#endif
}

//ID:22 �f�[�^�̍폜 ��const�̃��\�b�h�ł��邩
TEST(TestListRemove, IsNotConst)
{
#ifdef TEST_LIST_REMOVE_IS_NOT_CONST
	const List<Grades> list;
	list.remove(list.begin());
#endif
}

//ID:28 �擪�C�e���[�^�̎擾 const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
TEST(TestListBegin, IsNotConst)
{
#ifdef TEST_LIST_BEGIN_IS_NOT_CONST
	const List<Grades> list;
	List<Grades>::Iterator it = list.begin();
#endif
}

//ID:34 �擪�R���X�g�C�e���[�^�̎擾 const�̃��\�b�h�ł��邩
TEST(TestListConstBegin, IsConst)
{
#ifdef TEST_LIST_CONSTBEGIN_IS_CONST
	const List<Grades> list;
	list.constBegin();
#endif
}

//ID:40 �����C�e���[�^�̎擾 const�̃��X�g����AConstIterator�łȂ�Iterator�̎擾���s���Ȃ������`�F�b�N
TEST(TestListEnd, IsNotConst)
{
#ifdef TEST_LIST_END_IS_NOT_CONST
	const List<Grades> list;
	List<Grades>::Iterator it = list.end();
#endif
}

//ID:46 �����R���X�g�C�e���[�^�̎擾 const�̃��\�b�h�ł��邩
TEST(TestListConstEnd, IsConst)
{
#ifdef TEST_LIST_CONST_END_IS_CONST
	const List<Grades> list;
	list.constEnd();
#endif
}

//ID:2 �C�e���[�^�̎w���v�f���擾���� ConstIterator����擾�����v�f�ɑ΂��āA�l�̑�����s���Ȃ������`�F�b�N
TEST(TestConstIteratorGetElement, NotAssignable)
{
#ifdef TEST_CONST_ITERATOR_GET_ELEMENT_NOT_ASSIGNABLE
	const List<Grades> list;
	auto it = list.constBegin();
	(*it) = Grades{ 0,"hoge" };
#endif
}

//ID:17 ConstIterator����AIterator�̃R�s�[���쐬����Ȃ������`�F�b�N
TEST(TestConstIteratorCopy, CanNotCopyToIterator)
{
#ifdef TEST_CONST_ITERATOR_COPY_CAN_NOT_COPY_TO_ITERATOR
	List<Grades> list;
	auto constIt = list.constBegin();
	List<Grades>::Iterator it = constIt;
#endif
}

//ID:19 �C�e���[�^�̑�����s�� Iterator��ConstIterator�����ł��Ȃ������`�F�b�N
TEST(TestConstIteratorAssign, CanNotAssignToIterator)
{
#ifdef TEST_CONST_ITERATOR_ASSIGN_CAN_NOT_ASSIGN_TO_ITERATOR
	List<Grades> list;
	auto it = list.begin();
	auto constIt = list.constBegin();
	it = constIt;
#endif
}


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
