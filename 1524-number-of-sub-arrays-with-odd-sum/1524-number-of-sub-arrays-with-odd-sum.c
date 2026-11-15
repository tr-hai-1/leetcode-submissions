const int MOD = 1e9 + 7;
int numOfSubarrays(int* arr, int arrSize) {
  int currOdd = 0, currEven = 0, prevOdd = 0, prevEven = 0, res = 0;
  for (int i = 0; i < arrSize; i++) {
    prevOdd = currOdd, prevEven = currEven;
    if (arr[i] % 2 == 1) {
      currOdd = (1 + prevEven) % MOD;
      currEven = prevOdd;
    } else {
      currEven = (1 + prevEven) % MOD;
      currOdd = prevOdd;
    }
    res = (res + currOdd) % MOD;
  }
  return res;
}