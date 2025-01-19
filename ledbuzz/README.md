# Controle de GPIOs com BitDogLab e RP2040

Este projeto implementa o controle de LEDs RGB e um buzzer usando a placa educacional **BitDogLab** com o microcontrolador **RP2040**. Os periféricos são controlados através de comandos enviados pela interface UART, permitindo interatividade entre o usuário e o sistema embarcado.

---

## 🛠️ Funcionalidades

- Controle individual das cores do LED RGB:
  - **Verde** (GPIO 11)
  - **Azul** (GPIO 12)
  - **Vermelho** (GPIO 13)
- Controle combinado dos LEDs:
  - **Branco**: Acende todos os LEDs simultaneamente.
  - **Desligar**: Apaga todos os LEDs.
- Ativação do buzzer (GPIO 21) por 2 segundos.
- Reboot do sistema para habilitar o modo de gravação.

---

## 🔗 Teste Online

Você pode testar o circuito diretamente no simulador Wokwi clicando no link abaixo:

[![Teste no Wokwi](https://wokwi.com/projects/420104833635443713)]

---

## 🔗 Vídeo Demonstrativo

Vídeo demonstrativo do projeto:

[![Vídeo demonstrativo]()] 

---

## 🖥️ Execução no Visual Studio Code

### Pré-requisitos
1. **Placa BitDogLab (versão 6.3)**.
2. **Cabo micro-USB para USB-A**.
3. **Visual Studio Code** com as extensões:
   - [C/C++]
   - [Wokwi Simulator]
   - [Raspberry Pi Pico]
4. **SDK Pico** instalado e configurado.
5. **PuTTY** ou outro terminal para comunicação UART.
