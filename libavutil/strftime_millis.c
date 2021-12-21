
#include "strftime_millis.h"


size_t strftime_millis(char* ptr, size_t maxsize,const char* format, const struct timeval* tv)
{
    char* temp_name;
    struct tm *tm, tmpbuf;
    size_t result;
    tm = localtime_r(&(tv->tv_sec), &tmpbuf);
    if (tm == NULL)
    {
        return -1;
    }
	
    temp_name = malloc(maxsize);
    result = strftime(temp_name, maxsize, format, tm);
    if (result == 0)
    {
        free(temp_name);
        return -2;
    }

    result = snprintf(ptr, maxsize, temp_name, tv->tv_sec, tv->tv_usec);
    free(temp_name);
    return result;
}
