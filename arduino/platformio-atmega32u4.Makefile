SHELL := /bin/bash
.PHONY : lib

DEVICE := leonardo


port :
	@if [ -z "$(PORT)" ]; \
	  then \
	  echo "Error: 'PORT' variable is unset." 1>&2; \
	  false; \
	  fi
	@if [ ! -e "$(PORT)" ]; \
	  then \
	  echo "Error: Port '$(PORT)' does not exist. Check 'PORT' variable." 1>&2; \
	  false; \
	  fi


target :
	@if [ -z "$(TARGET)" ]; \
	  then \
	  echo "Error: 'TARGET' variable is unset." 1>&2; \
	  false; \
	  fi
	@if [ ! -e "src/$(TARGET)" ]; \
	  then \
	  echo "Error: Target 'src/$(TARGET)' does not exist. Check 'TARGET' variable." 1>&2; \
	  false; \
	  fi


build : src/$(TARGET) target platformio.ini
	platformio run -v -e $(DEVICE)

upload : src/$(TARGET) port target
	platformio run -v --upload-port $(PORT) -e $(DEVICE) -t upload

sleep :
	sleep 1

monitor :
	platformio device monitor --port $(PORT)

debug : upload
	sleep 1
	screen $(PORT)
