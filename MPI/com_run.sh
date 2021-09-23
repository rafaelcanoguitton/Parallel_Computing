#!/bin/bash
mpicc -g -Wall -o mpi_mat_vect_mult MPI_VEC.c;
mpicc -g -Wall -o mpi_odd_even MPI_SORT.c;
gcc -g -Wall -o mat_vect_mult GCC_VEC.c;
gcc -g -Wall -o odd_even GCC_SORT.c;
############
echo "Multiplicación matriz vector"
echo
echo "Corriendo con 2 procesos"
echo
echo "Para matriz de 1024x1024"
mpiexec -n 2 ./mpi_mat_vect_mult 1024 1024
echo "Para matriz de 2048x2048"
mpiexec -n 2 ./mpi_mat_vect_mult 2048 2048
echo "Para matriz de 4096x4096"
mpiexec -n 2 ./mpi_mat_vect_mult 4096 4096
echo "Para matriz de 8192x8192"
mpiexec -n 2 ./mpi_mat_vect_mult 8192 8192
echo "Para matriz de 16384x16384"
mpiexec -n 2 ./mpi_mat_vect_mult 16384 16384
echo "########################"
echo "########################"
echo "Corriendo con 4 procesos"
echo
echo "Para matriz de 1024x1024"
mpiexec -n 4 ./mpi_mat_vect_mult 1024 1024
echo "Para matriz de 2048x2048"
mpiexec -n 4 ./mpi_mat_vect_mult 2048 2048
echo "Para matriz de 4096x4096"
mpiexec -n 4 ./mpi_mat_vect_mult 4096 4096
echo "Para matriz de 8192x8192"
mpiexec -n 4 ./mpi_mat_vect_mult 8192 8192
echo "Para matriz de 16384x16384"
mpiexec -n 4 ./mpi_mat_vect_mult 16384 16384
echo "########################"
echo "########################"
echo "Corriendo con 8 procesos"
echo
echo "Para matriz de 1024x1024"
mpiexec --oversubscribe -n 8 ./mpi_mat_vect_mult 1024 1024
echo "Para matriz de 2048x2048"
mpiexec --oversubscribe -n 8 ./mpi_mat_vect_mult 2048 2048
echo "Para matriz de 4096x4096"
mpiexec --oversubscribe -n 8 ./mpi_mat_vect_mult 4096 4096
echo "Para matriz de 8192x8192"
mpiexec --oversubscribe -n 8 ./mpi_mat_vect_mult 8192 8192
echo "Para matriz de 16384x16384"
mpiexec --oversubscribe -n 8 ./mpi_mat_vect_mult 16384 16384
echo "########################"
echo "########################"
echo "Corriendo con 16 procesos"
echo
echo "Para matriz de 1024x1024"
mpiexec --oversubscribe -n 16 ./mpi_mat_vect_mult 1024 1024
echo "Para matriz de 2048x2048"
mpiexec --oversubscribe -n 16 ./mpi_mat_vect_mult 2048 2048
echo "Para matriz de 4096x4096"
mpiexec --oversubscribe -n 16 ./mpi_mat_vect_mult 4096 4096
echo "Para matriz de 8192x8192"
mpiexec --oversubscribe -n 16 ./mpi_mat_vect_mult 8192 8192
echo "Para matriz de 16384x16384"
mpiexec --oversubscribe -n 16 ./mpi_mat_vect_mult 16384 16384
echo "########################"
echo "########################"
echo "De manera secuencial"
echo
echo "Para matriz de 1024x1024"
./mat_vect_mult 1024 1024
echo "Para matriz de 2048x2048"
./mat_vect_mult 2048 2048
echo "Para matriz de 4096x4096"
./mat_vect_mult 4096 4096
echo "Para matriz de 8192x8192"
./mat_vect_mult 8192 8192
echo "Para matriz de 16384x16384"
./mat_vect_mult 16384 16384
echo "########################"
echo "########################"
echo "########################"
echo "########################"
echo "Odd even sorting"
echo
echo "Corriendo secuencialmente"
echo
echo "Para 200 elementos"
./odd_even 200 'g'
echo "Para 400 elementos"
./odd_even 400 'g'
echo "Para 800 elementos"
./odd_even 800 'g'
echo "Para 1600 elementos"
./odd_even 1600 'g'
echo "Para 3200 elementos"
./odd_even 3200 'g'
echo "########################"
echo "########################"
echo "Corriendo con 2 procesos"
echo
echo "Para 200 elementos"
mpirun -np 2 ./mpi_odd_even 'g' 200
echo "Para 400 elementos"
mpirun -np 2 ./mpi_odd_even 'g' 400
echo "Para 800 elementos"
mpirun -np 2 ./mpi_odd_even 'g' 800
echo "Para 1600 elementos"
mpirun -np 2 ./mpi_odd_even 'g' 1600
echo "Para 3200 elementos"
mpirun -np 2 ./mpi_odd_even 'g' 3200
echo "########################"
echo "########################"
echo "Corriendo con 4 procesos"
echo
echo "Para 200 elementos"
mpirun -np 4 ./mpi_odd_even 'g' 200 
echo "Para 400 elementos"
mpirun -np 4 ./mpi_odd_even 'g' 400 
echo "Para 800 elementos"
mpirun -np 4 ./mpi_odd_even 'g' 800 
echo "Para 1600 elementos"
mpirun -np 4 ./mpi_odd_even 'g' 1600 
echo "Para 3200 elementos"
mpirun -np 4 ./mpi_odd_even 'g' 3200
echo "########################"
echo "########################"
echo "Corriendo con 8 procesos"
echo
echo "Para 200 elementos"
mpirun --oversubscribe -np 8 ./mpi_odd_even 'g' 200
echo "Para 400 elementos"
mpirun --oversubscribe -np 8 ./mpi_odd_even 'g' 400
echo "Para 800 elementos"
mpirun --oversubscribe -np 8 ./mpi_odd_even 'g' 800
echo "Para 1600 elementos"
mpirun --oversubscribe -np 8 ./mpi_odd_even 'g' 1600
echo "Para 3200 elementos"
mpirun --oversubscribe -np 8 ./mpi_odd_even 'g' 3200
echo "########################"
echo "########################"
echo "Corriendo con 16 procesos"
echo
# echo "Para 200 elementos"
# mpirun --oversubscribe -np 16 ./mpi_odd_even 'g' 200
echo "Para 400 elementos"
mpirun --oversubscribe -np 16 ./mpi_odd_even 'g' 400
echo "Para 800 elementos"
mpirun --oversubscribe -np 16 ./mpi_odd_even 'g' 800
echo "Para 1600 elementos"
mpirun --oversubscribe -np 16 ./mpi_odd_even 'g' 1600
echo "Para 3200 elementos"
mpirun --oversubscribe -np 16 ./mpi_odd_even 'g' 3200
rm mpi_mat_vect_mult mat_vect_mult odd_even mpi_odd_even;