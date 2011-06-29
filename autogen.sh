#! /bin/sh

# 
# execute the complete autoconf sequence to create the proper configure scripts
# and all..
#

# new: run
#   ./bootstrap // autoreconf --force --symlink   
# instead...


# make sure the custom m4 macros are known to autoconf lateron:
aclocal -I m4

# run autoconf to create a fresh configure script
autoconf -f

# If your autoconf version changes, the autom4te.cache stuff will mess you up.
# Get rid of it.
echo ... removing autoheader cache files ...
rm -rf autom4te*.cache

# create a fresh config.h.in which is in sync with the configure.in script
autoheader -f

# run automake to create a matching Makefile.in makefile template
automake -a --gnu



