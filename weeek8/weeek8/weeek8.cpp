//#include <set>
//#include <vector>
//#include <unordered_map>
//#include <algorithm>
//
//using namespace std;
//
//set<pair<int, int>> twoSum(vector<int>& weights, unordered_map<int, int>& weightsMap,
//    int kilosWanted) {
//    set<pair<int, int>> answer;
//
//    for (int i = 0; i < weights.size(); i++) {
//        int current = weights[i];
//        int complement = kilosWanted - current;
//
//        if (weightsMap.count(complement)) {
//            int first = i;
//            int second = weightsMap[complement];
//
//            if (first > second)
//                swap(first, second);
//
//            answer.insert({ first, second });
//        }
//    }
//
//    return answer;
//}
//
//vector<vector<int>> threeSum(vector<int>& nums) {
//    set<vector<int>> answer;
//    unordered_map<int, int> weightsMap;
//    for (int i = 0; i < nums.size(); i++)
//        weightsMap.insert({ nums[i], i });
//
//    for (int i = 0; i < nums.size(); i++) {
//        set<pair<int, int>> validPairs = twoSum(nums, weightsMap, -nums[i]);
//
//        for (const auto& pair : validPairs) {
//            int firstIndex = pair.first;
//            int secondIndex = pair.second;
//
//            if (firstIndex != i && secondIndex != i &&
//                firstIndex != secondIndex) {
//                vector<int> current = { nums[firstIndex], nums[secondIndex],
//                                       nums[i] };
//                sort(current.begin(), current.end());
//                answer.insert(current);
//            }
//        }
//    }
//
//    vector<vector<int>> res(answer.begin(), answer.end());
//
//    return res;
//}
//
//// vector<vector<int>> threeSum(vector<int>& nums) {
////     vector<vector<int>> answer;
//
////     for (int i = 0; i < nums.size(); i++) {
////         vector<pair<int, int>> validPairs = twoSum(nums, -nums[i]);
//
////         for (int j = 0; j < validPairs.size(); j++) {
////             if (validPairs[j].first != i && validPairs[j].second != i &&
////                 validPairs[j].second != validPairs[j].first)
////                 answer.push_back({nums[validPairs[j].first],
////                                   nums[validPairs[j].second], nums[i]});
////         }
////     }
//
////     return answer;
//// }
//
//
//
