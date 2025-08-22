Para avaliar o CO2 produzido por sementes, foram utilizados um sensor MHZ19B conectado a um controlador Wemos D1.

Etapas de preparação:

1. O sensor foi instalado internamente na tampa de um recipiente de poliestireno transparente (13 x 13 x 9 cm; 700 mL de capacidade), dotada de anel de vedação de silicone com 3 abas. O controlador foi instalado em um Case transparente sobre a tampa. 
2. O sensor e o controlador foram conectados por cabos (Jumper de 20 cm). A alimentação de energia foi feita nos pinos "5V" e "GND" (neutro) do controlador, enquanto a recepção e a transmissão dos dados foram feitas no pinos RX_PIN "13" e TX_PIN "15", respectivamente.
3. O controlador foi conectado ao computador por um cabo USB-MiniUSB (fornecido pelo vendedor).

Sistema Arduino:

5. Instamos no computador o sistema Arduíno 1.8.19 (https://docs.arduino.cc/software/ide-v2/tutorials/getting-started/ide-v2-downloading-and-installing/).
7. Abrimos o sistema Arduino no computador e baixamos as Bibliotecas (ver na aba Ferramentas): "MHZ19.h"; "ESP8266WiFi.h"; "ThingSpeak.h"; "WiFiClient.h".
9. Na aba Ferramentas, selecionamos a Porta de conexão do controlador, a Placa "LOLIN(WeMos)D1 R1" e marcamos a opção "115200" na Upload Speed.
10. Fez-se a calibração do sensor por 20 minutos em ambiente aberto, utilizando o código disponível na Biblioteca MH-Z19 (https://github.com/WifWaf/MH-Z19).
11. Criamos uma conta e um canal no ThingSpeak (https://thingspeak.mathworks.com), para registrar os dados das leituras de CO2 de forma remota.
12. Abrimos o código apresentado neste projeto e substiuímos as informações indicadas nos //Comentários.
13. Carregamos o código apresentado neste projeto no controlador e aguardamos, até o envio dos dados de forma correta para o canal criado do ThinkSpeak a cada 5 minutos.

Preparação do Recipiente:

14. Fizemos a assepcia do recipiente com Álcool 70%.
15. Forma usados como substrato duas folhas de papel mata-borrão (10,4 x 10,4 cm), umedecidas com água destilada, com volume equivalente à 2,5 vezes a massa do papel, conforme recomendado para testes de germinação nas Regras para Análise de Sementes (https://wikisda.agricultura.gov.br/pt-br/Laborat%C3%B3rios/Metodologia/Sementes/RAS_2025/cap_4_Germinacao_rev_1).

Preparação da amostra:

16. Fez-se a homogeneização da amostra, para a obtenção de uma subamostra de trabalho constituída por 25 sementes.
17. As sementes foram colocadas no interior do recipiente de poliestireno transparente, sobre o papel umedecido.
