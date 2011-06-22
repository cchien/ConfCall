set multiplot
set grid
set title "Clients end date"
set xlabel "audio cycles"
set ylabel "usec"
plot "JackEngineProfiling.log" using 1 title "Audio period" with lines,"JackEngineProfiling.log" using 6 title "client1"with lines
 unset multiplot
set output 'Timing3.svg
set terminal svg
set multiplot
set grid
set title "Clients end date"
set xlabel "audio cycles"
set ylabel "usec"
plot "JackEngineProfiling.log" using 1 title "Audio period" with lines,"JackEngineProfiling.log" using 6 title "client1"with lines
unset multiplot
unset output
