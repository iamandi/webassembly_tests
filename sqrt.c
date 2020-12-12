#include <math.h>
#include <stdio.h>
#include <emscripten.h>

#ifdef __cplusplus
extern "C"
{
#endif

    EMSCRIPTEN_KEEPALIVE
    void sayHi()
    {
        printf("Hi!\n");
    }

    EMSCRIPTEN_KEEPALIVE
    int int_sqrt(int x)
    {
        return sqrt(x);
    }

#ifdef __cplusplus
}
#endif