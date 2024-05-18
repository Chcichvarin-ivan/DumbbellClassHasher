/*
 * @Author: Ivan Chichvarin ichichvarin@humanplus.ru
 * @Date: 2024-05-18 15:05:42
 * @LastEditors: Ivan Chichvarin ichichvarin@humanplus.ru
 * @LastEditTime: 2024-05-18 15:21:14
 * @FilePath: /DumbbellClassHasher/daumbbell_calss_hasher.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <iostream>
#include <string>

using namespace std;

struct Circle {
    double x;
    double y;
    double r;
};

struct Dumbbell {
    Circle circle1;
    Circle circle2;
    string text;
};

struct DumbbellHash {
    size_t operator() (const Dumbbell& dumbbell) const {
        size_t h_x1 = d_hasher_(dumbbell.circle1.x);
        size_t h_y1 = d_hasher_(dumbbell.circle1.y);
        size_t h_r1 = d_hasher_(dumbbell.circle1.r);

        size_t h_x2 = d_hasher_(dumbbell.circle2.x);
        size_t h_y2 = d_hasher_(dumbbell.circle2.y);
        size_t h_r2 = d_hasher_(dumbbell.circle2.r);

        size_t h_s =  s_hasher_(dumbbell.text);
        
        return h_s + h_x1*5 + h_y1 * (5 * 5) + h_r1 * (5 * 5 * 5) + h_x2 * ((5 * 5) * (5 * 5)) + h_y2 * ((5 * 5) * (5 * 5) * 5) + h_r2 * ((5 * 5) * (5 * 5) * (5 * 5));
    }
    private:
    std::hash<double> d_hasher_;
    std::hash<string> s_hasher_;
};

int main() {
    DumbbellHash hash;
    Dumbbell dumbbell{{10, 11.5, 2.3}, {3.14, 15, -8}, "abc"s};
    cout << "Dumbbell hash "s << hash(dumbbell);
}