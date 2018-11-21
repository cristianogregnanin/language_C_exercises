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
	materia_t materia;
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

studente_con_voti_t crea_studente(){
		
	materia_t materia, materie[DIM_MATERIE];
	strcpy(materie[0].nome, "Italiano");
	strcpy(materie[1].nome, "Storia");
	strcpy(materie[2].nome, "Informatica");
	
	for(i=0;i<DIM_MATERIE;i++){
		materia = materie[i].nome
		printf("Inserisci il nome del docente di %s", materia.nome);
		scanf("%s", materia.docente);
		materie[i] = materia;		
	}
	
	studente_t studente;
	studente_con_voti_t studente_con_voti;
	materia_con_voto_t materia_con_voto;
	
	printf("Inserisci il nome dello studente");
	scanf("%s",studente.nome);

	printf("Inserisci il cognome dello studente");
	scanf("%s",studente.cognome);	
	
	studente_con_voti.studente = studente;
	
	for (i=0;i<DIM_MATERIE;i++){
		materia_con_voto.materia = materie[i];
		for(j=0;j<DIM_VOTI;j++){
			printf("Inserisci il voto di %s",materia_con_voto.materia.nome);
			scanf("%d",materia_con_voto.voti[j]);
		}
		
		studente_con_voti.materie_con_voto[i] = materia_con_voto;	
	}
		
	return studente_con_voti;
}


int main(){
		
	studente_t studenti[DIM_STUDENTI], studente;
	int i,j,massimo,minimo;
	
	popola_materia();
	
	//TODO fare l'inseriemento
	for(i=0;i<DIM_STUDENTI;i++){
		studente = crea_studente();
		studenti[i] = studente;
	}

	
		
	for(i=0;i<DIM_STUDENTI;i++){
		printf("\n\n%s,%s: \n", studenti_con_voti[i].studente.nome, studenti_con_voti[i].studente.cognome);
		for(j=0;j<DIM_MATERIE;j++){
				materia = studenti_con_voti[i].materie_con_voto[j];
				massimo = calcola_massimo(materia.voti);
				minimo = calcola_minimo(materia.voti);
				printf("\t%s: voto piu alto %d, voto piu basso %d\n",materia.nome, massimo, minimo);
		}
		
	}
	
	return 0;
}
