class Solution {
  int minDistance(String word1, String word2) {
    int m = word1.length;
    int n = word2.length;

    List<List<int>> matrix = List.generate(m + 1, (_) => List.filled(n + 1, 0));

    for (int i = 0; i <= m; i++) {
      matrix[i][0] = i;
    }
    for (int j = 0; j <= n; j++) {
      matrix[0][j] = j;
    }

    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          matrix[i][j] = matrix[i - 1][j - 1];
        } else {
          matrix[i][j] = 1 +
              [matrix[i - 1][j], matrix[i][j - 1], matrix[i - 1][j - 1]]
                  .reduce((a, b) => a < b ? a : b);
        }
      }
    }

    return matrix[m][n];
  }
}
