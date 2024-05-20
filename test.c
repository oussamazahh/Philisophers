#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

static size_t get_current_time(void)
{
    struct timeval tv;

    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int ft_sleep(int time)
{
    size_t start;

    start = get_current_time();
    while (get_current_time() - start < time)
        usleep(100);
    return (1);
}

int main(void)
{
    printf("check of my ft_sleep if is working: %ld\n", get_current_time());
    ft_sleep(100);
    printf("check of my ft_sleep if is working: %ld\n", get_current_time());
    return (0);
}