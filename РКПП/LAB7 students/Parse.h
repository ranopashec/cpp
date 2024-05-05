#ifndef PARSE_H
#define PARSE_H
#include "SStudData.h"
#include "bits/stdc++.h"


int Stoi(const std::string& s){
    int res = 0;
    for (char e : s){
        if (e < '0' || e > '9') continue; //  throw std::runtime_error("Can't convert string to int");
        res *= 10;
        res += (e - '0');
    }
    return res;
}


SMark ParseToMark(const std::string& s){
    size_t it = 0;
    while (it < s.size() && s[it] != '-') ++it;
    if (s[it] != '-') throw std::runtime_error("Can't convert string to mark");
    return SMark{s.substr(0, it), Stoi(s.substr(it+1, INT_MAX))};
}

SStudData ParseLine(const std::string& s){
    int cnt = 0;
    std::string word;

    std::string name;
    int id;
    std::vector<SMark> marks;

    for (auto e : s){
        if (e == ';' || e == ','){
            ++cnt;
            switch (cnt){
                case 1:
                    name = word; break;
                case 2:
                    id = Stoi(word.substr()); break;
                default:
                    marks.push_back(ParseToMark(word)); break;
            }
            word = "";
            continue;
        }
        word += e;
    }
    marks.push_back(ParseToMark(word));
    return {name, id, marks};
}

std::vector<SStudData> ParseFile(std::ifstream& in){
    if (!in) {
        std::cerr << "Can't read from file";
    }
    std::string s;
    std::vector<SStudData> v;
    while (getline(in, s)){
        v.push_back(ParseLine(s));
    }
    return v;
}

#endif
