#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)
// ======================================================================

void hanoi(int n, char from, char tmp, char to)
{
	if (n == 1)//종료조건
	{
		printf("%c -> %c\n", from, to); //1개를 A -> C 로 보냄
	}
	if (n >= 2)
	{
		hanoi(n - 1, from, to, tmp); //n-1번 B와 C를 바꾼다. (최소 횟수로 전부 옮겨야되므로 n-1이 짝수일때와 홀수일때가 다르다.)
		                             //n이 홀수면 n-1은 짝수가 된다. n-1이 짝수면 처음 입력받은 B와 C 의 위치가 변하지않으므로 A -> C 로 disk 이동
		                             //n-1이 홀수면 처음입력받은 B 와 C의 위치가 바뀌므로 A -> B 로 disk 이동
		printf("%c -> %c\n", from, to); 
		                                //위의함수에서 A에서 1개가 B로 이동된 상태이므로 A에서 1개를 A -> C 로 disk 이동 
										//n-1이 1일 때까지 수행되면 A에는 0개 B에는 n-1개, C에 1개가 있는 상태가 된다.
		
		hanoi(n - 1, tmp, from, to); //n-1이 짝수면 B와 C의 위치가 바뀌지않은 hanoi(n, A,B,C)이므로 hanoi(n,C,A,B)가 된다. C가 A를 통해 B로 disk 이동  (첫번째 if 문에 의하여 n=1이면 C->B로 바로 이동)
		                             //n-1이 홀수면 B와 C의 위치가 바뀐 hanoi(n, A,C,B)이므로 hanoi(n, B,A,C) B가 된다. B가 A를 통해 C로 disk 이동 (첫번재 if문에 의하여 n=1이면 B->C 로 바로이동)
		                             //종료조건인 n-1이 결국 1이 될때까지, 즉 홀수가 될때 까지 수행되므로 최종적으로 B에 있는 n-1개가 A를 통해 C로 전부 disk 이동이 되는 형태가 된다. 
		          
		                             
		                            
 
	}

}

// ======================================================================

int main(void)
{
	int r, n;

	printf("n=");
	r = scanf("%d", &n);
	if (n >= 1)
		hanoi(n, 'A', 'B', 'C');

	return EXIT_SUCCESS;
}

// ======================================================================