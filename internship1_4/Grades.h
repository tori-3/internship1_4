#pragma once
#include<string>

///@brief ���тƖ��O�������N���X�ł��B
struct Grades
{
    //! �X�R�A
    int score;

    //! ���O
    std::string name;

    bool operator ==(const Grades& right)const
    {
        return (score == right.score) && (name == right.name);
    }

    bool operator !=(const Grades& right)const
    {
        return (score != right.score) || (name != right.name);
    }
};
