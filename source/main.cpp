#include <cstdio>
#include <omp.h>
int main(){
#pragma omp parallel
  printf("thread %d/%d\n", omp_get_thread_num(), omp_get_num_threads());
}