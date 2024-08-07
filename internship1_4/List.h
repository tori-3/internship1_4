#pragma once
#include<string>
#include <cassert>
#include <functional>

///@brief �o�������X�g�̃N���X�ł��B
template<typename DataType>
class List
{
private:
    ///@brief ���X�g�̃m�[�h�ł��B
    struct Node
    {
        //! �f�[�^
        DataType data;

        //! �O�̃m�[�h�̃|�C���^
        Node* front = nullptr;

        //! ���̃m�[�h�̃|�C���^
        Node* back = nullptr;
    };

public:

    ///@brief ���X�g�̃R���X�g�C�e���[�^�[�ł��B
    class ConstIterator
    {
    public:

        ConstIterator() = default;

        ConstIterator(Node* ptr, const List* parent);

        ConstIterator(const ConstIterator& iterator);

        ConstIterator operator =(const ConstIterator& iterator);

        const DataType& operator *()const;

        ConstIterator& operator --();

        ConstIterator& operator ++();

        ConstIterator operator --(int);

        ConstIterator operator ++(int);

        bool operator !=(ConstIterator right)const;

        bool operator ==(ConstIterator right)const;

    protected:

        //! �m�[�h�̃|�C���^
        Node* m_element = nullptr;

        //! ���X�g�̃|�C���^
        const List* m_parent = nullptr;

        friend List;
    };

    ///@brief ���X�g�̃C�e���[�^�[�ł��B
    class Iterator :public ConstIterator
    {
    public:
        using ConstIterator::ConstIterator;

        DataType& operator *();
    };

    

    ///@brief List�̃R���X�g���N�^�ł��B
    List();

    ///@brief List�̃f�X�g���N�^�ł��B
    ~List();

    ///@brief ���X�g�̐擪�C�e���[�^�[��Ԃ��܂�
    ///@return �擪�C�e���[�^�[
    Iterator begin();

    ///@brief ���X�g�̖����C�e���[�^�[��Ԃ��܂�
    ///@return �����C�e���[�^�[
    Iterator end();

    ///@brief ���X�g�̐擪�R���X�g�C�e���[�^�[��Ԃ��܂�
    ///@return �擪�R���X�g�C�e���[�^�[
    ConstIterator begin()const;

    ///@brief ���X�g�̖����R���X�g�C�e���[�^�[��Ԃ��܂�
    ///@return �����R���X�g�C�e���[�^�[
    ConstIterator end()const;

    ///@brief ���X�g�̐擪�R���X�g�C�e���[�^�[��Ԃ��܂�
    ///@return �擪�C�e���[�^�[
    ConstIterator constBegin() const;

    ///@brief ���X�g�̖����R���X�g�C�e���[�^�[��Ԃ��܂�
    ///@return �����C�e���[�^�[
    ConstIterator constEnd() const;

    ///@brief ���X�g�̒�����Ԃ��܂�
    ///@return ���X�g�̒���
    size_t size()const;

    ///@brief ���X�g�ɐV���ȗv�f��}�����܂��B
    ///@param iterator �ǉ�����ʒu�̃C�e���[�^�[
    ///@param addData �ǉ�����f�[�^
    ///@return �ǉ��ɐ���������true ���s������false
    bool insert(ConstIterator iterator, const DataType& addData);

    ///@brief ���X�g�̗v�f���폜���܂��B
    ///@param iterator �폜����ʒu�̃C�e���[�^�[
    ///@return �폜�ɐ���������true ���s������false
    bool remove(ConstIterator iterator);

    ///@brief ���X�g�̖����ɗv�f��ǉ����܂��B
    ///@param addData �ǉ�����f�[�^
    void add(const DataType& addData);

    void sort(std::function<bool(const DataType&, const DataType&)>compare = [](const DataType& left, const DataType& right) {return left < right; });


private:


    std::pair<Node*, Node*> quickSort(Node* beginNode, Node* lastNode, std::function<bool(const DataType&, const DataType&)>compare);

    //! �ԕ��̃|�C���^
    Node* m_sentinel;

    //! ���X�g�̒���
    size_t m_size = 0;
};

#include"List.inl"
