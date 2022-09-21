#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string>
#include <iostream>

const char* solution(int num) {
    // 리턴할 값은 메모리를 동적 할당해주세요
    const char* answer = (char*)malloc((5-num%2) * sizeof(char));    
    answer = num%2 == 0 ? "Even" : "Odd";
    return answer;
}

int main() {
    int num = 1;
    std::string answer;

    answer = solution(num);
    std::cout<< "answer : " << answer << std::endl;


    return 0;
}