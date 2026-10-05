# Lab 1.3: Flash LED on ESP32-C3

This ESP-IDF project flashes the board's WS2812 LED on GPIO2. The LED is on
for one second and off for one second. GPIO7 is not used.

From an ESP-IDF terminal, build and flash the project with:

```sh
cd ~/esp/lab1_3
idf.py build
idf.py flash monitor
```

Press `Ctrl-]` to exit the serial monitor.
