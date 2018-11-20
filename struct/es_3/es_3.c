#include<stdio.h>
#include<string.h>
#define DIM_STUDENTI 4
#define DIM_VOTI 4
#define DIM_MATERIE 3

typedef struct{
	char nome[20];
	char docente[20];
} materia_t;

typedef struct{
	char nome[20];
	char cognome[20];
} studente_t;

typedef struct{
	materia_t nome;
	int voti[DIM_VOTI];
}materia_con_voto_t;

typedef struct{
	studente_t studente;
	materie_con_voto_t materie_con_voto[DIM_MATERIE];			
}studente_con_voti_t;

int calcola_massimo(){
	int i,massimo = voti[0];
	
	for(i=1;i<DIM_VOTI;i++){
		if(voti[i]>massimo)
			massimo = voti[i];
	}
	
	return massimo;
}

int calcola_massimo(){
	int i,minimo = SHRT_INT;
	
	for(i=0;i<DIM_VOTI;i++){
		if(voti[i]<minimo)
			minimo = voti[i];
	}
	
	return minimo;
}


int main(){
	
	
	tipo_studente studenti[DIM_STUDENTI], studente;
	
	int i,j,massimo,minimo;
	
	
	//TODO fare l'inseriemento
	for(i=0;i<DIM_STUDENTI;i++){
		studente = crea_studente();
		studenti[i] = studente;
	}

	
		
	for(i=0;i<DIM_STUDENTI;i++){
		printf("\n\n%s,%s: \n", studenti_con_voti[i].studente.nome, studenti_con_voti[i].studente.cognome);
		for(j=0;j<3;j++){
				materia = studenti_con_voti[i].materie_con_voto[j];
				massimo = calcola_massimo(materia.voti);
				minimo = calcola_minimo(materia.voti);
				printf("\t%s: voto piu alto %d, voto piu basso %d\n",materia.nome, massimo, minimo);
		}
		
	}
	
	return 0;
}
