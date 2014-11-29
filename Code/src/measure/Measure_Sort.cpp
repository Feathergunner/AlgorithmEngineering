#include <measure/Meter.h>
#include <Sort.h>
#include <Sort_test.h>

typedef list<int> (*sort_list_ptr)(list<int>);
typedef vector<int> (*sort_vec_ptr)(vector<int>);

int main(){
	char casename[15];
	char filename_t[80];
	char filename_c[80];
	int nom;
	int inputsize;
	
	bool prepare_for_plotting = true;
	
	// Filenames for testcases:
	const char* cases[20] = {"IS_list_rand",
												"IS_list_perm",
												"IS_list_ord",
												"IS_list_revord",
												"QS_list_rand",
												"QS_list_perm",
												"QS_list_ord",
												"QS_list_revord",
												"IS_vec_rand",
												"IS_vec_perm",
												"IS_vec_ord",
												"IS_vec_revord",
												"QS_vec_rand",
												"QS_vec_perm",
												"QS_vec_ord",
												"QS_vec_revord",
												"MS_rand",
												"MS_perm",
												"MS_ord",
												"MS_revord"};

	//functionpointer:
	sort_list_ptr listalgos[2] = {Sort::insertionsort_list,
											Sort::quicksort_list};
	sort_vec_ptr vecalgos[3] = {Sort::insertionsort_vec,
										 Sort::quicksort_vec,
										 Sort::mergesort};

	// Meters to measure time and cycles:
	Meter m_t, m_c;
	
	list<int> testlist;
	vector<int> testvec;
	
	nom = 20;
	inputsize = 20000;
	
	for (int c=0; c<20; c++)
	{		
		sprintf(filename_t, "time_%s", cases[c]);
		m_t = Meter(filename_t);
		sprintf(filename_c, "cycles_%s", cases[c]);
		m_c = Meter(filename_c);
		
		// c<8 => list, c>=8 => vector
		if (c<8)
		{
			// list-algorithms:
			
			// measure until max. inputsize is reached or function needs more than 0.1s
			for (int i=100; i<=inputsize && m_t.get_mean() < 50000; i+=100)
			{			
				// created parameter list: an measure:
				// c%4==0 => random
				// c%4==1 => permuted
				// c%4==2 => ordered
				// c%4==3 => reverse ordered
				if (c%4==0)
					testlist = Sort::create_randomlist(i,0);
				if (c%4==1)
					testlist = Sort::create_permutedlist(i);
				if (c%4==2)
					testlist = Sort::create_orderedlist(i);
				if (c%4==3)
					testlist = Sort::create_revorderedlist(i);
				// Measure time:
				m_t.measure_time<list<int>, list<int> >(nom, listalgos[c/4], testlist);
				// Measure cycles:
				m_c.measure_cycles<list<int>, list<int> >(nom, listalgos[c/4], testlist);
			
				// write data to file:
				sprintf(casename, "%i",i);
				m_t.printData(casename);
				m_c.printData(casename);
				// extra-file for plotting:
				if (prepare_for_plotting){
					m_t.printData_plotting(casename);
					m_c.printData_plotting(casename);
				}
			}
		}else{
			// case: vector
			// measure until max. inputsize is reached or function needs more than 0.1s
			for (int i=100; i<=inputsize && m_t.get_mean() < 50000; i+=100)
			{	
				// created parameter vector:
				// c%4==0 => random
				// c%4==1 => permuted
				// c%4==2 => ordered
				// c%4==3 => reverse ordered
				if (c%4==0)
					testvec = Sort::create_randomvector(i,0);
				if (c%4==1)
					testvec = Sort::create_permutedvector(i);
				if (c%4==2)
					testvec = Sort::create_orderedvector(i);
				if (c%4==3)
					testvec = Sort::create_revorderedvector(i);
				// Measure:
				m_t.measure_time<vector<int>, vector<int> >(nom, vecalgos[(c-8)/4], testvec);
				m_c.measure_cycles<vector<int>, vector<int> >(nom, vecalgos[(c-8)/4], testvec);
		
				// write data to file:
				sprintf(casename, "%i",i);
				m_t.printData(casename);
				m_c.printData(casename);
				// extra-file for plotting:
				if (prepare_for_plotting){
					m_t.printData_plotting(casename);
					m_c.printData_plotting(casename);
				}
			}
		}
	}
	
	/*
	// std::vector sort:
	for (int c=0; c<4; c++)
	{
		sprintf(filename, "%s", "std_vec_sort");
		m = Meter(filename);
		for (int i=100; i<=inputsize; i+=100)
		{
			if (c==0)
				testvec = Sort::create_randomvector(i,0);
			if (c==1)
				testvec = Sort::create_permutedvector(i);
			if (c==2)
				testvec = Sort::create_orderedvector(i);
			if (c==3)
				testvec = Sort::create_revorderedvector(i);
			// Measure:
			m.measure<void, void >(nom, testvec.sort(), void);
			
			// write data to file:
			sprintf(casename, "%i",i);
			m.printData(casename);
			// extra-file for plotting:
			if (prepare_for_plotting) m.printData_plotting(casename);
		}
	}
	*/
	
	/*
	// std::list sort:
	for (int c=0; c<4; c++)
	{
		sprintf(filename, "%s", "std_list_sort");
		m = Meter(filename);
		for (int i=100; i<=inputsize; i+=100)
		{
			if (c==0)
				testlist = Sort::create_randomlist(i,0);
			if (c==1)
				testlist = Sort::create_permutedlist(i);
			if (c==2)
				testlist = Sort::create_orderedlist(i);
			if (c==3)
				testlist = Sort::create_revorderedlist(i);
			// Measure:
			m.measure<void, void >(nom, testlist.sort(), void);
			
			// write data to file:
			sprintf(casename, "%i",i);
			m.printData(casename);
			// extra-file for plotting:
			if (prepare_for_plotting) m.printData_plotting(casename);
		}
	}
	*/
	
	return 0;
}

