set grid
set title "Driver end date"
set xlabel "audio cycles"
set ylabel "usec"
plot  "JackEngineProfiling.log" using 2 title "Driver end date" with lines 
set output 'Timing2.svg
set terminal svg
set grid
set title "Driver end date"
set xlabel "audio cycles"
set ylabel "usec"
plot  "JackEngineProfiling.log" using 2 title "Driver end date" with lines 
unset output
