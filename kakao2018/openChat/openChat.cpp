#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

typedef struct
{
    string uid;
    int act; // 1-> Enter // 2-> Out
} Ans;

map<string, string> userMap;
vector<string> answer;
vector<string> solution(vector<string> record)
{

    vector<Ans> ansList;

    for (int i = 0; i < record.size(); i++)
    {

        string nUid;
        string nNickName;
        int nAct;
        int j;
        switch (record[i][0]) // Enter or Leave or Change
        {
        case 'E':
            j = 6;
            while (record[i][j] != ' ')
            {
                nUid += record[i][j]; // 더 알아보기
                j++;
            }
            j++;
            while (record[i][j] != '\0')
            {
                nNickName += record[i][j];
                j++;
            }
            nAct = 1;
            break;
        case 'L':
            j = 6;
            while (record[i][j] != '\0')
            {
                nUid += record[i][j]; // 더 알아보기
                j++;
            }

            nAct = 2;
            break;
        case 'C':
            j = 7;
            while (record[i][j] != ' ')
            {
                nUid += record[i][j]; // 더 알아보기
                j++;
            }
            j++;
            while (record[i][j] != '\0')
            {
                nNickName += record[i][j];
                j++;
            }
            nAct = 0;
            break;
        default:
            break;
        }
        if (nAct != 2) // 이걸 안해줘서 틀렸다.
            userMap[nUid] = nNickName;
        if (nAct == 0)
            continue;
        ansList.push_back({nUid, nAct});
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