#include <VitoWiFi.h>

VitoWiFi_setProtocol(GWG);

DPTempGWG heatertemp("heatertemp", "boiler",PHYSICAL_READ, 0x70,false);
DPTempGWG outsidetemp("outsidetemp", "boiler",PHYSICAL_READ, 0x06F,false);

void globalCallbackHandler(const IDatapoint& dp, DPValue value) {
  Serial1.print(dp.getGroup());
  Serial1.print(" - ");
  Serial1.print(dp.getName());
  Serial1.print(": ");
  char value_str[15] = {0};
  value.getString(value_str, sizeof(value_str));
  Serial1.println(value_str);
}

void setup() {
  VitoWiFi.setGlobalCallback(globalCallbackHandler);
  VitoWiFi.setup(&Serial);

  Serial1.begin(115200);
  Serial1.println(F("Setup finished..."));
}

void loop() {
  static unsigned long lastMillis = 0;
  if (millis() - lastMillis > 60 * 1000UL) {
    lastMillis = millis();
    VitoWiFi.readDatapoint(outsidetemp);
    VitoWiFi.readDatapoint(heatertemp);
    // Calling VitoWifi.readGroup("boiler"); would have the same result in this case are there are only 2 datapoints.
    // Calling VitoWifi.readAll(); obviously also has the same result in this example.
  }
  VitoWiFi.loop();
}
