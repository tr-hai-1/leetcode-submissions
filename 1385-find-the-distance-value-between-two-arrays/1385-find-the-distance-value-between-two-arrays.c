int findTheDistanceValue(int* arr1, int arr1Size, int* arr2, int arr2Size, int d) {
  int stop;
  int res = 0;
  for (int i = 0; i < arr1Size; i++) {
    stop = 0;
    for (int j = 0; j < arr2Size; j++) {
      if (abs(arr1[i] - arr2[j]) <= d) {
        stop = 1;
        break;
      }
    }
    if (stop) continue;
    else res++;
  }    
  return res;
}