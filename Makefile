SUBDIRS := client server

all : $(SUBDIRS)

$(SUBDIRS) : 
	$(MAKE) -C $@

clean : 
	$(MAKE) -C client clean
	$(MAKE) -C server clean

.PHONY : clean $(SUBDIRS)

