#include <unistd.h>
#include <string.h>

#include "readline.h"

#define MAX_LINE_LEN 256

static int g_extent = 0;
static int g_index = 0;
static char g_buff[MAX_LINE_LEN+1];

//*********************************************
char *readline(char *buff, int size, int fd)
{
    int offset = 0;

    do
    {
        do
        {
            while (g_index >= g_extent)
            {
                g_index = 0;
                g_extent = read(fd, g_buff, MAX_LINE_LEN);
                if (g_extent < 0) return NULL;
            }

            buff[offset] = g_buff[g_index];
            g_index++;
            offset++;
        } while ( offset < size-1 &&
                  buff[offset-1] != '\n' &&
                  g_index < g_extent);
    } while ( offset < size-1 &&
              buff[offset-1] != '\n');
    buff[offset] = 0;
    return buff;
}

//**********************************************
int writestr(char *buff, int fd)
{
    return write(fd, buff, strlen(buff));
}
