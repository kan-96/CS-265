
PY = python3
PYFLAGS =
PAGER = less


.PHONY : hello view run clean

hello :
	-echo -e "\nHello there, $$USER\n"

view : assn0
	-$(PAGER) assn0

run : assn0
	$(PY) assn0

clean :
ifneq ($(files),)
    rm -f $(files)
endif

