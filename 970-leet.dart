import 'dart:math';

class Solution {
  List<int> powerfulIntegers(int x, int y, int bound) {
    if (bound == 0) return [];

    final double lnBound = log(bound);
    late int maxPow;

    Map<int, bool> resulting = <int, bool>{};

    if (x != 1 || y != 1) {
      maxPow = (lnBound / log(min(x != 1 ? x : y, y != 1 ? y : x))).floor();
    } else
      maxPow = 0;

    for (int i = 0; i <= maxPow; i++) {
      for (int j = 0; j <= maxPow; j++) {
        final int result = (pow(x, i) + pow(y, j)).toInt().abs();

        if (result <= bound) resulting[result] = true;
        print(result);
      }
    }

    return resulting.keys.toList();
  }
}
