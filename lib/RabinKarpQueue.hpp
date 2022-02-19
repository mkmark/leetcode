/*
author: mark@mkmark.net
*/

#include <queue>
#include <string>

class RabinKarpQueue{
private:
    std::queue<char> que;
    long long base_power_mod = 1;

public:
    int base = 26;
    // int prime = 101   
    // int prime = 1009
    // int prime = 10007
    // int prime = 100003
    // int prime = 1000003 
    int prime = 97755331;
    long long hash = 0;
    int size() {return que.size();};
    char front() {return que.front();};

    void initial_push(char c){
        base_power_mod = base_power_mod * base % prime;
        push(c);
    }

    void push(char c){
        hash = (hash*base + val(c)) % prime;
        que.push(c);
    }

    void pop(){
        hash = (hash - val(que.front()) * base_power_mod) % prime;
        hash = hash < 0 ? (hash+prime) : hash;
        que.pop();
    }

    inline int val(char& c){
        return c-'a';
    }

    int base_power(int power){
        long long res;
        for (int i = 0; i < power; ++i){
            res *= base;
            res %= prime;
        }
        return res;
    }

    void init(std::string s){
        int n = s.length();
        for (int i = 0; i<s.length(); ++i){
            initial_push(s[i]);
        }
    }

    RabinKarpQueue(){};

    RabinKarpQueue(std::string s){
        init(s);
    };

    RabinKarpQueue(std::string s, int base)
        : base(base)
    {
        init(s);
    };

    RabinKarpQueue(std::string s, int prime, int base)
        : base(base)
        , prime(prime)
    {
        init(s);
    };
};
