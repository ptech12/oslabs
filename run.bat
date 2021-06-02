@echo off

cls
echo Compiling %1... 
gcc %1.c -o op\%1
echo Running....
"%cd%"\op\%1
