//Enzo Brito Alves de Oliveira - RA: 082220040
//Heitor Santos Ferreira - RA: 081230042
#include iostream
#include vector
#include string

using namespace std;

struct Musica {
    string nome;
    string categoria;
};

void insertionSort(vectorMusica& playlist) {
    int n = playlist.size();
    for (int i = 1; i  n; ++i) {
        Musica chave = playlist[i];
        int j = i - 1;

         Move os elementos do vetor que são maiores que a chave
         para uma posição à frente de sua posição atual
        while (j = 0 && playlist[j].categoria  chave.categoria) {
            playlist[j + 1] = playlist[j];
            j = j - 1;
        }
        playlist[j + 1] = chave;
    }
}

int main() {
     Exemplo de playlist desordenada
    vectorMusica playlist = {
        {Música 1, Rock},
        {Música 2, Pop},
        {Música 3, Eletrônica},
        {Música 4, Rock},
        {Música 5, Pop}
    };

     Ordena a playlist usando o insertion sort
    insertionSort(playlist);

     Imprime a playlist ordenada por categoria
    cout  Playlist ordenada por categoria  endl;
    for (const auto& musica  playlist) {
        cout  Nome   musica.nome  , Categoria   musica.categoria  endl;
    }

    return 0;
}
