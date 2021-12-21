
#include "strftime_millis.h"


size_t strftime_millis(char* ptr, size_t maxsize,const char* format, const struct timeval* tv)
{
    struct tm *tm;
    size_t result;
    char* temp_name = malloc(maxsize);
    if ((tm = localtime(&(tv->tv_sec))) == NULL)
    {
        return -1;
    }
	
    strftime(temp_name, maxsize, format, tm);
    result = snprintf(ptr, maxsize, temp_name, tv->tv_sec, tv->tv_usec);
    free(temp_name);
    return result;
}
