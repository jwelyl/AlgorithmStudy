int solution(int m, int n, vector<vector<int>> city_map) {

	int MOD = 20170805;
	int arr_u_d[501][501] = { 0, };
	int arr_l_r[501][501] = { 0, };

	arr_u_d[1][1] = 1, arr_l_r[1][1] = 1;

	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {

			if (city_map[i - 1][j - 1] == 0) {
				arr_u_d[i][j] += (arr_u_d[i - 1][j] + arr_l_r[i][j - 1]) % MOD;
				arr_l_r[i][j] += (arr_u_d[i - 1][j] + arr_l_r[i][j - 1]) % MOD;
			}
			else if (city_map[i - 1][j - 1] == 1) {
				arr_u_d[i][j] = 0;
				arr_l_r[i][j] = 0;
			}
			else {
				arr_u_d[i][j] += arr_u_d[i - 1][j];
				arr_l_r[i][j] += arr_l_r[i][j - 1];
			}

		}
	}

	return arr_u_d[m][n];

}