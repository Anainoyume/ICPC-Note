/* 
    �߾��ȼӷ���
    �����ڴ���һЩ�����ݵ�ʱ�򣬳�������ݽṹ��������unsigned long longҲ�����������ǵ������ʱ��
    ���Ǿ���Ҫ�Լ�ʵ�ִ����ݵĸ߾��ȼӷ�

    ԭ��ܼ򵥣�����ģ����ʽ�ӷ�����λ������ӣ���ʮ��һ
    ע����������ӵ�ʱ���ǴӸ�λ��ʼ�ӣ��������ǵ�����Ҫ��������ͬ�������ʱ��Ҳ�ǵ������

    �������£�
 */
#include <bits/stdc++.h>
using namespace std;

int a[5010], b[5010], result[5010]; //Ԥ����5010λ����

void hp(string& strA, string& strB) {
    int len = max(strA.size(),strB.size());    //��ʾ���ֵ�λ��
    //������������
    for (int i = 0; i < strA.size(); i++)
    {
        a[strA.size()-1-i] = strA[i] - '0';
    }
    for (int i = 0; i < strB.size(); i++)
    {
        b[strB.size()-1-i] = strB[i] - '0';
    }

    //���Ĵ��룬���
    for (int i = 0; i < len; i++)
    {
        result[i] += a[i] + b[i];
        result[i+1] = result[i]/10;
        result[i] %= 10;
    }
    
    if (result[len]) len++; //�������־ͳ��ȼ�һ

    //�������
    for (int i = len-1; i >= 0; i--)
    {
        cout << result[i];
    }
    cout << endl;
    
}

int main(int argc, char const *argv[])
{
    string strA, strB;  //�������ֵ��ַ���
    strA = "249759387198273897154892772";
    strB = "9734874871289274783275223";

    hp(strA,strB);
    
    
    system("pause");
    return 0;
}


