#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*bool solution(vector<string> phone_book) {
    bool answer = true;

    for(auto i=phone_book.begin(); i!=phone_book.end() ; i++) {
        for(auto j=phone_book.begin(); j!=phone_book.end(); j++) { //i 다음 번호부터 비교
            if(i == j) continue;
            cout << "i : " << *i << "\nj : " << *j << endl;
            if(i->length() < j->length()) { //i 번호의 길이가 j보다 짧을 경우에만
                int idx=0;
                for(idx=0; idx<i->length(); idx++) { // i와 j의 번호를 비교
                    if((*i)[idx] != (*j)[idx]) break;
                }
                if(idx == i->length()) answer = false;
            }
        }
    }
    return answer;
}*/

/*bool solution(vector<string> phone_book) {
    unordered_map<string, int> hash_map;
    for(int i=0; i<phone_book.size(); i++)
        hash_map[phone_book[i]] = 1;
    for(int i=0; i<phone_book.size(); i++) {
        cout << "i : " << phone_book[i] << endl;
        for(int j=0; j<phone_book[i].size()-1; j++) {
            string phone_number = phone_book[i].substr(0,j+1);
            cout <<"j : " << j << "  phone : " << phone_number << endl;
            if(hash_map[phone_number])
                return false;
        }
    }
    return true;
}*/

bool solution(vector<string> phone_book) {
    // 1. phoneBook 배열을 정렬한다.
    sort(phone_book.begin(), phone_book.end());
    for(auto i : phone_book) {
        cout << i << endl;
    }
    // 2. 1중 Loop을 돌며 앞 번호가 뒷 번호의 접두어인지 확인한다.
    for (int i = 0; i < phone_book.size() - 1; i++)
        if (phone_book[i + 1].find(phone_book[i]) == 0) return false;
    // 3. 여기까지 오면 접두어가 없다는 것이다.
    return true;
}

int main(void)
{
    vector<string> phone_book = {"2345", "456", "24", "2"};
    cout << "answer = " << solution(phone_book) << endl;

    return 0;
};