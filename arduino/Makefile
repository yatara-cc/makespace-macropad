SHELL := /bin/bash
.PHONY : lib

PORT := /dev/ttyACM0
DEVICE := leonardo


all : upload sleep monitor

build : src/$(TARGET) platformio.ini
	platformio run -v -e $(DEVICE)

upload : src/$(TARGET)
	platformio run -v --upload-port $(PORT) -e $(DEVICE) -t upload

sleep :
	sleep 1

monitor :
	platformio device monitor --port $(PORT)

debug : upload
	sleep 1
	screen $(PORT)
