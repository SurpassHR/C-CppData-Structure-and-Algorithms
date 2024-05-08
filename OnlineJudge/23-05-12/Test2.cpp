
/*
 * Copyright (c) Huawei Technologies Co., Ltd. 2019-2021. All rights reserved.
 * Description: 上机编程认证
 * Note: 缺省代码仅供参考，可自行决定使用、修改或删除
 */

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <map>
#include <algorithm>

using namespace std;

struct restaurant {
    int restaurantId;
    vector<int> mealType;
    vector<int> money;
};

class RestaurantSystem {
private:
    vector<restaurant> rests = {};

    static bool compare(const restaurant& a, const restaurant& b) {
        int sum_a = 0;
        int sum_b = 0;
        for (int i = 0; i < a.money.size(); i++) {
            sum_a += a.money[i];
        }
        for (int i = 0; i < a.money.size(); i++) {
            sum_b += b.money[i];
        }
        if (sum_a != sum_b) {
            return sum_a > sum_b;
        } else {
            return a.restaurantId < b.restaurantId;
        }
    }

public:
    // 待实现函数，在此函数中填入答题代码
    RestaurantSystem()
    {
    }

    // 待实现函数，在此函数中填入答题代码
    void Receive(int restaurantId, int mealType, int money)
    {
        for (int i = 0; i < rests.size(); i++) {
            if (rests[i].restaurantId == restaurantId) {
                rests[i].mealType.push_back(mealType);
                rests[i].money.push_back(money);
                return;
            }
        }
        restaurant rest;
        rest.restaurantId = restaurantId;
        rest.mealType.push_back(mealType);
        rest.money.push_back(money);
        rests.push_back(rest);
    }

    // 待实现函数，在此函数中填入答题代码
    vector<int> QueryRestaurant()
    {
        sort(rests.begin(), rests.end(), &compare);
        vector<int> ret = {};
        for (int i = 0; i < rests.size(); i++) {
            ret.push_back(rests[i].restaurantId);
        }
        return ret;
    }

    // 待实现函数，在此函数中填入答题代码
    int QueryIncome(int restaurantId, int mealType)
    {
        for (int i = 0; i < rests.size(); i++) {
            if (rests[i].restaurantId == restaurantId) {
                for (int j = 0; j < rests[i].mealType.size(); j++) {
                    if (rests[i].mealType[j] == mealType) {
                        return rests[i].money[j];
                    }
                }
            }
        }
        return 0;
    }
};

// 以下为考题输入输出框架，此部分代码不建议改动
const auto g_runWhile = [](auto fn, auto cond, auto s, auto d, auto e) {
    s();
    if (cond()) { fn(); }
    while (cond()) { d(), fn(); }
    e();
};

struct Reader {
    template<typename T, typename... P> static T Get(P... paras)
    {
        T t;
        Fill(t, paras...);
		if (cin.fail()) { throw invalid_argument(""); }
        return t;
    }
    template<typename T> static void Fill(T& x, ...) { cin >> x; }

    static auto ExpectChar(char s)
    {
        return [s]() {
            if (s == ' ' || s == '\0' || cin.eof()) { return; }
            while (cin.peek() == ' ' || cin.peek() == '\r') { cin.get(); }
			auto c = cin.get();
            if (c != s && c != '\n' && !cin.eof()) { throw invalid_argument(""); }
        };
    }

    template<typename T, typename... P> static void FillSeqUntil(T& seq, const char* sde, P... paras)
    {
        g_runWhile([&seq, paras...]() { seq.push_back(Get<typename T::value_type>(paras...)); }, [e = sde[2]]() {
			if (cin.eof() || cin.peek() == char_traits<char>::eof()) { return false; }
            while (cin.peek() == ' ' || cin.peek() == '\r') { cin.get(); }
            return cin.peek() != e && cin.peek() != '\n';
        }, ExpectChar(sde[0]), ExpectChar(sde[1]), ExpectChar(sde[2]));
    }

    template<typename... P>
    static void Fill(string& s, const char* sde, P... paras) { FillSeqUntil(s, sde, paras...); }
};

struct Writer {
    template<typename T> static void Put(const T& x, ...) { cout << x; }
    static auto PutPara(char c) { return [c]() { if (c != '\0') { cout << c; } }; }

    template<typename T, typename... P> static void Put(const vector<T>& v, const char* sde, P... paras)
    {
        size_t pos = 0;
        g_runWhile([&v, &pos, paras...]() { Put(v[pos++], paras...); }, [&v, &pos]() { return pos < v.size(); },
            PutPara(sde[0]), PutPara(sde[1]), PutPara(sde[2]));
    }
};

int main()
{
    try {
        auto num = Reader::Get<int>();
        auto cmd = Reader::Get<string>(0);
        if (cmd != "RestaurantSystem") { throw invalid_argument(""); }
        RestaurantSystem sys;
        cout << "null" << endl;
        --num;

        for (; num > 0; --num) {
            while (cin.peek() == '\r' || cin.peek() == '\n') { cin.get(); }
            cmd = Reader::Get<string>("  =");
            if (cmd == "receive") {
                auto restaurantId = Reader::Get<int>();
                auto mealType = Reader::Get<int>();
                auto money = Reader::Get<int>();
                sys.Receive(restaurantId, mealType, money);
                cout << "null" << endl;
            } else if (cmd == "queryRestaurant") {
                Writer::Put(sys.QueryRestaurant(), "[ ]");
                cout << endl;
            } else if (cmd == "queryIncome") {
                auto restaurantId = Reader::Get<int>();
                auto mealType = Reader::Get<int>();
                cout << sys.QueryIncome(restaurantId, mealType) << endl;
            } else {
                throw invalid_argument("");
            }
        }
    } catch (const invalid_argument&) {
        cout << "Input format error!" << endl;
    }

    return 0;
}
