

A[i] // độ cao lớn nhất tại vị trí i của A[i] + P[i]
B[i] // độ cao lớn nhất tại vị trí i của A[i] - P[i]

A[0] = B[0] = 0;

for(int i = 1; i<= n; ++i) {
    A[i] = max(A[i-1], B[i-1] + P[i]);
    B[i] = max(B[i-1], A[i-1] - P[i]);
}
ans = max(A[i], B[i]);