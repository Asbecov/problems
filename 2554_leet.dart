class Solution {
  int maxCount(List<int> banned, int n, int maxSum) {
    Map<int, bool> bannedMap = <int, bool>{};

    banned.forEach((val) => bannedMap[val] = true);

    int maxNum = 0;
    int curSum = 0;

    for (int i = 1; i <= n; i++) {
      if (bannedMap[i] ?? false) {
        continue;
      } else if (curSum + i > maxSum) {
        return maxNum;
      } else {
        ++maxNum;
        curSum += i;
      }
    }

    return maxNum;
  }
}
