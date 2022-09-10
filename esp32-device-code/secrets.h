#include <pgmspace.h>

#define SECRET
#define THINGNAME "ESP32-00001"

const char WIFI_SSID[] = "xxxxxxxx";
const char WIFI_PASSWORD[] = "xxxxxxxxxx";
const char AWS_IOT_ENDPOINT[] = "xxxxxxxxxxxx-ats.iot.ap-southeast-2.amazonaws.com";

// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
-----END CERTIFICATE-----
)EOF";

// Device Certificate
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
-----END CERTIFICATE-----
)KEY";

// Device Private Key
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
  
-----END RSA PRIVATE KEY-----
)KEY";
