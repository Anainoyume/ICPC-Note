#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define syc cin.tie(0)->sync_with_stdio(false);
const int md = 1e9 + 7;

int l, r;

int a[19]; // ��λ����
int f[19][100000];  //��¼����
// ��ʾ[pos+1,len]�Ѿ���д���ˣ�������λ��Ϊsum
// �������ǵ�[1,len]���������
// f[pos][sum]Ϊ����Լ��������������λ��֮��

// posΪ��ǰ��λ��λ�ã����Ǵ����λ��ʼ
/*
    �������ǵ�����Ϊ 4132
    2   3   1   4
    1   2   3   4 = len

    ��˴�len��ʼ
 */

//ʵ�ʼ��㻹��һ�㺬���Ǳ���
/* 
    ��������Ҫ�� 0 ~ 4132

    ��0Ϊǰ׺��������������ֵ���λ��
    0   �൱�ڽ���һά

    1 ��1Ϊǰ׺��������������ֵ���λ�ͣ�Ҳ���� 1000 ~ 1999

    2 ͬ��

    3

    4

    ����������Ѿ�ȷ���� 1???
    ������ѡ��

    ���� 12??
    ���� 1200 ~ 1299

    ��ѡ����� 127?
    ����1270 ~ 1279

    �൱��һ�����ĳ����չ�������Ӻͣ������仯������˼·����

    ���� 3100 ~ 3199
    �� 2200 ~ 2299
    �� 1300 ~ 1399

    ���ǻᷢ�֣����治����ôѡ�����һ���ģ���Ϊǰ2λ�ļӺ�Ϊ4���Ѿ�ȷ���ˣ����涼��00~99����ѡ��
    ���һ�£�������ǿ����������������ǵ�״̬
 */
LL dfs(int pos, bool limit, int sum)
{
    if (!pos) // �ݹ�߽�
        return sum;
    // ~ ��λȡ�����������ǵ�f��ʼ��Ϊ-1��~(-1)=0 ��ʾ��û����
    // ����ĺ������dp�Ѿ���������
    if (!limit && ~f[pos][sum]) // û���Ʋ���dpֵ��������
        return f[pos][sum];
    int up = limit ? a[pos] : 9;    //limit����������
    //������������ֻ��Ϊa[pos]���������ȡ��0~9
    LL res = 0;
    for (int i = 0; i <= up; i++)
        res = (res + dfs(pos - 1, limit && (i == up), sum + i)) % md;
    if (!limit) // ���ѣ��ɸ���
        f[pos][sum] = res;
    return res;
}

LL solve(LL x)
{
    int len = 0;
    while(x > 0)
    {
        a[++ len] = x % 10;
        x /= 10;
    }
    return dfs(len, true, 0); //��ʼ״̬�������Ϊlen֮ǰȫ����ǰ��0����
}

int main(int argc, char const *argv[])
{
    int t = 0;
    cin >> t;
    memset(f,-1,sizeof(f)); //Ҫ��ʼ��Ϊ-1
    while (t--)
    {
        LL l, r;
        cin >> l >> r;
        cout << (solve(r)-solve(l-1)+md)%md << endl;
    }
    

    system("pause");
    return 0;
}
