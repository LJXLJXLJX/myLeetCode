//
// Created by ljx on 19-1-25.
//

#include "minimum_number_of_refueling_stops.h"

using namespace std;


//https://www.youtube.com/watch?v=vWTPA5zw24M


//solution 1 : dp ,time O(n^2) , space O(n)
// reference : https://blog.csdn.net/u013445530/article/details/40210587

//int minRefuelStops(int target, int startFuel, std::vector<std::vector<int>> &stations) {
//    vector<long> dp(stations.size() + 1, 0);
//    dp[0] = startFuel;
//    for (int i = 0; i < stations.size(); ++i)
//        for (int t = i; t >= 0; --t)
//            if (dp[t] >= stations[i][0])
//                dp[t + 1] = max(dp[t + 1], dp[t] + (long) stations[i][1]);
//    for (int i = 0; i <= stations.size(); ++i)
//        if (dp[i] >= target)return i;
//    return -1;
//}

//*********************************************


//solution 2: Priority Queue
int minRefuelStops(int target, int cur, vector<vector<int>> s) {
    int i = 0, res;
    priority_queue<int> pq;
    for (res = 0; cur < target; res++) {
        while (i < s.size() && s[i][0] <= cur)
            pq.push(s[i++][1]);
        if (pq.empty()) return -1;
        cur += pq.top(), pq.pop();
    }
    return res;
}