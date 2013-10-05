.PHONY : thesis

thesis :
	latexmk -f -silent thesis.tex > /dev/null

clean :
	latexmk -c
	rm -f chap/*.aux
	rm -rf .minted-*
