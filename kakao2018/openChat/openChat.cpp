#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;
#define ENTER 1
#define LEAVE 2
typedef struct
{
    string uid;
    int act; // 1-> Enter // 2-> Leave
} Ans;

map<string, string> userMap;
vector<string> answer;
vector<string> solution(vector<string> record)
{
    int size = record.size();
    vector<Ans> ansList;

    vector<string> nAct(size);
    vector<string> nUid(size);
    vector<string> nNickName(size);

    for (int i = 0; i < record.size(); i++)
    {
        stringstream ss(record[i]);
        ss >> nAct[i];
        ss >> nUid[i];
        ss >> nNickName[i];
    }

    for (int i = 0; i < record.size(); i++)
    {
        if (nAct[i] == "Enter") //1
        {
            userMap[nUid[i]] = nNickName[i];
            ansList.push_back({nUid[i], ENTER});
        }
        else if (nAct[i] == "Leave") // 2
        {
            ansList.push_back({nUid[i], LEAVE});
        }
        else if (nAct[i] == "Change")
        {
            userMap[nUid[i]] = nNickName[i];
        }
    }

    for (int i = 0; i < ansList.size(); i++)
    {
        string tmpAnswer;
        if (ansList[i].act == 1)
        {
            tmpAnswer += userMap[ansList[i].uid];
            tmpAnswer += "님이 들어왔습니다.";
        }
        else
        {
            tmpAnswer += userMap[ansList[i].uid];
            tmpAnswer += "님이 나갔습니다.";
        }
        answer.push_back(tmpAnswer);
    }

    return answer;
}
int main()
{
    vector<string> record{"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"};
    solution(record);
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << ' ';
    }
    return 0;
}