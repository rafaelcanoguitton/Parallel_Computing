#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
//Generating random numbers
int rand_range(int min, int max)
{
    return rand() % (max - min + 1) + min;
}
//Defining linked list class
pthread_mutex_t mutex;
struct list_node_s
{
    int data;
    struct list_node_s *next;
};
struct list_node_s *head_p = NULL;
int Member(int value)
{
    struct list_node_s *curr_p = head_p;
    while (curr_p != NULL && curr_p->data < value)
        curr_p = curr_p->next;
    if (curr_p == NULL || curr_p->data > value)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int Insert(int value)
{
    struct list_node_s *curr_p = head_p;
    struct list_node_s *pred_p = NULL;
    struct list_node_s *temp_p;
    while (curr_p != NULL && curr_p->data < value)
    {
        pred_p = curr_p;
        curr_p = curr_p->next;
    }
    if (curr_p == NULL || curr_p->data > value)
    {
        temp_p = malloc(sizeof(struct list_node_s));
        temp_p->data = value;
        temp_p->next = curr_p;
        if (pred_p == NULL)
            head_p = temp_p;
        else
            pred_p->next = temp_p;
        return 1;
    }
    else
    {
        return 0;
    }
}
int Delete(int value)
{
    struct list_node_s *curr_p = head_p;
    struct list_node_s *pred_p = NULL;
    while (curr_p != NULL && curr_p->data < value)
    {
        pred_p = curr_p;
        curr_p = curr_p->next;
    }
    if (curr_p == NULL || curr_p->data > value)
    {
        return 0;
    }
    else
    {
        if (pred_p == NULL)
            head_p = curr_p->next;
        else
            pred_p->next = curr_p->next;
        free(curr_p);
        return 1;
    }
}
int Print()
{
    struct list_node_s *curr_p = head_p;
    while (curr_p != NULL)
    {
        printf("%d ", curr_p->data);
        curr_p = curr_p->next;
    }
    printf("\n");
    return 1;
}
// void Memberhelper()
// {
//     //80000 member calls
//     int i;
//     for (i = 0; i < 80000; i++)
//     {
//         Member(rand_range(0, 100000));
//     }
// }
// int InsertionHelper()
// {
//     //10000 insertion calls
//     int i;
//     for (i = 0; i < 10000; i++)
//     {

//         int value = rand_range(0, 100000);
//         pthread_mutex_lock(&mutex);
//         Insert(value);
//         pthread_mutex_unlock(&mutex);
//     }
//     return 1;
// }
// void DeletionHelper()
// {
//     //10000 deletion calls
//     int i;
//     for (i = 0; i < 10000; i++)
//     {
//         Delete(rand_range(0, 100000));
//     }
// }
void OpHelper()
{
    //100000 calls
    int i;
    //random_number_from_1_to_10
    for (i = 0; i < 100000; i++)
    {
        int op = rand_range(0, 9);
        int value=rand_range(0, 10000);
        if (op == 0)
        {
            pthread_mutex_lock(&mutex);
            Delete(value);
            pthread_mutex_unlock(&mutex);
        }
        else if (op == 1)
        {
            pthread_mutex_lock(&mutex);
            Insert(value);
            pthread_mutex_unlock(&mutex);
        }
        else
        {
            pthread_mutex_lock(&mutex);
            Member(value);
            pthread_mutex_unlock(&mutex);
        }
    }
}
void mainHelper(int numThreads)
{
    head_p = NULL;
    //Inicializar la lista con 1000 elementos
    int i;
    for (i = 0; i < 1000; i++)
    {
        int value=rand_range(0, 10000);
        Insert(value);
    }
    printf("--------------------------");
    printf("\n");
    printf("Tiempo para ");
    printf("%d", numThreads);
    printf(" hilos\n");
    clock_t start, end;
    pthread_t threads[numThreads];
    // start=clock();
    // for (i=0;i<numThreads;i++){
    //     pthread_create(&threads[i],NULL,(void*)InsertionHelper,NULL);
    // }
    // for(i=0;i<numThreads;i++){
    //     pthread_join(threads[i],NULL);
    // }
    // end=clock();
    // printf("\n");
    // printf("Para Inserción: \n");
    // printf("%f\n",(double)(end-start)/CLOCKS_PER_SEC);
    // start=clock();
    // for (i=0;i<numThreads;i++){
    //     pthread_create(&threads[i],NULL,(void*)Memberhelper,NULL);
    // }
    // for(i=0;i<numThreads;i++){
    //     pthread_join(threads[i],NULL);
    // }
    // end=clock();
    // printf("\n");
    // printf("Para Busqueda: \n");
    // printf("%f\n",(double)(end-start)/CLOCKS_PER_SEC);
    // start=clock();
    // for (i=0;i<numThreads;i++){
    //     pthread_create(&threads[i],NULL,(void*)DeletionHelper,NULL);
    // }
    // for(i=0;i<numThreads;i++){
    //     pthread_join(threads[i],NULL);
    // }
    // end=clock();
    // printf("\n");
    // printf("Para Eliminación: \n");
    // printf("%f\n",(double)(end-start)/CLOCKS_PER_SEC);
    // printf("--------------------------");
    //start=clock();
    // for(i=0;i<numThreads;i++){
    //     pthread_create(&op1[i],NULL,(void*)InsertionHelper,NULL);
    //     pthread_create(&op2[i],NULL,(void*)Memberhelper,NULL);
    //     pthread_create(&op3[i],NULL,(void*)DeletionHelper,NULL);
    // }
    // for(i=0;i<numThreads;i++){
    //     pthread_join(op1[i],NULL);
    //     pthread_join(op2[i],NULL);
    //     pthread_join(op3[i],NULL);
    // }
    //end=clock();
    start = clock();
    for (i = 0; i < numThreads; i++)
    {
        pthread_create(&threads[i], NULL,(void *)OpHelper, NULL);
    }
    for(i=0;i<numThreads;i++){
        pthread_join(threads[i],NULL);
    }
    end = clock();
    printf("\n");
    printf("Para 100,000 operaciones 80%% de inserción, 10%% de búsqueda y 10%% de eliminación aprox: \n");
    printf("%f\n", (double)(end - start) / CLOCKS_PER_SEC);
}
int main()
{
    srand(time(NULL));
    mainHelper(1);
    mainHelper(2);
    mainHelper(4);
    mainHelper(8);
    //Print();
    return 0;
}