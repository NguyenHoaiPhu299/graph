#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int edge, point;
vector<int> adj[1001];
bool visited[1001] = {false};

void Use_Vector_Change_EdgeList_AdjacencyList()
{
    cin >> edge >> point;
    for (int i = 1; i <= edge; i++)
    {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x); // Trong do thi vo huong thi bo dong nay
    }
    // memset(visited, false, sizeof(visited));
}

void BFS(int u)
{
    // Step 1: Khoi tao
    // Tao mot hang doi rong
    queue<int> q;
    q.push(u); // Day dinh u vao hang doi
    visited[u] = true; // Danh dau da tham dinh u

    // Step 2: Lap khi hang doi van con phan tu
    while (!q.empty())
    {
        int v = q.front(); // Lay ra dinh dau hang doi
        q.pop(); // Xoa dinh khoi dau hang doi
        cout << v << " "; // Tham dinh v

        // Duyet cac dinh ke voii v ma chua duoc tham va day vao hang doii
        for (int x : adj[v])
        {
            if (!visited[x]) // Neu x chua duoc tham
            {
                q.push(x);
                visited[x] = true;
            }
        }
    }

}

int main()
{
    Use_Vector_Change_EdgeList_AdjacencyList();
    BFS(1);
    return 0;
}
/*
10 11
1 2
1 3
1 5
1 10
2 4
3 6
3 7
3 9
6 7
5 8
8 9
*/

/*
10 11
1 2
1 3
1 10
2 4
3 5
3 6
5 8
5 10
6 7
7 3
8 9
*/
