char c = []() {ios::sync_with_stdio(false); cin.tie(NULL); return 'c';}();//good
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> ans;
        using p = pair<pair<u_short, u_short>, int>;
        auto cmp = [](p a, p b) { return a.second > b.second; };
        priority_queue<p, vector<p>, decltype(cmp)> pq;

        pq.push({ {0, 0}, nums1[0] + nums2[0] });
        while (k--) {
            auto [P, sum] = pq.top(); pq.pop();

            ans.push_back({ nums1[P.first], nums2[P.second] });
            if (P.first + 1 < nums1.size()) {
                pq.push({ {P.first + 1, P.second},  nums1[P.first + 1] + nums2[P.second] });
            }
            if (P.first == 0 && P.second + 1 < nums2.size()) {// fucking magic
                pq.push({ {P.first, P.second + 1},  nums1[P.first] + nums2[P.second + 1] });
            }
        }

        return ans;
    }
};