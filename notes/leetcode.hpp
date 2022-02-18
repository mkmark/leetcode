using namespace std;

vector<string> get_lines(string path){
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

vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}

vector<string> split (const string &s, char delim) {
    vector<string> result;
    stringstream ss (s);
    string item;

    while (getline (ss, item, delim)) {
        result.push_back (item);
    }

    return result;
}

inline int s2i(string& s){
    return stoi(s);
}

vector<string> s2vs(string& s){
    s = s.substr(1, s.size() - 2);
    return split(s, ',');
}

vector<int> vs2vi(vector<string>& vs){
    int n = vs.size();
    vector<int> vi(n);
    for (int i=0; i<n; ++i){
        vi[i] = s2i(vs[i]);
    }
    return vi;
}

vector<vector<string>> s2vvs(string& s){
    s = s.substr(2, s.size() - 4);
    vector<string> vs = split(s, "],[");
    int m = vs.size();
    vector<vector<string>> res(m);
    for (int i=0; i<m; ++i){
        res[i] = split(vs[i], ',');
    }
    return res;
}

vector<vector<int>> vvs2vvi(vector<vector<string>>& vvs){
    int n = vvs.size();
    vector<vector<int>> vvi(n);
    for (int i=0; i<n; ++i){
        vvi[i] = vs2vi(vvs[i]);
    }
    return vvi;
}

vector<int> s2vi(string& s){
    auto vs = s2vs(s);
    return vs2vi(vs);
}

vector<vector<int>> s2vvi(string& s){
    auto vvs = s2vvs(s);
    return vvs2vvi(vvs);
}