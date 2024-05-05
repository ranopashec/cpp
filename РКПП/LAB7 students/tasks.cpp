#include <bits/stdc++.h>
#include "SStudData.h"
#include "Parse.h"

int main() {
    setlocale(LC_ALL, "Russian");
    // 1) Вводом из текстового файла сформировать vector из объектов SStudData. 3 балла
    std::ifstream in("/Users/antipod/Documents/BSU/1-2/RK/LAB7/input.txt");
    std::vector<SStudData> v = ParseFile(in);
    // for (auto& e : v) std::cout << e << '\n';
    // 2) Выполнить единую сортировку объектов SStudData по двум критериям: по убыванию фамилий, затем – по возрастанию № зачетки 2 балла
    std::sort(v.begin(), v.end(), [](const SStudData &a, const SStudData &b) {
        if (a.GetName() == b.GetName()) {
            return a.GetId() < b.GetId();
        }
        return a.GetName() > b.GetName();
    });
    // 3) Сформировать из vector контейнер map<int, SStudData>, ключ – номер зачетки. 2 балла По полученному контейнеру map (используйте стандартные алгоритмы):
    {
        std::map<int, SStudData> m;
        for (auto &e: v) {
            m[e.GetId()] = e;
        }
    }
    // 4) Найти студента с максимальной суммой баллов. 2 балла
    auto SumMarks = [](const SStudData &st) {
        int cur = 0;
        for (auto &e: st.GetMarks()) {
            cur += e.Mark;
        }
        return cur;
    };
    {
        int mx = 0;
        SStudData BestStudent;
        for (auto &e: v) {
            int cur = SumMarks(e);
            if (cur > mx) {
                mx = cur;
                BestStudent = e;
            }
        }
        std::cout << "4) Student with maximum marks sum:\n" << BestStudent << '\n';
    }
    // 7) Найти всех студентов, не сдавших сессию (хотя бы одна 2) 2 балла
    {
        std::vector<SStudData> loosers;
        auto IsLooser = [](const SStudData &st) {
            for (auto &e: st.GetMarks()) {
                if (e.Mark <= 2) return true;
            }
            return false;
        };
        for (auto &e: v) {
            if (IsLooser(e)) {
                loosers.push_back(e);
            }
        }
        std::cout << "7) people with 2:\n";
        for (auto& e : loosers){
            std::cout << e << '\n';
        }
    }
    // 5) Вычислить средний балл по каждому студенту. 2 балла
    auto Mid = [&SumMarks](const SStudData &st) {
        if (st.GetMarks().empty()) return 0.0;
        return (double(SumMarks(st)) / st.GetMarks().size());
    };
    {
        for (auto& e : v){
            Mid(e);
        }
    }
    // 6) Вывести список всех студентов «Фамилия Средний_балл Номер_зачетки» в порядке: возрастания фамилий, для равных фамилий – по убыванию среднего балла. 2 балла
    std::sort(v.begin(), v.end(), [&Mid](const SStudData& a, const SStudData& b){
        if (a.GetName() == b.GetName()){
            return Mid(a) > Mid(b);
        }
       return a.GetName() < b.GetName();
    });
    std::cout << "6)\n";
    for (auto& e : v){
        std::cout << e.GetName() << ' ' << Mid(e) << ' ' << e.GetId() << '\n';
    }
    // 7) Вывести список студентов, средний балл которых принадлежит заданному диапазону. Порядок – по убыванию среднего балла. 2 балла
    {
        double mn = 7, mx = 8;
        std::cout << "7) entered diapason:\n"
        << mn << " - " << mx << '\n';
        // std::cin >> mn >> mx;
        std::sort(v.begin(), v.end(), [&Mid](const SStudData& a, const SStudData& b){
            return Mid(a) > Mid(b);
        });
        int cnt = 0;
        for (auto& e : v){
            double md = Mid(e);
            if ( md < mx && md >= mn){
                ++cnt;
                std::cout << e.GetName() << ' ' << md << ' ' << e.GetId() << '\n';
            }
        }
        if (cnt == 0){
            std::cout << "no student's with such grade";
        }

    }
    // 8) Вывести список студентов, которые сдавали заданный предмет (задавать в программе). 2 балла
    {
        std::string predmet = "ММКГ";
        std::cout << "8) Entered subject\n"
                     << predmet << "\n";
        for (auto& st : v){
            for(auto& mrk : st.GetMarks()){
                if (mrk.Subject == predmet){
                    std::cout << st.GetName() << '\n';
                }
            }
        }

    }
    // 9) Сколько студентов сдавало каждый предмет.
    {
        std::map<std::string, int> mp;
        for (auto& e : v){
            for (auto& mrk : e.GetMarks()){
                ++mp[mrk.Subject];
            }
        }
        std::cout << "9)\n";
        for (auto[sub, cnt] : mp){
            std::cout << sub << " : " << cnt << '\n';
        }
    }

}
