#include<stdio.h>
#include<string.h>
#define DIM 3

typedef struct{
		
		char nome[20];
		int voto;

}tipo_materia;

typedef struct{

		char nome[20];
		char cognome[20];
		tipo_materia materie[3];	
		
}tipo_studente;

typedef struct{

		tipo_studente studente;
		double media;
		
}tipo_studente_con_media;



tipo_studente crea_studente(){

	tipo_studente studente;
	int j;
			

	printf("inserisci il nome:\n");
	scanf("%s", studente.nome);
	
	printf("inserisci il cognome:\n");
	scanf("%s", studente.cognome);
	
	for(j=0;j<3;j++){			
		printf("inserisci il nome della materia:\n");
		scanf("%s", studente.materie[j].nome);
	
		printf("inserisci il voto per %s :\n", studente.materie[j].nome);
		scanf("%d", &studente.materie[j].voto);
	}
		
	return studente;

}

tipo_studente_con_media calcola_media(tipo_studente s){
	int i;
	double media, somma = 0;
	tipo_studente_con_media studente_con_media;
	
	studente_con_media.studente = s;
	
	for(i=0;i<3;i++){
		somma = somma + s.materie[i].voto;
	}
	
	studente_con_media.media = (double) somma/(double) 3;
		
	return studente_con_media;
}

tipo_studente_con_media calcola_vincitore(tipo_studente_con_media medie[]){
	
	int i;
	tipo_studente_con_media massimo;
	double max = medie[0].media;
	
	for(i=1;i<DIM;i++){
		if (medie[i].media>max){
			massimo.studente = medie[i].studente;
			massimo.media = medie[i].media;
		}
	}
	
	return massimo;
}

int main(){
	
	
	tipo_studente studenti[DIM], studente;
	tipo_studente_con_media medie[DIM],vincitore;
	int i;
	
	for(i=0;i<DIM;i++){
		studente = crea_studente();
		studenti[i] = studente;
		medie[i] = calcola_media(studente);
	}

	vincitore = calcola_vincitore(medie);
		
	
    printf("lo studente con la media piu alta e': %s %s \n\n", vincitore.studente.nome, vincitore.studente.cognome);

	return 0;
}
