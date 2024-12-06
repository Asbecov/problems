import 'dart:collection';

class Solution {
  int minimumPushes(String word) {
    Map<String, int> uniqueLetters = <String, int>{};

    word.runes.forEach((val) {
      String char = String.fromCharCode(val);
      if (uniqueLetters[char] == null)
        uniqueLetters[char] = 1;
      else
        uniqueLetters[char] = uniqueLetters[char]! + 1;
    });

    final List<String> orderedKeys = uniqueLetters.keys.toList(growable: false)
      ..sort(
          (key1, key2) => uniqueLetters[key2]!.compareTo(uniqueLetters[key1]!));
    final LinkedHashMap<String, int> orderedUniqueLetters =
        LinkedHashMap.fromIterable(orderedKeys,
            key: (key) => key, value: (key) => uniqueLetters[key]!);

    int numPush = 0;
    int lettersProcessed = 0;

    for (String i in orderedUniqueLetters.keys.toList(growable: false)) {
      ++lettersProcessed;

      numPush +=
          (orderedUniqueLetters[i]! * (lettersProcessed / 8).ceil()).toInt();
    }

    return numPush;
  }
}
