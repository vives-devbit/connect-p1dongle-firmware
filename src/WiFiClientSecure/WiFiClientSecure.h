#pragma once

#include <WiFiClientSecure.h>

namespace Xenn {

    class WiFiClientSecure : public ::WiFiClientSecure{
        public: 
            void setCACert(const char *rootCA);
            void setUseCertBundle(bool userCertBundle);
            bool loadCertBundle(Stream& stream, size_t size);
    };
}
