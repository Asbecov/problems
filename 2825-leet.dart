class Solution {
  static const String alphabet = "abcdefghijklmnopqrstuvwxyza";

  bool canMakeSubsequence(String str1, String str2) {
    if (str1.length < str2.length) return false;

    int len1 = 0;
    int len2 = 0;

    int str1Has = 0;

    while (len1 < str1.length) {
      final String curChar = str1[len1];
      final String modifiedCurChar = alphabet[alphabet.indexOf(str1[len1]) + 1];
      final int oldStr1Has = str1Has;

      while (len2 < str2.length) {
        final String curChar2 = str2[len2++];

        if (curChar == curChar2 || modifiedCurChar == curChar2) {
          ++str1Has;
          break;
        }
      }

      if (len2 == str2.length && oldStr1Has == str1Has) {
        len2 = 0;
      }

      ++len1;
    }

    return str1Has >= str2.length;
  }
}
