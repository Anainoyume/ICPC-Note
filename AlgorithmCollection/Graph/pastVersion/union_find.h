//ʵ�ֲ��鼯
class UnionFind
{
public:
    int *set;   //����
    int *cnt;   //��Ա����
    int size = 0;   //��С

    UnionFind(int size) {
        this->size = size;
        set = new int[size];
        cnt = new int[size];
        //ֱ�Ӹ�ֵ
        for (int i = 0; i < size; i++)
        {
            set[i] = i;
        }
    }

    //�ж��Ƿ�����ͬһ������
    int find(int a) {
        //return set[a] == a ? a : find(set[a]);
        return set[a] == a ? a : set[a] = find(set[a]); //·��ѹ��
        //find��ͬʱ����ָ�򣬽�Լ��һ�εĲ�ѯЧ��
    }

    //�ϲ�
    void Union(int a, int b) {
        //һ��Ҫ�޸���ײ�ϲ����Ǹ���ֵ��Ҫ��Ȼ���ºϲ��Ѿ��ϲ����ļ��Ͽ��ܻ����
        set[find(b)] = set[find(a)];
    }

    bool query(int a, int b) {
        return find(a) == find(b);
    }

    void count() {
        for (int i = 0; i < size; i++) cnt[i] = 0;
        for (int i = 0; i < size; i++)
            cnt[find(i)]++;
    }
    
};

