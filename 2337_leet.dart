class Solution {
  bool canChange(String start, String target) {
    int startWaiting = 0;
    int targetWaiting = 0;

    for (int index = 0; index < start.length; index++) {
      switch ((start[index], target[index])) {
        case (String, String) pair when pair.$1 == pair.$2:
          if (pair.$1 == "L" && targetWaiting != 0) {
            return false;
          } else if (pair.$1 == "R" && startWaiting != 0) {
            return false;
          }
          break;
        case ("_", "L"):
          if (targetWaiting == 0) {
            ++startWaiting;
            break;
          }

          return false;
        case ("L", "_"):
          if (startWaiting != 0) {
            --startWaiting;
            break;
          }

          return false;
        case ("R", "_"):
          if (startWaiting == 0) {
            ++targetWaiting;
            break;
          }

          return false;
        case ("_", "R"):
          if (targetWaiting != 0) {
            --targetWaiting;
            break;
          }

          return false;
        default:
          return false;
      }
    }

    return startWaiting == 0 && targetWaiting == 0;
  }
}
