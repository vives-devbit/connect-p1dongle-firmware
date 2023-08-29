#include "./WiFiClientSecure.h"

namespace Xenn
{
    void WiFiClientSecure::setCACert(const char* rootCA) {
        _CA_cert = rootCA;
    }

    void WiFiClientSecure::setUseCertBundle(bool userCertBundle) {
        _use_ca_bundle = true;
    }

    bool WiFiClientSecure::loadCertBundle(Stream& stream, size_t size) {
        // esp_crt_bundle_set expects a uint8_t * so we cannot reuse
        // the char *_streamLoad(stream, size); without modifying it.
        uint8_t *dest = (uint8_t*)malloc(size+1);
        if (!dest) {
            return false;
        }
        if (size != stream.readBytes(dest, size)) {
            free(dest);
            return false;
        }
        dest[size] = '\0';
        setCACertBundle(dest);
        return true;
    }
} // namespace Xenn
