#include<iostream>
#include<queue>


void BFS(int vtx, int A[][8], int n)
{
   using namespace std;
   queue<int> Q;
   int visited[8]{ 0 };

   //Initial
   cout << vtx << " , ";
   visited[vtx] = 1;
   Q.emplace(vtx);

   //Explore
   while (!Q.empty()) {
      int u = Q.front();   // Vertex u for exploring
      Q.pop();
      for (int v = 1; v <= n; v++) {
         if (A[u][v] == 1 && visited[v] == 0) { //Adjacent vertex and not visited
            cout << v << " , ";
            visited[v] = 1;
            Q.emplace(v);
         }
      }
   }
   cout << endl;
}

//int main()
//{
//   using namespace std;
//   int A[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
//                   {0, 0, 1, 1, 1, 0, 0, 0},
//                   {0, 1, 0, 1, 0, 0, 0, 0},
//                   {0, 1, 1, 0, 1, 1, 0, 0},
//                   {0, 1, 0, 1, 0, 1, 0, 0},
//                   {0, 0, 0, 1, 1, 0, 1, 1},
//                   {0, 0, 0, 0, 0, 1, 0, 0},
//                   {0, 0, 0, 0, 0, 1, 0, 0} };
//
//   cout << "Vertex: 1-> "; BFS(1, A, 8);
//   cout << "\nVertex: 4 -> "; BFS(4, A, 8);
//
//   return 0;
//}

