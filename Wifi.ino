#include <WiFi.h>

String ssid = "MascotaTracker"; // Nombre genérico para la red Wi-Fi 
String macAddress;

void setup() {
  Serial.begin(115200);

  // Obtener la dirección MAC del ESP32
  String macAddressAP = WiFi.softAPmacAddress();
  Serial.println("Dirección MAC del AP: " + macAddressAP);

  // Configurar el Wi-Fi como punto de acceso
  WiFi.softAP(ssid.c_str());
  Serial.println("Punto de acceso iniciado con el nombre: " + ssid);
  Serial.println("IP del punto de acceso: " + WiFi.softAPIP().toString());

  // Esperar 30 segundos para que la red esté disponible
  delay(30000);

  // Desactivar el Wi-Fi para ahorrar batería
  WiFi.disconnect(true);
  WiFi.mode(WIFI_OFF);
  Serial.println("Wi-Fi apagado para ahorrar batería.");

  // Configurar el ESP32 para entrar en modo de sueño profundo durante 5 minutos
  esp_sleep_enable_timer_wakeup(30 * 1000000); // 300 segundos = 5 minutos
  Serial.println("Entrando en modo de sueño profundo durante 5 minutos...");
  esp_deep_sleep_start();
}

void loop() {
  // El ESP32 no ejecutará nada en el loop mientras esté en sueño profundo
}
