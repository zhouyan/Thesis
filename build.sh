#!/bin/bash

if [ -z $1 ]; then
    latexmk -f -silent thesis.tex > /dev/null
else
    sed -e "s/Minion/$1/" thesis.tex > thesis-$1.tex
    if [ ! -z $2]; then
	sed -e "s/11pt/$2/" thesis-$1.tex > thesis-$1-$2.tex
    fi
    mv thesis-$1-$2.tex thesis-$1.tex
    latexmk -f -silent thesis-$1.tex > /dev/null
fi
