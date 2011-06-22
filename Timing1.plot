set grid
set title "Audio driver timing"
set xlabel "audio cycles"
set ylabel "usec"
plot "JackEngineProfiling.log" using 1 title "Audio period" with lines 
set output 'Timing1.svg
set terminal svg
set grid
set title "Audio driver timing"
set xlabel "audio cycles"
set ylabel "usec"
plot "JackEngineProfiling.log" using 1 title "Audio period" with lines 
unset output
