class Solution {
  bool isValid(String s) {
    if (s.length % 3 == 0) {
      List<String> chars = <String>[];

      for (int i = 0; i < s.length; i++) {
        if (s[i] == "a") {
          chars.add(s[i]);
        } else if (s[i] == "b" && chars.isNotEmpty && chars.last == "a") {
          chars.add(s[i]);
        } else if (s[i] == "c" && chars.isNotEmpty && chars.last == "b") {
          chars.removeLast();
          chars.removeLast();
        } else
          return false;
      }

      return chars.isEmpty;
    } else
      return false;
  }
}
