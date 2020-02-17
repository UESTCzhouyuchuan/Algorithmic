

#include "bits/stdc++.h"
using namespace std;

int a[500050], t1[500050], t2[500050];
int n, i, mx, ans = -100000000;

int main() {
	scanf("%d", &n);
	for (i = 1; i <= n; i++) scanf("%d", &a[i]);

	mx = 0; t1[0] = -100000000;
	for (i = 1; i <= n; i++) t1[i] = max(mx = max(a[i], mx + a[i]), t1[i - 1]);

	mx = 0; t2[n + 1] = -100000000;
	for (i = n; i >= 1; i--) t2[i] = max(mx = max(a[i], mx + a[i]), t2[i + 1]);

	ans = -100000000;
	for (i = 2; i < n; i++) ans = max(ans, t1[i - 1] + t2[i + 1]);

	printf("%d\n", ans);

	return 0;
}

