set multiplot
set grid
set title "Clients duration"
set xlabel "audio cycles"
set ylabel "usec"
plot "JackEngineProfiling.log" using 8 title "client1" with lines
 unset multiplot
set output 'Timing5.svg
set terminal svg
set multiplot
set grid
set title "Clients duration"
set xlabel "audio cycles"
set ylabel "usec"
plot "JackEngineProfiling.log" using 8 title "client1" with lines
unset multiplot
unset output
