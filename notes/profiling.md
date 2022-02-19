# profiling

https://stackoverflow.com/questions/375913/how-can-i-profile-c-code-running-on-linux

```sh
clear
g++ main.cpp -o main-gprof.out -fdiagnostics-color=always -g -pg 
./main-gprof.out
gprof main-gprof.out gmon.out
```
