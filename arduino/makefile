SHELL := /bin/bash

PROYECTOS := faro pines matrix letras atajos
.PHONY : $(PROYECTOS)

all :
	@echo "Elije una opción para compilar y subir un proyecto al dispositivo:"
	@for f in $(PROYECTOS); do echo "$(MAKE) $$f"; done;

define PROYECTO
$(1) :
	$(MAKE) -C $(1)
endef


$(foreach P,$(PROYECTOS),$(eval $(call PROYECTO,$(P))))

