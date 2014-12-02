set xlabel "Size of Input"
set ylabel "Duration (in µs)"

set style fill transparent solid 0.2

set terminal png truecolor size 1600,1200

set xr[0:1100]
set yr [0:1500]

filenamepostfix = '_sml'
files = 'IS_list IS_vec QS_list QS_vec MS'
titles = 'Insertionsort_list Insertionsort_vector Quicksort_list Quicksort_vector Mergesort'

set output 'sort_rand_time'.filenamepostfix.'.png'
plot for [i=1:words(files)] "measurements/".word(files,i)."_rand".filenamepostfix."_time_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/".word(files,i)."_rand".filenamepostfix."_time_p" \
			using 1:4 title word(titles, i) with line ls i

set output 'sort_perm_time'.filenamepostfix.'.png'
plot for [i=1:words(files)] "measurements/".word(files,i)."_perm".filenamepostfix."_time_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/".word(files,i)."_perm".filenamepostfix."_time_p" \
			using 1:4 title word(titles, i) with line ls i
			
set output 'sort_ord_time'.filenamepostfix.'.png'
plot for [i=1:words(files)] "measurements/".word(files,i)."_ord".filenamepostfix."_time_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/".word(files,i)."_ord".filenamepostfix."_time_p" \
			using 1:4 title word(titles, i) with line ls i
			
set output 'sort_revord_time'.filenamepostfix.'.png'
plot for [i=1:words(files)] "measurements/".word(files,i)."_revord".filenamepostfix."_time_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/".word(files,i)."_revord".filenamepostfix."_time_p" \
			using 1:4 title word(titles, i) with line ls i
			
set output 'sort_multi_time'.filenamepostfix.'.png'
plot for [i=1:words(files)] "measurements/".word(files,i)."_multi".filenamepostfix."_time_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/".word(files,i)."_multi".filenamepostfix."_time_p" \
			using 1:4 title word(titles, i) with line ls i

set ylabel "Cycles"
set yr [0:5000000]
set output 'sort_rand_cycles'.filenamepostfix.'.png'
plot for [i=1:words(files)] "measurements/".word(files,i)."_rand".filenamepostfix."_cycles_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/".word(files,i)."_rand".filenamepostfix."_cycles_p" \
			using 1:4 title word(titles, i) with line ls i

set output 'sort_perm_cycles'.filenamepostfix.'.png'
plot for [i=1:words(files)] "measurements/".word(files,i)."_perm".filenamepostfix."_cycles_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/".word(files,i)."_perm".filenamepostfix."_cycles_p" \
			using 1:4 title word(titles, i) with line ls i
			
set output 'sort_ord_cycles'.filenamepostfix.'.png'
plot for [i=1:words(files)] "measurements/".word(files,i)."_ord".filenamepostfix."_cycles_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/".word(files,i)."_ord".filenamepostfix."_cycles_p" \
			using 1:4 title word(titles, i) with line ls i
			
set output 'sort_revord_cycles'.filenamepostfix.'.png'
plot for [i=1:words(files)] "measurements/".word(files,i)."_revord".filenamepostfix."_cycles_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/".word(files,i)."_revord".filenamepostfix."_cycles_p" \
			using 1:4 title word(titles, i) with line ls i
			
set output 'sort_multi_cycles'.filenamepostfix.'.png'
plot for [i=1:words(files)] "measurements/".word(files,i)."_multi".filenamepostfix."_cycles_p" \
			using 1:($2):($3) notitle with filledcurve ls i, \
		 for [i=1:words(files)] "measurements/".word(files,i)."_multi".filenamepostfix."_cycles_p" \
			using 1:4 title word(titles, i) with line ls i
