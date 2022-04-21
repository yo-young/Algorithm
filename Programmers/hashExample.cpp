#include <stdio.h>
#include <unordered_map>
#include <string>
#include <iostream>

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    std::string strArr[100001];
    
    std::string name;
    std::unordered_map <std::string, int> pocketMon;
    for(int i = 1; i<=N; i++){
        std::cin >> name;
        
        pocketMon.insert(make_pair(name,i));
        strArr[i] = name;
    }

    for(int i = 0; i<M; i++)
    {
        std::string input;
        std::cin >> input;
        if(pocketMon.find(input)!=pocketMon.end()){	//이름을 입력하면 map 참조
            std::cout << pocketMon.find(input)->second << "\n";
        }
        else{
            int num = stoi(input);			//번호를 입력한 경우에는 배열 참조
            std::cout << strArr[num] << "\n";
        }
    }


    return 0;
}