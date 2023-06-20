# Explicação do arquivo
O arquivo fornecido é um código-fonte escrito em linguagem de programação Arduino. Ele controla um sistema de estacionamento inteligente utilizando um sensor ultrassônico e um motor de passo.

## Aqui está uma explicação do código em cada seção:

### Inclusão de bibliotecas

```
#include <Ultrasonic.h>
#include <AccelStepper.h>
```
 
 Nesta parte, as bibliotecas `Ultrasonic` e `AccelStepper` são incluídas no código. Essas bibliotecas fornecem funcionalidades para utilizar o sensor ultrassônico e o motor de passo, respectivamente.

### Definição dos pinos

```
const int pin1 = 5;
const int pin2 = 4;
const int pin3 = 3;
const int pin4 = 2;

#define TRIGGER_PIN1 11
#define ECHO_PIN1 10
#define TRIGGER_PIN2 9
#define ECHO_PIN2 8
#define TRIGGER_PIN3 7
#define ECHO_PIN3 6
```

Nesta parte, são definidos os pinos utilizados para controlar o motor de passo e os sensores ultrassônicos. Os pinos `pin1`, `pin2`, `pin3` e `pin4` controlam as bobinas do motor de passo. Os pinos `TRIGGER_PINX` e `ECHO_PINX` são utilizados para os sensores ultrassônicos, onde `X` representa o número do sensor.

## Criação de objetos

```
Ultrasonic ultrasonic1(TRIGGER_PIN1, ECHO_PIN1);
Ultrasonic ultrasonic2(TRIGGER_PIN2, ECHO_PIN2);
Ultrasonic ultrasonic3(TRIGGER_PIN3, ECHO_PIN3);
```

Nesta parte, são criados objetos da classe Ultrasonic para cada sensor ultrassônico, passando os pinos de trigger e echo como parâmetros para o construtor.

## Configuração inicial
```
void setup() {
  Serial.begin(9600);
  motor.setMaxSpeed(1000);
  motor.setAcceleration(500);
  motor.setSpeed(500);
}
```

A função setup é executada uma vez no início do programa. Nela, a comunicação serial é iniciada com uma taxa de transmissão de 9600 bps. Em seguida, são feitas configurações iniciais do motor de passo, como a velocidade máxima, a aceleração e a velocidade de rotação.

## Loop principal

```
void loop() {
  // Leitura dos sensores ultrassônicos
  // ...

  // Verificação de comandos enviados pela porta serial
  // ...

  // Verificação da distância medida pelos sensores e envio das informações pela porta serial
  // ...

  // Delay para aguardar um segundo antes de repetir o loop
  delay(1000);
}
```

A função loop é executada continuamente após a função setup. Nela, são realizadas as seguintes operações:

- Leitura dos sensores ultrassônicos e armazenamento das distâncias medidas.
- Verificação de comandos enviados pela porta serial, como "open" (abrir) ou "close" (fechar). - - - Esses comandos são utilizados para controlar o movimento do motor de passo.
- Verificação das distâncias medidas pelos sensores e envio das informações pela porta serial. As informações são enviadas em formato JSON e indicam se uma vaga de estacionamento está ocupada ou não, juntamente com o número da vaga e as coordenadas geográficas.
- Um delay de 1 segundo é utilizado para aguardar antes de repetir o loop.

## Funções auxiliares

```
void open() {
  // Movimenta o motor de passo para abrir o estacionamento
  // ...
}

void close() {
  // Movimenta o motor de passo para fechar o estacionamento
  // ...
}
```

Essas são funções auxiliares para abrir e fechar o estacionamento. Elas são chamadas quando comandos específicos são recebidos pela porta serial.

Esse código é apenas uma parte de um projeto maior e faz parte de um sistema mais complexo de controle de estacionamento. Para obter mais detalhes e contexto sobre o projeto, é recomendável verificar o repositório completo do código-fonte, que pode ser encontrado [aqui](https://github.com/JoaoZanardo/SPL).