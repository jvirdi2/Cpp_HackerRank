#include<bits/stdc++.h>
#include <algorithm>
using namespace std;

// Define the structs Workshops and Available_Workshops.
// Implement the functions initialize and CalculateMaxWorkshops
// Calculates maximum workshops a person can attend without overlapping time
// If a workshop is from 1-3 and the second one is from 2-4, then he cannot attend the second one
// Input is given as
// 6 (number of workshops)
// 1 3 0 5 5 8 (starting time of workshops)
// 1 1 6 2 4 1 (duration of workshops)

struct Workshop {
  int wkshop_st_time;
  int wkshop_dur;
  int wkshop_end_time;
};

struct Available_Workshops {
  int nws;
  Workshop* Workshop_arr = new Workshop[nws];
};

Available_Workshops *initialize(int start_time[], int duration[], int n) {
  Available_Workshops *p = new Available_Workshops[n]; // Initializing pointer
  p->nws = n;

  for (int i = 0; i < n; i++) {
    p->Workshop_arr[i].wkshop_st_time = start_time[i];
    p->Workshop_arr[i].wkshop_dur = duration[i];
    p->Workshop_arr[i].wkshop_end_time = start_time[i] + duration[i];
  }

  return p;
}

bool compare(Workshop a, Workshop b)                         
{                                                                              
      return a.wkshop_end_time < b.wkshop_end_time;                                                    
} 

int CalculateMaxWorkshops(Available_Workshops *pointer) {
  int n_curr = 0;
  n_curr = pointer->nws;
  int counter = 0;
  int s[n_curr];
  int e[n_curr];

  
  sort(pointer->Workshop_arr, (pointer->Workshop_arr) + n_curr,compare);
  
  for (int r = 0; r < n_curr; r++) {
    s[r] = pointer->Workshop_arr[r].wkshop_st_time;

   
    e[r] = pointer->Workshop_arr[r].wkshop_end_time;
  }
  
  int LF = -1;
  for (int iter = 0; iter < n_curr; iter++) {
    if (s[iter] >= LF) {

      counter = counter + 1;
      LF = e[iter];
    }
  }

  return counter;
}

int main(int argc, char *argv[]) {
    int n; // number of workshops
    cin >> n;
    // create arrays of unknown size n
    int* start_time = new int[n];
    int* duration = new int[n];

    for(int i=0; i < n; i++){
        cin >> start_time[i];
    }
    for(int i = 0; i < n; i++){
        cin >> duration[i];
    }

    Available_Workshops * ptr;
    ptr = initialize(start_time,duration, n);
    cout << CalculateMaxWorkshops(ptr) << endl;
    return 0;
}

