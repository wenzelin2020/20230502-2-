#include <bits/stdc++.h>//����ţ��!!!!!
using namespace std;
using namespace std;
int n, m, a[1001], d[1001], l, r, mid;

int check(int fuck) {
	memset(d, 0, sizeof(d));
	for (int i = 1; i <= n; i++) {

		d[i] = i - 1;
		for (int j = 1; j < i; j++) {
			if (abs(a[i] - a[j]) <= fuck * (i - j))//�ڷ�Χ��
				d[i] = min(d[i], d[j] + i - j - 1);//�����ٵ����ٵ�
		}
		if (d[i] + n - i <= m)
			return 1;//���ʣ�µĵ�������ʣ��ĵ�������
	}
	return 0;
}

signed main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	l = 0, r = 100000000, mid = (l + r) / 2;
	while (l < r) {
		mid = (l + r) / 2;
		if (check(mid))
			r = mid;
		else
			l = mid + 1;
	}
	cout << l << endl;
	return 0;
}