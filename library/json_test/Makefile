#
# make tasks for json_test.
#

# Best effort to get Python 2 executable and also allow custom PYTHON
# environment variable set by the user.
PYTHON ?= $(shell command -v python2 2> /dev/null || echo python)

.PHONY:	\
	default Release Debug clean

default:
ifeq ($(MEDIASOUP_BUILDTYPE),Debug)
	make Debug
else
	make Release
endif

Release:
	$(PYTHON) ./configure.py -R json_test
	$(MAKE) V=1 BUILDTYPE=Release -C out

Debug:
	$(PYTHON) ./configure.py -R json_test
	$(MAKE) V=1 BUILDTYPE=Debug -C out

xcode:
	$(PYTHON) ./configure.py --format=xcode

clean:
	$(RM) -rf out

