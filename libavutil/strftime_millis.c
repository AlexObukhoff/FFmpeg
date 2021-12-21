
#include "strftime_millis.h"


size_t strftime_millis(char* ptr, size_t maxsize,const char* format, const struct timeval* tv)
{
    char* temp_name;
    struct tm tm;
    size_t result;
    errno_t error = localtime_s(&tm, &(tv->tv_sec));
    if (error)
    {
        fprintf(stderr, "localtime_s failed: errno=%d\n", error);
        return -1;
    }
	
    temp_name = malloc(maxsize);
    result = strftime(temp_name, maxsize, format, &tm);
    if (result == 0)
    {
        free(temp_name);
        return -2;
    }

    result = snprintf(ptr, maxsize, temp_name, tv->tv_sec, tv->tv_usec);
    free(temp_name);
    return result;
}
