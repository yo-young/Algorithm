#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>

int solution(int n) {
    int answer = 0;
    //약수는 나눠서 나머지가 0이 되는 수
    for(int i=1; i<= n/2; i++)
    {
        std::cout<< "i : " << i << std::endl;
        if(n%i == 0) {
            std::cout<< "plus answer" << std::endl;
            answer += i;
            
        }
    }
    
    
    return answer+n;
}

int main()
{
    int answer = 0;
    int n;
    std::cin >> n;
    answer = solution(n);

    std::cout << "answer : " << answer << std::endl;

    return 0;
}