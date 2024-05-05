#ifndef SSTUDDATA_H
#define SSTUDDATA_H

#include <bits/stdc++.h>

#include <utility>

struct SMark {
    std::string Subject; //предмет
    int Mark; //оценка
};

std::ostream& operator<<(std::ostream& out, const SMark& mark){
    out << mark.Subject << " : " << mark.Mark;
    return out;
}

class SStudData {
private:
    std::string _name; // фамилия
    int _id; // номер зачетки
    std::vector<SMark> _marks; // рез-ты сессии – пустой на момент создания
public:
    SStudData() : _id(), _name(), _marks(){}
    SStudData(std::string name, int id, const std::vector<SMark>& marks = {}) : _name(std::move(name)), _id(id), _marks(marks){}
    SStudData(const SStudData&)= default;
    SStudData& operator=(const SStudData& oth) = default;

    [[nodiscard]] std::string GetName()const {
        return _name;
    }
    [[nodiscard]] int GetId()const{
        return _id;
    }
    [[nodiscard]] const std::vector<SMark>& GetMarks() const{
        return _marks;
    }
    // метод для добавления оценки
    void AddMark(const SMark& m){
        _marks.push_back(m);
    }
    friend std::ostream& operator<<(std::ostream& out, const SStudData& stud){
        out << stud._name << '\n';
        out << stud._id << '\n';
        for (auto& mark : stud._marks){
            out << "  " << mark << '\n';
        }
        return out;
    }
};

#endif
