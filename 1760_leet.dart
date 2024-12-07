class Solution {
  bool isPossible(List<int> num, int maxBallsInBag, int maxOperations) {
    int totalOperations = 0;

    for (int balls in num) {
      totalOperations += (balls / maxBallsInBag).ceil().toInt() - 1;

      if (totalOperations > maxOperations) return false;
    }

    return true;
  }

  int minimumSize(List<int> nums, int maxOperations) {
    int lowerBound = 1;
    int upperBound = 0;

    for (int numBalls in nums) {
      if (numBalls > upperBound) upperBound = numBalls;
    }

    while (lowerBound < upperBound) {
      final int middle = (lowerBound + upperBound) ~/ 2;

      if (isPossible(nums, middle, maxOperations)) {
        upperBound = middle;
      } else {
        lowerBound = middle + 1;
      }
    }

    return lowerBound;
  }
}

void main() {
  final Solution solution = Solution();

  print(solution.minimumSize([9], 2));
}
