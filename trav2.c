#include <stdio.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int map [5][5] = {
     {0, 3, 5, 3, 7},
     {2, 0, 8, 9, 15},
     {4, 10, 0, 3, 9},
     {9, 12, 7, 0, 2},
     {15, 12, 11, 4, 0 }
};

double generaFloats( double min, double max ) {    

    double scale = rand(

    ) / (double) RAND_MAX;

    return min + scale * ( max - min );
}
void getProbability(int population, int cities, int popArray[population][cities], int evalArray[population], double popProba[population]){
    int fitness;
    int i, j;
    int a;
    int distance = 0;
    int cumulativeDistance = 0;
    float sum = 0;
    for (i = 0; i < population; i++){
        printf("%d ", evalArray[i]);
        cumulativeDistance += evalArray[i];
    }

    printf("\nCumDist: %d", cumulativeDistance);
    printf("\n");
    for (i = 0; i < population; i++){
        popProba[i] =  (1 - ((evalArray[i]) /(float) cumulativeDistance)) / (population - 1) ;
        sum+= popProba[i];
        printf("%lf ", popProba[i]);
    }

    printf("\nprob total: %lf\n", sum);

    for (i = 1; i < population; i++){
        popProba[i] = popProba[i] + popProba[i-1];
        //printf("%lf", popProba[i]);
    }

    printf("\nprob total: %lf", popProba[9]);
}

void getFitness(int population, int cities, int index,int popArray[population][cities], int evalArray[population]){
    int fitness;
    int i, j;
    int distance = 0;
    int cumulativeDistance = 0;
    float sum = 0;

        for (i = 1; i < cities; i++ ){
            int startPoint = popArray[index][i-1];
            int endPoint= popArray[index][i];
            distance += map[startPoint][endPoint];

        }
        evalArray[index] = distance;
}

bool notInCitiesPlaced(int cities, int citiesPlaced[cities], int num){
    bool flag = true;
    int i;
    for (i = 0; i < cities; i++ ){
        if(citiesPlaced[i] == num )
            flag = false;
    }
    return flag;
}


void generateRoads(int population, int cities, int popArray[population][cities], int i ) {    
    int citiesPlaced [cities];
    int count = 0;

    for (count = 0; count < cities; count++){
        citiesPlaced[count] = -1;
    }

    for (count = 0; count < cities; count++){
        int num = rand() % cities;

        if (notInCitiesPlaced(cities, citiesPlaced, num)){
            popArray[i][count] = num;
            citiesPlaced[count] = num;
        } else{
            count--;
        }
    }
    
}

/* El main inicialmente genera la poblacion y posteriormente se generan nuevos elementos para la population mediante cruza y mutacion.
Este proceso se repite por la cantidad de veces que se hayan establecido las generaciones, osea si hay 25 generaciones se repite 25 veces.
Finalmente el mejor valor de cada generacion es guardado y al final se imprime el mejor resultado de todas las generaciones*/ 
int main( ) {

   srand(time(NULL));
   int cities = 5;
   int population = 10; //El tamano de la population
   int generations = 5; //La cantidad de generaciones

   int popArray [population][cities]; //Where population values are stored
   int evalArray [population]; //En donde se guardan los resultados de la population al evaluarse
   double popProba[population];// En donde se guarda la probabilidad de cada elemento de la population en ser escogido para futuras populationes
   int resultadosGeneracion [generations]; // En donde se guardan los resultados de los elementos mas altos de cada generacion

   int valorOptimo = 999999;
   int i;
   int j;
   int k;
   for (i = 0; i < population; i++){
        generateRoads(population, cities, popArray, i);
    }

    for (i = 0; i < 1; i++){ //generations

        for(j = 0; j < population; j++){
            for (k = 0; k < cities; k++){
                printf("%d ", popArray[j][k]);
            }
            printf("\n");
        }
        printf("\n\nNormalized:\n ");

        for (j = 0; j < population; j++){
            getFitness(population, cities, j, popArray, evalArray);
        }

        getProbability(population, cities, popArray, evalArray, popProba);
        //TODO: Ruletas para elegir padres, metodos de crossover y mutacion
        s
    }

        
}


