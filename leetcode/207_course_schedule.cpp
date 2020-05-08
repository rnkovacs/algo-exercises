/* There are a total of numCourses courses you have to take, labeled from 0
 * to numCourses-1. Some courses may have prerequisites, for example to take
 * course 0 you have to first take course 1, which is expressed as a pair:
 * [0,1]. Given the total number of courses and a list of prerequisite pairs,
 * is it possible for you to finish all courses?
 *
 * Runtime: 44 ms, faster than 33.90% of C++ online submissions.
 * Memory usage: 15.2 MB, less than 30.91% of C++ online submissions.
 */

#include <unordered_map>
#include <unordered_set>
#include <vector>

bool dfs(std::unordered_map<int, std::vector<int>> &graph, int v,
         std::vector<bool> &marked, std::unordered_set<int> &path) {
  marked[v] = true;
  path.insert(v); // 1 0
  
  for (int w: graph[v]) {
    if (path.count(w))
      return false;

    if (!marked[w] && !dfs(graph, w, marked, path))
      return false;
  }

  path.erase(v);
  return true;
}
    
bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
  std::unordered_map<int, std::vector<int>> graph;
  
  for (std::vector<int> &pair: prerequisites) {
    if (!graph.count(pair[0])) {
      graph[pair[0]] = { pair[1] };
    } else {
      graph[pair[0]].push_back(pair[1]);
    }
  }
  
  std::vector<bool> marked(numCourses, false);
  std::unordered_set<int> path;
  
  for (auto &entry: graph) {
    int v = entry.first;
    if (!marked[v] && !dfs(graph, v, marked, path))
      return false;
  }
  
  return true;
}
