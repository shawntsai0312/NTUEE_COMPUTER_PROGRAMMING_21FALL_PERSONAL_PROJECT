#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iomanip>

using namespace std;

const string hiragana[46] = {"あ", "い", "う", "え", "お", "か", "き", "く", "け", "こ", "さ", "し", "す", "せ", "そ", "た", "ち", "つ", "て", "と", "な", "に", "ぬ", "ね", "の", "は", "ひ", "ふ", "へ", "ほ", "ま", "み", "む", "め", "も", "や", "ゆ", "よ", "ら", "り", "る", "れ", "ろ", "わ", "を", "ん"};
const string katakana[46] = {"ア", "イ", "ウ", "エ", "オ", "カ", "キ", "ク", "ケ", "コ", "サ", "シ", "ス", "セ", "ソ", "タ", "チ", "ツ", "テ", "ト", "ナ", "二", "ヌ", "ネ", "ノ", "ハ", "ヒ", "フ", "ヘ", "ホ", "マ", "ミ", "ム", "メ", "モ", "ヤ", "ユ", "ヨ", "ラ", "リ", "ル", "レ", "ロ", "ワ", "ヲ", "ン"};
const string spelling[46] = {"a", "i", "u", "e", "o", "ka", "ki", "ku", "ke", "ko", "sa", "shi", "su", "se", "so", "ta", "chi", "tsu", "te", "to", "na", "ni", "nu", "ne", "no", "ha", "hi", "hu", "he", "ho", "ma", "mi", "mu", "me", "mo", "ya", "yu", "yo", "ra", "ri", "ru", "re", "ro", "wa", "o", "n"};

void random_order(vector<int> *a, int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        int x = rand() % n;
        int temp = a->at(i);
        a->at(i) = a->at(x);
        a->at(x) = temp;
    }
}

int main()
{
    bool end_or_conti;
    do
    {
        cout << "請選擇模式，只要平假名輸入1，只要片假名輸入2，兩者都要輸入3" << endl;
        int mode;
        cin >> mode;
        while (mode != 1 && mode != 2 && mode != 3)
        {
            cout << "請重新輸入有效數字，只要平假名輸入1，只要片假名輸入2，兩者都要輸入3" << endl;
            cin >> mode;
        }

        cout << "請輸入要測驗多少題?" << endl;
        int problem_n;
        cin >> problem_n;

        vector<int> problem;
        for (int i = 0; i < 46; i++)
            problem.push_back(i);

        int correct_n = 0;
        vector<int> wrong;

        random_order(&problem, problem.size());

        switch (mode)
        {
        case 1:
        {
            for (int i = 0; i < problem_n; i++)
            {
                string ans;
                cout << "第" << setw(2) << i + 1 << "題:" << hiragana[problem[i]] << "?" << endl;
                cin >> ans;
                int ans_pos;
                for (int j = 0; j < 46; j++)
                {
                    if (ans == spelling[j])
                    {
                        ans_pos = j;
                        break;
                    }
                }
                if (ans_pos == problem[i])
                    correct_n += 1;
                else
                    wrong.push_back(i);
            }
            cout << "答錯的題目有" << endl;
            for (int i = 0; i < wrong.size(); i++)
            {
                cout << "第" << setw(2) << wrong[i] + 1 << "題:" << hiragana[problem[wrong[i]]]
                     << "應為" << spelling[problem[wrong[i]]] << endl;
            }
            break;
        }
        case 2:
        {
            for (int i = 0; i < problem_n; i++)
            {
                string ans;
                cout << "第" << setw(2) << i + 1 << "題:" << katakana[problem[i]] << "?" << endl;
                cin >> ans;
                int ans_pos;
                for (int j = 0; j < 46; j++)
                {
                    if (ans == spelling[j])
                    {
                        ans_pos = j;
                        break;
                    }
                }
                if (ans_pos == problem[i])
                    correct_n += 1;
                else
                    wrong.push_back(i);
            }
            cout << "答錯的題目有" << endl;
            for (int i = 0; i < wrong.size(); i++)
            {
                cout << "第" << setw(2) << wrong[i] + 1 << "題:" << katakana[problem[wrong[i]]]
                     << "應為" << spelling[problem[wrong[i]]] << endl;
            }
            break;
        }
        case 3:
        {
            int state;
            vector<int> wrong_state;
            for (int i = 0; i < problem_n; i++)
            {
                string ans;
                state = rand() % 2;
                if (state == 0)
                    cout << "第" << setw(2) << i + 1 << "題:" << hiragana[problem[i]] << "?" << endl;
                else
                    cout << "第" << setw(2) << i + 1 << "題:" << katakana[problem[i]] << "?" << endl;
                cin >> ans;
                int ans_pos;
                for (int j = 0; j < 46; j++)
                {
                    if (ans == spelling[j])
                    {
                        ans_pos = j;
                        break;
                    }
                }
                if (ans_pos == problem[i])
                    correct_n += 1;
                else
                {
                    wrong.push_back(i);
                    wrong_state.push_back(state);
                }
            }
            if (wrong.size())
            {
                cout << "答錯的題目有" << endl;
                for (int i = 0; i < wrong.size(); i++)
                {
                    cout << "第" << setw(2) << wrong[i] + 1 << "題:";
                    if (wrong_state[i] == 0)
                    {
                        cout << hiragana[problem[wrong[i]]];
                    }
                    else
                    {
                        cout << katakana[problem[wrong[i]]];
                    }
                    cout << "應為" << spelling[problem[wrong[i]]] << endl;
                }
            }
            break;
        }
        }
        cout << "答對題數為" << setw(2) << correct_n << "，答對率為" << setw(5) << fixed
             << setprecision(2) << double(correct_n) / double(problem_n) * 100 << "%" << endl;
        cout << "是否要再進行一次，輸入0停止，輸入1繼續" << endl;
        cin >> end_or_conti;
    } while (end_or_conti);
    return 0;
}
