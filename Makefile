SUBDIRS := client server

all : $(SUBDIRS)
	@echo DEBUG $(SUBDIRS)

$(SUBDIRS) : 
	@echo DEBUG $@
	$(MAKE) -C $@

clean : 
	$(MAKE) -C client clean
	$(MAKE) -C server clean

.PHONY : clean $(SUBDIRS)