//邻接矩阵
/* 
    邻接矩阵只适用于没有重边（或重边可以忽略）的情况。
    其最显著的优点是可以 O(1) 查询一条边是否存在。
    由于邻接矩阵在稀疏图上效率很低（尤其是在点数较多的图上，
    空间无法承受），所以一般只会在稠密图上使用邻接矩阵。
 */
#include <iostream>
#include <vector>
#include <limits>
using namespace std;

void Floyd_Warshall(vector<vector<int>>& Graph, int size) {
    //务必保证传入的图是已经初始化好了的
    for (int i = 0; i < size; i++)  //vi是我们借助的点
    {
        //表示借助 v_i 到达其他点，注意我们的 v1下标改为从v0开始
        for (int j = 0; j < size; j++)
        {
            //如果是本身，则跳过当前轮，不必借助自己
            if (i == j)
                continue;
            //检查当前点是否连通vi，如果不能连通则跳过
            if (Graph[j][i] == INT_MAX)
                continue;
            else {
                for (int k = 0; k < size; k++)
                {
                    //开始当前轮计算，借助点到达本身不考虑
                    if (j == k)
                        continue;
                    else if (Graph[i][k] == INT_MAX)    //如果借助的点也不能到达其他点，则跳过
                        continue;
                    else {
                        Graph[j][k] = min(Graph[j][i]+Graph[i][k],Graph[j][k]);
                    }
                }
                
            }
        }
        
    }
}

int main(int argc, char const *argv[])
{
    //Floyd-Warshall多源最短路径算法
    //可以处理负边，但仍然无法处理负环
    /* 
        多源的意思：相对于单源，单源就是一次求一个顶点到所有点的最短路径
        而多源就是一次性求所有顶点到其他顶点的最短路径

        该图参考Graph01.png

        k = 0; 初始化阶段，表示直接联通的部分
            v1  v2  v3  v4
        v1  0   ∞   -2  ∞
        v2  4   0   3   ∞
        v3  ∞   ∞   0   2
        v4  ∞   -1  ∞   0    

        k = 1; 借助 v1 到达其他顶点
            v1  v2  v3  v4
        v1  0   ∞   -2  ∞   //v1借助自己到达其他结点，不考虑
        v2  4   0   2   ∞   //v2->v1 为 4，再考虑v1这一行，到达v1不变，到v2本身不考虑，到v3 4-2 = 2 < 3，更新长度，至于v4，v1->v4没有通路，因此还是∞
        v3  ∞   ∞   0   2   //v3与v1不连通，因此不能借助v1到达其他结点，不考虑
        v4  ∞   -1  ∞   0   //与v3同理

        k = 2; 借助 v2
            v1  v2  v3  v4
        v1  0   ∞   -2  ∞      //v1到不了v2，不考虑
        v2  4   0   2   ∞      //本身不变
        v3  ∞   ∞   0   2      //不能到v2，不考虑
        v4  3   -1  1   0      //更新

        k = 3; 借助 v3
            v1  v2  v3  v4
        v1  0   ∞   -2  0   //更新      
        v2  4   0   2   4   //更新      
        v3  ∞   ∞   0   2   //本身跳过   
        v4  3   -1  1   0   //更新      

        k = 4; 借助 v4
            v1  v2  v3  v4
        v1  0   -1  -2  0   //更新      
        v2  4   0   2   4   //更新      
        v3  5   1   0   2   //更新   
        v4  3   -1  1   0   //不动  
        这样，所有的最短路径，都计算完毕了
     */

    //由于弗洛伊德算法借助邻接矩阵，因此在此处实现
    //先创建图
    vector<vector<int>> Graph = {
        {0, INT_MAX, -2, INT_MAX},
        {4, 0, 3, INT_MAX},
        {INT_MAX, INT_MAX, 0, 2},
        {INT_MAX, -1, INT_MAX, 0}
    };

    Floyd_Warshall(Graph,4);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    
    system("pause");
    return 0;
}
