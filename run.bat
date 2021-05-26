@echo off

cls
echo Compiling %1... 
gcc %1.c -o %1
echo "Done"
