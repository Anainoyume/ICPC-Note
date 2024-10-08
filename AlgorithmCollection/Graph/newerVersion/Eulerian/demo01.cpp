#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e4+5;

// Hierholzer�㷨 (�𲽲����·��) ���Ӷ� O(n+m)
// �����Ҫ����ֵ�����С��ŷ��·��ŷ����·�Ļ�����Ϊ��Ҫ��������
// ��ͼ��ɫ���⣺��������ٵ���ɫ����ͼ�ϵ�����������ɫ��ʹ������������ɫ��ͬ��


bool edges[maxN][maxN];
// �������ڽӱ���ʱߵ�ʱ������˳��ģ�Ϊ�˼�¼������һ�η��ʵ��������ˣ����ǿ���ʹ�� st ����¼��һ�η��ʵ���
// ���һ���ߣ��ӿ����ǵĲ�ѯ�ٶ�
int deg[maxN], st[maxN];
int n, m;

int node[maxN]; //���ֵ

stack<int> ans;
void Hierholzer(int cur)
{
    for (int i = 1; i <= n; i++) {
        if (edges[cur][i]) {
            edges[cur][i] = false;
            edges[i][cur] = false;
            Hierholzer(i);
        }
    }
    ans.push(node[cur]);
}

void print() {
    while (!ans.empty()) {
        cout << ans.top() << " ";
        ans.pop();
    }
    cout << endl;
}


signed main()
{
    // �ȼ������е�����
    // �����Ϊ 2 ��ʱ��ָ�� ��� Ϊ��㣬Ϊ 0 ʱ������ָ�����

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> node[i];
    }

    for (int i = 1; i <= m; ++i) {
        int from, to;
        cin >> from >> to;
        edges[from][to] = true;
        edges[to][from] = true;

        deg[from] += 1;
        deg[to] += 1;
    }

    int deg1 = 0, bg = -1;
    for (int i = 1; i <= n; ++i) {
        if (deg[i] & 1) {
            bg = i;
            deg1 += 1;
        }
    }

    // ������ŷ����·
    if (deg1 != 0 && deg1 != 2) {
        cout << -1 << endl;
    }

    if (deg1 == 0) {
        // ֻ��ż����
        Hierholzer(1);
        print();
    }
    else { 
        //�����������
        Hierholzer(bg);
        print();
    }


    system("pause");
    return 0;
}