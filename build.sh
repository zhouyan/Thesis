#!/bin/bash

if [ -z $1 ]; then
    latexmk -f -silent thesis.tex > /dev/null
else
    sed -e "s/Minion/$1/" thesis.tex > thesis-$1.tex
    latexmk -f -silent thesis-$1.tex > /dev/null
fi
