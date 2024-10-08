/* 
    BFS�����·��
 */
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define syc cin.tie(0)->sync_with_stdio(false)
const int md = 1e9+7;

int ans;
string from, to;
vector<pair<string,string>> mp; //ӳ������
unordered_map<string,bool> vis;  //��ֹ����

struct node
{
    string s;
    int cnt;
};

//BFS�ж����·��
void bfs(string& str) {
    queue<node> que;
    que.push({str,0});
    vis[str] = 1;

    while (!que.empty()) {
        node cur = que.front();
        //cout << cur.s << endl;
        if (cur.cnt > 10) {
            cout << "NO ANSWER!" << endl;
            return;
        }

        if (cur.s == to) {
            cout << cur.cnt << endl;
            return;
        }

        for (auto &&[ori,cha] : mp)
        {
            //����ÿ���任,ȡint,δ���ҵ�����-1
            int index = 0;
            while (cur.s.find(ori,index) != -1) {
                index = (int)cur.s.find(ori,index);
                
                string tmp = cur.s;
                tmp.replace(index,ori.size(),cha);
                //cout << change << " " << (vis.find(change) != vis.end()) << endl;
                // ����������仰�Ǵ����
                // if (vis.find(tmp) != vis.end())
                //     break;

                // ����ؼ���������????
                if (vis.find(tmp) == vis.end()) {
                    que.push({tmp,cur.cnt+1});
                    vis[tmp] = 1;
                }

                index += ori.size();
                //cout << index << endl;
            }
        }
        //cout << "done" << endl;
        que.pop();
    }

    cout << "NO ANSWER!" << endl;
}

int main(int argc, char const *argv[])
{
    /* 
        abcd xyz
        3
        abc xu
        ud y
        y yz
     */
    cin >> from >> to;
    string ori, cha;
    while (cin >> ori >> cha) {
        mp.push_back({ori,cha});
    }

    bfs(from);    

    system("pause");
    return 0;
}


