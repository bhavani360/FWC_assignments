#!/bin/bash


#Download python and latex templates

#svn co https://github.com/gadepall/training/trunk/math  /sdcard/Download/math

#Test Latex Installation
#Uncomment only the following lines and comment the above line


python3 /home/bhavani/Documents/optimization/opt_02/opt_02.py

cd /home/bhavani/Documents/optimization/opt_02
pdflatex opt_02.tex
xdg-open opt_02.pdf


#Test Python Installation
#Uncomment only the following line
