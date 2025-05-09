#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Attivita {
    int inizio;
    int fine;
};

/**
 * @brief Funzione di confronto per ordinare le attività in base al tempo di fine crescente
 * 
 * @param a prima attività da confrontare
 * @param b seconda attività da confrontare
 * @return true se a.fine < b.fine, false altrimenti
 */
bool confronto(const Attivita& a, const Attivita& b) {
    return a.fine < b.fine;
}

/**
 * @brief Seleziona il massimo numero di attività compatibili utilizzando un algoritmo greedy.
 *
 * Dato un insieme di attività ciascuna con un orario di inizio e fine, l'algoritmo seleziona
 * il massimo numero di attività tali che nessuna coppia si sovrapponga temporalmente.
 * L'algoritmo ordina le attività per tempo di fine crescente e seleziona greedy la prima disponibile
 * che non si sovrappone alla precedente.
 *
 * @param attivita vettore di attività, ciascuna con attributi `inizio` e `fine`
 * @return vettore contenente il sottoinsieme massimo di attività compatibili
 *
 * @complexity Tempo: Θ(n log n) per l’ordinamento + Θ(n) per la selezione → complessità totale: Θ(n log n)
 *             Spazio: Θ(n) per l’output delle attività selezionate
 */
vector<Attivita> selezionaAttivitaMassime(vector<Attivita>& attivita) {
    // Ordina le attività in base al tempo di fine crescente (strategia greedy)
    sort(attivita.begin(), attivita.end(), confronto);

    vector<Attivita> selezionate;  // Insieme risultato di attività compatibili selezionate
    int tempoUltimaFine = 0;       // Tiene traccia del tempo di fine dell’ultima attività accettata

    // Itera attraverso le attività ordinate
    for (auto& a : attivita) {
        // Se l'attività corrente non si sovrappone all'ultima selezionata, la accettiamo
        if (a.inizio >= tempoUltimaFine) {
            selezionate.push_back(a);       // Aggiunge l’attività alla selezione finale
            tempoUltimaFine = a.fine;       // Aggiorna il tempo di fine di riferimento
        }
    }

    return selezionate;
}

int main() {
    vector<Attivita> attivita = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9}, {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };

    vector<Attivita> selezionate = selezionaAttivitaMassime(attivita);

    cout << "Attività selezionate:\n";
    for (auto& a : selezionate) {
        cout << "Inizio: " << a.inizio << ", Fine: " << a.fine << endl;
    }

    return 0;
}
