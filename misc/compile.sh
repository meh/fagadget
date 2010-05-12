#! /bin/bash

function bawww {
    echo ""
    echo "Something went wrong ;_;"
    echo ""
    echo "BAWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWWW"
    exit 1
}

FAIL=true;
which autoconf-2.13 &> /dev/null; if [ $? = 0 ]; then FAIL=false; fi;
which autoconf2.13  &> /dev/null; if [ $? = 0 ]; then FAIL=false; fi;
which autoconf213   &> /dev/null; if [ $? = 0 ]; then FAIL=false; fi;

if $FAIL; then
    echo "Install autoconf 2.13 kthx"
    exit 1
fi

(autoconf-2.13 || autoconf2.13 || autoconf213) &> /dev/null

CONFIGURE='./configure --with-system-nspr --enable-static --enable-threadsafe --enable-optimize=-Os'

if [[ $DEBUG ]]; then
    CONFIGURE="$CONFIGURE --enable-debug --enable-gczeal"
fi

(eval $CONFIGURE && make) || bawww
