double findMaxAverage(int* nums, int numsSize, int k) {
  double sum = 0;
  for (int i = 0; i < k; i++) {
    sum += nums[i];
  }
  double res = sum;
  for (int i = 0; i < numsSize - k; i++) {
    sum += nums[k + i];
    sum -= nums[i];
    if (res < sum) res = sum;
  }
  return res / k;
}