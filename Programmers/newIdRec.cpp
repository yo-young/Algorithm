#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string step1 = "";
    string answer = "";

    for(int i=0; i<new_id.size(); i++)
    {
        //step 1
        new_id[i] = tolower(new_id[i]);
        //step 2
        if((new_id[i] >= '0' && new_id[i] <= '9') ||
           (new_id[i] >= 'a' && new_id[i] <= 'z') ||
           (new_id[i] == '-' || new_id[i] == '_' || new_id[i] == '.'))
        {
            step1 += new_id[i];
        }
    }
    //step3
    for(int i=0; i<step1.size(); i++)
    {
        if(step1[i-1] == '.' && step1[i] == '.') continue;
         answer += step1[i];
    }
   
    //step 4
    if(answer.front() == '.') answer.erase(0, 1);
    if(answer.back() == '.') answer.erase(answer.size()-1, answer.size());

    //step 5
    if(answer.empty()) answer = "a";

    //step 6
    if(answer.size() >= 16) answer.erase(15, answer.size());
    if(answer.front() == '.') answer.erase(0, 1);
    if(answer.back() == '.') answer.erase(answer.size()-1, answer.size());

    //step 7
    if(answer.size() <= 2)
    {
        while(answer.size()<=2)
        {
            answer += answer.back();
        }
    }

    return answer;
}

int main()
{
    // char a = '$';
    // a = a-1;
    // printf("%c", a);
    string new_id, answer;

    cin >> new_id;
    
    answer = solution(new_id);
    cout << answer << endl;

    return 0;
}