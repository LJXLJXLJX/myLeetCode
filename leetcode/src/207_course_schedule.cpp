#include "207_course_schedule.h"

using namespace std;


bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites) {
	//adj 为有向邻接表
	vector<vector<int>> adj(numCourses, vector<int>());
	//degree 为前驱数量表
	vector<int> degree(numCourses, 0);
	for (auto &p : prerequisites) {
		adj[p[1]].push_back(p[0]);
		degree[p[0]]++;
	}
	//q为无前驱节点的队列
	queue<int> q;
	for (int i = 0; i < numCourses; i++)
		if (degree[i] == 0) q.push(i);
	while (!q.empty()) {
		int curr = q.front(); q.pop(); numCourses--;
		for (auto next : adj[curr])
			if (--degree[next] == 0) q.push(next);
	}
	return numCourses == 0;
}

// 拓扑排序 这种实现效率似乎较低
//bool canFinish(int numCourses, std::vector<std::vector<int>>& prerequisites)
//{
//	vector<vector<int>> mat(numCourses, vector<int>(numCourses));
//	for (auto p : prerequisites) {
//		int i = p[0];
//		int j = p[1];
//		mat[i][j] = 1;
//	}
//
//	vector<int>row_sum(numCourses);
//	for (int i = 0; i < numCourses; ++i) {
//		for (int j = 0; j < numCourses; ++j) {
//			row_sum[i] += mat[i][j];
//		}
//	}
//	vector<int>col_sum(numCourses);
//	for (int j = 0; j < numCourses; ++j) {
//		for (int i = 0; i < numCourses; ++i) {
//			col_sum[j] += mat[i][j];
//		}
//	}
//
//	bool has_node_without_pre = true;
//	while (has_node_without_pre) {
//		has_node_without_pre = false;
//		for (int n = 0; n < numCourses; ++n) {
//			if (col_sum[n] == 0) {
//				if (row_sum[n] == 0)
//					continue;
//				else {
//					has_node_without_pre = true;
//					int i = n;
//					for (int j = 0; j < numCourses; ++j) {
//						if (mat[i][j] == 1) {
//							mat[i][j] = 0;
//							row_sum[i]--;
//							col_sum[j]--;
//						}
//					}
//				}
//			}
//		}
//	}
//
//	int sum = 0;
//	for (auto i : col_sum)
//		sum += i;
//
//	return sum == 0;
//}
