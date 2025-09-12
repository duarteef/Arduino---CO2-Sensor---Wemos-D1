/*O presente código para determinar a produção de CO2 nas sementes foi produzido no âmbito do 
 * projeto de pesquisa "Produção de qualidade de sementes em Rede" 
 * (https://botanica.icb.ufg.br/p/47978-pesquisa-e-inovacao-projeto-producao-e-qualidade-de-sementes-em-rede).
 * Está sendo disponibilizado para reuso livre e gratuíto, por utilizar a plantaforma
 * Arduino e para ampliar o uso da técnica na avaliação da atividade respiratória em sementes.
 * Para o uso do sensor de CO2, as conexões com os cabos de energia e de comunicação com o Controlador recomendamos ler informações disponiveis em:
 * https://www.usinainfo.com.br/sensor-de-gas-arduino/sensor-de-co2-mh-z19b-infravermelho-5000ppm-cabo-6089.html?srsltid=AfmBOorSnNatdjMKYauMe2L4ebMYP1ukeBZTOjg8Xzc2LBIwj9iLuT5C
 * fazendo as conexões para a comunicação nos pinos 13 e 15 do controlador Wemos D1 que usamos.*/

#include <SoftwareSerial.h>      // Comunicação serial com o sensor
#include <MHZ19.h>               // Biblioteca para sensor MH-Z19B
#include <ESP8266WiFi.h>         // Biblioteca WiFi para ESP8266
#include <ThingSpeak.h>          // Biblioteca para enviar dados ao ThingSpeak
#include <WiFiClient.h>          // Biblioteca para conexões HTTP

// Definições de pinos
#define RX_PIN 13   // RX do ESP (para TX do sensor)
#define TX_PIN 15   // TX do ESP (para RX do sensor)

// Criação da serial para o sensor
SoftwareSerial sensorSerial(RX_PIN, TX_PIN);

MHZ19 co2Sensor; // Instância do sensor MH-Z19

// Intervalo de envio em milissegundos (5 minutos)
unsigned long intervalo = 300000;
unsigned long ultimoEnvio = 0;

// Credenciais Wi-Fi
const char* ssid = "XXXXXX";         // Substitua pelo nome da sua rede Wi-Fi
const char* password = "XXXXXX";       // Substitua pela senha da sua rede Wi-Fi

// Dados do ThingSpeak
const char* writeApiKey = "XXXXXX";  // Substitua pela sua Write API Key
const char* readApiKey = "XXXXXX";    // Substitua pela sua Read API Key
const int canalID = XXXXXX;                   // Substitua pelo número do seu canal

WiFiClient cliente;

void setup() {
  Serial.begin(9600);              // Inicializa a serial para depuração
  sensorSerial.begin(9600);        // Inicializa a serial com o sensor

  co2Sensor.begin(sensorSerial);   // Conecta o sensor MH-Z19 à serial

  // Desativa a calibração automática e realiza calibração manual
  co2Sensor.autoCalibration(false);  // Desativa calibração automática

  // Força a calibração manual com CO2 de 400 ppm (ajuste conforme necessário)
  co2Sensor.calibrateZero();  // Calibra o sensor com a referência de 400 ppm

  // Dê ao sensor alguns segundos para se estabilizar e realizar a calibração
  Serial.println("Iniciando calibração manual. Aguarde alguns segundos...");
  delay(10000);  // Espera 10 segundos para a calibração inicial

  // Conecta-se à rede Wi-Fi
  WiFi.begin(ssid, password);
  Serial.print("Conectando-se ao Wi-Fi");

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println("\nWi-Fi conectado!");
  Serial.print("Endereço IP: ");
  Serial.println(WiFi.localIP());

  ThingSpeak.begin(cliente); // Inicializa comunicação com ThingSpeak
}

void loop() {
  unsigned long agora = millis();

  // Verifica se passou o tempo de envio (5 minutos)
  if (agora - ultimoEnvio >= intervalo) {
    ultimoEnvio = agora;

    // Lê a concentração de CO2 e a temperatura
    int co2 = co2Sensor.getCO2();
    int temperatura = co2Sensor.getTemperature();  // Lê a temperatura do sensor

    // Exibe os valores no monitor serial
    Serial.print("Concentração de CO2: ");
    Serial.print(co2);
    Serial.print(" ppm, Temperatura: ");
    Serial.print(temperatura);
    Serial.println(" °C");

    // Envia os valores para o ThingSpeak
    ThingSpeak.setField(1, co2);           // Envia o valor de CO2 para o campo 1
    ThingSpeak.setField(2, temperatura);  // Envia o valor da temperatura para o campo 2

    int status = ThingSpeak.writeFields(canalID, writeApiKey);

    if (status == 200) {
      Serial.println("Dados enviados com sucesso ao ThingSpeak.");
    } else {
      Serial.print("Erro ao enviar dados: ");
      Serial.println(status);
    }
  }

  // Aguarda um pouco antes de verificar novamente
  delay(1000);
}
