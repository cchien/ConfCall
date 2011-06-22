set multiplot
set grid
set title "Clients scheduling latency"
set xlabel "audio cycles"
set ylabel "usec"
plot "JackEngineProfiling.log" using 7 title "client1" with lines
 unset multiplot
set output 'Timing4.svg
set terminal svg
set multiplot
set grid
set title "Clients scheduling latency"
set xlabel "audio cycles"
set ylabel "usec"
plot "JackEngineProfiling.log" using 7 title "client1" with lines
unset multiplot
unset output
