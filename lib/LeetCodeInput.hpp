/*
author: mark@mkmark.net
*/

#include <bits/stdc++.h>

using namespace std;

class LeetCodeInput{
    vector<string> get_lines(string path);
    vector<string> split(string s, string delimiter);
    vector<string> split(const string &s, char delim);

    vector<string>          r2vr(string& r);
    vector<vector<string>>  r2vvr(string& r);
    vector<int>             vr2vi(vector<string>& vr);
    vector<string>          vr2vs(vector<string>& vr);
    vector<vector<int>>     vvr2vvi(vector<vector<string>>& vvr);
    vector<vector<string>>  vvr2vvs(vector<vector<string>>& vvr);

    int                     r2i(string& r);
    string                  r2s(string& r);
    vector<int>             r2vi(string& r);
    vector<vector<int>>     r2vvi(string& r);
    vector<string>          r2vs(string& r);
    vector<vector<string>>  r2vvs(string& r);
public: 
    vector<string> lines;

    LeetCodeInput(string path){
        lines = get_lines(path);
    }

    int                     get_i(int line)     {return r2i(lines[line]);};
    string                  get_s(int line)     {return r2s(lines[line]);};
    vector<int>             get_vi(int line)    {return r2vi(lines[line]);};
    vector<vector<int>>     get_vvi(int line)   {return r2vvi(lines[line]);};
    vector<string>          get_vs(int line)    {return r2vs(lines[line]);};
    vector<vector<string>>  get_vvs(int line)   {return r2vvs(lines[line]);};
};

vector<string> LeetCodeInput::get_lines(string path){
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

vector<string> LeetCodeInput::split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back(s.substr(pos_start));
    return res;
}

vector<string> LeetCodeInput::split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

int LeetCodeInput::r2i(string& r){
    return stoi(r);
}

string LeetCodeInput::r2s(string& r){
    return r.substr(1, r.size() - 2);;
}

vector<string> LeetCodeInput::r2vr(string& r){
    r = r.substr(1, r.size() - 2);
    return split(r, ',');
}

vector<int> LeetCodeInput::vr2vi(vector<string>& vr){
    int n = vr.size();
    vector<int> vi(n);
    for (int i=0; i<n; ++i){
        vi[i] = r2i(vr[i]);
    }
    return vi;
}

vector<string> LeetCodeInput::vr2vs(vector<string>& vr){
    int n = vr.size();
    vector<string> vs(n);
    for (int i=0; i<n; ++i){
        vs[i] = r2s(vr[i]);
    }
    return vs;
}

vector<vector<string>> LeetCodeInput::r2vvr(string& r){
    r = r.substr(2, r.size() - 4);
    vector<string> vr = split(r, "],[");
    int m = vr.size();
    vector<vector<string>> vvr(m);
    for (int i=0; i<m; ++i){
        vvr[i] = split(vr[i], ',');
    }
    return vvr;
}

vector<vector<int>> LeetCodeInput::vvr2vvi(vector<vector<string>>& vvr){
    int n = vvr.size();
    vector<vector<int>> vvi(n);
    for (int i=0; i<n; ++i){
        vvi[i] = vr2vi(vvr[i]);
    }
    return vvi;
}

vector<vector<string>> LeetCodeInput::vvr2vvs(vector<vector<string>>& vvr){
    int n = vvr.size();
    vector<vector<string>> vvs(n);
    for (int i=0; i<n; ++i){
        vvs[i] = vr2vs(vvr[i]);
    }
    return vvs;
}

vector<int> LeetCodeInput::r2vi(string& r){
    auto vr = r2vr(r);
    return vr2vi(vr);
}

vector<vector<int>> LeetCodeInput::r2vvi(string& r){
    auto vvr = r2vvr(r);
    return vvr2vvi(vvr);
}

vector<string> LeetCodeInput::r2vs(string& r){
    auto vr = r2vr(r);
    return vr2vs(vr);
}

vector<vector<string>> LeetCodeInput::r2vvs(string& r){
    auto vvr = r2vvr(r);
    return vvr2vvs(vvr);
}