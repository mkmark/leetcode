/*
author: mark@mkmark.net
*/

#include <bits/stdc++.h>

using namespace std;

template <class T>
struct is_std_vector { static const bool value=false; };

template <class T>
struct is_std_vector<std::vector<T>> { static const bool value=true; };

class LeetCodeInput{
private:
    vector<string> get_lines(string &path);
    vector<string> split(const string &s);

    template <class T>
    T r2t(string& r);

public: 
    vector<string> lines;

    LeetCodeInput(string path){
        lines = get_lines(path);
    }

    template <class T>
    T get(int line) {return r2t<T>(lines[line]);};

};

vector<string> LeetCodeInput::get_lines(string &path){
    string line;
    vector<string> lines;
    ifstream input(path);
    if (input.is_open())
    {
        while (getline(input, line))
        {
            lines.push_back(line);
        }
        input.close();
    }
    return lines;
}

vector<string> LeetCodeInput::split (const string &s) {
    vector<string> result;
    int level=0;
    if (s == "[]"){
        return result;
    } else {
        result.push_back("");
    }
    for (auto c : s){
        switch(c){
            case '[': 
                if (level != 0) {
                    result.back().push_back(c);
                } 
                ++level;
                break;
            case ']': 
                if (level != 0) {
                    result.back().push_back(c);
                } 
                --level;
                break;
            case ',':
                if (level == 1) {
                    result.push_back("");
                } else {
                    result.back().push_back(c);
                }
                break;
            default: 
                result.back().push_back(c);
                break;
        }
    }
    return result;
}

template <>
int LeetCodeInput::r2t(string& r){
    return stoi(r);
}

template <>
char LeetCodeInput::r2t(string& r){
    return r[1];
}

template <>
string LeetCodeInput::r2t(string& r){
    return r.substr(1, r.size() - 2);
}

template <class T>
T LeetCodeInput::r2t(string& r){
    T res;
    for (auto e : split(r)){
        res.push_back(r2t<typename T::value_type>(e));
    }
    return res;
}
