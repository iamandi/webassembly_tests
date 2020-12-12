#include <emscripten.h>
#include "src/webp/encode.h"

#ifdef __cplusplus
extern "C"
{
#endif
    EMSCRIPTEN_KEEPALIVE
    int webpVersion()
    {
        return WebPGetEncoderVersion();
    }

#ifdef __cplusplus
}
#endif