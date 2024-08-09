#pragma once
#include<string>

///@brief 成績と名前を扱うクラスです。
struct Grades
{
    //! スコア
    int score;

    //! 名前
    std::string name;

    ///@brief データが等しいか調べます。
    ///@param right 比較するイテレーター
    ///@return データ同士が等しければtrue 異なっていればfalseを返します。
    ///@detail score name それぞれを比較しています。
    bool operator ==(const Grades& right)const
    {
        return (score == right.score) && (name == right.name);
    }

    ///@brief データが異なっているか調べます。
    ///@param right 比較するイテレーター
    ///@return データ同士が異なっていればtrue 等しければfalseを返します。
    ///@detail score name それぞれを比較しています。
    bool operator !=(const Grades& right)const
    {
        return (score != right.score) || (name != right.name);
    }
};
