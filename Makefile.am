## Process this file with automake to produce Makefile.in

if TRE_AGREP
agrep_dirs = src doc
else
agrep_dirs =
endif

SUBDIRS = lib $(agrep_dirs) tests utils po m4

EXTRA_DIST = \
	LICENSE \
	win32/tre-config.h win32/config.h \
	win32/libtre_lib.2005.vcproj \
	win32/libtre_dll.2005.vcproj \
	win32/tre.2005.sln \
	win32/retest.2005.vcproj \
	win32/libtre_lib.2008.vcproj \
	win32/libtre_dll.2008.vcproj \
	win32/tre.2008.sln \
	win32/retest.2008.vcproj \
	win32/retestw.2008.vcproj \
	win32/tre.def \
	python/tre-python.c \
	python/setup.py \
	python/example.py

ACLOCAL_AMFLAGS = -I m4
AC_CONFIG_AUX_DIR = utils

pkgconfigdir = $(libdir)/pkgconfig
pkgconfig_DATA = tre.pc
