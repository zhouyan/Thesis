#!/bin/bash

sed -e 's/\\{\\&}/{\\\&}/' library.bib > library-tmp.bib
mv library-tmp.bib library.bib
