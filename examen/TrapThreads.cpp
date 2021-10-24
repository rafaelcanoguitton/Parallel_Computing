#include <iostream>
#include <thread>
#include <semaphore.h>
#include <pthread.h>
#include <cmath>
using namespace std;
int num_divs=1000;
int num_threads=4;
double resultado=0;
sem_t sem;
//Nuestra función
double f(double x){
    return sin(x);
}
void trapezoidal_rule(double (*f)(double),double min,double max){
    double integral=0;
    double step_size=(max-min)/num_divs;
    for(int i=0;i<num_divs;i++){
        double x=min+i*step_size;
        double y=f(x);
        integral+=y*step_size;
    }
    sem_wait(&sem);
    resultado+=integral;
    sem_post(&sem);
}
int main(){
    pthread_t threads[num_threads];
    for(int i=0;i<num_threads;i++){
        pthread_create(&threads[i],NULL,&trapezoidal_rule,&f);
    }
}