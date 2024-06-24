int minKBitFlips(vector<int>& A, int K, int res = 0) {
  queue<int> flips;
  for (auto i = 0; i < A.size(); ++i) {
    if (A[i] != (flips.size() % 2 ? 0 : 1)) {
      ++res;
      flips.push(i + K - 1);
    }
    if (!flips.empty() && flips.front() <= i) flips.pop();
  }
  return flips.empty() ? res : -1;
}



class Solution {
public:
    int minKBitFlips(vector<int>& A, int K, int res = 0, int flips = 0) {
        for (auto i = 0; i < A.size(); ++i) {
            if (A[i] == flips % 2) {
            if (i > A.size() - K) return -1;
            ++res, ++flips, A[i] -= 2;
            }
            if (i >= K - 1 && A[i - K + 1] < 0) --flips, A[i - K + 1] += 2;
        }
        return res;
    }
};



int minKBitFlips(vector<int>& A, int K, int res = 0) {
  for (auto i = 0; i < A.size(); ++i) {
    if (A[i] != 1) {
      if (i + K - 1 >= A.size()) return -1;
      for (auto j = i; j < i + K; ++j) A[j] = !A[j];
      ++res;
    }
  }
  return res;
}
