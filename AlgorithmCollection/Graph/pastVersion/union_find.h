//实现并查集
class UnionFind
{
public:
    int *set;   //集合
    int *cnt;   //成员个数
    int size = 0;   //大小

    UnionFind(int size) {
        this->size = size;
        set = new int[size];
        cnt = new int[size];
        //直接赋值
        for (int i = 0; i < size; i++)
        {
            set[i] = i;
        }
    }

    //判断是否属于同一个集合
    int find(int a) {
        //return set[a] == a ? a : find(set[a]);
        return set[a] == a ? a : set[a] = find(set[a]); //路径压缩
        //find的同时更新指向，节约下一次的查询效率
    }

    //合并
    void Union(int a, int b) {
        //一定要修改最底层合并的那个数值，要不然重新合并已经合并过的集合可能会出错
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

