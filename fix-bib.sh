#!/bin/bash

sed -f fix-bib.sed thesis.bib > thesis-tmp.bib
mv thesis-tmp.bib thesis.bib
