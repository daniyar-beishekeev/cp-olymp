:loop
gen.exe > test.txt
slow.exe < test.txt > slow.txt
fast.exe < test.txt > fast.txt
fc slow.txt fast.txt
if errorlevel 1 (
goto exit
)
goto loop
:exit