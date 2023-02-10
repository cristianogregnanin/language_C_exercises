/**
 * \file structPersona.c
 * \author Cristiano Gregnanin
 * \brief The program asks to enter the name, the surname and the age of four people, then it tells the user which person is the oldest.
 */

#include <stdio.h>
#include <stdlib.h>
/// \param DIM: The dimension of the array of people.
#define DIM 4

/**
 * \brief The struct "Person_T" represents a person. It has a name, a surname and an age
 * \param char name[12]: The name of the person
 * \param char surname[12]: The surname of the person
 * \param int age: The age of the person
 */
typedef struct
{
    char name[12];
    char surname[12];
    int age;
} Person_T;

/**
 * \fn addPerson()
 * \brief The function "addPerson()" asks the user to enter the name of the person, their surname and their age
 * \return Person_T: The function returns a person
 */
Person_T addPerson()
{
    Person_T person;
    printf("\nInserisci il nome della persona: ");
    scanf("%s", person.name);
    printf("\nInserisci il cognome della persona: ");
    scanf("%s", person.surname);
    printf("\nInserisci l'eta' della persona: ");
    scanf("%d", &person.age);
    return person;
}

/**
 * \fn findOldest(Person_T people[])
 * \brief The function "findOldest" receives in input an array of variables which type is Person_T, and finds which person has the higher age
 * \return Person_T: The function returns the oldest person in the array
 * \param Person_T oldest: The oldest person of the array
 * \param Person_T person: The person we are comparing to the current oldest person
 */
Person_T findOldest(Person_T people[])
{
    Person_T oldest = people[0];
    Person_T person;
    for (int i = 1; i < DIM; i++)
    {
        person = people[i];
        if (oldest.age < person.age)
        {
            oldest = person;
        }
    }
    return oldest;
}

/**
 * \brief In the main function the program will call the addPerson function, DIM times, in order to populate an array of people. Then, it calls the findOldest function to find the oldest person of the array, and it tells the name and the surname of the oldest person
 * \param Person_T oldest: The oldest person of the array
 * \param people[DIM]: An array of people, which size is defined by DIM
 */
int main(int argc, char *argv[])
{
    Person_T oldest;
    Person_T people[DIM];
    for (int i = 0; i < DIM; i++)
    {
        people[i] = addPerson();
    }
    oldest = findOldest(people);
    printf("\nLa persona piu' vecchia e' %s %s, di eta': %d", oldest.name, oldest.surname, oldest.age);
    return 0;
}
