#include<iostream>
#include<stack>

void Recursive_DFS(int u, int A[][8], int n)
{
   static int visited[8]{ 0 };

   if (visited[u] == 0) {
      std::cout << u << " , ";
      visited[u] = 1;
      for (int v = 1; v < n; v++) {
         if (A[u][v] == 1 && visited[v] == 0) {
            Recursive_DFS(v, A, n);
         }
      }
   }
}

void DFS(int u, int A[][8], int n)
{
   int visited[8]{ 0 };
   std::stack<int> stk;
   stk.emplace(u);

   while (!stk.empty()) {
      u = stk.top();
      stk.pop();

      if (visited[u] == 0 ) {
         std::cout << u << " , ";
         visited[u] = 1;
         for (int v = n - 1; v >= 0; v--) {
            if (A[u][v] == 1 && visited[v] == 0) {
               stk.emplace(v);
            }
         }
      }
   }
}

int main()
{
   int A[8][8] = { {0, 0, 0, 0, 0, 0, 0, 0},
                  {0, 0, 1, 1, 1, 0, 0, 0},
                  {0, 1, 0, 1, 0, 0, 0, 0},
                  {0, 1, 1, 0, 1, 1, 0, 0},
                  {0, 1, 0, 1, 0, 1, 0, 0},
                  {0, 0, 0, 1, 1, 0, 1, 1},
                  {0, 0, 0, 0, 0, 1, 0, 0},
                  {0, 0, 0, 0, 0, 1, 0, 0} };

   std::cout << "Vertex: 1 -> " << std::flush;
   //Recursive_DFS(4, A, 8);
   DFS(1, A, 8);
   std::cout << std::endl;
   return 0;
}
