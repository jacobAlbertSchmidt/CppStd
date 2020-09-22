#include "../Headers/Panic.h"
#include "unistd.h"

char buff[256];

int strlen(const char *str) {
        const char *begin = str;
        while (*str) {++str;}
        return str - begin; 
}


void Panic(const Span<const char> msg, 
           const char *file_name = __FILE__, 
           const int line_n = __LINE__, 
           const char *fn = __FUNCTION__) 
{       
        
        //TODO : Do filename, line_n and fn formating 'n stuff


        write(2, msg.Data(), msg.Size());
        _exit(1);
}