#!/bin/bash

sed -e 's/\\{\\&}/{\\\&}/' thesis.bib > thesis-tmp.bib
mv thesis-tmp.bib thesis.bib
