/* There are a total of n courses you have to take, labeled from 0 to n-1.
 * Some courses may have prerequisites, for example to take course 0 you
 * have to first take course 1, which is expressed as a pair: [0,1].
 *
 * Given the total number of courses and a list of prerequisite pairs,
 * return the ordering of courses you should take to finish all courses.
 *
 * There may be multiple correct orders, you just need to return one of
 * them. If it is impossible to finish all courses, return an empty array.
 *
 * Runtime: 28 ms, faster than 55.33% of C++ online submissions.
 * Memory usage: 11.8 MB, less than 100.00% of C++ online submissions.
 */

const int NOT_VISITED = 0;
const int BEING_VISITED = 1;
const int DONE_VISITING = 2;
    
void dfs(const std::vector<std::vector<int>> &graph, int i,
         std::vector<int> &visited, std::stack<int> &rpo, bool &cycle) {
  if (cycle) return;
  
  visited[i] = BEING_VISITED;
  for (int neighbor : graph[i]) {
    if (visited[neighbor] == BEING_VISITED)
      cycle = true;
    if (visited[neighbor] == NOT_VISITED)
      dfs(graph, neighbor, visited, rpo, cycle);
  }
  
  visited[i] = DONE_VISITING;
  rpo.push(i);
}
    
std::vector<int>
findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites) {
  std::vector<std::vector<int>> graph(numCourses);
  for (int i = 0; i < numCourses; ++i) graph[i] = {};
  
  for (auto &pair : prerequisites)
    graph[pair[1]].push_back(pair[0]);
  
  std::vector<int> visited(numCourses, NOT_VISITED);
  std::stack<int> rpo;
  bool cycle = false;
  
  for (int i = 0; i < numCourses; ++i) {
    if (!visited[i])
      dfs(graph, i, visited, rpo, cycle);
  }
  
  if (cycle) return {};
  
  std::vector<int> sched;
  while (!rpo.empty()) {
    sched.push_back(rpo.top());
    rpo.pop();
  }
  return sched;
}
