set xlabel "Size of Input"
set ylabel "Duration (in µs)"

set style fill transparent solid 0.2

set terminal png truecolor size 1600,1200

set xr[0:21000]
set yr [0:25000]

files = 'IS_list IS_vec QS_list QS_vec MS'
titles = 'Insertionsort_list Insertionsort_vector Quicksort_list Quicksort_vector Mergesort'

set output 'sort_rand_time.png'
plot for [i=1:words(files)] "measurements/time_".word(files,i)."_rand_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/time_".word(files,i)."_rand_p" \
			using 1:4 title word(titles, i) with line ls i

set output 'sort_perm_time.png'
plot for [i=1:words(files)] "measurements/time_".word(files,i)."_perm_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/time_".word(files,i)."_perm_p" \
			using 1:4 title word(titles, i) with line ls i
			
set output 'sort_ord_time.png'
plot for [i=1:words(files)] "measurements/time_".word(files,i)."_ord_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/time_".word(files,i)."_ord_p" \
			using 1:4 title word(titles, i) with line ls i
			
set output 'sort_revord_time.png'
plot for [i=1:words(files)] "measurements/time_".word(files,i)."_revord_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/time_".word(files,i)."_revord_p" \
			using 1:4 title word(titles, i) with line ls i
			
set output 'sort_multi_time.png'
plot for [i=1:words(files)] "measurements/time_".word(files,i)."_multi_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/time_".word(files,i)."_multi_p" \
			using 1:4 title word(titles, i) with line ls i

set ylabel "Cycles"
set yr [0:100000000]
set output 'sort_rand_cycles.png'
plot for [i=1:words(files)] "measurements/cycles_".word(files,i)."_rand_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/cycles_".word(files,i)."_rand_p" \
			using 1:4 title word(titles, i) with line ls i

set output 'sort_perm_cycles.png'
plot for [i=1:words(files)] "measurements/cycles_".word(files,i)."_perm_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/cycles_".word(files,i)."_perm_p" \
			using 1:4 title word(titles, i) with line ls i
			
set output 'sort_ord_cycles.png'
plot for [i=1:words(files)] "measurements/cycles_".word(files,i)."_ord_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/cycles_".word(files,i)."_ord_p" \
			using 1:4 title word(titles, i) with line ls i
			
set output 'sort_revord_cycles.png'
plot for [i=1:words(files)] "measurements/cycles_".word(files,i)."_revord_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/cycles_".word(files,i)."_revord_p" \
			using 1:4 title word(titles, i) with line ls i

set output 'sort_multi_cycles.png'
plot for [i=1:words(files)] "measurements/cycles_".word(files,i)."_multi_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/cycles_".word(files,i)."_multi_p" \
			using 1:4 title word(titles, i) with line ls i

