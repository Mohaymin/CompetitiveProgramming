#include <stdio.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int main()
{
	long long ans;
        long long i, j, N, M, T, X, Y, ax, ay, bx, by;

	scanf("%lld", &T);
	while(T--)
	{
		ans = 0;
		scanf("%lld%lld%lld%lld", &N, &M, &X, &Y);
		for(i = 1; i <= N; i++)
			for(j = 1; j <= M; j++)
			{
				// (i, j) are position of queen 1
				if(i == X && j == Y)
					continue;
				ans += N * M - 2; // all positions for queen 2

				// Delete paths crossed by queen 1
				ans -= (N - 1) + (M - 1); // row and column
				ans -= MIN(i - 1, j - 1); // upper right down diagonal
				ans -= MIN(N - i, M - j); // lower right down diagonal
				ans -= MIN(i - 1, M - j); // lower left up diagonal
				ans -= MIN(N - i, j - 1); // upper left up diagonal

				if(j == Y)
				{
					// Same Row
					if(X < i)
						ans += X - 1;
					else
						ans += N - X;
					ans++; // because I assumed earlier that king was not in Q1's path
				}
				else if(i == X)
				{
					// Same Column
					if(Y < j)
						ans += Y - 1;
					else
						ans += M - Y;
					ans++; // because I assumed earlier that king was not in Q1's path
				}
				else if((i - X) == (j - Y))
				{
					// same right down diagonal
					if(X < i) // which means Y < j
						ans += MIN(X - 1, Y - 1);
					else
						ans += MIN(N - X, M - Y);
					ans++; // because I assumed earlier that king was not in Q1's path
				}
				else if((i - X) == (Y - j))
				{
					// same left up diagonal
					if(X < i) // which means Y > j
						ans += MIN(X - 1, M - Y);
					else
						ans += MIN(N - X, Y - 1);
					ans++; // because I assumed earlier that king was not in Q1's path
				}
			}
		printf("%lld\n", ans);
	}
	return 0;
}
