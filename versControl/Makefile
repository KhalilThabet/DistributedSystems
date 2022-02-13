SUBDIRS = client server sources Temp

all:
	@for subdir in $(SUBDIRS); do \
	cd $$subdir && $(MAKE) all ; \
	cd ..; \
	done
