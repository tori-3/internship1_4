#include<iostream>
#include<fstream>
#include<sstream> 
#include"Grades.h"
#include"List.h"

void PrintGrades(const List<Grades>&list) 
{
    for (auto grades :list)
    {
        std::cout << grades.score << "\t" << grades.name << std::endl;
    }
}

int main()
{

    List<Grades> list;

    std::ifstream file;
    std::string line;

    file.open("Scores.txt", std::ios::in);

    //��s���ǂݍ���
    while (std::getline(file, line))
    {
        Grades grades;

        //�^�u�ŋ�؂�A���X�g�ɒǉ�����B
        std::string temp;
        std::stringstream ss{ line };
        std::getline(ss, temp, '\t');
        grades.score = atoi(temp.c_str());
        std::getline(ss, temp, '\t');
        grades.name = temp;

        list.add(grades);
    }

    list.sort([](const Grades& left, const Grades& right) {return left.score < right.score; });

    std::cout << "-----�X�R�A�ŕ��ёւ�-----" << std::endl;
    PrintGrades(list);

    list.sort([](const Grades& left, const Grades& right) {return left.name < right.name; });

    std::cout << "-----���O�ŕ��ёւ�-----" << std::endl;
    PrintGrades(list);
}
