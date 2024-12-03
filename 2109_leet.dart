import 'dart:math';

class Solution {
  String addSpaces(String s, List<int> spaces) {
    StringBuffer resulting = StringBuffer();
    int listI = 0;

    for (int stringI = 0; stringI < s.length; stringI++) {
      if (stringI == spaces[listI]) {
        resulting.write(" ");

        listI = min(listI + 1, spaces.length - 1);
      }
      resulting.write(s[stringI]);
    }

    return resulting.toString();
  }
}
