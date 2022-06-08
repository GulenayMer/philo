#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

long long mili(void)
{
	struct timeval tv;
	gettimeofday(&tv, NULL);
	return ((long long)(tv.tv_sec) * 1000 + (tv.tv_usec/1000));
}

int	main(int argc, char **argv)
{
	long long i;

	i = mili();
	printf("%lld", i);
	return (0);
}
