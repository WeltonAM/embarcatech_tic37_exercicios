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

Você pode testar o circuito diretamente no simulador Wokwi clicando no botão abaixo:

[![Teste no Wokwi](https://img.shields.io/badge/Simular%20no%20Wokwi-Testar%20Online-brightgreen)](https://wokwi.com/projects/420104833635443713)

---

## 🎥 Vídeo Demonstrativo

Assista ao vídeo explicativo do projeto e veja os resultados obtidos:

[![Vídeo Demonstrativo](https://img.shields.io/badge/Assistir-Vídeo-blue)](https://www.dropbox.com/scl/fi/jevku9wjif9zy1iechuxd/VID-20250109-WA0044.mp4?rlkey=4cb9qag7ziis20u8ivjgtvmdk&dl=0)

---

## 🖥️ Execução no Visual Studio Code

### Pré-requisitos
1. **Placa BitDogLab (versão 6.3)**.
2. **Cabo micro-USB para USB-A**.
3. **Visual Studio Code** com as extensões:
   - [C/C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools)
   - [PlatformIO](https://platformio.org/)
4. **SDK Pico** instalado e configurado.
5. **PuTTY** ou outro terminal para comunicação UART.