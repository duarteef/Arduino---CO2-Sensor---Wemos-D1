Para avaliar o CO2 produzido por sementes, foram utilizados um sensor MHZ19B conectado a um controlador Wemos D1.

Etapas de preparação:
1. O sensor foi instalado internamente na tampa de um recipiente de poliestireno transparente (13 x 13 x 9 cm; 700 mL de capacidade), dotada de anel de vedação de silicone com 3 abas. O controlador foi instalado em um Case transparente sobre a tampa. 
2. O sensor e o controlador foram conectados por cabos (Jumper de 20 cm). A alimentação de energia foi feita nos pinos "5V" e "GND" (neutro) do controlador, enquanto a recepção e a transmissão dos dados foram feitas no pinos RX_PIN "13" e TX_PIN "15", respectivamente.
3. O controlador foi conectado ao computador por um cabo USB-MiniUSB (fornecido pelo vendedor).
4. Instamos no computador o sistema Arduíno 1.8.19 (https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/).
5. Abrimos o sistema no computador e baixamos as Bibliotecas (ver na aba Ferramentas): "MHZ19.h"; "ESP8266WiFi.h"; "ThingSpeak.h"; "WiFiClient.h".
6. Na aba Ferramentas, selecionamos a Porta de conexão do controlador, a Placa "LOLIN(WeMos)D1 R1" e marcamos a opção "115200" na Upload Speed.
7. 
