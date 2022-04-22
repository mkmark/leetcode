/*
author: mark@mkmark.net
*/

#include <queue>
#include <stack>
#include <string>

template<class T>
class RabinKarpQueue{
private:
    std::queue<T> que;
    // std::stack<long long> base_power_mods;

    long long base_power_mod = 1;

    int get_size(std::string arr){
        return arr.length();
    }

    int get_size(T* arr){
        return *(&arr + 1) - arr;
    }

    int get_size(vector<T> arr){
        return arr.size();
    }

    void fixed_push(T t){
        hash = (hash*base + val(t)) % prime;
        que.push(t);
    }

    void fixed_pop(){
        hash = (hash + prime - val(*l) * n_power_mod % prime) % prime;
        que.pop();
    }

public:
    int base = 26;
    // int prime = 101;
    // int prime = 1009;
    // int prime = 10007;
    // int prime = 100003;
    // int prime = 1000003; 
    // int prime = 97755331;
    // int prime = 4294967291;
    int prime = 92232275197933;
    long long hash = 0;
    int size() {return que.size();};
    T front() {return que.front();};

    void push(T t){
        base_power_mod = base_power_mod * base % prime;
        // base_power_mods.push(base_power_mod);
        fixed_push(t);
    }

    // void pop(){
    //     fixed_pop();
    //     base_power_mods.pop();
    //     base_power_mod = base_power_mods.top();
    // }

    void push_pop(T t){
        fixed_push(t);
        fixed_pop();
    }

    inline int val(char& c){
        return c-'a';
    }

    inline int val(T& t){
        return t;
    }

    int base_power(int power){
        long long res;
        for (int i = 0; i < power; ++i){
            res *= base;
            res %= prime;
        }
        return res;
    }

    void init(std::string::iterator l, std::string::iterator r){
        // base_power_mods.push(1);
        for (auto it = l; it != r; ++it){
            push(*it);
        }
    }

    void init(T* l, T* r){
        // base_power_mods.push(1);
        for (auto it = l; it != r; ++it){
            push(*it);
        }
    }

    void init(typename vector<T>::iterator l, typename vector<T>::iterator r){
        // base_power_mods.push(1);
        for (auto it = l; it != r; ++it){
            push(*it);
        }
    }


    RabinKarpQueue(){};

    RabinKarpQueue(std::string::iterator l, std::string::iterator r, int base)
        : base(base)
    {
        init(arr);
    };

    RabinKarpQueue(T* l, T* r, int base)
        : base(base)
    {
        init(l, r);
    };

    RabinKarpQueue(typename vector<T>::iterator l, typename vector<T>::iterator r, int base)
        : base(base)
    {
        init(l, r);
    };
};
