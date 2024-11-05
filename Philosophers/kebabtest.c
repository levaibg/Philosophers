#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *print_message(void *arg) {
    int id = *(int *)arg;
    printf("Bonjour, je suis le thread %d\n", id);
    return NULL;
}

int main() {
    int nb_threads = 5;
    pthread_t threads[nb_threads];
    int ids[nb_threads];  // Stocke les IDs pour chaque thread

    for (int i = 0; i < nb_threads; i++) {
        ids[i] = i + 1; // ID unique pour chaque thread

        // Création du thread, en passant l'ID comme argument
        if (pthread_create(&threads[i], NULL, print_message, &ids[i]) != 0) {
            perror("Erreur de création du thread");
            return 1;
        }
    }

    // Attendre la fin de chaque thread
    for (int i = 0; i < nb_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
