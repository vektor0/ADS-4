// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int p = 0;
  for (int i = 0; i < len; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value)
        p += 1;
    }
  }
  return p;
}
int countPairs2(int *arr, int len, int value) {
  int p = 0;
  int t;
  for (int i = len - 1; i >= 0; i--) {
    if (arr[i] > value) {
      continue;
    } else {
      t = i;
      break;
    }
  }
  for (int i = 0; i < t - 1; i++) {
    for (int j = t; j >= i + 1; j--) {
      if (arr[i] + arr[j] == value)
        p++;
    }
  }
  return p;
}
int countPairs3(int *arr, int len, int value) {
  int p = 0, t = 0, f = len - 1;
  while (t < f - 1) {
    int d_1 = (t + f) / 2;
    if (arr[d_1] <= value)
      t = d_1;
    else
      f = d_1;
  }
  len = f - 1;
  for (int i = 0; i < len; i++) {
    t = i + 1, f = len - 1;
    int q = 0;
    while (t < f) {
      int d_2 = (t + f) / 2;
      if (arr[d_2] < (value - arr[i]))
        t = d_2 + 1;
      else
        f = d_2;
    }
    while (arr[t] == (value - arr[i])) {
      q++;
      t++;
    }
    p += q;
  }
  return p;
}
